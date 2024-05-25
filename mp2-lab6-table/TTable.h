#pragma once
#include <iostream>
#include <string>

#define TabOK        0 // ������ ���
#define TabEmpty  -101 // ������� �����
#define TabFull   -102 // ������� �����
#define TabNoRec  -103 // ��� ������
#define TabRecDbl -104 // ������������ ������
#define TabNoMem  -105 // ��� ������

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
	int DataCount; // ���-�� ������� � �������
	int eff; // ������� ������������� ���������� ��������
public:
	TTable() { DataCount = 0; eff = 0; }
	virtual ~TTable() {}

	// �������������� ������
	int getDataCount()   { return DataCount; }
	int getEff()         { return eff; }
	void clrEff()        { eff = 0; }
	bool isEmpty() const { return DataCount == 0; }
	virtual bool isFull() const = 0;

	// �������� ������
	virtual bool findRec(TKey key) = 0;
	virtual int insRec(TRecord rec) = 0;
	virtual int delRec(TKey key) = 0;

	// ���������
	virtual void reset() = 0;
	virtual bool isTabEnd() const = 0;
	virtual void goNext() = 0;

	// ������
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

	std::ostream& printTab(std::ostream& os, TTable& tab) // ���������� ��� ���������� � ����
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