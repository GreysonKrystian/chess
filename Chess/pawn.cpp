#include "pawn.h"

Pawn::Pawn(int my_color, int my_pos_y, int my_pos_x)
{
	color = my_color;
	pos_y = my_pos_y;
	pos_x = my_pos_x;
	first_move = true;
	
}

std::list<std::vector<int>> Pawn::get_possible_positions()
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

std::list<std::vector<int>> Pawn::get_strike_positions()
{
	std::list<std::vector<int>> positions;

	if (color == 1) //bialy // od do³u
	{
		std::vector<int> pos_1 = { pos_x + 1, pos_y - 1 };
		std::vector<int> pos_2 = { pos_x - 1 , pos_y - 1 };
		positions.push_back(pos_1);
		positions.push_back(pos_2);
	}

	if (color == 0) //czarny // od gory
	{
		std::vector<int> pos_1 = { pos_x + 1, pos_y + 1 };
		std::vector<int> pos_2 = { pos_x - 1 , pos_y + 1 };
		positions.push_back(pos_1);
		positions.push_back(pos_2);

	}
	return positions;
}
