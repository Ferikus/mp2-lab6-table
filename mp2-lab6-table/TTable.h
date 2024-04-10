#pragma once
#include <iostream>

#define TabOK        0 // ошибок нет
#define TabEmpty  -101 // таблица пуста
#define TabFull   -102 // таблица полна
#define TabNoRec  -103 // нет записи
#define TabRecDbl -104 // дублирование записи
#define TabNoMem  -105 // нет памяти

#define TabMaxSize 25

template <class TKey, class TValue>
struct TRecord
{
	TKey key;
	TValue value;
};

template <class TKey, class TValue>
class TTable
{
protected:
	int DataCount; // кол-во записей в таблице
	int eff; // подсчёт эффективности выполнения операций
public:
	TTable(); // занулить поля
	virtual ~TTable() {};

	// информационные методы
	int getDataCount();
	int getEff();
	void clrEff();
	bool isEmpty();
	virtual bool isFull();

	// основные методы
	virtual bool findRecord();
	virtual int insRecord();
	virtual int delRecord();

	// навигация
	virtual int reset();
	virtual int isEnd();
	virtual int goNext();

	// доступ
	virtual TKey getKey();
	virtual TValue getValue();

	friend std::ostream& operator<<(std::ostream& os, TTable& tab);
};