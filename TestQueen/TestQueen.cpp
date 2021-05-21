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
			Queen hetman(1, 1, 1);
			std::list<std::vector<int>> pos = hetman.get_possible_positions();
			pos.sort();
			std::list<std::vector<int>> expected_pos = { {1,2},{1,3},{1,4},{1,5},{1,6},{1,7},{1,8},{2,1},{3,1},{4,1},{5,1},{6,1},{7,1},{8,1},{2,2},{3,3},{4,4},{5,5},{6,6},{7,7},{8,8} };
			expected_pos.sort();
			Assert::IsTrue(pos == expected_pos);
		}		
		
		TEST_METHOD(upper_right_corner)
		{
			Queen hetman(1, 8, 8);
			std::list<std::vector<int>> pos = hetman.get_possible_positions();
			pos.sort();
			std::list<std::vector<int>> expected_pos = { {1,8},{2,8},{3,8},{4,8},{5,8},{6,8},{7,8},{8,1},{8,2},{8,3},{8,4},{8,5},{8,6},{8,7},{1,1},{2,2},{3,3},{4,4},{5,5},{6,6},{7,7} };
			expected_pos.sort();
			Assert::IsTrue(pos == expected_pos);
		}

		TEST_METHOD(center)
		{
			Queen hetman(1, 4, 5);
			std::list<std::vector<int>> pos = hetman.get_possible_positions();
			pos.sort();
			std::list<std::vector<int>> expected_pos = { {5,5},{3,5},{4,6},{4,4},{6,5},{2,5},{4,7},{4,3},{7,5},{1,5},{4,8},{4,2},{8,5},{4,1},{1,2},{2,3},{3,4},{5,4},{6,3},{7,2},{8,1},{3,6},{2,7},{1,8},{5,6},{6,7},{7,8} };
			expected_pos.sort();
			Assert::IsTrue(pos == expected_pos);
		}

	};
}

