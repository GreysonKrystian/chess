#pragma once

#include <list>
#include <vector>

class Figure
{
protected:
	int color; //0 czarny, 1 bialy (biale od dolu)
	int pos_x;
	int pos_y;
public:

	virtual std::list<std::vector<int>> get_possible_positions() = 0;

};