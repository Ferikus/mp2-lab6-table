#pragma once
#include "TTable.h"

class TArrayTable : public TTable
{
protected:
	TRecord* pRecs; // память для записей таблицы
	int MaxSize;	// максимальное возможное количество записей
	int CurrPos;	// номер текущей записи (нумерация от 0)
public:
	TArrayTable(int size = TabMaxSize)
	{
		pRecs = new TRecord[size];
		MaxSize = size;
		DataCount = 0;
		CurrPos = -1;
	}
	~TArrayTable() { delete[] pRecs; }

	// информационные методы
	virtual bool isFull() const { return DataCount >= MaxSize; }
	int getMaxSize() const		{ return MaxSize; }

	// доступ
	virtual TRecord& getRec() const
	{
		if (CurrPos < 0 || CurrPos >= MaxSize) throw "Index is out of range";
		return pRecs[CurrPos];
	}
	virtual void setRec(TRecord rec) {
		if (CurrPos < 0 || CurrPos >= MaxSize) throw "Index is out of range";
		pRecs[CurrPos] = rec;
		DataCount++;
	}
	virtual int getCurrPos() const	 { return CurrPos; };
	virtual void setCurrPos(int pos) { CurrPos = pos; };

	// значение
	virtual void reset()			 { CurrPos = 0; }
	virtual bool isTabEnd() const	 { return CurrPos >= DataCount; }
	virtual void goNext()			 { if (!isTabEnd()) CurrPos++; }

	// заполнение и печать
	virtual void fillTab(int size, int keyrange) = 0;
	virtual void printTab(std::string filename)
	{
		std::ofstream file("saved-tables/" + filename + ".txt");
		file << "Table printing" << std::endl;
		for (reset(); !isTabEnd(); goNext())
		{
			file << "Key: " << getRec().key
				<< " Val: " << getRec().val << std::endl;
		}
		file.close();
	}
	virtual void clrTab() = 0;
};