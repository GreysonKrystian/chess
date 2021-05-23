#pragma once
#include "../Board/Board.h"

class Game
{
private:
	Board board;
	bool is_white_turn;
public:
	Game();
	void capture_figure(int x, int y);
	bool check_win_condition(int current_color);
	void change_turn();
	bool castling_left_conditions(int pos_x, int pos_y);
	bool castling_right_conditions(int pos_x, int pos_y);
	std::list<std::vector<int>> get_castling_positions();


	bool get_current_player(); // sprawdz ktory kolor ma ruch bialy = true, czarny false
	
};