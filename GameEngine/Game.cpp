#include "Game.h"


Game::Game()
{
	is_white_turn = true;
}


void Game::capture_figure(int x, int y)
{
 	Figure* captured = board.get_figure(x, y);
	delete captured;
}

bool Game::check_win_condition(int current_color)
{
	return true;
}











bool Game::castling_left_conditions(int pos_x, int pos_y)
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

bool Game::castling_right_conditions(int pos_x, int pos_y)
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

std::list<std::vector<int>> Game::get_castling_positions()
{
	int pos_x = 4;
	int pos_y = 0;
	if (get_current_player() == true)
	{
		int pos_x = 4;
		int pos_y = 7;
	}
	std::list<std::vector<int>> castling_positions;

	if ((castling_left_conditions(pos_x, pos_y) == true) && (board.get_figure(pos_x - 1, pos_y) == nullptr) && (board.get_figure(pos_x - 2, pos_y) == nullptr)
		&& board.get_figure(pos_x - 3, pos_y))
	{
		castling_positions.push_back({ pos_x - 2, pos_y });
	}
	if ((castling_right_conditions(pos_x, pos_y) == true) && (board.get_figure(pos_x + 1, pos_y)) == nullptr && (board.get_figure(pos_x + 2, pos_y) == nullptr))
	{
		castling_positions.push_back({ pos_x + 2, pos_y });
	}

	return castling_positions;
}

bool Game::get_current_player()
{
	return is_white_turn;
}

void Game::change_turn()
{
	if (is_white_turn == true)
	{
		is_white_turn = false;
	}
	else
	{
		is_white_turn = true;
	}
}