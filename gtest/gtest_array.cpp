#include "gtest/gtest.h"
#include "../mp2-lab6-table/TSortTable.h"

/* -------------------------- “≈—“€ ƒÀﬂ TScanTable (Õ≈”œŒ–ﬂƒŒ◊≈ÕÕ€≈ “¿¡À»÷€) -------------------------- */

TEST(ScanTable, CAN_CREATE_TABLE)
{
	EXPECT_NO_THROW(TScanTable tab);
}

TEST(ScanTable, CAN_SET_GET_CURRENT_REC)
{
	TScanTable tab;
	EXPECT_ANY_THROW(tab.getRec());

	TRecord rec1(1, 3), rec2;
	EXPECT_NO_THROW(tab.setCurrPos(0));
	EXPECT_NO_THROW(tab.setRec(rec1));
	rec2 = tab.getRec();
	
	EXPECT_EQ(rec1, rec2);
}

TEST(ScanTable, FULL_TABLE_IS_FULL)
{
	TScanTable tab(3);
	EXPECT_FALSE(tab.isFull());
	tab.fillTab(3, 100);
	EXPECT_TRUE(tab.isFull());
}

TEST(ScanTable, CAN_FIND_REC)
{
	TScanTable tab(3);
	tab.setCurrPos(0);  tab.setRec(TRecord(1, 5));
	tab.setCurrPos(1);  tab.setRec(TRecord(3, 10));
	tab.setCurrPos(2);  tab.setRec(TRecord(2, 15));
	EXPECT_TRUE(tab.findRec(2));
	EXPECT_FALSE(tab.findRec(4));
}

TEST(ScanTable, CAN_INSERT_REC)
{
	TScanTable tab(3);
	tab.setCurrPos(0);  tab.setRec(TRecord(1, 5));
	tab.setCurrPos(1);  tab.setRec(TRecord(3, 15));
	EXPECT_EQ(tab.insRec(TRecord(2, 10)), TabOK);
	tab.setCurrPos(2);
	TRecord rec1 = tab.getRec(),
			rec2(2, 10);
	EXPECT_EQ(rec1, rec2);
	EXPECT_EQ(tab.insRec(TRecord(2, 10)), TabNoMem);
}

TEST(ScanTable, CAN_DEL_REC)
{
	TScanTable tab(3);
	tab.setCurrPos(0);  tab.setRec(TRecord(1, 5));
	EXPECT_EQ(tab.delRec(1), TabOK);
	EXPECT_EQ(tab.delRec(1), TabNoRec);
}

TEST(ScanTable, CHECK_PRINTED_TAB)
{
	TScanTable tab;
	tab.fillTab(3, 100);
	EXPECT_NO_THROW(tab.printTab("scantable"));
}

/* -------------------------- “≈—“€ ƒÀﬂ TSortTable (”œŒ–ﬂƒŒ◊≈ÕÕ€≈ “¿¡À»÷€) -------------------------- */

TEST(SortTable, CAN_CREATE_TABLE)
{
	EXPECT_NO_THROW(TSortTable tab);
}

TEST(SortTable, QUICK_SORT_IS_CORRECT)
{
	TSortTable tab(10, quick);
	tab.fillTab(3, 100);
	TRecord prevrec;
	tab.reset();
	prevrec = tab.getRec();
	for (tab.goNext(); !tab.isTabEnd(); tab.goNext()) {
		EXPECT_TRUE(prevrec.key < tab.getRec().key);
	}
}

TEST(SortTable, SELECT_SORT_IS_CORRECT)
{
	TSortTable tab(10, select);
	tab.fillTab(3, 100);
	TRecord prevrec;
	tab.reset();
	prevrec = tab.getRec();
	for (tab.goNext(); !tab.isTabEnd(); tab.goNext()) {
		EXPECT_TRUE(prevrec.key < tab.getRec().key);
	}
}

TEST(SortTable, MERGE_SORT_IS_CORRECT)
{
	TSortTable tab(10, merge);
	tab.fillTab(3, 100);
	TRecord prevrec;
	tab.reset();
	prevrec = tab.getRec();
	for (tab.goNext(); !tab.isTabEnd(); tab.goNext()) {
		EXPECT_TRUE(prevrec.key < tab.getRec().key);
	}
}

TEST(SortTable, CAN_FIND_REC)
{
	TSortTable tab(3, quick);
	tab.setCurrPos(0);  tab.setRec(TRecord(1, 5));
	tab.setCurrPos(1);  tab.setRec(TRecord(2, 10));
	tab.setCurrPos(2);  tab.setRec(TRecord(3, 15));
	EXPECT_TRUE(tab.findRec(2));
	EXPECT_FALSE(tab.findRec(4));
}

TEST(SortTable, CAN_INSERT_REC)
{
	TSortTable tab(3);
	tab.setCurrPos(0);  tab.setRec(TRecord(1, 5));
	tab.setCurrPos(1);  tab.setRec(TRecord(3, 15));
	EXPECT_EQ(tab.insRec(TRecord(2, 10)), TabOK);
	tab.setCurrPos(1);
	TRecord rec1 = tab.getRec(),
		rec2(2, 10);
	EXPECT_EQ(rec1, rec2);
	EXPECT_EQ(tab.insRec(TRecord(2, 10)), TabNoMem);
}

TEST(SortTable, CAN_DEL_REC)
{
	TSortTable tab(3);
	tab.insRec(TRecord(1, 5));
	tab.insRec(TRecord(2, 10));
	tab.insRec(TRecord(3, 15));
	EXPECT_EQ(tab.delRec(2), TabOK);
	tab.setCurrPos(1);
	EXPECT_EQ(tab.getRec(), TRecord(3, 15));
	EXPECT_EQ(tab.delRec(2), TabNoRec);
}

TEST(SortTable, CHECK_PRINTED_TAB)
{
	TSortTable tab_quick(10, quick);
	tab_quick.fillTab(3, 100);
	EXPECT_NO_THROW(tab_quick.printTab("sorttable_quick"));

	TSortTable tab_select(10, select);
	tab_select.fillTab(3, 100);
	EXPECT_NO_THROW(tab_select.printTab("sorttable_select"));

	TSortTable tab_merge(10, merge);
	tab_merge.fillTab(3, 100);
	EXPECT_NO_THROW(tab_merge.printTab("sorttable_merge"));
}