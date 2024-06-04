#pragma once
#include "THashTable.h"

class TArrayHash : public THashTable
{
protected:
	TRecord* pRecs; // память для записей таблицы
	int HashStep;	// шаг вторичного хеширования
	int Free;		// первая свободная строка, обнаруженная при поиске
	int Curr;		// строка памяти при завершении поиска
	TRecord Del;	// маркер для индикации строк с удалёнными записями
	TRecord Empty;	// маркер для индикации незанятых строк
public:
	TArrayHash(int size = TabMaxSize);
	~TArrayHash();

	// информационные методы
	virtual bool isFull() const { return DataCount >= MaxSize; }

	// навигация
	virtual void reset();
	virtual bool isTabEnd() const;
	virtual void goNext();

	// доступ
	virtual TRecord& getRec() const;

	// основные методы
	virtual bool findRec(TKey key);
	virtual int insRec(TRecord rec);
	virtual int delRec(TKey key);

	// заполнение и печать
	virtual void fillTab(int size, int keyrange);
	virtual void printTab(std::string filename);
	virtual void clrTab();
};



TArrayHash::TArrayHash(int size)
{
	MaxSize = size;
	pRecs = new TRecord[MaxSize];
	Free = Curr = -1;
	Del = TRecord(-2, 0);
	Empty = TRecord(-3, 0);
	for (int i = 0; i < MaxSize; i++)
		pRecs[i] = Empty;
	HashStep = 1;
}

TArrayHash::~TArrayHash()
{
	delete[] pRecs;
}

void TArrayHash::reset()
{
	for (Curr = 0; Curr < MaxSize; Curr++) {
		if (pRecs[Curr] != Empty && pRecs[Curr] != Del)
			break;
	}
}

bool TArrayHash::isTabEnd() const
{
	return (Curr == MaxSize);
}

void TArrayHash::goNext()
{
	Curr++;
	for (; Curr < MaxSize; Curr++) {
		if (pRecs[Curr] != Empty && pRecs[Curr] != Del)
			break;
	}
}

TRecord& TArrayHash::getRec() const
{
	if (Curr < 0 || Curr >= MaxSize) throw "Index is out of range";
	return pRecs[Curr];
}

bool TArrayHash::findRec(TKey key)
{
	Free = -1;
	Curr = HashFunc(key);
	for (int i = 0; i < MaxSize; i++) {
		if (pRecs[Curr].key == key)
			return true;
		if (pRecs[Curr] == Del && Free == -1)
			Free = Curr;
		if (pRecs[Curr] == Empty)
			return false;
		Curr = (Curr + HashStep) % MaxSize;
		eff++;
	}
	return false;
}

int TArrayHash::insRec(TRecord rec)
{
	if (isFull()) return TabNoMem;
	bool res = findRec(rec.key);
	if (res) return TabRecDbl;
	else {
		if (Free != -1) Curr = Free;
		pRecs[Curr] = rec;
		DataCount++;
	}
	return TabOK;
}

int TArrayHash::delRec(TKey key)
{
	bool res = findRec(key);
	if (!res) return TabNoRec;
	else {
		pRecs[Curr] = Del;
		DataCount--;
	}
	return TabOK;
}

void TArrayHash::fillTab(int size, int keyrange)
{
	if (size <= 0 || size > MaxSize) throw "Invalid value for the table size";
	srand(time(0));
	TRecord rec;
	int keyrand, valrand;
	DataCount = size;

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

void TArrayHash::printTab(std::string filename)
{
	std::ofstream file("saved-tables/" + filename + ".txt");
	file << "Table printing" << std::endl;
	for (reset(); !isTabEnd(); goNext())
	{
		file << "Key: " << getRec().key
			<< " Val: " << getRec().val << std::endl;
	}
	file.close();
}

void TArrayHash::clrTab()
{
    while (!isEmpty()) {
		delRec(getRec().key);
	}
}