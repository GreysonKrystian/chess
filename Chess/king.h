#include "Figure.h"


class King : public Figure
{
private:
	std::list<std::vector<int>> get_all_positions();
public:
	King(int, int, int);
	virtual std::list<std::vector<int>> get_possible_positions();
};



