#include "Board.hpp"

Board::Board() :
	rPawns{ RED_PAWNS_INITIAL },
	rKnights{ RED_KNIGHTS_INITIAL },
	rBishops{ RED_BISHOPS_INITIAL },
	rRooks{ RED_ROOKS_INITIAL },
	rQueens{ RED_QUEENS_INITIAL },
	rKing{ RED_KING_INITIAL },
	bPawns{ BLUE_PAWNS_INITIAL },
	bKnights{ BLUE_KNIGHTS_INITIAL },
	bBishops{ BLUE_BISHOPS_INITIAL },
	bRooks{ BLUE_ROOKS_INITIAL },
	bQueens{ BLUE_QUEENS_INITIAL },
	bKing{ BLUE_KING_INITIAL },
	yPawns{ YELLOW_PAWNS_INITIAL },
	yKnights{ YELLOW_KNIGHTS_INITIAL },
	yBishops{ YELLOW_BISHOPS_INITIAL },
	yRooks{ YELLOW_ROOKS_INITIAL },
	yQueens{ YELLOW_QUEENS_INITIAL },
	yKing{ YELLOW_KING_INITIAL },
	gPawns{ GREEN_PAWNS_INITIAL },
	gKnights{ GREEN_KNIGHTS_INITIAL },
	gBishops{ GREEN_BISHOPS_INITIAL },
	gRooks{ GREEN_ROOKS_INITIAL },
	gQueens{ GREEN_QUEENS_INITIAL },
	gKing{ GREEN_KING_INITIAL }
{
}

I256 Board::getRedPawns() const
{
	return rPawns;
}

I256 Board::getRedKnights() const
{
	return rKnights;
}

I256 Board::getRedBishops() const
{
	return rBishops;
}

I256 Board::getRedRooks() const
{
	return rRooks;
}

I256 Board::getRedQueens() const
{
	return rQueens;
}

I256 Board::getRedKing() const
{
	return rKing;
}

I256 Board::getBluePawns() const
{
	return bPawns;
}

I256 Board::getBlueKnights() const
{
	return bKnights;
}

I256 Board::getBlueBishops() const
{
	return bBishops;
}

I256 Board::getBlueRooks() const
{
	return bRooks;
}

I256 Board::getBlueQueens() const
{
	return bQueens;
}

I256 Board::getBlueKing() const
{
	return bKing;
}

I256 Board::getYellowPawns() const
{
	return yPawns;
}

I256 Board::getYellowKnights() const
{
	return yKnights;
}

I256 Board::getYellowBishops() const
{
	return yBishops;
}

I256 Board::getYellowRooks() const
{
	return yRooks;
}

I256 Board::getYellowQueens() const
{
	return yQueens;
}

I256 Board::getYellowKing() const
{
	return yKing;
}

I256 Board::getGreenPawns() const
{
	return gPawns;
}

I256 Board::getGreenKnights() const
{
	return gKnights;
}

I256 Board::getGreenBishops() const
{
	return gBishops;
}

I256 Board::getGreenRooks() const
{
	return gRooks;
}

I256 Board::getGreenQueens() const
{
	return gQueens;
}

I256 Board::getGreenKing() const
{
	return gKing;
}

I256 Board::getCorners() const
{
	return CORNERS;
}