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
			Bishop bishop(0, 4, 4);
			std::list<std::vector<int>> positions = bishop.get_possible_positions();
			positions.sort();
			std::list<std::vector<int>> expected = { {0,0},{1,1},{1,7},{2,2},{2,6},{3,3},{3,5},{5,3},{5,5},{6,2},{6,6},{7,1},{7,7} };
			Assert::IsTrue(positions == expected);
		}
		TEST_METHOD(TestBishopAllPossibleMovesBottomRightCorner)
		{
			Bishop bishop(0, 7, 7);
			std::list<std::vector<int>> positions = bishop.get_possible_positions();
			positions.sort();
			std::list<std::vector<int>> expected = { {0,0},{1,1},{2,2},{3,3},{4,4},{5,5},{6,6} };
			Assert::IsTrue(positions == expected);
		}
		TEST_METHOD(TestBishopAllPossibleMovesTopLeftCorner)
		{
			Bishop bishop(0, 0, 0);
			std::list<std::vector<int>> positions = bishop.get_possible_positions();
			positions.sort();
			std::list<std::vector<int>> expected = { {1,1},{2,2},{3,3},{4,4},{5,5},{6,6},{7,7} };
			Assert::IsTrue(positions == expected);
		}
		TEST_METHOD(TestBishopPossibleMovesBottomLeftCorner)
		{
			Bishop bishop(0, 0, 7);
			std::list<std::vector<int>> positions = bishop.get_possible_positions();
			positions.sort();
			std::list<std::vector<int>> expected = { {1,6},{2,5},{3,4},{4,3},{5,2},{6,1},{7,0} };
			Assert::IsTrue(positions == expected);
		}
	};
}
