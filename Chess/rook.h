#pragma once

#include "Figure.h"

class Rook : public Figure
{
public:
	Rook(int color, int pos_x, int pos_y);
	std::list<std::vector<int>> get_possible_positions();
};
