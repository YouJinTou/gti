#include <iostream>
#include <windows.h>

#include "BoardDrawer.hpp"

BoardDrawer::BoardDrawer(const Board& board) :
	board(board)
{
}

void BoardDrawer::DrawBoard() const
{
	auto rPawns = board.getRedPawns();
	auto rKnights = board.getRedKnights();
	auto rBishops = board.getRedBishops();
	auto rRooks = board.getRedRooks();
	auto rQueens = board.getRedQueens();
	auto rKing = board.getRedKing();
	WORD red = 4;
	auto bPawns = board.getBluePawns();
	auto bKnights = board.getBlueKnights();
	auto bBishops = board.getBlueBishops();
	auto bRooks = board.getBlueRooks();
	auto bQueens = board.getBlueQueens();
	auto bKing = board.getBlueKing();
	WORD blue = 1;
	auto yPawns = board.getYellowPawns();
	auto yKnights = board.getYellowKnights();
	auto yBishops = board.getYellowBishops();
	auto yRooks = board.getYellowRooks();
	auto yQueens = board.getYellowQueens();
	auto yKing = board.getYellowKing();
	WORD yellow = 4;
	auto gPawns = board.getGreenPawns();
	auto gKnights = board.getGreenKnights();
	auto gBishops = board.getGreenBishops();
	auto gRooks = board.getGreenRooks();
	auto gQueens = board.getGreenQueens();
	auto gKing = board.getGreenKing();
	WORD green = 2;
	WORD white = 15;

	for (size_t i = 0; i < board.TOTAL_SQUARES; i++)
	{
		if (i % board.SQUARES_PER_SIDE == 0)
		{
			std::cout << "\n\n";
		}

		bool squareDrawn =
			TryDrawSquare(i, red, rPawns, rKnights, rBishops, rRooks, rQueens, rKing) ||
			TryDrawSquare(i, blue, bPawns, bKnights, bBishops, bRooks, bQueens, bKing) ||
			TryDrawSquare(i, yellow, yPawns, yKnights, yBishops, yRooks, yQueens, yKing) ||
			TryDrawSquare(i, green, gPawns, gKnights, gBishops, gRooks, gQueens, yKing);

		if (!squareDrawn)
		{
			SetColor(white);

			std::cout << i << "\t";
		}
	}
}

void BoardDrawer::SetColor(WORD color) const
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, color);
}

bool BoardDrawer::TryDrawSquare(
	size_t i,
	WORD color,
	I256 pawns, 
	I256 knights, 
	I256 bishops, 
	I256 rooks, 
	I256 queens, 
	I256 king) const
{
	SetColor(color);

	auto mask = I256{ 1 } << i;

	if ((mask & pawns) == mask)
	{
		std::cout << "P\t";

		return true;
	}
	else if ((mask & knights) == mask) {
		std::cout << "N\t";

		return true;
	}
	else if ((mask & bishops) == mask) {
		std::cout << "B\t";

		return true;
	}
	else if ((mask & rooks) == mask) {
		std::cout << "R\t";

		return true;
	}
	else if ((mask & queens) == mask) {
		std::cout << "Q\t";

		return true;
	}
	else if ((mask & king) == mask) {
		std::cout << "K\t";

		return true;
	}

	return false;
}
