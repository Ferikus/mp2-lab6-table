#pragma once
#include <iostream>
#include <string>

#define TabOK        0 // ошибок нет
#define TabEmpty  -101 // таблица пуста
#define TabFull   -102 // таблица полна
#define TabNoRec  -103 // нет записи
#define TabRecDbl -104 // дублирование записи
#define TabNoMem  -105 // нет памяти

#define TabMaxSize 25

typedef int TKey;
typedef std::string TValue;

struct TRecord
{
	TKey key;
	TValue val;

	TRecord() {}
	TRecord(TKey _key, TValue _val) {
		key = _key;
		val = _val;
	}
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
	int getEff()         { return eff; }
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
	virtual TKey getKey() const = 0;
	virtual TValue getValue() const = 0;

	friend std::ostream& operator<<(std::ostream& os, TTable& tab)
	{
		os << "Table printing" << std::endl;
		for (tab.reset(); !tab.isTabEnd(); tab.goNext())
		{
			os << "Key: " << tab.getKey()
				<< "Val: " << tab.getValue() << std::endl;
		}
		return os;
	}

	std::ostream& printTab(std::ostream& os, TTable& tab) // ПЕРЕДЕЛАТЬ ПОД СОХРАНЕНИЕ В ФАЙЛ
	{
		os << "Table printing" << std::endl;
		for (tab.reset(); !tab.isTabEnd(); tab.goNext())
		{
			os << "Key: " << tab.getKey()
				<< "Val: " << tab.getValue() << std::endl;
		}
		return os;
	}

};