#pragma once
#include <iostream>

#define TabOK        0 // ������ ���
#define TabEmpty  -101 // ������� �����
#define TabFull   -102 // ������� �����
#define TabNoRec  -103 // ��� ������
#define TabRecDbl -104 // ������������ ������
#define TabNoMem  -105 // ��� ������

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
	int DataCount; // ���-�� ������� � �������
	int eff; // ������� ������������� ���������� ��������
public:
	TTable(); // �������� ����
	virtual ~TTable() {};

	// �������������� ������
	int getDataCount();
	int getEff();
	void clrEff();
	bool isEmpty();
	virtual bool isFull();

	// �������� ������
	virtual bool findRecord();
	virtual int insRecord();
	virtual int delRecord();

	// ���������
	virtual int reset();
	virtual int isEnd();
	virtual int goNext();

	// ������
	virtual TKey getKey();
	virtual TValue getValue();

	friend std::ostream& operator<<(std::ostream& os, TTable& tab);
};