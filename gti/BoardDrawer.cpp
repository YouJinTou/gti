#include <iostream>
#include <stack>
#include <vector>
#include <windows.h>

#include "BoardDrawer.hpp"

BoardDrawer::BoardDrawer(const Board& board) :
	board{ board }
{
}

void BoardDrawer::DrawBoard() const
{
	auto rPawns = board.GetRedPawns();
	auto rKnights = board.GetRedKnights();
	auto rBishops = board.GetRedBishops();
	auto rRooks = board.GetRedRooks();
	auto rQueens = board.GetRedQueens();
	auto rKing = board.GetRedKing();
	auto bPawns = board.GetBluePawns();
	auto bKnights = board.GetBlueKnights();
	auto bBishops = board.GetBlueBishops();
	auto bRooks = board.GetBlueRooks();
	auto bQueens = board.GetBlueQueens();
	auto bKing = board.GetBlueKing();
	auto yPawns = board.GetYellowPawns();
	auto yKnights = board.GetYellowKnights();
	auto yBishops = board.GetYellowBishops();
	auto yRooks = board.GetYellowRooks();
	auto yQueens = board.GetYellowQueens();
	auto yKing = board.GetYellowKing();
	auto gPawns = board.GetGreenPawns();
	auto gKnights = board.GetGreenKnights();
	auto gBishops = board.GetGreenBishops();
	auto gRooks = board.GetGreenRooks();
	auto gQueens = board.GetGreenQueens();
	auto gKing = board.GetGreenKing();

	for (size_t i = 0; i < board.TOTAL_SQUARES; i++)
	{
		if (i % board.SQUARES_PER_SIDE == 0)
		{
			std::cout << std::endl;
		}

		bool squareDrawn =
			TryDrawPlayerSquare(i, RED, rPawns, rKnights, rBishops, rRooks, rQueens, rKing) ||
			TryDrawPlayerSquare(i, BLUE, bPawns, bKnights, bBishops, bRooks, bQueens, bKing) ||
			TryDrawPlayerSquare(i, YELLOW, yPawns, yKnights, yBishops, yRooks, yQueens, yKing) ||
			TryDrawPlayerSquare(i, GREEN, gPawns, gKnights, gBishops, gRooks, gQueens, gKing);

		if (!squareDrawn)
		{
			DrawEmptySquare(i);
		}
	}
}

void BoardDrawer::DrawBitboard(I256 bitboard) const // Starts from A1 (bottom-left)
{
	std::vector<std::stack<I256>> rows{};

	for (size_t i = 0; i < board.TOTAL_SQUARES; i++)
	{
		if (i % board.SQUARES_PER_SIDE == 0)
		{
			rows.push_back(std::stack<I256>{});
		}

		int currentRow = i / board.SQUARES_PER_SIDE;

		rows[currentRow].push(((bitboard >> i) & 1));
	}

	for (size_t i = 0; i < board.TOTAL_SQUARES; i++)
	{
		if (i % board.SQUARES_PER_SIDE == 0 && i != 0)
		{
			std::cout << std::endl;
		}

		int currentRow = i / board.SQUARES_PER_SIDE;

		std::cout << rows[currentRow].top();

		rows[currentRow].pop();
	}

	std::cout << std::endl << std::endl;
}

void BoardDrawer::SetColor(WORD color) const
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, color);
}

bool BoardDrawer::TryDrawPlayerSquare(
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

void BoardDrawer::DrawEmptySquare(size_t i) const
{
	auto mask = I256{ 1 } << i;
	auto corners = board.CORNERS;

	if ((mask & corners) == mask)
	{
		SetColor(GRAY);
	}
	else
	{
		SetColor(WHITE);
	}

	std::cout << i << "\t";
}
