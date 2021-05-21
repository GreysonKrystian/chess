#include "CppUnitTest.h"
#include "../Chess/king.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestKing
{
	TEST_CLASS(TestKing)
	{
	public:
		
		TEST_METHOD(TestKingAllPossibleMovesMiddle)
		{
			King king(0,5,5);
			std::list<std::vector<int>> positions = king.get_possible_positions();
			positions.sort();
			std::list<std::vector<int>> expected = { {4,4},{4,5},{4,6},{5,4},{5,6},{6,4},{6,5},{6,6} };
			Assert::IsTrue(positions == expected);
		}
		TEST_METHOD(TestKingAllPossibleMovesBottomCorner)
		{
			King king(0, 8, 8);
			std::list<std::vector<int>> positions = king.get_possible_positions();
			positions.sort();
			std::list<std::vector<int>> expected = { {7,7},{7,8},{8,7} };
			Assert::IsTrue(positions == expected);
		}
		TEST_METHOD(TestKingAllPossibleMovesTopCorner)
		{
			King king(0, 1, 1);
			std::list<std::vector<int>> positions = king.get_possible_positions();
			positions.sort();
			std::list<std::vector<int>> expected = { {1,2},{2,1},{2,2} };
			Assert::IsTrue(positions == expected);
		}
	};
}
