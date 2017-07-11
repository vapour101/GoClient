#ifndef COORDS_HXX
#define COORDS_HXX

class Coords
{
public:
	Coords(int x, int y);

	bool isAdjacentTo(const Coords& other) const;

	int toIndexForBoardsize(const Coords& boardSize) const;
	int getLinearArraySize() const;

	friend bool operator==(const Coords& lhs, const Coords& rhs);

private:
	int x;
	int y;
};

bool operator==(const Coords& lhs, const Coords& rhs);
bool operator!=(const Coords& lhs, const Coords& rhs);

#endif // COORDS_HXX
