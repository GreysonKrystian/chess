#include "Figure.h"


void Figure::change_pos(int x, int y)
{
	pos_x = x;
	pos_y = y;
	first_move = false;
}

std::vector<int> Figure::get_position()
{
	std::vector<int> my_vector = { pos_x, pos_y };
	return my_vector;
}

int Figure::get_color()
{
	return color;
}

std::string Figure::get_type()
{
	return type;
}

void Figure::change_first_move_status()
{
	first_move = false;
}

bool Figure::get_first_move()
{
	return first_move;
}
