#include "../Chess/bishop.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestBishop
{
	TEST_CLASS(TestBishop)
	{
	public:
		
		TEST_METHOD(TestBishopAllPossibleMovesMiddle)
		{
			Bishop bishop(0, 5, 5);
			std::list<std::vector<int>> positions = bishop.get_possible_positions();
			positions.sort();
			std::list<std::vector<int>> expected = { {1,1},{2,2},{2,8},{3,3},{3,7},{4,4},{4,6},{6,4},{6,6},{7,3},{7,7},{8,2},{8,8} };
			Assert::IsTrue(positions == expected);
		}
		TEST_METHOD(TestBishopAllPossibleMovesBottomRightCorner)
		{
			Bishop bishop(0, 8, 8);
			std::list<std::vector<int>> positions = bishop.get_possible_positions();
			positions.sort();
			std::list<std::vector<int>> expected = { {1,1},{2,2},{3,3},{4,4},{5,5},{6,6},{7,7} };
			Assert::IsTrue(positions == expected);
		}
		TEST_METHOD(TestBishopAllPossibleMovesTopLeftCorner)
		{
			Bishop bishop(0, 1, 1);
			std::list<std::vector<int>> positions = bishop.get_possible_positions();
			positions.sort();
			std::list<std::vector<int>> expected = { {2,2},{3,3},{4,4},{5,5},{6,6},{7,7},{8,8} };
			Assert::IsTrue(positions == expected);
		}
		TEST_METHOD(TestBishopPossibleMovesBottomLeftCorner)
		{
			Bishop bishop(0, 1, 8);
			std::list<std::vector<int>> positions = bishop.get_possible_positions();
			positions.sort();
			std::list<std::vector<int>> expected = { {2,7},{3,6},{4,5},{5,4},{6,3},{7,2},{8,1} };
			Assert::IsTrue(positions == expected);
		}
	};
}
