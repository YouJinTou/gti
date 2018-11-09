#include "MoveGenerator.hpp"
#include "Utils.hpp"

const I256 MoveGenerator::RANK_MASKS[14]
{
	I256{ "100427497784023428665939197383214061420903212154935817797632" }, // 1
	I256{ "6129608019044398722286327965284061366021924570003406848" },
	I256{ "374121583193627851702046384599857261109736607055872" },
	I256{ "22834569286720449932986229528799881659529822208" },
	I256{ "1393711504316433711730116548388664652070912" },
	I256{ "85065399433376081038215121361612832768" },
	I256{ "5191979945884770571180122153418752" },
	I256{ "316893307243943516307380502528" },
	I256{ "19341632522213349383995392" },
	I256{ "1180519563123373375488" },
	I256{ "72053195991416832" },
	I256{ "4397778075648" },
	I256{ "268419072" },
	I256{ "16383" },
};

const I256 MoveGenerator::FILE_MASKS[14]
{
	I256{ "50219879061258806145241078635089742567989253056020871127040" }, // A
	I256{ "25109939530629403072620539317544871283994626528010435563520" },
	I256{ "12554969765314701536310269658772435641997313264005217781760" },
	I256{ "6277484882657350768155134829386217820998656632002608890880" },
	I256{ "3138742441328675384077567414693108910499328316001304445440" },
	I256{ "1569371220664337692038783707346554455249664158000652222720" },
	I256{ "784685610332168846019391853673277227624832079000326111360" },
	I256{ "392342805166084423009695926836638613812416039500163055680" },
	I256{ "196171402583042211504847963418319306906208019750081527840" },
	I256{ "98085701291521105752423981709159653453104009875040763920" },
	I256{ "49042850645760552876211990854579826726552004937520381960" },
	I256{ "24521425322880276438105995427289913363276002468760190980" },
	I256{ "12260712661440138219052997713644956681638001234380095490" },
	I256{ "6130356330720069109526498856822478340819000617190047745" },
};

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