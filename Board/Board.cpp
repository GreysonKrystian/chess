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
	for (auto itr_x = board.begin(); itr_x != board.end(); ++itr_x)
	{
		for (auto itr_y = (*itr_x).begin(); itr_y != (*itr_x).end(); ++itr_y)
		{
			delete *itr_y;
		}
	}
}


void Board::set_starting_postions()
{	
	Figure* bishop_l_b = new Bishop(0, 2, 0);
	Figure* bishop_r_b = new Bishop(0, 5, 0);
	Figure* rook_l_b = new Rook(0, 0, 0);
	Figure* rook_r_b = new Rook(0, 7, 0);
	Figure* knight_l_b = new Knight(0, 1, 0);
	Figure* knight_r_b = new Knight(0, 6, 0);
	Figure* king_b = new King(0, 4, 0);
	Figure* queen_b = new Queen(0, 3, 0);
	Figure* pawn_b_1 = new Pawn(0, 0, 1);
	Figure* pawn_b_2 = new Pawn(0, 1, 1);
	Figure* pawn_b_3 = new Pawn(0, 2, 1);
	Figure* pawn_b_4 = new Pawn(0, 3, 1);
	Figure* pawn_b_5 = new Pawn(0, 4, 1);
	Figure* pawn_b_6 = new Pawn(0, 5, 1);
	Figure* pawn_b_7 = new Pawn(0, 6, 1);
	Figure* pawn_b_8 = new Pawn(0, 7, 1);

	//Biale
	Figure* bishop_l_w = new Bishop(1, 2, 7);
	Figure* bishop_r_w = new Bishop(1, 5, 7);
	Figure* rook_l_w = new Rook(1, 0, 7);
	Figure* rook_r_w = new Rook(1, 7, 7);
	Figure* knight_l_w = new Knight(1, 1, 7);
	Figure* knight_r_w = new Knight(1, 6, 7);
	Figure* king_w = new King(1, 4, 7);
	Figure* queen_w = new Queen(1, 3, 7);
	Figure* pawn_w_1 = new Pawn(1, 0, 6);
	Figure* pawn_w_2 = new Pawn(1, 1, 6);
	Figure* pawn_w_3 = new Pawn(1, 2, 6);
	Figure* pawn_w_4 = new Pawn(1, 3, 6);
	Figure* pawn_w_5 = new Pawn(1, 4, 6);
	Figure* pawn_w_6 = new Pawn(1, 5, 6);
	Figure* pawn_w_7 = new Pawn(1, 6, 6);
	Figure* pawn_w_8 = new Pawn(1, 7, 6);

	//czarne
	board[0][0] = rook_l_b;
	board[1][0] = knight_l_b;
	board[2][0] = bishop_l_b;
	board[3][0] = queen_b;
	board[4][0] = king_b;
	board[5][0] = bishop_r_b;
	board[6][0] = knight_r_b;
	board[7][0] = rook_r_b;

	board[0][1] = pawn_b_1;
	board[1][1] = pawn_b_2;
	board[2][1] = pawn_b_3;
	board[3][1] = pawn_b_4;
	board[4][1] = pawn_b_5;
	board[5][1] = pawn_b_6;
	board[6][1] = pawn_b_7;
	board[7][1] = pawn_b_8;
	 

	//białe 
	board[0][7] = rook_l_w;
	board[1][7] = knight_l_w;
	board[2][7] = bishop_l_w;
	board[3][7] = king_w;
	board[4][7] = queen_w;
	board[5][7] = bishop_r_w;
	board[6][7] = knight_r_w;
	board[7][7] = rook_r_w;

	board[0][6] = pawn_w_1;
	board[1][6] = pawn_w_2;
	board[2][6] = pawn_w_3;
	board[3][6] = pawn_w_4;
	board[4][6] = pawn_w_5;
	board[5][6] = pawn_w_6;
	board[6][6] = pawn_w_7;
	board[7][6] = pawn_w_8;
}



void Board::move_figure(Figure* my_figure, int x, int y)
{
	std::vector<int> pos = my_figure->get_position();

	my_figure->change_pos(x, y);
	board[x][y] = my_figure;

	board[pos[0]][pos[1]] = nullptr;
}

Figure* Board::get_figure(int x, int y)
{
	return board[x][y];
}


std::list<std::vector<int>> Board::get_free_positions_for_figure(Figure* my_figure)
{
	std::list<std::vector<int>> possible_pos = my_figure->get_possible_positions();
	std::list<std::vector<int>> occupied_positions; // pozycje na które może się przemieścić figura, ale to pole jest zajęte przez inną

	int fig_x = (my_figure->get_position())[0];
	int fig_y = (my_figure->get_position())[1];

	for (auto itr = possible_pos.begin(); itr != possible_pos.end(); ++itr)
	{
		if ((board[(*itr)[0]][(*itr)[1]] != nullptr))
		{
			occupied_positions.push_back(*itr);
		}
	}
	
	for (auto itr = occupied_positions.begin(); itr != occupied_positions.end(); ++itr)
	{
		std::list<std::vector<int>> points_to_del = get_positions_behind(my_figure->get_position(), *itr);
		
		int blc_x = (*itr)[0];
		int blc_y = (*itr)[1];
		if (my_figure->get_color() == (board[blc_x][blc_y])->get_color())
		{
			points_to_del.push_back(*itr);
		}

		for (auto itr_del = points_to_del.begin(); itr_del != points_to_del.end(); ++itr_del)
		{
			for (auto itr_pos = possible_pos.begin(); itr_pos != possible_pos.end(); ++itr_pos)
			{
				if (*itr_pos == *itr_del)
				{
					possible_pos.erase(itr_pos);
					break;
				}
			}
		}
	}
	return possible_pos;
}




std::list<std::vector<int>> Board::get_positions_behind(std::vector<int> current_fig_pos, std::vector<int> blocking_fig_pos)
{
	int cur_x = current_fig_pos[0];
	int cur_y = current_fig_pos[1];
	int blc_x = blocking_fig_pos[0];
	int blc_y = blocking_fig_pos[1];

	std::list<std::vector<int>> positions_behind;

	if ((blc_x == cur_x) && (blc_y > cur_y)) //pion w górę
	{
		blc_y--;
		while (blc_y >= 0)
		{
			std::vector<int> point = { blc_x, blc_y };
			positions_behind.push_back(point);
			blc_y--;
		}
	}

	if ((blc_x == cur_x) && (blc_y < cur_y)) //pion w dół
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

	/*if ((possible_pos[0] > starting_pos[0]) && (possible_pos[1] > starting_pos[1]))
	{
		for (int i = ; i <= ; i + )
	}
	if ((possible_pos[0] < starting_pos[0]) && ((possible_pos[1] < starting_pos[1]))
	{

	}
	if ((possible_pos[0] > starting_pos[0]) && ((possible_pos[1] < starting_pos[1]))
	{

	}
	if ((possible_pos[0] < starting_pos[0]) && ((possible_pos[1] > starting_pos[1]))
	{

	}*/
}