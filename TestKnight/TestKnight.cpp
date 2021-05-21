#include "CppUnitTest.h"
#include "../Chess/knight.h"
#include <vector>
#include <list>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestFigures
{
	TEST_CLASS(UnitTestFigures)
	{
	public:

		TEST_METHOD(Knight_get_possible_positions_center)
		{
			Knight kon(1, 5, 4);
			std::vector<int> pos1 = { 6,2 };
			std::vector<int> pos2 = { 7,3 };
			std::vector<int> pos3 = { 7,5 };
			std::vector<int> pos4 = { 6,6 };
			std::vector<int> pos5 = { 4,6 };
			std::vector<int> pos6 = { 3,5 };
			std::vector<int> pos7 = { 3,3 };
			std::vector<int> pos8 = { 4,2 };

			std::list<std::vector<int>> certain_positions;
			certain_positions.push_back(pos1);
			certain_positions.push_back(pos2);
			certain_positions.push_back(pos3);
			certain_positions.push_back(pos4);
			certain_positions.push_back(pos5);
			certain_positions.push_back(pos6);
			certain_positions.push_back(pos7);
			certain_positions.push_back(pos8);

			std::list<std::vector<int>> positions = kon.get_possible_positions();
			positions.sort();
			certain_positions.sort();



			Assert::IsTrue(positions == certain_positions);
		}


		TEST_METHOD(Knight_get_possible_positions_left_top_corner)
		{
			Knight kon(1, 1, 1);
			std::vector<int> pos1 = { 3,2 };
			std::vector<int> pos2 = { 2,3 };

			std::list<std::vector<int>> certain_positions;
			certain_positions.push_back(pos1);
			certain_positions.push_back(pos2);

			std::list<std::vector<int>> positions = kon.get_possible_positions();
			positions.sort();
			certain_positions.sort();

			Assert::IsTrue(positions == certain_positions);
		}


		TEST_METHOD(Knight_get_possible_positions_right_top_corner)
		{
			Knight kon(1, 8, 1);
			std::vector<int> pos1 = { 6,2 };
			std::vector<int> pos2 = { 7,3 };

			std::list<std::vector<int>> certain_positions;
			certain_positions.push_back(pos1);
			certain_positions.push_back(pos2);

			std::list<std::vector<int>> positions = kon.get_possible_positions();
			positions.sort();
			certain_positions.sort();

			Assert::IsTrue(positions == certain_positions);
		}


		TEST_METHOD(Knight_get_possible_positions_left_bottom_corner)
		{
			Knight kon(1, 1, 8);
			std::vector<int> pos1 = { 2,6 };
			std::vector<int> pos2 = { 3,7 };

			std::list<std::vector<int>> certain_positions;
			certain_positions.push_back(pos1);
			certain_positions.push_back(pos2);

			std::list<std::vector<int>> positions = kon.get_possible_positions();
			positions.sort();
			certain_positions.sort();

			Assert::IsTrue(positions == certain_positions);
		}

		TEST_METHOD(Knight_get_possible_positions_right_bottom_corner)
		{
			Knight kon(1, 8, 8);
			std::vector<int> pos1 = { 7,6 };
			std::vector<int> pos2 = { 6,7 };

			std::list<std::vector<int>> certain_positions;
			certain_positions.push_back(pos1);
			certain_positions.push_back(pos2);

			std::list<std::vector<int>> positions = kon.get_possible_positions();
			positions.sort();
			certain_positions.sort();

			Assert::IsTrue(positions == certain_positions);
		}
	};
}