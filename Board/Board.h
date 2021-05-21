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
	std::list<std::vector<int>> check_positions_behind(std::vector<int>, std::vector<int>);

public:
	Board();
	~Board();
	std::list<std::vector<int>> get_free_positions_for_figure(Figure*);
	void set_starting_postions();
	void move_figure(Figure* my_figure, int x, int y);
};