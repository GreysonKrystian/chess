#pragma once
#include "../Board/Board.h"

class Game
{
private:
	Board my_board;
public:
	Game();
	void capture_figure();
	bool check_win_condition(int current_color);
	void change_turn();
	bool castling_left_conditions(Board& board);
	bool castling_right_conditions(Board& board);
	std::list<std::vector<int>> get_castling_positions(Board& board);

	
};