#include "Knight.h"


Knight::Knight(int my_color, int my_pos_x, int my_pos_y)
{
	color = my_color;
	pos_y = my_pos_y;
	pos_x = my_pos_x;
}


std::list<std::vector<int>> Knight::get_possible_positions()
{
	std::list<std::vector<int>>	all_points = get_all_positions();
	std::list<std::vector<int>> possible;

	for (auto itr = all_points.begin(); itr != all_points.end(); ++itr)
	{
		bool in_range = true;
		bool condition1 = ((*itr)[0] < 1 || (*itr)[0] > 8);
		bool condition2 = ((*itr)[1] < 1 || (*itr)[1] > 8);
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


std::list<std::vector<int>> Knight::get_all_positions()
{
		
	std::list<std::vector<int>> positions;

	std::vector<int> pos1 = { pos_x + 1, pos_y - 2 };
	std::vector<int> pos2 = { pos_x + 2, pos_y - 1 };
	
	std::vector<int> pos3 = { pos_x + 2, pos_y + 1 };
	std::vector<int> pos4 = { pos_x + 1, pos_y + 2 };
	
	std::vector<int> pos5 = { pos_x - 1, pos_y + 2 };
	std::vector<int> pos6 = { pos_x - 2, pos_y + 1 };
	
	std::vector<int> pos7 = { pos_x - 2, pos_y - 1 };
	std::vector<int> pos8 = { pos_x - 1, pos_y - 2 };

	positions.push_back(pos1);
	positions.push_back(pos2);
	positions.push_back(pos3);
	positions.push_back(pos4);
	positions.push_back(pos5);
	positions.push_back(pos6);
	positions.push_back(pos7);
	positions.push_back(pos8);

	return positions;
}


