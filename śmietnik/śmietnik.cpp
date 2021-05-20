#include <iostream>
#include <list>
#include <vector>
#include "../Chess/Figure.h"
#include "../Chess/Knight.h"
#include "../Chess/Bishop.h"
#include "../Chess/King.h"
#include "../Chess/Queen.h"
#include "../Chess/Pawn.h"
#include "../Chess/Rook.h"

using namespace std;

int main()
{
	Pawn goniec(1, 5, 4);
	list<vector<int>> lista = goniec.get_possible_positions();

	for (auto itr = lista.begin(); itr != lista.end(); ++itr)
	{
		cout << (*itr)[0] << " : " << (*itr)[1] << endl;
	}

}
