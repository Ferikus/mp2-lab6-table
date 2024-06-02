#include "TTreeTable.h";

bool TTreeTable::findRec(TKey key)
{
	pCurr = pRoot;
	pPr = NULL;
	while (pCurr != nullptr) {
		if (pCurr->rec.key == key) break;
		else {
			pPr = pCurr;
			if (pCurr->rec.key > key) pCurr = pCurr->pLeft;
			else pCurr = pCurr->pRight;
		}
		eff++;
	}
	if (pCurr != NULL) return true;
	else {
		pCurr = pPr;
		return false;
	}
	return TabOK;
}

int TTreeTable::insRec(TRecord rec)
{
	bool res = findRec(rec.key);
	if (res) return TabRecDbl;
	else {
		DataCount++;
		TTreeNode* pNew = new TTreeNode;
		pNew->rec = rec; // заменить на конструктор
		if (pRoot == NULL) pRoot = pNew;
		else {
			if (pCurr->rec.key > rec.key) pCurr->pLeft = pNew;
			else pCurr->pRight = pNew;
		}
	}
	return TabOK;
}

//int TTreeTable::delRec(TKey key)
//{
//	bool res = findRec(key);
//	if (res == false) return TabNoRec;
//	else {
//		TTreeNode* pDel;
//		if (pPr == NULL) pRoot = pCurr->pLeft; // ??? верный ли порядок команд, проверить на примере
//		else {
//			if (pCurr->pRight == NULL) {
//				pDel = pCurr;
//				if (pPr->rec.key > pCurr->rec.key) // левая ветка
//					pPr->pLeft = pCurr->pLeft;
//				else pPr->pRight == pCurr->pRight; // правая ветка
//			}
//			else if (pCurr->pLeft == NULL) {
//				pDel = pCurr;
//				if (pPr->rec.key > pCurr->rec.key) // левая ветка
//					pPr->pRight = pCurr->pRight;
//				else pPr->pLeft == pCurr->pLeft; // правая ветка
//			}
//		}
//		delete pDel;
//	}
//	return TabOK;
//}