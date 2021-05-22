#pragma once

#include "Figure.h"

class Rook : public Figure
{
private:
	bool in_range(std::vector<int>);
	bool first_move;
public:
	Rook(int, int, int);
	virtual std::list<std::vector<int>> get_possible_positions();
	bool get_first_move();
};
