#include "TSortTable.h";

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

TSortTable::TSortTable(int size) : TScanTable(size)
{
	pBuf = new TRecord[MaxSize];
}

TSortTable::TSortTable(const TScanTable& st)
{
	// переписать все данные
	Sort();
}