#pragma once

#include <list>
#include <vector>

class Figure
{
protected:
	int color;
	int pos_x;
	int pos_y;
public:

	virtual std::list<std::vector<int>>  get_possible_positions() = 0;

};