#include "MoveGenerator.hpp"

MoveGenerator::MoveGenerator(const Board& board) :
	board{ board }
{
}

std::vector<Move> MoveGenerator::GetMoves() const
{
	std::vector<Move> moves{};
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

std::vector<Move> MoveGenerator::GetPawnMoves() const
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
		return std::vector<Move>{};
	}
}

std::vector<Move> MoveGenerator::GetPawnMoves(
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
	I256 emptySquares = board.GetEmptySquares();
	int doubleForwardShift = forwardShift * 2;
	I256 emptyForwardShifts = increasing ? (emptySquares >> forwardShift) : (emptySquares << forwardShift);
	I256 forwardShifts = increasing ? (pawns << forwardShift) : (pawns >> forwardShift);
	I256 doubleShifts = increasing ? (pawns << doubleForwardShift) : (pawns >> doubleForwardShift);
	I256 leftShifts = increasing ? (pawns >> leftShift) : (pawns << rightShift);
	I256 rightShifts = increasing ? (pawns >> rightShift) : (pawns << rightShift);
	I256 oneForwardMoves = forwardShifts & emptySquares &  ~promotionLine;
	I256 twoForwardMoves = doubleShifts & emptySquares & emptyForwardShifts & twoForwardLine;
	I256 leftCaptures = leftShifts & othersPieces & ~promotionLine & ~leftCaptureOpposingLine;
	I256 rightCaptures = rightShifts & othersPieces & ~promotionLine & ~rightCaptureOpposingLine;
	I256 forwardPromotions = forwardShifts & emptySquares & promotionLine;
	I256 leftCapturePromotions = leftShifts & othersPieces & promotionLine;
	I256 rightCapturePromotions = rightShifts & othersPieces & promotionLine;
	std::vector<Move> moves{};

	for (int i = 0, j = board.TOTAL_SQUARES; i < board.TOTAL_SQUARES; i++, j--)
	{
		if (((oneForwardMoves >> i) & 1) == 1)
		{
			moves.push_back({ increasing ? j + forwardShift : j - forwardShift, j });
		}

		if (((twoForwardMoves >> i) & 1) == 1)
		{
			moves.push_back({ increasing ? j + doubleForwardShift : j - doubleForwardShift, j });
		}

		if (((leftCaptures >> i) & 1) == 1)
		{
			moves.push_back({ increasing ? j + leftShift : j - leftShift, j });
		}

		if (((rightCaptures >> i) & 1) == 1)
		{
			moves.push_back({ increasing ? j + rightShift : j - rightShift, j });
		}

		if (((forwardPromotions >> i) & 1) == 1)
		{
			moves.push_back({ increasing ? j + forwardShift : j - forwardShift, j });
		}

		if (((leftCapturePromotions >> i) & 1) == 1)
		{
			moves.push_back({ increasing ? j + leftShift : j - leftShift, j });
		}

		if (((rightCapturePromotions >> i) & 1) == 1)
		{
			moves.push_back({ increasing ? j + rightShift : j - rightShift, j });
		}
	}

	return moves;
}

std::vector<Move> MoveGenerator::GetKnightMoves() const
{
	return std::vector<Move>();
}

std::vector<Move> MoveGenerator::GetBishopMoves() const
{
	return std::vector<Move>();
}

std::vector<Move> MoveGenerator::GetRookMoves() const
{
	return std::vector<Move>();
}

std::vector<Move> MoveGenerator::GetQueenMoves() const
{
	return std::vector<Move>();
}

std::vector<Move> MoveGenerator::GetKingMoves() const
{
	return std::vector<Move>();
}
