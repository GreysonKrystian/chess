#include "../Chess/bishop.h"
#include "../Chess/king.h"
#include "../Chess/knight.h"
#include "../Chess/pawn.h"
#include "../Chess/queen.h"
#include "../Chess/rook.h"
#include <array>

class Board
{

private:
	std::array<std::array < Figure, 8>, 8> board = {};

public:
	void set_starting_postions();
	void      
