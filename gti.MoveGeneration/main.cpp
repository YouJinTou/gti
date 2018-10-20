#include <iostream>
#include "Board.hpp"
#include "BoardDrawer.hpp"

int main() 
{
	Board board{};
	BoardDrawer bd{ board };

	board.GetNextPlayerMoves();

	bd.DrawBoard();

	std::getchar();

	return 0;
}