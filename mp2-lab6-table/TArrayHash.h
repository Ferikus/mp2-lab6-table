#pragma once
#include "THashTable.h"

class TArrayHashTable : public THashTable
{
protected:
	TRecord* pRecs;
	int MaxSize,
		HashStep,
		Free,
		CurrPos;
	TRecord Del;
	TRecord Empty;
	int getNextPos(int pos);
};