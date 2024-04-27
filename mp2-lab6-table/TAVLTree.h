#pragma once
#include "TTreeTable.h";

#define HeightOK      0
#define HeightINC	  1
#define HeightDEC	 -1

class TAVLTreeTable : public TTreeTable
{
protected:
	int insBal(TTreeNode*& pNode, TRecord rec);
	int LeftBalance(TTreeNode*& pNode);
	int RightBalance(TTreeNode*& pNode);
public:
	int insRec(TRecord rec);
};