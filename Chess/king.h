#pragma once
#include "Figure.h"
#include "../Board/Board.h"

class King : public Figure
{
private:
	std::list<std::vector<int>> get_all_positions();
	bool first_move;

public:
	King(int, int, int);
	std::list<std::vector<int>> get_possible_positions();
};
