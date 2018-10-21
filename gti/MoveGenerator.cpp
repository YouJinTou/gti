#include "MoveGenerator.hpp"

MoveGenerator::MoveGenerator(const Board& board) :
	board{ board }
{
}

std::vector<I256> MoveGenerator::GetMoves() const
{
	std::vector<I256> moves{};
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

std::vector<I256> MoveGenerator::GetPawnMoves() const
{
	switch (board.ToMove())
	{
	case PlayerColor::Red:
		return GetRedPawnMoves();
	case PlayerColor::Blue:
		return GetBluePawnMoves();
	case PlayerColor::Yellow:
		return GetYellowPawnMoves();
	case PlayerColor::Green:
		return GetGreenPawnMoves();
	default:
		return std::vector<I256>{};
	}
}

std::vector<I256> MoveGenerator::GetRedPawnMoves() const
{
	auto pawns = board.GetRedPawns();
	auto emptySquares = board.GetEmptySquares();
	auto oneForwardMoves = (pawns >> 14) & emptySquares & ~RED_PROMOTION_RANK;
	auto twoForwardMoves = 
		(pawns >> 28) & emptySquares & (emptySquares >> 14) & Board::RED_PAWNS_INITIAL;

	return std::vector<I256>{ oneForwardMoves, twoForwardMoves };
}

std::vector<I256> MoveGenerator::GetBluePawnMoves() const
{
	return std::vector<I256>();
}

std::vector<I256> MoveGenerator::GetYellowPawnMoves() const
{
	return std::vector<I256>();
}

std::vector<I256> MoveGenerator::GetGreenPawnMoves() const
{
	return std::vector<I256>();
}

std::vector<I256> MoveGenerator::GetKnightMoves() const
{
	return std::vector<I256>();
}

std::vector<I256> MoveGenerator::GetBishopMoves() const
{
	return std::vector<I256>();
}

std::vector<I256> MoveGenerator::GetRookMoves() const
{
	return std::vector<I256>();
}

std::vector<I256> MoveGenerator::GetQueenMoves() const
{
	return std::vector<I256>();
}

std::vector<I256> MoveGenerator::GetKingMoves() const
{
	return std::vector<I256>();
}
