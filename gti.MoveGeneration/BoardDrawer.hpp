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
private:
	const Board& board;
private:
	void SetColor(WORD color) const;
	bool TryDrawPlayerSquare(size_t i, WORD color, I256 pawns, I256 knights, I256 bishops, I256 rooks, I256 queens, I256 king) const;
	void DrawEmptySquare(size_t i) const;
};

#endif // !BOARD_DRAWER_HPP
