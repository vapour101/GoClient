#ifndef COORDS_HXX
#define COORDS_HXX

#include <functional>

class Coords
{
public:
	Coords(int row, int column);
	Coords(const Coords& other);

	bool isAdjacentTo(const Coords& other) const;

	std::size_t hash() const;

	Coords& operator=(const Coords& other);

	friend bool operator==(const Coords& lhs, const Coords& rhs);

private:
	int row;
	int column;
};

bool operator==(const Coords& lhs, const Coords& rhs);
bool operator!=(const Coords& lhs, const Coords& rhs);

//Specialization of std::hash for Coords class
namespace std
{
	template<> struct hash<Coords>
	{
		std::size_t operator()(Coords const& coords) const
		{
			return coords.hash();
		}
	};
}

#endif // COORDS_HXX
