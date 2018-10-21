#include <iostream>
#include "Board.hpp"
#include "BoardDrawer.hpp"
#include "MoveGenerator.hpp"

int main() 
{
	Board board{};
	BoardDrawer drawer{ board };
	MoveGenerator generator{ board };
	auto moves = generator.GetMoves();

	drawer.DrawBoard();

	std::getchar();

	return 0;
}