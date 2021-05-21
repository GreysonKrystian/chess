#pragma once
#include <list>
#include <vector>
#include "../Board/board.h"

class Figure
{
protected:
	int color; //0 czarny, 1 bialy (biale od dolu)
	int pos_x;
	int pos_y;
public:

	virtual std::list<std::vector<int>> get_possible_positions() = 0;
	
	void change_pos(int x, int y);
	std::vector<int, int> get_position();
};