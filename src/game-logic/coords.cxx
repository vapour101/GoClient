#include "coords.hxx"
#include <cmath>
#include <stdexcept>

Coords::Coords(int x, int y):x{x}, y{y}
{
}

bool Coords::isAdjacentTo(const Coords& other) const
{
	int absoluteDifferenceX = std::abs(this->x - other.x);
	int absoluteDifferenceY = std::abs(this->y - other.y);

	bool xIsAdjacent = absoluteDifferenceX == 1;
	bool yIsAdjacent = absoluteDifferenceY == 1;

	bool exactlyOneIsAdjacent = xIsAdjacent != yIsAdjacent;

	return exactlyOneIsAdjacent;
}

int Coords::toIndexForBoardsize(const Coords& boardSize) const
{
	if (x > boardSize.x || y > boardSize.y || x < 1 || y < 1)
		throw std::domain_error("Coordinates out of range for boardsize.");

	return (x-1) * boardSize.x + (y-1);
}

int Coords::getLinearArraySize() const
{
	return (x * y);
}

bool operator==(const Coords& lhs, const Coords& rhs)
{
	return (lhs.x == rhs.x && lhs.y == rhs.y);
}



bool operator!=(const Coords& lhs, const Coords& rhs)
{
	return !(lhs == rhs);
}
