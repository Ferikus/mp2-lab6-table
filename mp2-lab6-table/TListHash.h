#pragma once
#include "THashTable.h"

class TListHash : public THashTable
{
protected:
	std::list<TRecord>* pList;			// ������ ��� ������� ������� (������ �������)
	int CurrList;						// ����� �������� ������
	std::list<TRecord>::iterator pCurr; // �������� ��� ������� �� �������� ������
public:
	TListHash(int size = TabMaxSize);
	~TListHash();

	// ���������
	virtual void reset();
	virtual bool isTabEnd() const;
	virtual void goNext();

	// �������������� ������ ------------------ isFull getRec � �� ������������
	virtual bool isFull() const { return 0; };
	// ������
	virtual TRecord& getRec() const;

	// �������� ������
	virtual bool findRec(TKey key);
	virtual int insRec(TRecord rec);
	virtual int delRec(TKey key);

	// ���������� � ������
	virtual void fillTab(int size, int keyrange);
	virtual void printTab(std::string filename);
	virtual void clrTab();
};



TListHash::TListHash(int size)
{
	MaxSize = size;
	pList = new std::list<TRecord>[MaxSize];
	CurrList = -1;
}

TListHash::~TListHash()
{
	delete[] pList;
}

void TListHash::reset()
{
	CurrList = 0;
	pCurr = pList[CurrList].begin();
	while (pCurr == pList[CurrList].end()) {
		// pCurr == pList[CurrList].end() ������, ��� ������� ������ ������
		// pList[CurrList].end() ��������� �� ��������� ������� ����� ����������, ��� ������ nullptr
		CurrList++;
		if (CurrList < MaxSize) {
			pCurr = pList[CurrList].begin();
		}
		else
			break;
	}
}

bool TListHash::isTabEnd() const
{
	return (CurrList == MaxSize);
}

void TListHash::goNext()
{
	while (pCurr == pList[CurrList].end()) {
		CurrList++;
		if (CurrList < MaxSize) pCurr = pList[CurrList].begin();
		else break;
	}
}

TRecord& TListHash::getRec() const
{
	if (CurrList < 0 || CurrList >= MaxSize) throw "CurrList out of range";
	if (pList[CurrList].begin() == pList[CurrList].end()) throw "CurrList is empty";
	return TRecord(pCurr->key, pCurr->val);
}

bool TListHash::findRec(TKey key)
{
	CurrList = HashFunc(key);
	for (pCurr = pList[CurrList].begin(); pCurr != pList[CurrList].end(); pCurr++) {
		eff++;
		if (key == pCurr->key) return true;
	}
	return false;
}

int TListHash::insRec(TRecord rec)
{
	bool res = findRec(rec.key);
	if (res) return TabRecDbl;
	pList[CurrList].push_back(rec);
	DataCount++;
	return TabOK;
}

int TListHash::delRec(TKey key)
{
	bool res = findRec(key);
	if (!res) return TabNoRec;
	pList[CurrList].erase(pCurr);
	DataCount--;
	return TabOK;
}

void TListHash::fillTab(int size, int keyrange)
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

void TListHash::printTab(std::string filename)
{
	std::ofstream file("saved-tables/" + filename + ".txt");
	file << "Table printing" << std::endl;
	for (reset(); !isTabEnd(); goNext())
	{
		pCurr = pList[CurrList].begin();
		file << "(" << pCurr->key << ", " << pCurr->val << ") ";
		pCurr++;
		for (; pCurr != pList[CurrList].end(); pCurr++) {
			file << "-> (" << pCurr->key << ", " << pCurr->val << ") ";
		}
		file << std::endl;
	}
	file.close();
}

void TListHash::clrTab()
{
	/*for (reset(); !isTabEnd(); goNext())
	{
		pList[CurrList].erase(pList[CurrList].begin(), pList[CurrList].end());
	}*/
	for (int i = 0; i < MaxSize; i++) {
		pList[i].clear(); // ������� ������ ������ � �������
	}
	delete[] pList; // ����������� ������, ������� �������� �������
	pList = nullptr;
	pList = new std::list<TRecord>[MaxSize];
	DataCount = 0;
}