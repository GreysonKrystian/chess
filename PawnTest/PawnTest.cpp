//#include "../Chess/pawn.h"
//#include "CppUnitTest.h"
//#include <vector>
//#include <list>
//
//using namespace Microsoft::VisualStudio::CppUnitTestFramework;
//
//namespace PawnTest
//{
//	TEST_CLASS(PawnTest)
//	{
//	public:
//		
//		TEST_METHOD(Pawn_get_possible_positions_white_first_move)
//		{
//			Pawn pion(1, 2, 6);
//
//			std::vector<int> pos1 = { 2,5 };
//			std::vector<int> pos2 = { 2,4 };
//			std::list<std::vector<int>> certain_positions;
//			certain_positions.push_back(pos1);
//			certain_positions.push_back(pos2);
//
//			std::list<std::vector<int>> positions = pion.get_possible_positions();
//			positions.sort();
//			certain_positions.sort();
//
//			Assert::IsTrue(positions == certain_positions);
//		}
//
//		TEST_METHOD(Pawn_get_possible_positions_black_first_move)
//		{
//			Pawn pion(0, 2, 1);
//
//			std::vector<int> pos1 = { 2,2 };
//			std::vector<int> pos2 = { 2,3 };
//			std::list<std::vector<int>> certain_positions;
//			certain_positions.push_back(pos1);
//			certain_positions.push_back(pos2);
//
//			std::list<std::vector<int>> positions = pion.get_possible_positions();
//			positions.sort();
//			certain_positions.sort();
//
//			Assert::IsTrue(positions == certain_positions);
//		}
//
//		TEST_METHOD(Pawn_get_possible_positions_white_standard_move)
//		{
//			Pawn pion(1, 2, 6);
//
//			std::vector<int> pos1 = { 2,5 };
//			std::list<std::vector<int>> certain_positions;
//			certain_positions.push_back(pos1);
//
//			pion.change_first_move_status();
//			std::list<std::vector<int>> positions = pion.get_possible_positions();
//			positions.sort();
//			certain_positions.sort();
//
//			Assert::IsTrue(positions == certain_positions);
//		}
//
//		TEST_METHOD(Pawn_get_possible_positions_black_standard_move)
//		{
//			Pawn pion(0, 2, 1);
//			std::vector<int> pos1 = { 2,2 };
//			std::list<std::vector<int>> certain_positions;
//			certain_positions.push_back(pos1);
//
//			pion.change_first_move_status();
//			std::list<std::vector<int>> positions = pion.get_possible_positions();
//			positions.sort();
//			certain_positions.sort();
//
//			Assert::IsTrue(positions == certain_positions);
//		}
//
//		TEST_METHOD(Pawn_get_strike_positions_black)
//		{
//			Pawn pion(0, 2, 1);
//			std::vector<int> pos1 = { 1,2 };
//			std::vector<int> pos2 = { 3,2 };
//
//			std::list<std::vector<int>> certain_positions;
//			certain_positions.push_back(pos1);
//			certain_positions.push_back(pos2);
//
//			pion.change_first_move_status();
//			std::list<std::vector<int>> positions = pion.get_strike_positions();
//			positions.sort();
//			certain_positions.sort();
//
//			Assert::IsTrue(positions == certain_positions);
//		}
//
//		TEST_METHOD(Pawn_get_strike_positions_white)
//		{
//			Pawn pion(1, 2, 6);
//			std::vector<int> pos1 = { 1,5 };
//			std::vector<int> pos2 = { 3,5 };
//
//			std::list<std::vector<int>> certain_positions;
//			certain_positions.push_back(pos1);
//			certain_positions.push_back(pos2);
//
//			pion.change_first_move_status();
//			std::list<std::vector<int>> positions = pion.get_strike_positions();
//			positions.sort();
//			certain_positions.sort();
//
//			Assert::IsTrue(positions == certain_positions);
//		}
//
//		TEST_METHOD(Pawn_get_strike_positions_black_left_top_corner)
//		{
//			Pawn pion(0, 0, 0);
//			std::vector<int> pos1 = { 1,1 };
//
//			std::list<std::vector<int>> certain_positions;
//			certain_positions.push_back(pos1);
//
//			pion.change_first_move_status();
//			std::list<std::vector<int>> positions = pion.get_strike_positions();
//			positions.sort();
//			certain_positions.sort();
//
//			Assert::IsTrue(positions == certain_positions);
//		}
//
//		TEST_METHOD(Pawn_get_strike_positions_black_right_top_corner)
//		{
//			Pawn pion(0, 7, 0);
//			std::vector<int> pos1 = { 6,1 };
//
//			std::list<std::vector<int>> certain_positions;
//			certain_positions.push_back(pos1);
//
//			pion.change_first_move_status();
//			std::list<std::vector<int>> positions = pion.get_strike_positions();
//			positions.sort();
//			certain_positions.sort();
//
//			Assert::IsTrue(positions == certain_positions);
//		}
//
//		TEST_METHOD(Pawn_get_strike_positions_white_left_bottom_corner)
//		{
//			Pawn pion(1, 0, 7);
//			std::vector<int> pos1 = { 1,6 };
//
//			std::list<std::vector<int>> certain_positions;
//			certain_positions.push_back(pos1);
//
//			pion.change_first_move_status();
//			std::list<std::vector<int>> positions = pion.get_strike_positions();
//			positions.sort();
//			certain_positions.sort();
//
//			Assert::IsTrue(positions == certain_positions);
//		}
//
//		TEST_METHOD(Pawn_get_strike_positions_white_right_bottom_corner)
//		{
//			Pawn pion(1, 7, 7);
//			std::vector<int> pos1 = { 6,6 };
//
//			std::list<std::vector<int>> certain_positions;
//			certain_positions.push_back(pos1);
//
//			pion.change_first_move_status();
//			std::list<std::vector<int>> positions = pion.get_strike_positions();
//			positions.sort();
//			certain_positions.sort();
//
//			Assert::IsTrue(positions == certain_positions);
//		}
//	};
//}
