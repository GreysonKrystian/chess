#include "rook.h"

Rook::Rook(int color, int pos_x, int pos_y)
{
	this->color = color;
	this->pos_x = pos_x;
	this->pos_y = pos_y;
}

bool Rook::in_range()
{
	if (possible_pos[0] > 0 && possible_pos[1] > 0 && possible_pos[0] < 8 && possible[1] < 8)
		return true;
	else
		return false;
}

std::list<std::vector<int>> Rook::get_possible_positions()
{
	std::list<std::vector<int>> all_positions = {};
	for (int i{ 0 }; i < 8; i++)
	{
		std::vector<int> possible_pos = { pos_x + i, pos_y};
		if (in_range)
		{
			all_positions.push_back(possible_pos);
		}
		
		std::vector<int> possible_pos = { pos_x - i, pos_y };
		if (in_range)
		{
			all_positions.push_back(possible_pos);
		}
		
		std::vector<int> possible_pos = { pos_x, pos_y + i };
		if (in_range)
		{
			all_positions.push_back(possible_pos);
		}

		std::vector<int> possible_pos = { pos_x, pos_y + i };
		if (in_range)
		{
			all_positions.push_back(possible_pos);
		}
	}
	return all_positions;
}