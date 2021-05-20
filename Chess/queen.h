#pragma once

#include "Figure.h"

class Queen : public Figure
{
private:
	bool in_range(std::vector<int>);
public:
	Queen(int, int, int);
	std::list<std::vector<int>> get_possible_positions();
};

