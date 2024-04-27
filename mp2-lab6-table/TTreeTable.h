#pragma once
#include <stack>
#include "TTable.h";

#define BalOK		 0 // ������ ��������������
#define BalLeft		-1 // ������� � ����� �������
#define BalRight	 1 // ������� � ������ �������

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

	// ��������� ������
	void printTreeTab(std::ostream& os, TTreeNode* pNode);
	void drawTreeTab(TTreeNode* pNode, int level);
	void deleteTreeTab(TTreeNode* pNode) // �������� ������ � �������� pNode
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
	//�����������: �������� ��� ����
	//�������� �� �������: ����������� ������� ����� (�������� �� ������������� ������)
	~TTreeTable() { deleteTreeTab(pRoot); }

	// ???
	bool findRec(TKey key);
	int insRec(TRecord rec);
	int delRec(TKey key);
};