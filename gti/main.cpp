#include "PositionStringParser.hpp"
#include <iostream>
#include "Board.hpp"
#include "BoardDrawer.hpp"
#include "MoveGenerator.hpp"
#include "Utils.hpp"
#include <chrono>

int main()
{
	void PrintBoard();
	void RunTest();

	PrintBoard();

	return 0;
}

void PrintBoard()
{
	Board board{};
	BoardDrawer drawer{ board };

	drawer.DrawBoard();

	std::getchar();
}

void RunTest()
{
	PositionStringParser parser;
	Board board = parser.ParsePositionString(PositionStringParser::INITIAL_STRING);
	auto start = std::chrono::high_resolution_clock::now();

	for (size_t i = 0; i < 1000; i++)
	{
		MoveGenerator generator{ board };
		auto moves = generator.GetMoves();
	}

	auto diff = std::chrono::high_resolution_clock::now() - start;
	auto time = std::chrono::duration_cast<std::chrono::milliseconds>(diff);

	std::cout << time.count() << std::endl;

	std::getchar();
}