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
#include "../GameEngine/Game.h"
#include "../Board/Board.h"
#include <string>

using namespace std;

int main()
{
	Game game;
	/*Knight goniec(1, 7, 0);
	list<vector<int>> lista = goniec.get_possible_positions();
	cout << "////////////// /////////////////////" << endl;

	for (auto itr = lista.begin(); itr != lista.end(); ++itr)
	{
		cout << (*itr)[0] << " : " << (*itr)[1] << endl;
	}*/

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


	/*cout << "///////////////posortowane////////////////////" << endl;

	lista.sort();

	for (auto itr1 = lista.begin(); itr1 != lista.end(); ++itr1)
	{
		cout << (*itr1)[0] << " : " << (*itr1)[1] << endl;
	}*/

	/*cout << "//////////////pewne posortowane/////////////////////" << endl;

	certain_positions.sort();
	for (auto itr = certain_positions.begin(); itr != certain_positions.end(); ++itr)
	{
		cout << (*itr)[0] << " : " << (*itr)[1] << endl;
	}*/
	

	//Figure* queen_b = new Queen(0, 3, 0);
	//Figure* pawn_b_1 = new Pawn(0, 0, 1);

	//list<Figure*> list;
	//list.push_back(queen_b);
	//list.push_back(pawn_b_1);

	//delete queen_b;


	//Board plansza;
	//plansza.set_starting_postions();
	//plansza.move_figure(plansza.get_figure(3, 0), 3, 3);
	//std::list<std::vector<int>> positions = plansza.get_free_positions_for_figure(plansza.get_figure(3,3));

	//for (auto itr = positions.begin(); itr != positions.end(); ++itr)
	//{
	//	cout << (*itr)[0] << " : " << (*itr)[1] << endl;
	//}



	//std::string starting_position = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR";

	//cout << starting_position[0] << endl;

	//std::string str("Test string");
	//for (std::string::iterator it = str.begin(); it != str.end(); ++it)
	//	std::cout << *it<<endl;
	//std::cout << '\n';

}
