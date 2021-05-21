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
			King king(0,4,4);
			std::list<std::vector<int>> positions = king.get_possible_positions();
			positions.sort();
			std::list<std::vector<int>> expected = { {3,3},{3,4},{3,5},{4,3},{4,5},{5,3},{5,4},{5,5} };
			Assert::IsTrue(positions == expected);
		}
		TEST_METHOD(TestKingAllPossibleMovesBottomCorner)
		{
			King king(0, 7, 7);
			std::list<std::vector<int>> positions = king.get_possible_positions();
			positions.sort();
			std::list<std::vector<int>> expected = { {6,6},{6,7},{7,6} };
			Assert::IsTrue(positions == expected);
		}
		TEST_METHOD(TestKingAllPossibleMovesTopCorner)
		{
			King king(0, 0, 0);
			std::list<std::vector<int>> positions = king.get_possible_positions();
			positions.sort();
			std::list<std::vector<int>> expected = { {0,1},{1,0},{1,1} };
			Assert::IsTrue(positions == expected);
		}
	};
}
