#pragma once
#include "../Board/Board.h"

class Player
{
private:
	std::list<Figure*> player_figures;
public:
	Player();
	void set_player_figures(std::list<Figure*>);
	std::list<Figure*> get_player_figures();
	Figure* get_king();
};

class Game
{
private:
	Board board;
	bool is_white_turn;
	Player player_white;
	Player player_black;
	std::list<std::vector<int>> restrict_king_positions(Player current_player);
	bool castling_left_conditions(int pos_x, int pos_y);
	std::list<std::vector<int>> get_castling_positions();
	bool castling_right_conditions(int pos_x, int pos_y);
	std::list<Figure*> get_checking_figures(Player current_player);
	

public:
	Game();
	void capture_figure(int x, int y);
	bool check_win_condition();
	void change_turn();
	void create_figures();
	bool get_current_player(); // sprawdz ktory kolor ma ruch bialy = true, czarny false
	std::list<std::vector<int>> get_allowed_moves(Player);
};