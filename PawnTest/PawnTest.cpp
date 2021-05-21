#include "../Chess/pawn.h"
#include "CppUnitTest.h"
#include <vector>
#include <list>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PawnTest
{
	TEST_CLASS(PawnTest)
	{
	public:
		
		TEST_METHOD(Pawn_get_possible_positions_white_first_move)
		{
			Pawn pion(1, 3, 7);

			std::vector<int> pos1 = { 3,6 };
			std::vector<int> pos2 = { 3,5 };
			std::list<std::vector<int>> certain_positions;
			certain_positions.push_back(pos1);
			certain_positions.push_back(pos2);

			std::list<std::vector<int>> positions = pion.get_possible_positions();
			positions.sort();
			certain_positions.sort();

			Assert::IsTrue(positions == certain_positions);
		}

		TEST_METHOD(Pawn_get_possible_positions_black_first_move)
		{
			Pawn pion(0, 3, 2);

			std::vector<int> pos1 = { 3,3 };
			std::vector<int> pos2 = { 3,4 };
			std::list<std::vector<int>> certain_positions;
			certain_positions.push_back(pos1);
			certain_positions.push_back(pos2);

			std::list<std::vector<int>> positions = pion.get_possible_positions();
			positions.sort();
			certain_positions.sort();

			Assert::IsTrue(positions == certain_positions);
		}

		TEST_METHOD(Pawn_get_possible_positions_white_standard_move)
		{
			Pawn pion(1, 3, 7);

			std::vector<int> pos1 = { 3,6 };
			std::list<std::vector<int>> certain_positions;
			certain_positions.push_back(pos1);

			pion.change_first_move_status();
			std::list<std::vector<int>> positions = pion.get_possible_positions();
			positions.sort();
			certain_positions.sort();

			Assert::IsTrue(positions == certain_positions);
		}

		TEST_METHOD(Pawn_get_possible_positions_black_standard_move)
		{
			Pawn pion(0, 3, 2);
			std::vector<int> pos1 = { 3,3 };
			std::list<std::vector<int>> certain_positions;
			certain_positions.push_back(pos1);

			pion.change_first_move_status();
			std::list<std::vector<int>> positions = pion.get_possible_positions();
			positions.sort();
			certain_positions.sort();

			Assert::IsTrue(positions == certain_positions);
		}

		TEST_METHOD(Pawn_get_strike_positions_black)
		{
			Pawn pion(0, 3, 2);
			std::vector<int> pos1 = { 2,3 };
			std::vector<int> pos2 = { 4,3 };

			std::list<std::vector<int>> certain_positions;
			certain_positions.push_back(pos1);
			certain_positions.push_back(pos2);

			pion.change_first_move_status();
			std::list<std::vector<int>> positions = pion.get_strike_positions();
			positions.sort();
			certain_positions.sort();

			Assert::IsTrue(positions == certain_positions);
		}

		TEST_METHOD(Pawn_get_strike_positions_white)
		{
			Pawn pion(1, 3, 7);
			std::vector<int> pos1 = { 2,6 };
			std::vector<int> pos2 = { 4,6 };

			std::list<std::vector<int>> certain_positions;
			certain_positions.push_back(pos1);
			certain_positions.push_back(pos2);

			pion.change_first_move_status();
			std::list<std::vector<int>> positions = pion.get_strike_positions();
			positions.sort();
			certain_positions.sort();

			Assert::IsTrue(positions == certain_positions);
		}

		TEST_METHOD(Pawn_get_strike_positions_black_left_top_corner)
		{
			Pawn pion(0, 1, 1);
			std::vector<int> pos1 = { 2,2 };

			std::list<std::vector<int>> certain_positions;
			certain_positions.push_back(pos1);

			pion.change_first_move_status();
			std::list<std::vector<int>> positions = pion.get_strike_positions();
			positions.sort();
			certain_positions.sort();

			Assert::IsTrue(positions == certain_positions);
		}

		TEST_METHOD(Pawn_get_strike_positions_black_right_top_corner)
		{
			Pawn pion(0, 8, 1);
			std::vector<int> pos1 = { 7,2 };

			std::list<std::vector<int>> certain_positions;
			certain_positions.push_back(pos1);

			pion.change_first_move_status();
			std::list<std::vector<int>> positions = pion.get_strike_positions();
			positions.sort();
			certain_positions.sort();

			Assert::IsTrue(positions == certain_positions);
		}

		TEST_METHOD(Pawn_get_strike_positions_white_left_bottom_corner)
		{
			Pawn pion(1, 1, 8);
			std::vector<int> pos1 = { 2,7 };

			std::list<std::vector<int>> certain_positions;
			certain_positions.push_back(pos1);

			pion.change_first_move_status();
			std::list<std::vector<int>> positions = pion.get_strike_positions();
			positions.sort();
			certain_positions.sort();

			Assert::IsTrue(positions == certain_positions);
		}

		TEST_METHOD(Pawn_get_strike_positions_white_right_bottom_corner)
		{
			Pawn pion(1, 8, 8);
			std::vector<int> pos1 = { 7,7 };

			std::list<std::vector<int>> certain_positions;
			certain_positions.push_back(pos1);

			pion.change_first_move_status();
			std::list<std::vector<int>> positions = pion.get_strike_positions();
			positions.sort();
			certain_positions.sort();

			Assert::IsTrue(positions == certain_positions);
		}
	};
}
