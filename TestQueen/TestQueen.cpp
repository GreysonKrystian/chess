#include "CppUnitTest.h"
#include "../Chess/queen.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
	TEST_CLASS(UnitTest2)
	{
	public:

		TEST_METHOD(bottom_left_corner)
		{
			Queen hetman(1, 0, 0);
			std::list<std::vector<int>> pos = hetman.get_possible_positions();
			pos.sort();
			std::list<std::vector<int>> expected_pos = { {0,1},{0,2},{0,3},{0,4},{0,5},{0,6},{0,7},{1,0},{2,0},{3,0},{4,0},{5,0},{6,0},{7,0},{1,1},{2,2},{3,3},{4,4},{5,5},{6,6},{7,7} };
			expected_pos.sort();
			Assert::IsTrue(pos == expected_pos);
		}		
		
		TEST_METHOD(upper_right_corner)
		{
			Queen hetman(1, 7, 7);
			std::list<std::vector<int>> pos = hetman.get_possible_positions();
			pos.sort();
			std::list<std::vector<int>> expected_pos = { {0,7},{1,7},{2,7},{3,7},{4,7},{5,7},{6,7},{7,0},{7,1},{7,2},{7,3},{7,4},{7,5},{7,6},{0,0},{1,1},{2,2},{3,3},{4,4},{5,5},{6,6} };
			expected_pos.sort();
			Assert::IsTrue(pos == expected_pos);
		}

		TEST_METHOD(center)
		{
			Queen hetman(1, 3, 4);
			std::list<std::vector<int>> pos = hetman.get_possible_positions();
			pos.sort();
			std::list<std::vector<int>> expected_pos = { {4,4},{2,4},{3,5},{3,3},{5,4},{1,4},{3,6},{3,2},{6,4},{0,4},{3,7},{3,1},{7,4},{3,0},{0,1},{1,2},{2,3},{4,3},{5,2},{6,1},{7,0},{2,5},{1,6},{0,7},{4,5},{5,6},{6,7} };
			expected_pos.sort();
			Assert::IsTrue(pos == expected_pos);
		}

	};
}

