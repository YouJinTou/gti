#include "MoveGenerator.hpp"
#include "Utils.hpp"

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
			board.RANK_8,
			board.FILE_N,
			board.FILE_A);
	case PlayerColor::Blue:
		return GetPawnMoves(
			board.GetBluePawns(),
			false,
			BLUE_PAWN_FORWARD_MOVE_SHIFT,
			BLUE_PAWN_LEFT_CAPTURE_SHIFT,
			BLUE_PAWN_RIGHT_CAPTURE_SHIFT,
			board.FILE_D,
			board.GetOthersPieces(),
			board.FILE_H,
			board.RANK_1,
			board.RANK_14);
	case PlayerColor::Yellow:
		return GetPawnMoves(
			board.GetYellowPawns(),
			true,
			YELLOW_PAWN_FORWARD_MOVE_SHIFT,
			YELLOW_PAWN_LEFT_CAPTURE_SHIFT,
			YELLOW_PAWN_RIGHT_CAPTURE_SHIFT,
			board.RANK_11,
			board.GetOthersPieces(),
			board.RANK_7,
			board.FILE_A,
			board.FILE_N);
	case PlayerColor::Green:
		return GetPawnMoves(
			board.GetGreenPawns(),
			true,
			GREEN_PAWN_FORWARD_MOVE_SHIFT,
			GREEN_PAWN_LEFT_CAPTURE_SHIFT,
			GREEN_PAWN_RIGHT_CAPTURE_SHIFT,
			board.FILE_K,
			board.GetOthersPieces(),
			board.FILE_G,
			board.RANK_14,
			board.RANK_1);
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
	I256 leftShifts = increasing ? (pawns >> leftShift) : (pawns << leftShift);
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
		else if (((twoForwardMoves >> i) & 1) == 1)
		{
			moves.push_back({ increasing ? j + doubleForwardShift : j - doubleForwardShift, j });
		}
		else if (((leftCaptures >> i) & 1) == 1)
		{
			moves.push_back({ increasing ? j + leftShift : j - leftShift, j });
		}
		else if (((rightCaptures >> i) & 1) == 1)
		{
			moves.push_back({ increasing ? j + rightShift : j - rightShift, j });
		}
		else if (((forwardPromotions >> i) & 1) == 1)
		{
			moves.push_back({ increasing ? j + forwardShift : j - forwardShift, j });
		}
		else if (((leftCapturePromotions >> i) & 1) == 1)
		{
			moves.push_back({ increasing ? j + leftShift : j - leftShift, j });
		}
		else if (((rightCapturePromotions >> i) & 1) == 1)
		{
			moves.push_back({ increasing ? j + rightShift : j - rightShift, j });
		}
	}

	return moves;
}

std::vector<Move> MoveGenerator::GetKnightMoves() const
{
	switch (board.ToMove())
	{
	case PlayerColor::Red:
		return GetKnightMoves(board.GetRedKnights(), board.GetOthersPieces());
	case PlayerColor::Blue:
		return GetKnightMoves(board.GetBlueKnights(), board.GetOthersPieces());
	case PlayerColor::Yellow:
		return GetKnightMoves(board.GetYellowKnights(), board.GetOthersPieces());
	case PlayerColor::Green:
		return GetKnightMoves(board.GetGreenKnights(), board.GetOthersPieces());
	default:
		return std::vector<Move>{};
	}
}

std::vector<Move> MoveGenerator::GetKnightMoves(I256 knights, I256 othersPieces) const
{
	I256 emptySquares = board.GetEmptySquares();
	I256 nneMoves = (knights >> KNIGHT_NNE_SHIFT) & (emptySquares | othersPieces) & ~Board::FILE_A;
	I256 neMoves = (knights >> KNIGHT_NE_SHIFT) & (emptySquares | othersPieces) & ~Board::FILE_A & ~Board::FILE_B;
	I256 seMoves = (knights << KNIGHT_SE_SHIFT) & (emptySquares | othersPieces) & ~Board::FILE_A & ~Board::FILE_B;
	I256 sseMoves = (knights << KNIGHT_SSE_SHIFT) & (emptySquares | othersPieces) & ~Board::FILE_A;
	I256 sswMoves = (knights << KNIGHT_SSW_SHIFT) & (emptySquares | othersPieces) & ~Board::FILE_N;
	I256 swMoves = (knights << KNIGHT_SW_SHIFT) & (emptySquares | othersPieces) & ~Board::FILE_M & ~Board::FILE_N;
	I256 nwMoves = (knights >> KNIGHT_NW_SHIFT) & (emptySquares | othersPieces) & ~Board::FILE_M & ~Board::FILE_N;
	I256 nnwMoves = (knights >> KNIGHT_NNW_SHIFT) & (emptySquares | othersPieces) & ~Board::FILE_N;
	std::vector<Move> moves{};

	for (int i = 0, j = board.TOTAL_SQUARES; i < board.TOTAL_SQUARES; i++, j--)
	{
		if (((nneMoves >> i) & 1) == 1)
		{
			moves.push_back({ j - KNIGHT_NNE_SHIFT, j });
		}
		else if (((neMoves >> i) & 1) == 1)
		{
			moves.push_back({ j - KNIGHT_NE_SHIFT, j });
		}
		else if (((seMoves >> i) & 1) == 1)
		{
			moves.push_back({ j + KNIGHT_SE_SHIFT, j });
		}
		else if (((sseMoves >> i) & 1) == 1)
		{
			moves.push_back({ j + KNIGHT_SSE_SHIFT, j });
		}
		else if (((sswMoves >> i) & 1) == 1)
		{
			moves.push_back({ j + KNIGHT_SSW_SHIFT, j });
		}
		else if (((swMoves >> i) & 1) == 1)
		{
			moves.push_back({ j + KNIGHT_SW_SHIFT, j });
		}
		else if (((nwMoves >> i) & 1) == 1)
		{
			moves.push_back({ j - KNIGHT_NW_SHIFT, j });
		}
		else if (((nnwMoves >> i) & 1) == 1)
		{
			moves.push_back({ j - KNIGHT_NNW_SHIFT, j });
		}
	}

	return moves;
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

std::vector<Move> MoveGenerator::GetSliderMoves(I256 slider, I256 mask) const
{
	I256 othersPieces = board.GetOthersPieces();
	I256 occupied = board.GetAll();
	I256 attacks = ((occupied & mask - (2 * slider)) ^ r((r(occupied & mask) - (2 * r(slider))))) & mask;

	return std::vector<Move>{};
}

inline I256 r(I256 n)
{
	return Utils::ReverseBits(n);
}