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
	Figure* knight_l_b = new Knight(0, 1, 0);
	Figure* knight_r_b = new Knight(0, 7, 1);
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
	Figure* knight_l_w = new Knight(1, 1, 7);
	Figure* knight_r_w = new Knight(1, 6, 7);
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
	board[0][1] = knight_l_b;
	board[0][2] = bishop_l_b;
	board[0][3] = queen_b;
	board[0][4] = king_b;
	board[0][5] = bishop_r_b;
	board[0][6] = knight_r_b;
	board[0][7] = rook_r_b;

	board[1][1] = pawn_b_1;
	board[2][1] = pawn_b_2;
	board[3][1] = pawn_b_3;
	board[4][1] = pawn_b_4;
	board[5][1] = pawn_b_5;
	board[6][1] = pawn_b_6;
	board[7][1] = pawn_b_7;
	board[7][1] = pawn_b_8;
	 

	//białe 
	board[7][0] = rook_l_w;
	board[7][1] = knight_l_w;
	board[7][2] = bishop_l_w;
	board[7][3] = king_w;
	board[7][4] = queen_w;
	board[7][5] = bishop_r_w;
	board[7][6] = knight_r_w;
	board[7][7] = rook_r_w;

	board[1][1] = pawn_w_1;
	board[2][1] = pawn_w_2;
	board[3][1] = pawn_w_3;
	board[4][1] = pawn_w_4;
	board[5][1] = pawn_w_5;
	board[6][1] = pawn_w_6;
	board[7][1] = pawn_w_7;
	board[7][1] = pawn_w_8;
}



void Board::move_figure(Figure* my_figure, int x, int y)
{
	std::vector<int, int> pos = my_figure->get_position();

	my_figure->change_pos(x, y);
	board[x][y] = my_figure;

	board[pos[1]][pos[2]] = nullptr;
}

std::list<std::vector<int>> Board::get_positions_in_board(Figure*)
{

}