#pragma once
#include "TScanTable.h"

// упорядоченная таблица на массиве

enum TSortType { select, merge, quick };

class TSortTable : public TScanTable
{
protected:
	TRecord* pBuf; // вспомогательный буфер для сортировки
	void Sort(); // функция вызова одного из методов сортировки
	void SelectSort();
	void Merge(int left, int mid, int right); // вспомогательная функция для сортировки слиянием
	void MergeSort(int left, int right);
	void QSort(int l, int r); // вспомогательная функция для быстрой сортировки
	void QuickSort();
	TSortType SortType; // тип сортировки
public:
	TSortTable(int MaxSize = TabMaxSize, TSortType stype = quick);
	TSortTable(const TScanTable& st, TSortType stype);

	bool findRec(TKey key);
	int insRec(TRecord rec);
	int delRec(TKey key);

	virtual void fillTab(int size);
};



void TSortTable::Sort()
{
	if (SortType == select) SelectSort();
	else if (SortType == merge) MergeSort(0, DataCount - 1);
	else if (SortType == quick) QuickSort();
}

void TSortTable::SelectSort()
{
	int i, j, mini, tmp;
	for (i = 0; i < DataCount; i++)
	{
		int min = pRecs[i].key, mini = i;
		for (j = i; j < DataCount; j++) {
			if (min > pRecs[j].key) {
				mini = j;
				min = pRecs[j].key;
			}
		}
		tmp = pRecs[mini].key;
		pRecs[mini].key = pRecs[i].key;
		pRecs[i].key = tmp;
	}
}

void TSortTable::Merge(int left, int mid, int right)
{
	int i = left, j = mid + 1; // индексы для прохождения по массиву
	int k = left; // индекс для прохода по буферу
	while (i <= mid && j <= right)
	{
		if (pRecs[i].key < pRecs[j].key)
		{
			pBuf[k] = pRecs[i];
			i++;
		}
		else {
			pBuf[k] = pRecs[j];
			j++;
		}
		k++;
	}
	if (i > mid) {
		while (j <= right) {
			pBuf[k] = pRecs[j];
			j++; k++;
		}
	}
	else {
		while (i <= mid) {
			pBuf[k] = pRecs[i];
			i++; k++;
		}
	}
	k = 0;
	for (i = left; i <= right; i++) {
		pRecs[i] = pBuf[i];
		k++;
	}
}

void TSortTable::MergeSort(int left, int right)
{
	if (left == right) return;
	int mid = (right + left) / 2;
	MergeSort(left, mid);
	MergeSort(mid + 1, right);
	Merge(left, mid, right);
}

void TSortTable::QSort(int l, int r) // вспомогательная функция для быстрой сортировки
{
	int m = (l + r) / 2;
	TKey mkey = pRecs[m].key;
	int i = l, j = r;
	while (i < j) {
		while (pRecs[i].key < mkey) i++;
		while (pRecs[j].key > mkey) j--;
		if (i <= j) {
			std::swap(pRecs[i], pRecs[j]);
			i++; j--;
		}
	}
	if (j > l) QSort(l, j);
	if (i < r) QSort(i, r);
}

void TSortTable::QuickSort() { QSort(0, DataCount - 1); }

TSortTable::TSortTable(int MaxSize, TSortType stype) : TScanTable(MaxSize)
{
	pBuf = new TRecord[MaxSize];
	SortType = stype;
}

TSortTable::TSortTable(const TScanTable& st, TSortType stype)
{
	pBuf = new TRecord[MaxSize];
	for (reset(); isTabEnd(); goNext()) {
		getRec() = st.getRec();
	}
	SortType = stype;
	Sort();
}

bool TSortTable::findRec(TKey key)
{
	int l = 0, r = DataCount - 1;
	while (l <= r) {
		int m = (l + r) / 2;
		if (key == pRecs[m].key) {
			CurrPos = m;
			return true;
		}
		else if (key > pRecs[m].key) {
			l = m + 1;
		}
		else { r = m - 1; }
	}
	CurrPos = l;
	return false;
}

int TSortTable::insRec(TRecord rec)
{
	if (isFull()) return TabNoMem;
	bool res = findRec(rec.key);
	if (res) return TabRecDbl;
	// перепаковать - сдвинуть все элементы начиная с Curr вправо на 1
	for (int i = DataCount; i > CurrPos; i--)
		pRecs[i] = pRecs[i - 1];
	pRecs[CurrPos] = rec;
	DataCount++; eff++;
	return TabOK;
}

int TSortTable::delRec(TKey key)
{
	bool res = findRec(key);
	if (res == false) return TabNoRec;
	// перепаковать - сместить все элементы начиная с Curr+1 влево на 1
	for (int i = CurrPos; i < DataCount - 1; i++)
		pRecs[i] = pRecs[i + 1];
	DataCount--; eff++;
	return TabOK;
}

void TSortTable::fillTab(int size)
{
	if (size <= 0 || size > MaxSize) throw "Invalid value for the table size";
	srand(time(0));
	DataCount = size;
	for (int i = 0; i < size; i++) {
		pRecs[i] = TRecord(rand() % 100, rand() % (-1999) - 1000);
	}
	Sort();
}