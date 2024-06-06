#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <ctime>
#include <fstream>

#define TabOK        0 // ошибок нет
#define TabEmpty  -101 // таблица пуста
#define TabFull   -102 // таблица полна
#define TabNoRec  -103 // нет записи
#define TabRecDbl -104 // дублирование записи
#define TabNoMem  -105 // нет памяти

#define TabMaxSize 5000

typedef int TKey;
typedef int TValue;

struct TRecord
{
	TKey key;
	TValue val;

	TRecord() {}
	TRecord(TKey _key, TValue _val) {
		key = _key;
		val = _val;
	}

	bool operator== (const TRecord& rec) const { return (key == rec.key && val == rec.val); }
	bool operator!= (const TRecord& rec) const { return !(*this == rec); }
};

class TTable
{
protected:
	int DataCount; // кол-во записей в таблице
	int eff; // подсчёт эффективности выполнения операций
public:
	TTable() { DataCount = 0; eff = 0; }
	virtual ~TTable() {}

	// информационные методы
	int getDataCount()   { return DataCount; }
	int getEff()		 { return eff; }
	void clrEff()        { eff = 0; }
	bool isEmpty() const { return DataCount == 0; }
	virtual bool isFull() const = 0;

	// основные методы
	virtual bool findRec(TKey key) = 0;
	virtual int insRec(TRecord rec) = 0;
	virtual int delRec(TKey key) = 0;

	// навигация
	virtual void reset() = 0;
	virtual bool isTabEnd() const = 0;
	virtual void goNext() = 0;

	// доступ
	virtual TRecord& getRec() const = 0;

	// служебные методы
	virtual void fillTab(int size, int keyrange) = 0;
	virtual void printTab(std::string filename) = 0;
	virtual void clrTab() = 0;
};