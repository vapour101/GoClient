#include "gtest/gtest.h"
#include "../src/game-logic/coords.hxx"
#include "../src/game-logic/board.hxx"

#include <vector>

class BoardTest : public ::testing::Test
{
public:
	BoardTest() = default;

	Board testBoard{Coords{19,19}};

	Coords c0{3, 3};
	Coords c1{4, 4};
	Coords c2{3, 4};
	Coords c3{4, 3};
};

TEST_F(BoardTest, AddingMoves)
{
	ASSERT_EQ(testBoard.getBlackVector().size(), 0) << "New board is not empty.";

	testBoard.playBlackMoveAt(c0);

	EXPECT_EQ(testBoard.getBlackVector().size(), 1);
}
