#pragma once
#include "THashTable.h"
#include <list>

class TListHash : public THashTable
{
protected:
	std::list<TRecord>* pList;			// пам€ть дл€ записей таблицы (массив списков)
	int CurrList;						// номер текущего списка
	std::list<TRecord>::iterator pCurr; // итератор дл€ пробега по текущему списку
public:
	TListHash(int size = TabMaxSize);
	~TListHash();

	// навигаци€
	virtual void reset();
	virtual bool isTabEnd() const;
	virtual void goNext();

	// информационные методы ------------------ isFull getRec и Ќ≈ »—ѕќЋ№«”ё“—я
	virtual bool isFull() const { return 0; };
	// доступ
	virtual TRecord& getRec() const;

	// основные методы
	virtual bool findRec(TKey key);
	virtual int insRec(TRecord rec);
	virtual int delRec(TKey key);

	// заполнение и печать
	virtual void fillTab(int size);
	virtual void printTab(std::string filename);
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
	while (pCurr == pList[CurrList].end() && CurrList < MaxSize) {
		// pCurr == pList[CurrList].end() значит, что текущий список пустой
		// pList[CurrList].end() указывает на следующий элемент после последнего, это аналог nullptr
		CurrList++;
		pCurr = pList[CurrList].begin();
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
		if (key == pCurr->key) return true;
		eff++;
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

void TListHash::fillTab(int size)
{
	if (size <= 0) throw "Invalid value for the table size";
	srand(time(0));
	TRecord rec;
	DataCount = size; 
	for (int i = 0; i < size; i++) {
		rec = TRecord(rand() % 100, rand() % (-1999) - 1000);
		insRec(rec);
	}
}

void TListHash::printTab(std::string filename)
{
	std::ofstream file(filename + ".txt");
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

