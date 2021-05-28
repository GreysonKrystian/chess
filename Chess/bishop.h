#pragma once
#include "Figure.h"


class Bishop : public Figure
{
private:
	bool in_range(std::vector<int> const&) const; //czy ruch jest w szachownicy
public:
	Bishop(int, int, int);
	virtual std::list<std::vector<int>> get_possible_positions() const;
};