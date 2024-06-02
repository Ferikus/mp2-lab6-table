#pragma once
#include "TTable.h"

class THashTable : public TTable
{
protected:
	int MaxSize; // ������������ ���������� �������
public:
	virtual unsigned int HashFunc(const TKey key) { return key % MaxSize; }

	// ���������� � ������
	virtual void fillTab(int size) = 0;
	virtual void printTab(std::string filename) = 0;
};

