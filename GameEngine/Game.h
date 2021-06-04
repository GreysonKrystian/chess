#pragma once
#include "../Board/Board.h"
#include <algorithm>

class Player
{
private:
	std::list<Figure*> player_figures;
public:
	Player(){}
	void set_player_figures(std::list<Figure*> const&);
	std::list<Figure*> get_player_figures() const;
	Figure* get_king() const;
	void del_figure(Figure* fig_to_del);
	void replace_figure(Figure* fig_to_add, Figure* current_figure);
};


class Game
{
private:
	Player player_white;
	Player player_black;
	Board board; // było public
	bool is_white_turn;
	std::list<std::vector<int>> restrict_king_positions(Player const& current_player, Player const& checked_player) const;
	bool castling_left_conditions(int pos_x, int pos_y) const;
	bool castling_right_conditions(int pos_x, int pos_y) const;
	std::list<Figure*> get_checking_figures() const;
	void create_figures();

public:
	Game();
	~Game();
	void capture_figure(int x, int y);
	bool check_win_condition(Player const& current_player, Player const& checked_player) const;
	void change_turn();
	bool check_promote_pawn(Figure* pawn);
	std::vector<int> do_castling(int new_x, int new_y);
	void make_move(Figure*, int, int);
	std::list<std::vector<int>> get_castling_positions() const;
	Board get_board();
	bool get_current_player() const; // sprawdz ktory kolor ma ruch bialy = true, czarny false
	std::list<std::vector<int>> get_allowed_moves() const; //zwraca możliwe ruchy dla szachowanego gracza
	Player get_player()const; // zwraca gracza który ma teraz turę
	Player get_enemy_player()const; // zwraca gracza który nie ma tury  
};
