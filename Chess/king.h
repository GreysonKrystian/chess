#include "Figure.h"


class King : public Figure
{
private:
	std::list<std::vector<int>> get_all_positions();
	bool first_move;
public:
	King(int, int, int);
	virtual std::list<std::vector<int>> get_possible_positions(Board& board);
	void change_pos(int x, int y);
	bool castling_left_conditions(Board& board);
	bool castling_right_conditions(Board& board);
	std::list<std::vector<int>> add_castling_positions(std::list<std::vector<int>> possible, Board& board);
};



