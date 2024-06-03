#include "gtest/gtest.h"
#include "../mp2-lab6-table/TAVLTree.h"

/* -------------------------- реярш дкъ TTreeTable (депебэъ) -------------------------- */

TEST(TreeTable, CAN_CREATE_TABLE)
{
	EXPECT_NO_THROW(TTreeTable tab);
}


TEST(TreeTable, CAN_FIND_INSERT_REC)
{
	TTreeTable tab;
	EXPECT_EQ(tab.insRec(TRecord(1, 5)), TabOK);
	EXPECT_FALSE(tab.findRec(2));
	EXPECT_EQ(tab.insRec(TRecord(2, 10)), TabOK);
	EXPECT_TRUE(tab.findRec(2));
	EXPECT_EQ(tab.insRec(TRecord(2, 10)), TabRecDbl);
}

TEST(TreeTable, CAN_DEL_REC)
{
	TTreeTable tab;
	tab.insRec(TRecord(1, 5));
	EXPECT_EQ(tab.delRec(1), TabOK);
	EXPECT_EQ(tab.delRec(1), TabNoRec);
}

TEST(TreeTable, CHECK_PRINTED_TAB)
{
	TTreeTable tab;
	tab.fillTab(20);
	EXPECT_NO_THROW(tab.printTab("treetable"));
}


/* -------------------------- реярш дкъ TAVLTree (AVL-яаюкюмяхпнбюммше депебэъ) -------------------------- */

TEST(AVLTree, CAN_CREATE_TABLE)
{
	EXPECT_NO_THROW(TAVLTree tab);
}


TEST(AVLTree, CAN_FIND_INSERT_REC)
{
	TAVLTree tab;
	EXPECT_EQ(tab.insRec(TRecord(1, 5)), TabOK);
	EXPECT_FALSE(tab.findRec(2));
	EXPECT_EQ(tab.insRec(TRecord(2, 10)), TabOK);
	EXPECT_TRUE(tab.findRec(2));
	EXPECT_EQ(tab.insRec(TRecord(2, 10)), TabRecDbl);
}

TEST(AVLTree, CAN_DEL_REC)
{
	TAVLTree tab;
	tab.insRec(TRecord(1, 5));
	EXPECT_EQ(tab.delRec(1), TabOK);
	EXPECT_EQ(tab.delRec(1), TabNoRec);
}

TEST(AVLTree, CHECK_PRINTED_TAB)
{
	TAVLTree tab;
	tab.fillTab(10);
	EXPECT_NO_THROW(tab.printTab("avltreetable"));
}