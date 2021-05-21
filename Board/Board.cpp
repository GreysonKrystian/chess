#include "Board.h"



void Board::set_starting_postions()
{
	//Czarne
	Figure* bishop_l_b = new Bishop(0, 3, 1);
	Figure* bishop_r_b = new Bishop(0, 6, 1);
	Figure* rook_l_b = new Rook(0, 1, 1);
	Figure* rook_r_b = new Rook(0, 8, 1);
	Figure* knight_l_b = new Knight(0,2,1);
	Figure* knight_r_b = new Knight(0,7,1);
	Figure* king_b = new King(0, 5, 1);
	Figure* queen_b = new Queen(0, 4, 1);
	Figure* knight_l_b = new Knight(0, 2, 1);
	Figure* knight_r_b = new Knight(0, 7, 1);
	Figure* pawn_b_1 = new Pawn(0, 1, 2);
	Figure* pawn_b_2 = new Pawn(0, 2, 2);
	Figure* pawn_b_3 = new Pawn(0, 3, 2);
	Figure* pawn_b_4 = new Pawn(0, 4, 2);
	Figure* pawn_b_5 = new Pawn(0, 5, 2);
	Figure* pawn_b_6 = new Pawn(0, 6, 2);
	Figure* pawn_b_7 = new Pawn(0, 7, 2);
	Figure* pawn_b_8 = new Pawn(0, 8, 2);
	

	//Biale
	Figure* bishop_l_w = new Bishop(1, 3, 8);
	Figure* bishop_r_w = new Bishop(1, 6, 8);
	Figure* rook_l_w = new Rook(1, 1, 8);
	Figure* rook_r_w = new Rook(1, 8, 8);
	Figure* knight_l_w = new Knight(1, 2, 8);
	Figure* knight_r_w = new Knight(1, 7, 8);
	Figure* king_w = new King(1, 5, 8);
	Figure* queen_w = new Queen(1, 4, 8);
	Figure* knight_l_w = new Knight(1, 2, 8);
	Figure* knight_r_w = new Knight(1, 7, 8);
	Figure* pawn_w_1 = new Pawn(1, 1, 7);
	Figure* pawn_w_2 = new Pawn(1, 2, 7);
	Figure* pawn_w_3 = new Pawn(1, 3, 7);
	Figure* pawn_w_4 = new Pawn(1, 4, 7);
	Figure* pawn_w_5 = new Pawn(1, 5, 7);
	Figure* pawn_w_6 = new Pawn(1, 6, 7);
	Figure* pawn_w_7 = new Pawn(1, 7, 7);
	Figure* pawn_w_8 = new Pawn(1, 8, 7);

	
}