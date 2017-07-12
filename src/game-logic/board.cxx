#include "board.hxx"

namespace seki {

Board::Board(Coords boardSize)
{

}

void Board::playBlackMoveAt(const Coords& point)
{
	gamePosition.insert({point, BLACK});
}

std::vector<Coords> Board::getBlackVector() const
{
	std::vector<Coords> blackVector{};

	for (auto i : gamePosition)
	{
		if (i.second == BLACK)
			blackVector.push_back(i.first);
	}

	return blackVector;
}

}//namespace seki
