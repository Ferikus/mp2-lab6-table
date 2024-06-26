#include "gtest/gtest.h"
#include "../mp2-lab6-table/TAVLTree.h"

/* -------------------------- ����� ��� TTreeTable (�������) -------------------------- */

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
	tab.fillTab(200, 1000);
	EXPECT_NO_THROW(tab.printTab("treetable"));
}

TEST(TreeTable, CLEAR_TAB_IS_COREECT)
{
	TTreeTable tab;
	tab.fillTab(3, 100);
	EXPECT_NO_THROW(tab.clrTab());
	EXPECT_TRUE(tab.isEmpty());
	EXPECT_NO_THROW(tab.printTab("treetable_CLEAR"));
}

/* -------------------------- ����� ��� TAVLTree (AVL-���������������� �������) -------------------------- */

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
	tab.fillTab(50, 50);
	EXPECT_NO_THROW(tab.printTab("avltreetable"));
}

TEST(AVLTree, CLEAR_TAB_IS_COREECT)
{
	TAVLTree tab;
	tab.fillTab(3, 100);
	EXPECT_NO_THROW(tab.clrTab());
	EXPECT_TRUE(tab.isEmpty());
	EXPECT_NO_THROW(tab.printTab("avltable_CLEAR"));
}