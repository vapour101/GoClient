#include "coords.hxx"
#include <cmath>
#include <stdexcept>

Coords::Coords(int row, int column):row{row}, column{column}
{
}

bool Coords::isAdjacentTo(const Coords& other) const
{
	int absoluteDifferenceRow = std::abs(this->row - other.row);
	int absoluteDifferenceColumn = std::abs(this->column - other.column);

	bool rowIsAdjacent = absoluteDifferenceRow == 1;
	bool columnIsAdjacent = absoluteDifferenceColumn == 1;

	bool exactlyOneIsAdjacent = rowIsAdjacent != columnIsAdjacent;

	return exactlyOneIsAdjacent;
}

std::size_t Coords::hash() const
{
	std::size_t const h1 ( std::hash<int>{}(row) );
	std::size_t const h2 ( std::hash<int>{}(column) );
	return h1 ^ (h2 << 1); //Combine hashes
}

bool operator==(const Coords& lhs, const Coords& rhs)
{
	return (lhs.row == rhs.row && lhs.column == rhs.column);
}

bool operator!=(const Coords& lhs, const Coords& rhs)
{
	return !(lhs == rhs);
}
