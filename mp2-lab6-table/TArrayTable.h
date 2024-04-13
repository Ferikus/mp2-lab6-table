#pragma once
#include "TTable.h";
#include "TSortTable.h"

class TArrayTable : public TTable
{
protected:
	TRecord* pRecs; // ������ ��� ������� �������
	int MaxSize; // ������������ ��������� ���������� �������
	int CurrPos; // ����� ������� ������ (��������� �� 0)
public:
	TArrayTable(int size = TabMaxSize)
	{
		pRecs = new TRecord[size];
		MaxSize = size;
		DataCount = CurrPos = 0;
	}
	~TArrayTable()
	{
		delete[] pRecs;
	}

	// �������������� ������
	virtual bool isFull() const { return DataCount >= MaxSize; }
	int getMaxSize() const { return MaxSize; }

	// ������
	virtual TKey getKey() const
	{
		// ��������� ��������
		return pRecs[CurrPos].key;
	}
	virtual TValue getValue() const
	{
		// ��������� ��������
		return pRecs[CurrPos].val;
	}
	virtual void reset()
	{
		CurrPos = 0;
	}
	virtual bool isTabEnd() const
	{
		return CurrPos >= DataCount;
	}
	virtual void goNext()
	{
		if (!isTabEnd()) CurrPos++;
	}
	virtual int setCurrPos(int pos);
	int getCurrPos() const;
	friend TSortTable;
};