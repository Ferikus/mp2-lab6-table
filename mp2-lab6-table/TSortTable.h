#pragma once
#include "TScanTable.h";

enum TSortType { select, merge, quick };

class TSortTable : public TScanTable {
protected:
	TRecord* pBuf; // ��������������� ����� ��� ����������
	void Sort(); // ������� ������ ������ �� ������� ����������
	void SelectSort();
	void MergeSort();
	void QSort(int l, int r); // ��������������� ������� ��� ������� ����������
	void QuickSort();
	TSortType SortType; // ��� ����������
public:
	TSortTable(int size);
	TSortTable(const TScanTable& st);

	bool findRec(TKey key);
	int insRec(TRecord rec);
	int delRec(TRecord rec);
};