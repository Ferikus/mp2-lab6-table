#pragma once
#include "TScanTable.h";

enum TSortType { select, merge, quick };

class TSortTable : public TScanTable {
protected:
	TRecord* Buf; // вспомогательный буфер для сортировки
	void Sort(); // функция вызова одного из методов сортировки
	void selectSort();
	void MergeSort();
	void QSort(int l, int r); // вспомогательная функция для быстрой сортировки
	void QuickSort();
	TSortType SortType; // тип сортировки
public:
	TSortTable(int size);
	TSortTable(const TScanTable& st);

	bool findRec(TKey key);
	int insRec(TRecord rec);
	int delRec(TRecord rec);
};