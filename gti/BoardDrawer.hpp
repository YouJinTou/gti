#ifndef BOARD_DRAWER_HPP
#define BOARD_DRAWER_HPP

#include <windows.h>

#include "Board.hpp"
#include "Typedefs.hpp"

class BoardDrawer
{
public:
	BoardDrawer(const Board& board);
	void DrawBoard() const;
	static void DrawBitboard(I256 bitboard);
private:
	static constexpr WORD RED = 4;
	static constexpr WORD BLUE = 1;
	static constexpr WORD GREEN = 2;
	static constexpr WORD YELLOW = 14;
	static constexpr WORD WHITE = 15;
	static constexpr WORD GRAY = 8;
private:
	const Board& board;
private:
	void SetColor(WORD color) const;
	bool TryDrawPlayerSquare(size_t i, WORD color, I256 pawns, I256 knights, I256 bishops, I256 rooks, I256 queens, I256 king) const;
	void DrawEmptySquare(size_t i) const;
};

#endif // !BOARD_DRAWER_HPP
