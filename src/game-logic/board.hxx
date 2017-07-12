#ifndef BOARD_HXX
#define BOARD_HXX

#include <vector>
#include <unordered_map>

#include "coords.hxx"
#include "common/constants.hxx"

namespace seki {

class Board
{
public:
	Board(Coords boardSize);

	void playBlackMoveAt(const Coords& point);
	std::vector<Coords> getBlackVector() const;

private:
	std::unordered_map<Coords, Colour> gamePosition;
};

}

#endif // BOARD_HXX
