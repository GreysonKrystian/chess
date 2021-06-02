#include "CppUnitTest.h"
#include <vector>
#include <list>
#include "../Board/Board.h"
#include "../GameEngine/Game.h"

#include "../Chess/bishop.h"
#include "../Chess/king.h"
#include "../Chess/knight.h"
#include "../Chess/pawn.h"
#include "../Chess/queen.h"
#include "../Chess/rook.h"

std::list<Figure*> get_figures()
{

	Figure* bishop_l_b = new Bishop(0, 2, 0);
	Figure* bishop_r_b = new Bishop(0, 5, 0);
	Figure* rook_l_b = new Rook(0, 0, 0);
	Figure* rook_r_b = new Rook(0, 7, 0);
	Figure* knight_l_b = new Knight(0, 1, 0);
	Figure* knight_r_b = new Knight(0, 6, 0);
	Figure* king_b = new King(0, 4, 0);
	Figure* queen_b = new Queen(0, 3, 0);
	Figure* pawn_b_1 = new Pawn(0, 0, 1);
	Figure* pawn_b_2 = new Pawn(0, 1, 1);
	Figure* pawn_b_3 = new Pawn(0, 2, 1);
	Figure* pawn_b_4 = new Pawn(0, 3, 1);
	Figure* pawn_b_5 = new Pawn(0, 4, 1);
	Figure* pawn_b_6 = new Pawn(0, 5, 1);
	Figure* pawn_b_7 = new Pawn(0, 6, 1);
	Figure* pawn_b_8 = new Pawn(0, 7, 1);

	//Biale
	Figure* bishop_l_w = new Bishop(1, 2, 7);
	Figure* bishop_r_w = new Bishop(1, 5, 7);
	Figure* rook_l_w = new Rook(1, 0, 7);
	Figure* rook_r_w = new Rook(1, 7, 7);
	Figure* knight_l_w = new Knight(1, 1, 7);
	Figure* knight_r_w = new Knight(1, 6, 7);
	Figure* king_w = new King(1, 4, 7);
	Figure* queen_w = new Queen(1, 3, 7);
	Figure* pawn_w_1 = new Pawn(1, 0, 6);
	Figure* pawn_w_2 = new Pawn(1, 1, 6);
	Figure* pawn_w_3 = new Pawn(1, 2, 6);
	Figure* pawn_w_4 = new Pawn(1, 3, 6);
	Figure* pawn_w_5 = new Pawn(1, 4, 6);
	Figure* pawn_w_6 = new Pawn(1, 5, 6);
	Figure* pawn_w_7 = new Pawn(1, 6, 6);
	Figure* pawn_w_8 = new Pawn(1, 7, 6);
	std::list <Figure*> figures{ bishop_l_b, bishop_r_b, rook_l_b, rook_r_b, knight_l_b, knight_r_b, king_b, queen_b,
	pawn_b_1, pawn_b_2, pawn_b_3, pawn_b_4, pawn_b_5, pawn_b_6, pawn_b_7, pawn_b_8,
	bishop_l_w, bishop_r_w, rook_l_w, rook_r_w, knight_l_w, knight_r_w, king_w, queen_w,
	pawn_w_1, pawn_w_2, pawn_w_3, pawn_w_4, pawn_w_5, pawn_w_6, pawn_w_7, pawn_w_8 };

	return figures;
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestBoard
{
	TEST_CLASS(TestBoard)
	{
	public:
		
		TEST_METHOD(Create_board)
		{
			Board my_board;
			for (auto& row : my_board.get_board())
			{
				for (auto& item : row)
				{
					Assert::IsTrue(item == nullptr);
					
				}
			}

		}

		TEST_METHOD(Set_Starting_Positions)
		{
			Board my_board;
			Figure* bishop_r_b = new Bishop(0, 5, 0);
			Figure* rook_l_b = new Rook(0, 0, 0);
			Figure* rook_r_w = new Rook(1, 7, 7);
			Figure* knight_l_w = new Knight(1, 1, 7);
			std::list <Figure*> figures{ bishop_r_b, rook_l_b, rook_r_w, knight_l_w };
			my_board.set_starting_postions(figures);
			auto a_board = my_board.get_board();
			Assert::IsTrue(a_board[5][0] != nullptr);
			Assert::IsTrue(a_board[0][0] != nullptr);
			Assert::IsTrue(a_board[1][7] != nullptr);
			Assert::IsTrue(a_board[7][7] != nullptr);
			
			/*auto figures = get_figures();
			Board my_board;
			my_board.set_starting_postions(figures);
			auto a_board = my_board.get_board();
			
			for (int x = 0; x <= 7; x++)
			{
				Assert::IsTrue(a_board[x][0] != nullptr);
				Assert::IsTrue(a_board[x][1] != nullptr);
				Assert::IsTrue(a_board[x][6] != nullptr);
				Assert::IsTrue(a_board[x][7] != nullptr);
				
				Assert::IsTrue(a_board[x][2] == nullptr);
				Assert::IsTrue(a_board[x][3] == nullptr);
				Assert::IsTrue(a_board[x][4] == nullptr);
				Assert::IsTrue(a_board[x][5] == nullptr);

			}
			Assert::IsTrue(a_board[0][0]->get_type() == "R");*/
		}

		TEST_METHOD(MoveFigure)
		{
			Board my_board;
			Figure* bishop_r_b = new Bishop(0, 5, 0);
			
			std::list <Figure*> figures{ bishop_r_b};
			my_board.set_starting_postions(figures);
			Assert::IsTrue(my_board.get_board()[5][0] != nullptr);
			
			my_board.move_figure(bishop_r_b, 7, 6);
			Assert::IsTrue(my_board.get_board()[5][0] == nullptr);
			Assert::IsTrue(my_board.get_board()[7][6] != nullptr);
		}

		TEST_METHOD(Get_free_positions_knight)
		{
			Board my_board;
			Figure* rook_l_b = new Rook(0, 0, 0);
			Figure* rook_r_w = new Rook(1, 3, 1);
			Figure* knight_l_w = new Knight(1, 1, 2);

			std::list <Figure*> figures{ rook_l_b, rook_r_w, knight_l_w };
			my_board.set_starting_postions(figures);

			std::list<std::vector<int>> free_pos = my_board.get_free_positions_for_figure(knight_l_w);
			free_pos.sort();

			std::vector<int> pos1 = { 2,0 };
			std::vector<int> pos2 = { 0,4 };
			std::vector<int> pos3 = { 2,4 };
			std::vector<int> pos4 = { 3,3 };
			std::vector<int> pos5 = { 0,0 };

			std::list<std::vector<int>> certain_positions;
			certain_positions.push_back(pos1);
			certain_positions.push_back(pos2);
			certain_positions.push_back(pos3);
			certain_positions.push_back(pos4);
			certain_positions.push_back(pos5);

			certain_positions.sort();

			Assert::IsTrue(certain_positions == free_pos);

		}


		TEST_METHOD(Get_free_positions_queen)
		{
			Board my_board;
			Figure* rook_l_b = new Rook(0, 5, 2); // przeciwny kolor
			Figure* rook_r_w = new Rook(1, 5, 5);
			Figure* knight_l_w = new Knight(1, 2, 4);
			
			Figure* queen_w = new Queen(1, 2, 2);

			std::list <Figure*> figures{ rook_l_b, rook_r_w, knight_l_w, queen_w };
			my_board.set_starting_postions(figures);

			std::list<std::vector<int>> free_pos = my_board.get_free_positions_for_figure(queen_w);
			free_pos.sort();

			std::vector<int> pos1 = { 0,0 };
			std::vector<int> pos2 = { 0,2 };
			std::vector<int> pos3 = { 0,4 };
			std::vector<int> pos4 = { 1,1 };
			std::vector<int> pos5 = { 1,2 };
			std::vector<int> pos6 = { 1,3 };
			std::vector<int> pos7 = { 2,0 };
			std::vector<int> pos8 = { 2,1 };
			std::vector<int> pos9 = { 2,3 };
			std::vector<int> pos10 = { 3,1 };
			std::vector<int> pos11 = { 3,2 };
			std::vector<int> pos12 = { 3,3 };
			std::vector<int> pos13 = { 4,0 };
			std::vector<int> pos14 = { 4,2 };
			std::vector<int> pos15 = { 4,4 };
			std::vector<int> pos16 = { 5,2 };

			std::list<std::vector<int>> certain_positions{ pos1,pos2,pos3,pos4,pos5,pos6,pos7,
														   pos8,pos9,pos10,pos11,pos12,pos13,pos14, pos15, pos16 };
			certain_positions.sort();

			Assert::IsTrue(certain_positions == free_pos);

		}

		TEST_METHOD(Get_free_positions_rook)
		{
			Board my_board;
			Figure* rook_l_b = new Rook(0, 5, 2); // przeciwny kolor
			Figure* rook_r_w = new Rook(1, 2, 1);
			

			Figure* rook_w = new Rook(1, 2, 2);

			std::list <Figure*> figures{ rook_l_b, rook_r_w, rook_w };
			my_board.set_starting_postions(figures);

			std::list<std::vector<int>> free_pos = my_board.get_free_positions_for_figure(rook_w);
			free_pos.sort();

			std::vector<int> pos1 = { 2,3 };
			std::vector<int> pos2 = { 2,4 };
			std::vector<int> pos3 = { 2,5 };
			std::vector<int> pos4 = { 2,6 };
			std::vector<int> pos5 = { 2,7 };
			std::vector<int> pos6 = { 1,2 };
			std::vector<int> pos7 = { 0,2 };
			std::vector<int> pos8 = { 3,2 };
			std::vector<int> pos9 = { 4,2 };
			std::vector<int> pos10 = { 5,2 };

			std::list<std::vector<int>> certain_positions{ pos1,pos2,pos3,pos4,pos5,pos6,pos7,
														   pos8,pos9,pos10};
			certain_positions.sort();

			Assert::IsTrue(certain_positions == free_pos);
		}
		

		TEST_METHOD(Get_free_positions_bishop)
		{
			Board my_board;
			Figure* rook_l_b = new Rook(0, 5, 5); // przeciwny kolor
			Figure* rook_r_w = new Rook(1, 0, 4);


			Figure* bishop_w = new Bishop(1, 2, 2);

			std::list <Figure*> figures{ rook_l_b, rook_r_w, bishop_w };
			my_board.set_starting_postions(figures);

			std::list<std::vector<int>> free_pos = my_board.get_free_positions_for_figure(bishop_w);
			free_pos.sort();

			std::vector<int> pos1 = { 0,0 };
			std::vector<int> pos2 = { 1,1 };
			std::vector<int> pos3 = { 3,1 };
			std::vector<int> pos4 = { 4,0 };
			std::vector<int> pos5 = { 1,3 };
			std::vector<int> pos6 = { 3,3 };
			std::vector<int> pos7 = { 4,4 };
			std::vector<int> pos8 = { 5,5 };

			std::list<std::vector<int>> certain_positions{ pos1,pos2,pos3,pos4,pos5,pos6,pos7,pos8 };
			certain_positions.sort();

			Assert::IsTrue(certain_positions == free_pos);
		}


		TEST_METHOD(Get_free_positions_king)
		{
			Board my_board;
			Figure* rook_l_b = new Rook(0, 3, 1); // przeciwny kolor
			Figure* knight_l_b = new Knight(0, 3, 2); //przeciwny kolor
			Figure* rook_r_w = new Rook(1, 1, 2);



			Figure* king_w = new King(1, 2, 2);

			std::list <Figure*> figures{ rook_l_b, rook_r_w, king_w };
			my_board.set_starting_postions(figures);

			std::list<std::vector<int>> free_pos = my_board.get_free_positions_for_figure(king_w);
			free_pos.sort();

			std::vector<int> pos1 = { 2,1 };
			std::vector<int> pos2 = { 1,1 };
			std::vector<int> pos3 = { 3,1 };
			std::vector<int> pos4 = { 3,2 };
			std::vector<int> pos5 = { 3,3 };
			std::vector<int> pos6 = { 2,3 };
			std::vector<int> pos7 = { 1,3 };
			

			std::list<std::vector<int>> certain_positions{ pos1,pos2,pos3,pos4,pos5,pos6,pos7};
			certain_positions.sort();

			Assert::IsTrue(certain_positions == free_pos);

		}

		TEST_METHOD(Get_free_positions_pawn_firts_move)
		{
			Board my_board;
			
			Figure* rook_r_b = new Rook(0, 2, 5);
			Figure* pawn_w = new Pawn(1, 2, 6);

			std::list <Figure*> figures{rook_r_b, pawn_w};
			my_board.set_starting_postions(figures);

			std::list<std::vector<int>> free_pos = my_board.get_free_positions_for_figure(pawn_w);
			free_pos.sort();

			std::list<std::vector<int>> certain_positions{};
			certain_positions.sort();

			Assert::IsTrue(certain_positions == free_pos);
		}

		TEST_METHOD(Get_free_positions_pawn)
		{
			Board my_board;

			Figure* rook_r_b = new Rook(0, 2, 5);
			Figure* pawn_w = new Pawn(1, 2, 6);

			std::list <Figure*> figures{ rook_r_b, pawn_w };
			my_board.set_starting_postions(figures);

			std::list<std::vector<int>> free_pos = my_board.get_free_positions_for_figure(pawn_w);
			free_pos.sort();

			std::list<std::vector<int>> certain_positions{};
			certain_positions.sort();

			Assert::IsTrue(certain_positions == free_pos);
		}


		TEST_METHOD(Get_free_positions_pawn_striking_positions)
		{
			Board my_board;

			Figure* rook_r_b = new Rook(0, 2, 5);
			Figure* rook_l_b = new Rook(0, 1, 5);
			Figure* pawn_w = new Pawn(1, 2, 6);

			std::list <Figure*> figures{ rook_r_b, pawn_w, rook_l_b };
			my_board.set_starting_postions(figures);

			std::list<std::vector<int>> free_pos = my_board.get_free_positions_for_figure(pawn_w);
			free_pos.sort();

			std::vector<int> pos1 = { 1,5 };

			std::list<std::vector<int>> certain_positions{pos1};
			certain_positions.sort();

			Assert::IsTrue(certain_positions == free_pos);
		}

		
		//TEST_METHOD(Get_figure)
		//{
		//	Board my_board;

		//	Figure* rook_r_b = new Rook(0, 2, 5);
		//	Figure* rook_l_b = new Rook(0, 1, 5);
		//	Figure* pawn_w = new Pawn(1, 2, 6);


		//	std::list <Figure*> figures{ rook_r_b, pawn_w, rook_l_b };
		//	my_board.set_starting_postions(figures);
		//	
		//	auto my_figure = my_board.get_figure(2, 5);
		//	
		//	Assert::IsTrue(typeid(my_figure) == typeid(rook_l_b));
		//}




		//////////////////////////////////////////get positions behind ///////////////////////////////
		

		TEST_METHOD(Get_positions_behind_up)
		{
			Board my_board;
			std::vector<int> base = { 2,6 };
			std::vector<int> blocking = { 2,4 };
		 	
			auto positions = my_board.get_positions_behind(base, blocking);
			positions.sort();

			std::vector<int> pos1 = { 2,3 };
			std::vector<int> pos2 = { 2,2 };
			std::vector<int> pos3 = { 2,1 };
			std::vector<int> pos4 = { 2,0 };

			std::list<std::vector<int>> certain_positions{ pos1,pos2,pos3,pos4};
			certain_positions.sort();

			Assert::IsTrue(certain_positions == positions);
		}

		TEST_METHOD(Get_positions_behind_down)
		{
			Board my_board;
			std::vector<int> base = { 2,1 };
			std::vector<int> blocking = { 2,3 };

			auto positions = my_board.get_positions_behind(base, blocking);
			positions.sort();

			std::vector<int> pos1 = { 2,4 };
			std::vector<int> pos2 = { 2,5 };
			std::vector<int> pos3 = { 2,6 };
			std::vector<int> pos4 = { 2,7 };

			std::list<std::vector<int>> certain_positions{ pos1,pos2,pos3,pos4 };
			certain_positions.sort();

			Assert::IsTrue(certain_positions == positions);
		}

		TEST_METHOD(Get_positions_behind_right)
		{
			Board my_board;
			std::vector<int> base = { 1,3 };
			std::vector<int> blocking = { 3,3 };

			auto positions = my_board.get_positions_behind(base, blocking);
			positions.sort();

			std::vector<int> pos1 = { 4,3 };
			std::vector<int> pos2 = { 5,3 };
			std::vector<int> pos3 = { 6,3 };
			std::vector<int> pos4 = { 7,3 };

			std::list<std::vector<int>> certain_positions{ pos1,pos2,pos3,pos4 };
			certain_positions.sort();

			Assert::IsTrue(certain_positions == positions);
		}

		TEST_METHOD(Get_positions_behind_left)
		{
			Board my_board;
			std::vector<int> base = { 6,3 };
			std::vector<int> blocking = { 4,3 };

			auto positions = my_board.get_positions_behind(base, blocking);
			positions.sort();

			std::vector<int> pos1 = { 3,3 };
			std::vector<int> pos2 = { 2,3 };
			std::vector<int> pos3 = { 1,3 };
			std::vector<int> pos4 = { 0,3 };

			std::list<std::vector<int>> certain_positions{ pos1,pos2,pos3,pos4 };
			certain_positions.sort();

			Assert::IsTrue(certain_positions == positions);
		}

		TEST_METHOD(Get_positions_behind_left_up)
		{
			Board my_board;
			std::vector<int> base = { 5,6 };
			std::vector<int> blocking = { 3,4 };

			auto positions = my_board.get_positions_behind(base, blocking);
			positions.sort();

			std::vector<int> pos1 = { 2,3 };
			std::vector<int> pos2 = { 1,2 };
			std::vector<int> pos3 = { 0,1 };

			std::list<std::vector<int>> certain_positions{ pos1,pos2,pos3 };
			certain_positions.sort();

			Assert::IsTrue(certain_positions == positions);
		}

		TEST_METHOD(Get_positions_behind_right_up)
		{
			Board my_board;
			std::vector<int> base = { 0,5 };
			std::vector<int> blocking = { 2,3 };

			auto positions = my_board.get_positions_behind(base, blocking);
			positions.sort();

			std::vector<int> pos1 = { 3,2 };
			std::vector<int> pos2 = { 4,1 };
			std::vector<int> pos3 = { 5,0 };

			std::list<std::vector<int>> certain_positions{ pos1,pos2,pos3 };
			certain_positions.sort();

			Assert::IsTrue(certain_positions == positions);
		}

		TEST_METHOD(Get_positions_behind_left_down)
		{
			Board my_board;
			std::vector<int> base = { 5,1 };
			std::vector<int> blocking = { 3,3 };

			auto positions = my_board.get_positions_behind(base, blocking);
			positions.sort();

			std::vector<int> pos1 = { 2,4 };
			std::vector<int> pos2 = { 1,5 };
			std::vector<int> pos3 = { 0,6 };

			std::list<std::vector<int>> certain_positions{ pos1,pos2,pos3 };
			certain_positions.sort();

			Assert::IsTrue(certain_positions == positions);
		}

		TEST_METHOD(Get_positions_behind_right_down)
		{
			Board my_board;
			std::vector<int> base = { 1,1 };
			std::vector<int> blocking = { 4,3 };

			auto positions = my_board.get_positions_behind(base, blocking);
			positions.sort();

			std::vector<int> pos1 = { 5,4 };
			std::vector<int> pos2 = { 6,5 };
			std::vector<int> pos3 = { 7,6 };

			std::list<std::vector<int>> certain_positions{ pos1,pos2,pos3 };
			certain_positions.sort();

			Assert::IsTrue(certain_positions == positions);
		}

	};
}
