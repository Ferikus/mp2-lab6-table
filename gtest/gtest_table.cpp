#include "gtest/gtest.h"
#include "../mp2-lab6-table/TTable.h"

/* -------------------------- ����� ��� TList -------------------------- */

TEST(List, CAN_CREATE_LIST)
{
	EXPECT_NO_THROW(TList<int> l);
}