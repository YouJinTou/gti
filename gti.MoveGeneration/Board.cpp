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

PlayerColor Board::ToMove() const
{
	return toMove;
}

I256 Board::GetRedPawns() const
{
	return rPawns;
}

I256 Board::GetRedKnights() const
{
	return rKnights;
}

I256 Board::GetRedBishops() const
{
	return rBishops;
}

I256 Board::GetRedRooks() const
{
	return rRooks;
}

I256 Board::GetRedQueens() const
{
	return rQueens;
}

I256 Board::GetRedKing() const
{
	return rKing;
}

I256 Board::GetBluePawns() const
{
	return bPawns;
}

I256 Board::GetBlueKnights() const
{
	return bKnights;
}

I256 Board::GetBlueBishops() const
{
	return bBishops;
}

I256 Board::GetBlueRooks() const
{
	return bRooks;
}

I256 Board::GetBlueQueens() const
{
	return bQueens;
}

I256 Board::GetBlueKing() const
{
	return bKing;
}

I256 Board::GetYellowPawns() const
{
	return yPawns;
}

I256 Board::GetYellowKnights() const
{
	return yKnights;
}

I256 Board::GetYellowBishops() const
{
	return yBishops;
}

I256 Board::GetYellowRooks() const
{
	return yRooks;
}

I256 Board::GetYellowQueens() const
{
	return yQueens;
}

I256 Board::GetYellowKing() const
{
	return yKing;
}

I256 Board::GetGreenPawns() const
{
	return gPawns;
}

I256 Board::GetGreenKnights() const
{
	return gKnights;
}

I256 Board::GetGreenBishops() const
{
	return gBishops;
}

I256 Board::GetGreenRooks() const
{
	return gRooks;
}

I256 Board::GetGreenQueens() const
{
	return gQueens;
}

I256 Board::GetGreenKing() const
{
	return gKing;
}

I256 Board::GetCorners() const
{
	return CORNERS;
}

std::vector<I256> Board::GetNextPlayerMoves() const
{
	std::vector<I256> moves;
	auto pawnMoves = GetPawnMoves();
	auto knightMoves = GetKnightMoves();
	auto bishopMoves = GetBishopMoves();
	auto rookMoves = GetRookMoves();
	auto queenMoves = GetQueenMoves();
	auto kingMoves = GetKingMoves();

	moves.insert(moves.end(), pawnMoves.cbegin(), pawnMoves.cend());
	moves.insert(moves.end(), knightMoves.cbegin(), knightMoves.cend());
	moves.insert(moves.end(), bishopMoves.cbegin(), bishopMoves.cend());
	moves.insert(moves.end(), rookMoves.cbegin(), rookMoves.cend());
	moves.insert(moves.end(), queenMoves.cbegin(), queenMoves.cend());
	moves.insert(moves.end(), kingMoves.cbegin(), kingMoves.cend());

	return moves;
}

std::vector<I256> Board::GetPawnMoves() const
{
	return std::vector<I256>();
}

std::vector<I256> Board::GetKnightMoves() const
{
	return std::vector<I256>();
}

std::vector<I256> Board::GetBishopMoves() const
{
	return std::vector<I256>();
}

std::vector<I256> Board::GetRookMoves() const
{
	return std::vector<I256>();
}

std::vector<I256> Board::GetQueenMoves() const
{
	return std::vector<I256>();
}

std::vector<I256> Board::GetKingMoves() const
{
	return std::vector<I256>();
}
