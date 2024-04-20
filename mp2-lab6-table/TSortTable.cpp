#include "TSortTable.h";

void TSortTable::Sort()
{
	if (SortType == select) SelectSort();
	else if (SortType == merge) MergeSort();
	else if (SortType == quick) QuickSort();
}

void TSortTable::SelectSort()
{

}

void TSortTable::MergeSort()
{

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

TSortTable::TSortTable(int size) : TScanTable(size)
{
	pBuf = new TRecord[MaxSize];
	SortType = quick;
}

TSortTable::TSortTable(const TScanTable& st)
{
	// переписать все данные
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
	bool res = findRec(rec.key);
	if (!res) {
		// сдвинуть на 1 от Curr
		pRecs[CurrPos] = rec;
		DataCount++;
	}
}

int TSortTable::delRec(TRecord rec)
{

}