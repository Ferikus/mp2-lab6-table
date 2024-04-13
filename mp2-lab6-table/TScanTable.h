#pragma once
#include "TArrayTable.h";

class TScanTable : public TArrayTable
{
public:
	TScanTable(int MaxSize = TabMaxSize) : TArrayTable(MaxSize) {};
	virtual bool findRec(TKey key)
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
	virtual int insRec(TKey key, TValue val)
	{
		if (isFull()) {
			return TabNoMem;
		}
		pRecs[DataCount] = TRecord(key, val);
		DataCount++;
		eff++;
		return TabOK;
	}
	virtual int delRec(TKey key)
	{
		if (findRec(key) == false) return TabNoRec;
		DataCount--;
		pRecs[CurrPos] = pRecs[DataCount];
		eff++;
		return TabOK;
	}
};