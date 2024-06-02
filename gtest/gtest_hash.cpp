#include "gtest/gtest.h"
#include "../mp2-lab6-table/TArrayHash.h"
#include "../mp2-lab6-table/TListHash.h"

/* -------------------------- “≈—“€ ƒÀﬂ TArrayHash (’›ÿ-“¿¡À»÷€ Õ¿ Ã¿——»¬≈) -------------------------- */

TEST(ArrayHash, CAN_CREATE_TABLE)
{
	EXPECT_NO_THROW(TArrayHash tab);
}

TEST(ArrayHash, FULL_TABLE_IS_FULL)
{
	TArrayHash tab(3);
	EXPECT_FALSE(tab.isFull());
	tab.fillTab(3);
	EXPECT_TRUE(tab.isFull());
}

TEST(ArrayHash, CAN_FIND_INSERT_REC)
{
	TArrayHash tab(3);
	EXPECT_EQ(tab.insRec(TRecord(1, 5)), TabOK);
	EXPECT_EQ(tab.insRec(TRecord(3, 15)), TabOK);
	EXPECT_EQ(tab.insRec(TRecord(2, 10)), TabOK);
	EXPECT_TRUE(tab.findRec(2));
	TRecord rec1 = tab.getRec(),
			rec2(2, 10);
	EXPECT_EQ(rec1, rec2);
	EXPECT_EQ(tab.insRec(TRecord(2, 10)), TabNoMem);
}

TEST(ArrayHash, CAN_DEL_REC)
{
	TArrayHash tab(3);
	tab.insRec(TRecord(1, 5));
	EXPECT_EQ(tab.delRec(1), TabOK);
	EXPECT_EQ(tab.delRec(1), TabNoRec);
}

TEST(ArrayHash, CHECK_PRINTED_TAB)
{
	TArrayHash tab;
	tab.fillTab(10);
	EXPECT_NO_THROW(tab.printTab("arrayhashtable"));
}

/* -------------------------- “≈—“€ ƒÀﬂ TListHash (’›ÿ-“¿¡À»÷€ Õ¿ —œ»— ¿’) -------------------------- */

TEST(ListHash, CAN_CREATE_TABLE)
{
	EXPECT_NO_THROW(TListHash tab(3));
}

TEST(ListHash, CAN_FIND_INSERT_REC)
{
	TListHash tab(3);
	EXPECT_EQ(tab.insRec(TRecord(1, 5)), TabOK);
	EXPECT_EQ(tab.insRec(TRecord(3, 15)), TabOK);
	EXPECT_EQ(tab.insRec(TRecord(2, 10)), TabOK);
	EXPECT_TRUE(tab.findRec(2));
	TRecord rec1 = tab.getRec(),
		rec2(2, 10);
	EXPECT_EQ(rec1, rec2);
	EXPECT_EQ(tab.insRec(TRecord(2, 10)), TabRecDbl);
}

TEST(ListHash, CAN_DEL_REC)
{
	TListHash tab(3);
	tab.insRec(TRecord(1, 5));
	EXPECT_EQ(tab.delRec(1), TabOK);
	EXPECT_EQ(tab.delRec(1), TabNoRec);
}

TEST(ListHash, CHECK_PRINTED_TAB)
{
	TListHash tab(5);
	tab.fillTab(10);
	EXPECT_NO_THROW(tab.printTab("listhashtable"));
}