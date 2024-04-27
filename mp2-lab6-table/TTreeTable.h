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
	TTreeNode(TRecord _rec)
	{
		rec = _rec;
		pLeft = pRight = NULL;
		bal = BalOK;
	}
};

class TTreeTable : public TTable
{
protected:
	TTreeNode* pRoot, * pCurr, * pPr;
	std::stack<TTreeNode> st;

	// служебные методы
	void printTreeTab(std::ostream& os, TTreeNode* pNode);
	void drawTreeTab(TTreeNode* pNode, int level);
	void deleteTreeTab(TTreeNode* pNode) // удаление дерева с вершиной pNode
	{
		if (pNode != NULL)
		{
			deleteTreeTab(pNode->pLeft);
			deleteTreeTab(pNode->pRight);
			delete pNode;
		}
	}
public:
	TTreeTable() : TTable() { CurrPos = 0; pRoot = pCurr = NULL; }
	//конструктор: обнулить все поля
	//проверка на полноту: попробовать создать звено (проверка на заполненность памяти)
	~TTreeTable() { deleteTreeTab(pRoot); }

	// ???
	bool findRec(TKey key);
	int insRec(TRecord rec);
	int delRec(TKey key);
};