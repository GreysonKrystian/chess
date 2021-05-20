#pragma once
#include "Figure.h"

class Pawn : public Figure
{
private:
	bool first_move;
public:
	Pawn(int, int, int);
	std::list<std::vector<int>> get_possible_positions();
	std::list<std::vector<int>> get_strike_positions();
};
