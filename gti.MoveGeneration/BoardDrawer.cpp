#include <iostream>
#include <windows.h>

#include "BoardDrawer.hpp"

BoardDrawer::BoardDrawer(const Board& board) :
	board(board)
{
}

void BoardDrawer::DrawBoard() const
{
	DrawRed();
}

void BoardDrawer::DrawRed() const
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD redColor = 4;

	SetConsoleTextAttribute(hConsole, redColor);

	auto redPawns = board.getRedPawns();

	for (size_t i = 0; i < board.TOTAL_SQUARES; i++)
	{
		if (i % board.SQUARES_PER_SIDE == 0)
		{
			std::cout << std::endl;
		}

		if (((redPawns >> i) & 1) == 1) 
		{
			std::cout << "p\t";
		}
		else {
			std::cout << i << "\t";
		}
	}
}
