#pragma once
#include <stack>
#include "TTable.h";

#define BalOK		 0 // дерево сбалансировано
#define BalLeft		-1 // перевес в левую сторону
#define BalRight	 1 // перевес в правую сторону

struct TTreeNode
{
	TRecord rec;
	TTreeNode* pLeft, *pRight;
	int bal;

	TTreeNode()
	{
		pLeft = pRight = NULL;
		bal = BalOK;
	}
	TTreeNode(const TRecord& _rec)
	{
		rec = _rec;
		pLeft = pRight = NULL;
		bal = BalOK;
	}
};

class TTreeTable : public TTable
{
protected:
	TTreeNode* pRoot; // корень дерева
	TTreeNode* pCurr; // текущий элемент
	TTreeNode* pPr;	  // предшествующий элемент
	std::stack<TTreeNode*> st;
	int Deep; // глубина элемента
public:
	TTreeTable() : TTable() { pRoot = pCurr = pPr = NULL; }
	~TTreeTable() { deleteTreeTab(pRoot); }

	// информационные методы
	virtual bool isFull() const { return false; };

	// навигаци€
	virtual void reset();
	virtual bool isTabEnd() const;
	virtual void goNext();

	// основные методы
	virtual bool findRec(TKey key) final;
	virtual int insRec(TRecord rec);
	virtual int delRec(TKey key);

	// служебные методы
	void printTreeTab(std::ofstream& file, TTreeNode* pNode, int level);
	//void drawTreeTab(TTreeNode* pNode, int level);
	void deleteTreeTab(TTreeNode* pNode); // удаление дерева с вершиной pNode

	// доступ
	virtual TRecord& getRec() const final;

	// служебные методы
	virtual void fillTab(int size, int keyrange);
	virtual void printTab(std::string filename) final;
	virtual void clrTab() final;
};



bool TTreeTable::findRec(TKey key)
{
	pCurr = pRoot;
	pPr = NULL;
	while (pCurr != NULL) {
		eff++;
		if (pCurr->rec.key == key) break;
		else {
			pPr = pCurr;
			if (pCurr->rec.key > key)
				pCurr = pCurr->pLeft;
			else
				pCurr = pCurr->pRight;
		}
	}
	if (pCurr != NULL) return true;
	else {
		pCurr = pPr;
		return false;
	}
}

int TTreeTable::insRec(TRecord rec)
{
	bool res = findRec(rec.key);
	if (res) return TabRecDbl;
	else {
		DataCount++;
		TTreeNode* pNew = new TTreeNode(rec);
		if (pRoot == NULL) pRoot = pNew;
		else {
			if (pCurr->rec.key > rec.key) pCurr->pLeft = pNew;
			else pCurr->pRight = pNew;
		}
	}
	return TabOK;
}

int TTreeTable::delRec(TKey key)
{
	bool res = findRec(key);
	if (!res) return TabNoRec;
	else {
		TTreeNode* pDel = NULL;
		if (pCurr->pRight == NULL)
		{
			if (pPr == NULL) pRoot = pRoot->pLeft;
			else {
				if (pCurr->rec.key > pPr->rec.key)
					pPr->pRight = pCurr->pLeft;
				else
					pPr->pLeft = pCurr->pLeft;
			}
		}
		else if (pCurr->pLeft == NULL)
		{
			if (pPr == NULL)  pRoot = pRoot->pRight;
			else {
				if (pCurr->rec.key > pPr->rec.key)
					pPr->pRight = pCurr->pRight;
				else
					pPr->pLeft = pCurr->pRight;
			}
		}
		else
		{
			TTreeNode* tmp = pCurr->pLeft;
			pPr = pCurr;
			while (tmp->pRight != NULL) {
				eff++;
				pPr = tmp;
				tmp = tmp->pRight;
			}
			pCurr->rec = tmp->rec;
			if (pPr != pCurr)
				pPr->pRight = tmp->pLeft;
			else
				pPr->pLeft = tmp->pLeft;
			pDel = tmp;
		}
		eff++;
		delete pDel;
		DataCount--;
	}
	return TabOK;
}

void TTreeTable::reset()
{
	while (!st.empty()) st.pop();

	pCurr = pRoot;
	while (pCurr != NULL)
	{
		st.push(pCurr);
		pCurr = pCurr->pLeft;
	}
	pCurr = st.top();
	Deep = 0;
}

void TTreeTable::goNext()
{
	if (pCurr == NULL || isTabEnd()) throw "";
	if (!st.empty()) st.pop();
	if (pCurr->pRight != NULL)
	{
		pCurr = pCurr->pRight;
		while (pCurr != NULL)
		{
			st.push(pCurr);
			pCurr = pCurr->pLeft;
		}
		pCurr = st.top();
	}
	else if (!st.empty())
		pCurr = st.top();
	Deep++;
}

bool TTreeTable::isTabEnd() const
{
	return Deep == DataCount;
}

void TTreeTable::printTreeTab(std::ofstream& file, TTreeNode* pNode, int level)
{
	if (pNode != NULL)
	{
		for (int i = 0; i < level; i++)
			file << "  ";
		file << pNode->rec.key << std::endl;
		printTreeTab(file, pNode->pRight, level + 1);
		printTreeTab(file, pNode->pLeft, level + 1);
	}
}

void TTreeTable::printTab(std::string filename)
{
	std::ofstream file("saved-tables/" + filename + ".txt");
	printTreeTab(file, pRoot, 0);
	file.close();
}

void TTreeTable::deleteTreeTab(TTreeNode* pNode)
{
	if (pNode != NULL)
	{
		deleteTreeTab(pNode->pLeft);
		deleteTreeTab(pNode->pRight);
		delete pNode;
		DataCount--;
	}
}

TRecord& TTreeTable::getRec() const
{
	return pCurr->rec;
}

void TTreeTable::fillTab(int size, int keyrange)
{
	if (size <= 0) throw "Invalid value for the table size";
	srand(time(0));
	TRecord rec;
	int keyrand, valrand;
	DataCount = 0;

	std::vector<bool> usedKeys(keyrange, false);

	for (int i = 0; i < size; i++) {
		do {
			keyrand = rand() % keyrange;
		} while (usedKeys[keyrand]);

		usedKeys[keyrand] = true;

		valrand = rand() % (-1999) - 1000;
		rec = TRecord(keyrand, valrand);
		insRec(rec);
	}
}

void TTreeTable::clrTab()
{
	deleteTreeTab(pRoot);
	pRoot = NULL;
}