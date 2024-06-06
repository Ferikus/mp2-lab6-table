#pragma once
#include "TTreeTable.h";

#define H_OK      0
#define H_INC	  1
#define H_DEC	 -1

class TAVLTree : public TTreeTable
{
protected:
	int LeftBalance(TTreeNode*& pNode);			// балансировка левого поддерева pNode
	int RightBalance(TTreeNode*& pNode);		// балансировка правого поддерева pNode
	int insBal(TTreeNode*& pNode, TRecord rec); // вспомогательная функция для добавления узла в АВЛ-дереве
	int delBal(TTreeNode*& pNode, TKey key);	// вспомогательная функция для удаления узла в АВЛ-дереве
	int RemoveMin(TTreeNode*& pNode);			// исключить минимальный элемент из дерева (отвязывает его от дерева)
	TTreeNode* FindMin(TTreeNode* pNode);		// поиск минимального элемента в поддереве pNode
public:
	// основные методы
	virtual int insRec(TRecord rec);
	virtual int delRec(TKey key);

	// служебные методы
	void fillTab(int size, int keyrange);
};

int TAVLTree::LeftBalance(TTreeNode*& pNode)
{
	eff++;
	int res = H_OK;

	switch (pNode->bal)
	{
	case BalRight:
		pNode->bal = BalOK;
		res = H_OK;
		break;

	case BalOK: 
		pNode->bal = BalLeft;
		res = H_INC;
		break;

	case BalLeft:
		TTreeNode* p1, *p2;
		p1 = pNode->pLeft;
		if (p1->bal == BalLeft)
		{
			pNode->pLeft = p1->pRight;
			p1->pRight = pNode;
			pNode->bal = BalOK;
			pNode = p1;
		}
		else
		{
			p2 = p1->pRight;
			p1->pRight = p2->pLeft;
			p2->pLeft = p1;
			pNode->pLeft = p2->pRight;
			p2->pRight = pNode;

			if (p2->bal == BalLeft)
				pNode->bal = BalRight;
			else
				pNode->bal = BalOK;

			if (p2->bal == BalRight)
				p1->bal = BalLeft;
			else
				p1->bal = BalOK;

			pNode = p2;
		}
		pNode->bal = BalOK;
		res = H_OK;
	}
	return res;
}

int TAVLTree::RightBalance(TTreeNode*& pNode)
{
	eff++;
	int res = H_OK;

	switch (pNode->bal)
	{
	case BalLeft:
		pNode->bal = BalOK;
		res = H_OK;
		break;

	case BalOK:
		pNode->bal = BalRight;
		res = H_INC;
		break;

	case BalRight:
		TTreeNode* p1, * p2;
		p1 = pNode->pRight;
		if (p1->bal == BalRight)
		{
			pNode->pRight = p1->pLeft;
			p1->pLeft = pNode;
			pNode->bal = BalOK;
			pNode = p1;
		}
		else
		{
			p2 = p1->pLeft;
			p1->pLeft = p2->pRight;
			p2->pRight = p1;
			pNode->pRight = p2->pLeft;
			p2->pLeft = pNode;

			if (p2->bal == BalRight)
				pNode->bal = BalLeft;
			else
				pNode->bal = BalOK;

			if (p2->bal == BalLeft)
				p1->bal = BalRight;
			else
				p1->bal = BalOK;

			pNode = p2;
		}
		pNode->bal = BalOK;
		res = H_OK;
	}
	return res;
}

int TAVLTree::insBal(TTreeNode*& pNode, TRecord rec)
{
	eff++;
	int res = H_OK;
	if (pNode == NULL) {
		pNode = new TTreeNode(rec);
		res = H_INC;
		DataCount++;
	}
	else if (pNode->rec.key > rec.key) {
		int tmp = insBal(pNode->pLeft, rec);
		if (tmp == H_INC) res = LeftBalance(pNode);
	}
	else if (pNode->rec.key < rec.key) {
		int tmp = insBal(pNode->pRight, rec);
		if (tmp == H_INC) res = RightBalance(pNode);
	}
	return res;
}

int TAVLTree::delBal(TTreeNode*& pNode, TKey key)
{
	eff++;
	int res = H_OK;
	if (pNode == NULL) return res;
	if (pNode->rec.key > key)
	{
		res = delBal(pNode->pLeft, key);
		if (res != H_OK)
		{
			res = RightBalance(pNode);
		}
	}
	else if (pNode->rec.key < key)
	{
		res = delBal(pNode->pRight, key);
		if (res != H_OK)
		{
			res = LeftBalance(pNode);
		}
	}
	else
	{
		DataCount--;
		if (pNode->pLeft == NULL && pNode->pRight == NULL)
		{
			delete pNode;
			pNode = NULL;
			res = H_DEC;
		}
		else if (pNode->pRight == NULL && pNode->pLeft != NULL)
		{
			pNode->rec = pNode->pLeft->rec;
			delete pNode->pLeft;
			pNode->pLeft = NULL;
			pNode->bal = BalOK;
			res = H_DEC;
		}
		else if (pNode->pRight != NULL && pNode->pLeft == NULL)
		{
			pNode->rec = pNode->pRight->rec;
			delete pNode->pRight;
			pNode->pRight = NULL;
			pNode->bal = BalOK;
			res = H_DEC;
		}
		else
		{
			TTreeNode* l, * r;
			l = pNode->pLeft;
			r = pNode->pRight;
			TTreeNode* min = FindMin(r);
			int min_key = min->rec.key;
			pNode->rec = min->rec;
			res = RemoveMin(r);

			delete min;
			pNode->pLeft = l;
			pNode->pRight = r;

			if (res != H_OK)
			{
				res = LeftBalance(pNode);
			}

		}
	}
	return res;

}

int TAVLTree::RemoveMin(TTreeNode*& pNode)
{
	eff++;
	int res = H_OK;
	if (pNode->pLeft == NULL) {
		pNode = pNode->pRight;
		res = H_DEC;
	}
	else {
		res = RemoveMin(pNode->pLeft);
		if (res != H_OK)
			res = RightBalance(pNode);
	}
	return res;
}

TTreeNode* TAVLTree::FindMin(TTreeNode* pNode)
{
	if (pNode == NULL) return NULL; 
	while (pNode->pLeft != NULL)
		pNode = pNode->pLeft;
	return pNode;
}

int TAVLTree::delRec(TKey key)
{
	bool res = findRec(key);
	if (!res) return TabNoRec;
	delBal(pRoot, key);
	return TabOK;
}

int TAVLTree::insRec(TRecord rec)
{
	bool res = findRec(rec.key);
	if (res) return TabRecDbl;
	insBal(pRoot, rec);
	return TabOK;
}

void TAVLTree::fillTab(int size, int keyrange)
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