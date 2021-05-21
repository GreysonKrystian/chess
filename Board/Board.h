#include "../Chess/bishop.h"
#include "../Chess/king.h"
#include "../Chess/knight.h"
#include "../Chess/pawn.h"
#include "../Chess/queen.h"
#include "../Chess/rook.h"
#include <array>
#include <list>
#include <vector>

class Board
{
	std::array<std::array < Figure*, 8>, 8> board;
public:
	Board();
	~Board();
	std::list<std::vector<int>> get_positions_in_board()
	void set_starting_postions();
	void move_figure(Figure* my_figure, int x, int y);
};