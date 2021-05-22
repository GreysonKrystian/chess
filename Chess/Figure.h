#pragma once
#include <list>
#include <vector>
#include <string>
//#include "../Board/board.h"

class Figure
{
protected:
	int color; //0 czarny, 1 bialy (biale od dolu)
	int pos_x;
	int pos_y;
	std::string type; // nazwa figury
	bool first_move = true; // czy pierwsza figura siê ruszy³a 
public:
	virtual std::list<std::vector<int>> get_possible_positions() = 0;
	void change_pos(int x, int y);
	std::vector<int> get_position();
	int get_color();
	std::string get_type();
	void change_first_move_status();
	bool get_first_move();
};