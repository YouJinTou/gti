#include <iostream>
#include "Board.hpp"
#include "BoardDrawer.hpp"
#include "MoveGenerator.hpp"
#include "Utils.hpp"

int main() 
{
	Board board{};
	Utils::PrintBinary(board.GetEmptySquares());
	/*BoardDrawer drawer{ board };
	MoveGenerator generator{ board };
	auto moves = generator.GetMoves();

	drawer.DrawBoard();*/

	std::getchar();

	return 0;
}