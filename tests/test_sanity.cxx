#include "gtest/gtest.h"

TEST(SanityTests, ConstantsAreConstant)
{
	ASSERT_EQ(0, 0);
	ASSERT_EQ(1, 1);
	ASSERT_NE(1, 0);
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
