#include "pawn.h"

Pawn::Pawn(int my_color, int my_pos_x, int my_pos_y)
{
	color = my_color;
	pos_y = my_pos_y;
	pos_x = my_pos_x;
	first_move = true;
	
}

std::list<std::vector<int>> Pawn::get_all_positions()
{
	std::list<std::vector<int>> positions;
	
	if (color == 1) //bialy // od do³u idzie w gore
	{
		std::vector<int> pos_1 = { pos_x, pos_y - 1 };
		positions.push_back(pos_1);
		if (first_move == true)
		{
			std::vector<int> pos_2 = { pos_x, pos_y - 2 };
			positions.push_back(pos_2);
		}
	}
	
	if (color == 0) //czarny // od gory
	{
		std::vector<int> pos_1 = { pos_x, pos_y + 1 };
		positions.push_back(pos_1);
		if (first_move == true)
		{
			std::vector<int> pos_2 = { pos_x, pos_y + 2 };
			positions.push_back(pos_2);
		}
	}
	return positions;
}


std::list<std::vector<int>> Pawn::get_possible_positions()
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


std::list<std::vector<int>> Pawn::get_strike_positions()
{
	std::list<std::vector<int>> positions;

	if (color == 1) //bialy // od do³u
	{
		
		if (pos_x + 1 <= 7 && pos_y - 1 >= 0) //po prawo
		{
			std::vector<int> pos_1 = { pos_x + 1, pos_y - 1 };
			positions.push_back(pos_1);
		}

		if (pos_x - 1 >= 0 && pos_y - 1 >= 0) //po lewo
		{
			std::vector<int> pos_2 = { pos_x - 1 , pos_y - 1 };
			positions.push_back(pos_2);
		}
	}

	if (color == 0) //czarny // od gory
	{
		if (pos_x + 1 <= 7 && pos_y + 1 <= 7) //po prawo
		{
			std::vector<int> pos_1 = { pos_x + 1, pos_y + 1 };
			positions.push_back(pos_1);
		}

		if (pos_x - 1 >= 0 && pos_y + 1 <= 7) //po lewo
		{
			std::vector<int> pos_2 = { pos_x - 1 , pos_y + 1 };
			positions.push_back(pos_2);
		}

	}
	return positions;
}

void Pawn::change_first_move_status()
{
	first_move = false;
}
