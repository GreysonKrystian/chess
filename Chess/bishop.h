#pragma once
#import "Figure.h"

class Bishop: public Figure
{
public:
	Bishop(int color, int pos_x, int pos_y);
	virtual std::list<std::vector<int>>  get_possible_positions();
}