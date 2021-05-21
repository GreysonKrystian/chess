#include "Figure.h"


void Figure::change_pos(int x, int y)
{
	pos_x = x;
	pos_y = y;
}

std::vector<int, int> Figure::get_position()
{
	std::vector<int, int> my_vector = { pos_x, pos_y };
	return my_vector;
}