#include "Board.h"
#include <string>



Board::Board()
{
	for (auto itr_x = board.begin(); itr_x != board.end(); ++itr_x)
	{
		for (auto itr_y = (*itr_x).begin(); itr_y != (*itr_x).end(); ++itr_y)
		{
			*itr_y = nullptr;
		}
	}
}

Board::~Board()
{
	/*for (auto itr_x = board.begin(); itr_x != board.end(); ++itr_x)
	{
		for (auto itr_y = (*itr_x).begin(); itr_y != (*itr_x).end(); ++itr_y)
		{
			delete *itr_y;
		}
	}*/
}

std::array<std::array < Figure*, 8>, 8> Board::get_board() const
{
	return board;
}

void Board::set_starting_postions(std::list < Figure*> const& figure_list)
{
	for (auto itr = figure_list.begin(); itr != figure_list.end(); ++itr)
	{
		int pos_x = ((*itr)->get_position())[0];
		int pos_y = ((*itr)->get_position())[1];
		board[pos_x][pos_y] = *itr;
	}
}

void Board::move_figure(Figure* my_figure, int x, int y)
{
	std::vector<int> old_pos = my_figure->get_position();
	//if (my_figure->get_type() == "K" )
	//{
	// zrob roszade
	//}
	if (my_figure->get_first_move() == true)
	{
		my_figure->change_first_move_status();
	}
	my_figure->change_pos(x, y);
	board[x][y] = my_figure;

	board[old_pos[0]][old_pos[1]] = nullptr;
}

Figure* Board::get_figure(int x, int y) const
{
	return board[x][y];
}


std::list<std::vector<int>> Board::get_free_positions_for_figure(Figure* my_figure) const
{
	std::list<std::vector<int>> possible_pos = my_figure->get_possible_positions();
	std::list<std::vector<int>> occupied_positions; // pozycje na które może się przemieścić figura, ale to pole jest zajęte przez inną nieważne jakiego koloru

	int fig_x = (my_figure->get_position())[0];
	int fig_y = (my_figure->get_position())[1];

	for (auto itr = possible_pos.begin(); itr != possible_pos.end(); ++itr)
	{
		if ((board[(*itr)[0]][(*itr)[1]] != nullptr))
		{
			occupied_positions.push_back(*itr);
		}
	}
	
	for (auto itr_ocp = occupied_positions.begin(); itr_ocp != occupied_positions.end(); ++itr_ocp)
	{
		std::list<std::vector<int>> points_to_del;
		if (my_figure->get_type() == "R" || my_figure->get_type() == "Q" || my_figure->get_type() == "B" || my_figure->get_type() == "P") // jesli królowa, goniec lub wieża dodaje pozycje do usunięcia za zablokowanym polem
		{
			std::list<std::vector<int>> points_behind = get_positions_behind(my_figure->get_position(), *itr_ocp);
			
			points_to_del.insert(points_to_del.end(), points_behind.begin(), points_behind.end());
		}
		
		int blc_x = (*itr_ocp)[0];
		int blc_y = (*itr_ocp)[1];
		if (my_figure->get_color() == (board[blc_x][blc_y])->get_color() || my_figure->get_type() == "P")
		{
			points_to_del.push_back(*itr_ocp);
		}

		for (auto itr_del = points_to_del.begin(); itr_del != points_to_del.end(); ++itr_del)
		{
			auto itr_pos = std::find(possible_pos.begin(), possible_pos.end(), *itr_del);
			if (itr_pos != possible_pos.end())
			{possible_pos.erase(itr_pos);}
		}
	}

	if (my_figure->get_type() == "P") // bicie piona
	{
		auto strikes = this->get_strike_positions_for_pawn(my_figure);		
		for (auto itr = strikes.begin(); itr!= strikes.end(); ++itr)
		{
			int x = (*itr)[0];
			int y = (*itr)[1];
			auto aaaa = board[x][y];
			if (board[x][y] != nullptr)
			{
				if (board[x][y]->get_color() != my_figure->get_color())
				{
					possible_pos.push_back(*itr);
				}
			}
		}
	}
	return possible_pos;
}

std::list<std::vector<int>> Board::get_strike_positions_for_pawn(Figure* my_pawn) const
{
	std::list<std::vector<int>> positions;
	int color = my_pawn->get_color();
	int pos_x = my_pawn->get_position()[0];
	int pos_y = my_pawn->get_position()[1];


	if (color == 1) //bialy // od dołu
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




std::list<std::vector<int>> Board::get_positions_behind(std::vector<int> const& current_fig_pos, std::vector<int> const& blocking_fig_pos) const
{
	int cur_x = current_fig_pos[0];
	int cur_y = current_fig_pos[1];
	int blc_x = blocking_fig_pos[0];
	int blc_y = blocking_fig_pos[1];

	std::list<std::vector<int>> positions_behind;

	if ((blc_x == cur_x) && (blc_y < cur_y)) //pion w górę
	{
		blc_y--;
		while (blc_y >= 0)
		{
			std::vector<int> point = { blc_x, blc_y };
			positions_behind.push_back(point);
			blc_y--;
		}
	}

	if ((blc_x == cur_x) && (blc_y > cur_y)) //pion w dół
	{
		blc_y++;
		while (blc_y <= 7)
		{
			std::vector<int> point = { blc_x, blc_y };
			positions_behind.push_back(point);
			blc_y++;
		}
	}


	if ((blc_x > cur_x) && (blc_y == cur_y)) //poziom w prawo
	{
		blc_x++;
		while (blc_x <= 7)
		{
			std::vector<int> point = { blc_x, blc_y };
			positions_behind.push_back(point);
			blc_x++;
		}
	}

	if ((blc_x < cur_x) && (blc_y == cur_y)) //poziom w lewo
	{
		blc_x--;
		while (blc_x >= 0)
		{
			std::vector<int> point = { blc_x, blc_y };
			positions_behind.push_back(point);
			blc_x--;
		}
	}

	if ((blc_x > cur_x) && (blc_y < cur_y)) // prawy ukos w górę
	{
		blc_x++;
		blc_y--;
		while (blc_x <= 7 && blc_y >=0)
		{
			std::vector<int> point = { blc_x, blc_y };
			positions_behind.push_back(point);
			blc_x++;
			blc_y--;
		}
	}

	if ((blc_x > cur_x) && (blc_y > cur_y)) // prawy ukos w dół
	{
		blc_x++;
		blc_y++;
		while (blc_x <= 7 && blc_y <= 7)
		{
			std::vector<int> point = { blc_x, blc_y };
			positions_behind.push_back(point);
			blc_x++;
			blc_y++;
		}
	}

	if ((blc_x < cur_x) && (blc_y < cur_y)) // lewy ukos w górę
	{
		blc_x--;
		blc_y--;
		while (blc_x >= 0 && blc_y >= 0)
		{
			std::vector<int> point = { blc_x, blc_y };
			positions_behind.push_back(point);
			blc_x--;
			blc_y--;
		}
	}

	if ((blc_x < cur_x) && (blc_y > cur_y)) // lewy ukos w dół
	{
		blc_x--;
		blc_y++;
		while (blc_x >= 0 && blc_y <= 7)
		{
			std::vector<int> point = { blc_x, blc_y };
			positions_behind.push_back(point);
			blc_x--;
			blc_y++;
		}
	}
	return positions_behind; 
}