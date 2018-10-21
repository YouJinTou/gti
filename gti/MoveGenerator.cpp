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
		return GetPawnMoves(
			board.GetRedPawns(), 
			false, 
			RED_PAWN_FORWARD_MOVE_SHIFT, 
			RED_PAWN_LEFT_CAPTURE_SHIFT, 
			RED_PAWN_RIGHT_CAPTURE_SHIFT, 
			board.RANK_4, 
			board.GetOthersPieces(), 
			board.RED_PROMOTION_RANK, 
			board.FILE_N, 
			board.FILE_A);
	case PlayerColor::Blue:
		return GetPawnMoves();
	case PlayerColor::Yellow:
		return GetPawnMoves();
	case PlayerColor::Green:
		return GetPawnMoves();
	default:
		return std::vector<I256>{};
	}
}

std::vector<I256> MoveGenerator::GetPawnMoves(
	I256 pawns, 
	bool increasing, 
	int forwardShift, 
	int leftShift, 
	int rightShift, 
	I256 twoForwardLine, 
	I256 othersPieces, 
	I256 promotionLine, 
	I256 leftCaptureOpposingLine,
	I256 rightCaptureOpposingLine) const
{
	auto emptySquares = board.GetEmptySquares();
	auto doubleForwardShift = forwardShift * 2;
	auto emptyForwardShifts = increasing ? (emptySquares >> forwardShift) : (emptySquares << forwardShift);
	auto forwardShifts = increasing ? (pawns << forwardShift) : (pawns >> forwardShift);
	auto doubleShifts = increasing ? (pawns << doubleForwardShift) : (pawns >> doubleForwardShift);
	auto leftShifts = increasing ? (pawns >> leftShift) : (pawns << rightShift);
	auto rightShifts = increasing ? (pawns >> rightShift) : (pawns << rightShift);
	auto oneForwardMoves = forwardShifts & emptySquares &  ~promotionLine;
	auto twoForwardMoves = doubleShifts & emptySquares & emptyForwardShifts & twoForwardLine;
	auto leftCaptures = leftShifts & othersPieces & ~promotionLine & ~leftCaptureOpposingLine;
	auto rightCaptures = rightShifts & othersPieces & ~promotionLine & ~rightCaptureOpposingLine;
	auto forwardPromotions = forwardShifts & emptySquares & promotionLine;
	auto leftCapturePromotions = leftShifts & othersPieces & promotionLine;
	auto rightCapturePromotions = rightShifts & othersPieces & promotionLine;

	return std::vector<I256>
	{
		oneForwardMoves,
			twoForwardMoves,
			leftCaptures,
			rightCaptures,
			forwardPromotions,
			leftCapturePromotions,
			rightCapturePromotions
	};
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
