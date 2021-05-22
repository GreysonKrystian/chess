#include "Game.h"


Board::Board()
{
}


void capture_figure(int x, int y)
{
 	Figure* captured = my_board.get_(x, y);
	delete captured;
}

void check_win_condition(int current_color)
{
	
}