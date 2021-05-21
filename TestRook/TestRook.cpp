#include "CppUnitTest.h"
#include "../Chess/rook.h"



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(bottom_left_corner)
		{
			Rook wieza(1, 0, 0);
			std::list<std::vector<int>> pos = wieza.get_possible_positions();
			pos.sort();
			std::list<std::vector<int>> expected_pos = { {0,1},{0,2},{0,3},{0,4},{0,5},{0,6},{0,7},{1,0},{2,0},{3,0},{4,0},{5,0},{6,0},{7,0} };
			Assert::IsTrue(pos == expected_pos);
		}

		TEST_METHOD(bottom_right_corner)
		{
			Rook wieza(1, 8, 1);
			std::list<std::vector<int>> pos = wieza.get_possible_positions();
			pos.sort();
			std::list<std::vector<int>> expected_pos = { {0,0},{1,0},{2,0},{3,0},{4,0},{5,0},{6,0},{7,1},{7,2},{7,3},{7,4},{7,5},{7,6},{7,7} };
			Assert::IsTrue(pos == expected_pos);
		}

		TEST_METHOD(upper_left_corner)
		{
			Rook wieza(1, 1, 8);
			std::list<std::vector<int>> pos = wieza.get_possible_positions();
			pos.sort();
			std::list<std::vector<int>> expected_pos = { {1,1},{1,2},{1,3},{1,4},{1,5},{1,6},{1,7},{2,8},{3,8},{4,8},{5,8},{6,8},{7,8},{8,8} };
			Assert::IsTrue(pos == expected_pos);
		}

		TEST_METHOD(upper_right_corner)
		{
			Rook wieza(1, 8, 8);
			std::list<std::vector<int>> pos = wieza.get_possible_positions();
			pos.sort();
			std::list<std::vector<int>> expected_pos = { {1,8},{2,8},{3,8},{4,8},{5,8},{6,8},{7,8},{8,1},{8,2},{8,3},{8,4},{8,5},{8,6},{8,7} };
			Assert::IsTrue(pos == expected_pos);
		}

		TEST_METHOD(center)
		{
			Rook wieza(1, 4, 5);
			std::list<std::vector<int>> pos = wieza.get_possible_positions();
			pos.sort();
			std::list<std::vector<int>> expected_pos = { {5,5},{3,5},{4,6},{4,4},{6,5},{2,5},{4,7},{4,3},{7,5},{1,5},{4,8},{4,2},{8,5},{4,1} };
			expected_pos.sort();
			Assert::IsTrue(pos == expected_pos);
		}
	};
}
