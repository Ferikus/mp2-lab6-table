#pragma once
#include "TArrayTable.h"

// неупорядоченная таблица на массиве

class TScanTable : public TArrayTable
{
public:
	TScanTable(int MaxSize = TabMaxSize) : TArrayTable(MaxSize) {};

	virtual bool findRec(TKey key);
	virtual int insRec(TRecord rec);
	virtual int delRec(TKey key);

	virtual void fillTab(int size, int keyrange);
	virtual void clrTab();
};



bool TScanTable::findRec(TKey key)
{
	int i;
	for (i = 0; i < DataCount; i++) {
		eff++;
		if (pRecs[i].key == key) break;
	}
	CurrPos = i;
	if (i < DataCount) return true;
	return false;
}

int TScanTable::insRec(TRecord rec)
{
	if (isFull()) return TabNoMem;
	if (findRec(rec.key)) return TabRecDbl;
	pRecs[DataCount] = rec;
	DataCount++; eff++;
	return TabOK;
}

int TScanTable::delRec(TKey key)
{
	if (!findRec(key)) return TabNoRec;
	pRecs[CurrPos] = pRecs[DataCount];
	DataCount--; eff++;
	return TabOK;
}

void TScanTable::fillTab(int size, int keyrange)
{
	if (size <= 0 || size > MaxSize) throw "Invalid value for the table size";
	srand(time(0));
	TRecord rec;
	int keyrand, valrand;

	// Массив для хранения уже сгенерированных ключей
	std::vector<bool> usedKeys(keyrange, false);

	for (int i = 0; i < size; i++) {
		do {
			keyrand = rand() % keyrange;
		} while (usedKeys[keyrand]); // Генерируем новый ключ, пока он не будет уникальным

		usedKeys[keyrand] = true; // Отмечаем ключ как использованный

		valrand = rand() % (-1999) - 1000; // rand() % (end - start + 1) + start;
		rec = TRecord(keyrand, valrand);
		insRec(rec);
	}
}

void TScanTable::clrTab()
{
	while (!isEmpty()) {
		CurrPos = 0;
		delRec(getRec().key);
	}
}