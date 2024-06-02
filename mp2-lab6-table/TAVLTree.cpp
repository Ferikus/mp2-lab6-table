#include "TAVLTree.h";

int TAVLTreeTable::insBal(TTreeNode*& pNode, TRecord rec)
{
	eff++;
	int res = HeightOK;
	if (pNode == NULL) {
		pNode = new TTreeNode(rec);
		res = HeightINC;
		DataCount++;
	}
	else if (pNode->rec.key > rec.key) {
		int tmp = insBal(pNode->pLeft, rec);
		if (tmp == HeightINC) res = LeftBalance(pNode);
	}
	else if (pNode->rec.key < rec.key) {
		int tmp = insBal(pNode->pRight, rec);
		if (tmp == HeightINC) res = RightBalance(pNode);
	}
	return res;
}

//int TAVLTreeTable::LeftBalance(TTreeNode*& pNode)
//{
//
//}
//
//int TAVLTreeTable::RightBalance(TTreeNode*& pNode)
//{
//}

int TAVLTreeTable::insRec(TRecord rec)
{
	bool res = findRec(rec.key);
	if (res == true) return TabRecDbl;
	insBal(pRoot, rec);
	return TabOK;
}