#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <ctime>
#include <fstream>

#define TabOK        0 // ������ ���
#define TabEmpty  -101 // ������� �����
#define TabFull   -102 // ������� �����
#define TabNoRec  -103 // ��� ������
#define TabRecDbl -104 // ������������ ������
#define TabNoMem  -105 // ��� ������

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
	int DataCount; // ���-�� ������� � �������
	int eff; // ������� ������������� ���������� ��������
public:
	TTable() { DataCount = 0; eff = 0; }
	virtual ~TTable() {}

	// �������������� ������
	int getDataCount()   { return DataCount; }
	int getEff()		 { return eff; }
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
	virtual TRecord& getRec() const = 0;

	// ��������� ������
	virtual void fillTab(int size, int keyrange) = 0;
	virtual void printTab(std::string filename) = 0;
	virtual void clrTab() = 0;
};