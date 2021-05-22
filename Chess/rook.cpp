#include "rook.h"

Rook::Rook(int my_color, int my_pos_x, int my_pos_y)
{
	color = my_color;
	pos_y = my_pos_y;
	pos_x = my_pos_x;
	type = "R";
}

bool Rook::in_range(std::vector<int> possible_pos)
{
	if (possible_pos[0] >= 0 && possible_pos[1] >= 0 && possible_pos[0] < 8 && possible_pos[1] < 8)
		return true;
	else
		return false;
}



std::list<std::vector<int>> Rook::get_possible_positions()
{
	std::list<std::vector<int>> all_positions = {};
	for (int i = 1; i <= 8; i++)
	{
		std::vector<int> possible_pos = { pos_x + i, pos_y };
		if (in_range(possible_pos))
		{
			all_positions.push_back(possible_pos);
		}

		possible_pos = { pos_x - i, pos_y };
		if (in_range(possible_pos))
		{
			all_positions.push_back(possible_pos);
		}

		possible_pos = { pos_x, pos_y + i };
		if (in_range(possible_pos))
		{
			all_positions.push_back(possible_pos);
		}

		possible_pos = { pos_x, pos_y - i };
		if (in_range(possible_pos))
		{
			all_positions.push_back(possible_pos);
		}
	}
	return all_positions;
}