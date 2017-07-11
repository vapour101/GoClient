#include <stdexcept>
#include "gtest/gtest.h"
#include "../src/game-logic/coords.hxx"
#include <utility>

class CoordsTest : public ::testing::Test
{
public:
	CoordsTest() = default;

	Coords c0{3, 3};
	Coords c1{4, 4};
	Coords c2{3, 3};
	Coords c3{3, 4};
	Coords c4{4, 3};

	Coords Square19{19, 19};
};

TEST_F(CoordsTest, Equality)
{
	EXPECT_NE(c0, c1);
	EXPECT_EQ(c0, c2);
	EXPECT_NE(c0, c3);
	EXPECT_NE(c0, c4);
}

TEST_F(CoordsTest, Copying)
{
	Coords c5{c0};

	EXPECT_EQ(c0, c5);

	Coords c6 = c1;

	EXPECT_EQ(c1, c6);
}

TEST_F(CoordsTest, Assignment)
{
	ASSERT_EQ(c0, c2);

	c0 = c1;

	EXPECT_EQ(c0, c1);
	EXPECT_NE(c0, c2);
}

TEST_F(CoordsTest, Moving)
{
	Coords c5{3, 4};

	ASSERT_EQ(c5, c3);

	c0 = std::move(c5);

	EXPECT_EQ(c0, c3);
}

TEST_F(CoordsTest, Adjancency)
{
	EXPECT_TRUE(c0.isAdjacentTo(c3));
	EXPECT_TRUE(c0.isAdjacentTo(c4));
	EXPECT_FALSE(c0.isAdjacentTo(c2));
	EXPECT_FALSE(c0.isAdjacentTo(c0));
	EXPECT_FALSE(c0.isAdjacentTo(c1));
}

TEST_F(CoordsTest, Hashing)
{
	std::hash<Coords> coordHasher{};

	EXPECT_EQ(coordHasher(c0), coordHasher(c2));
	EXPECT_EQ(coordHasher(c4), coordHasher(c4));
	EXPECT_EQ(coordHasher(c3), coordHasher(c3));
}
