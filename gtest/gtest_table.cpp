#include "gtest/gtest.h"
#include "../mp2-lab6-table/TTable.h"

/* -------------------------- реярш дкъ TList -------------------------- */

TEST(List, CAN_CREATE_LIST)
{
	EXPECT_NO_THROW(TList<int> l);
}