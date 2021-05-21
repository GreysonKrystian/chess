#include "Figure.h"
#include "../Board/Board.h"
#include <list>
#include <vector>

class Knight : public Figure
{
private:
	std::list<std::vector<int>> get_all_positions();
	std::list<std::vector<int>> get_positions_in_board();

public:

	Knight(int, int, int);
	std::list<std::vector<int>> get_possible_positions();
};
