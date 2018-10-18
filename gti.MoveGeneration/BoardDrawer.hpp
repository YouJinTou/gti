#ifndef BOARD_DRAWER_HPP
#define BOARD_DRAWER_HPP

#include "Board.hpp"

class BoardDrawer
{
public:
	BoardDrawer(const Board& board);
	void DrawBoard() const;
private:
	const Board& board;
private:
	void DrawRed() const;
};

#endif // !BOARD_DRAWER.HPP
