#include <stdexcept>
#include "gtest/gtest.h"
#include "../src/game-logic/coords.hxx"


class CoordsTest : public ::testing::Test
{
public:
	CoordsTest()
	: c0{3, 3}, c1{4, 4}, c2{3, 3}, c3{3, 4}, c4{4, 3}, Square19{19, 19}
	{}

	Coords c0;
	Coords c1;
	Coords c2;
	Coords c3;
	Coords c4;

	Coords Square19;
};

TEST_F(CoordsTest, Equality)
{
	EXPECT_NE(c0, c1);
	EXPECT_EQ(c0, c2);
	EXPECT_NE(c0, c3);
	EXPECT_NE(c0, c4);
}

TEST_F(CoordsTest, Adjancency)
{
	EXPECT_TRUE(c0.isAdjacentTo(c3));
	EXPECT_TRUE(c0.isAdjacentTo(c4));
	EXPECT_FALSE(c0.isAdjacentTo(c2));
	EXPECT_FALSE(c0.isAdjacentTo(c0));
	EXPECT_FALSE(c0.isAdjacentTo(c1));
}

TEST_F(CoordsTest, LinearRepresentation)
{
	EXPECT_EQ(Coords(1,1).toIndexForBoardsize(Square19), 0);
	EXPECT_EQ(Coords(1,2).toIndexForBoardsize(Square19), 1);
	EXPECT_EQ(Coords(2,1).toIndexForBoardsize(Square19), 19);
	EXPECT_EQ(Coords(19,19).toIndexForBoardsize(Square19), 360);

	EXPECT_THROW(Coords(20,19).toIndexForBoardsize(Square19), std::domain_error);
	EXPECT_THROW(Coords(19,20).toIndexForBoardsize(Square19), std::domain_error);
	EXPECT_THROW(Coords(0,1).toIndexForBoardsize(Square19), std::domain_error);
	EXPECT_THROW(Coords(1,0).toIndexForBoardsize(Square19), std::domain_error);

	EXPECT_EQ(Square19.getLinearArraySize(), 361);
	EXPECT_EQ(Coords(1,1).getLinearArraySize(), 1);
	EXPECT_EQ(Coords(4,4).getLinearArraySize(), 16);
}
