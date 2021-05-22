#include "king.h"

King::King(int my_color, int my_pos_x, int my_pos_y)
{
	color = my_color;
	pos_x = my_pos_x;
	pos_y = my_pos_y;
	first_move = true;
	type = "K";
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

bool King::castling_left_conditions(Board& board)
{	
	if (board.get_figure(pos_x - 4, pos_y) == nullptr)
		return false;
	else
	{
		Figure* corner_figure = board.get_figure(pos_x - 4, pos_y);
		if ((corner_figure->get_type() == "R") && (corner_figure->get_first_move() == true))
			return true;
		return false;
	}
}

bool King::castling_right_conditions(Board& board)
{
	if (board.get_figure(pos_x + 3, pos_y) == nullptr)
		return false;
	else
	{
		Figure* corner_figure = board.get_figure(pos_y + 3, pos_y);
		if ((corner_figure->get_type() == "R") && (corner_figure->get_first_move() == true))
			return true;
		return false;
	}
}

std::list<std::vector<int>> King::get_castling_positions(Board& board)
{
	
	std::list<std::vector<int>> castling_positions;
	
	if ((castling_left_conditions(board) == true) && (board.get_figure(pos_x - 1, pos_y) == nullptr) && (board.get_figure(pos_x - 2, pos_y) == nullptr)
	&& board.get_figure(pos_x - 3, pos_y))
	{
		castling_positions.push_back({ pos_x - 2, pos_y });
	}
	if ((castling_right_conditions(board) == true) && (board.get_figure(pos_x + 1, pos_y)) == nullptr && (board.get_figure(pos_x + 2, pos_y) == nullptr))
	{
		castling_positions.push_back({ pos_x + 2, pos_y });
	}

	return castling_positions;
}