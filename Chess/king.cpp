
#include "king.h"

King::King(int my_color, int my_pos_x, int my_pos_y)
{
	color = my_color;
	pos_x = my_pos_x;
	pos_y = my_pos_y;
}

std::list<std::vector<int>> King::get_possible_positions()
{
	std::list<std::vector<int>>	all_points = get_all_positions();
	std::list<std::vector<int>> possible;

	for (auto itr = all_points.begin(); itr != all_points.end(); ++itr)
	{
		bool in_range = true;
		bool condition1 = ((*itr)[0] < 0 || (*itr)[0] > 7);
		bool condition2 = ((*itr)[1] < 0 || (*itr)[1] > 7);
		if (condition1 || condition2)
		{
			in_range = false;
		}
		
		if (in_range)
		{
			possible.push_back(*itr);
		}

	}
	return possible;
}


std::list<std::vector<int>> King::get_all_positions()
{
	std::list<std::vector<int>> all_positions = {};
	all_positions.push_back({ pos_x + 1, pos_y});
	all_positions.push_back({ pos_x + 1, pos_y + 1 });
	all_positions.push_back({ pos_x + 1, pos_y - 1 });
	all_positions.push_back({ pos_x - 1, pos_y});
	all_positions.push_back({ pos_x - 1, pos_y + 1 });
	all_positions.push_back({ pos_x - 1, pos_y - 1 });
	all_positions.push_back({ pos_x, pos_y - 1 });
	all_positions.push_back({ pos_x, pos_y + 1 });
	
	return all_positions;
}