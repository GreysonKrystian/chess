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
	Knight goniec(1, 7, 0);
	list<vector<int>> lista = goniec.get_possible_positions();
	cout << "////////////// /////////////////////" << endl;

	for (auto itr = lista.begin(); itr != lista.end(); ++itr)
	{
		cout << (*itr)[0] << " : " << (*itr)[1] << endl;
	}

	/*cout << "//////////////pewne/////////////////////" << endl;

	std::vector<int> pos1 = { 6,2 };
	std::vector<int> pos2 = { 7,3 };
	std::vector<int> pos3 = { 7,5 };
	std::vector<int> pos4 = { 6,6 };
	std::vector<int> pos5 = { 4,6 };
	std::vector<int> pos6 = { 3,5 };
	std::vector<int> pos7 = { 3,3 };
	std::vector<int> pos8 = { 4,2 };

	std::list<std::vector<int>> certain_positions;
	certain_positions.push_back(pos1);
	certain_positions.push_back(pos2);
	certain_positions.push_back(pos3);
	certain_positions.push_back(pos4);
	certain_positions.push_back(pos5);
	certain_positions.push_back(pos6);
	certain_positions.push_back(pos7);
	certain_positions.push_back(pos8);*/

	/*for (auto itr = certain_positions.begin(); itr != certain_positions.end(); ++itr)
	{
		cout << (*itr)[0] << " : " << (*itr)[1] << endl;
	}*/


	cout << "///////////////posortowane////////////////////" << endl;

	lista.sort();

	for (auto itr1 = lista.begin(); itr1 != lista.end(); ++itr1)
	{
		cout << (*itr1)[0] << " : " << (*itr1)[1] << endl;
	}

	/*cout << "//////////////pewne posortowane/////////////////////" << endl;

	certain_positions.sort();
	for (auto itr = certain_positions.begin(); itr != certain_positions.end(); ++itr)
	{
		cout << (*itr)[0] << " : " << (*itr)[1] << endl;
	}*/

}
