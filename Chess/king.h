#import "Figure.h"

class King: public Figure
{
public:
	King(int color, int pos_x, int pos_y);
	virtual std::list<std::vector<int>>  get_possible_positions();
}
