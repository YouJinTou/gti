#ifndef BOARD_HPP
#define BOARD_HPP

#include <string>

#include "Constants.hpp"
#include "Typedefs.hpp"
#include "PositionStringParser.hpp"

class Board 
{
public:
	static constexpr int TOTAL_SQUARES = 196;
	static constexpr int SQUARES_PER_SIDE = 14;
public:
	static const I256 EMPTY_BOARD;
	static const I256 RED_PAWNS_INITIAL;
	static const I256 RED_KNIGHTS_INITIAL;
	static const I256 RED_BISHOPS_INITIAL;
	static const I256 RED_ROOKS_INITIAL;
	static const I256 RED_QUEENS_INITIAL;
	static const I256 RED_KING_INITIAL;
	static const I256 BLUE_PAWNS_INITIAL;
	static const I256 BLUE_KNIGHTS_INITIAL;
	static const I256 BLUE_BISHOPS_INITIAL;
	static const I256 BLUE_ROOKS_INITIAL;
	static const I256 BLUE_QUEENS_INITIAL;
	static const I256 BLUE_KING_INITIAL;
	static const I256 YELLOW_PAWNS_INITIAL;
	static const I256 YELLOW_KNIGHTS_INITIAL;
	static const I256 YELLOW_BISHOPS_INITIAL;
	static const I256 YELLOW_ROOKS_INITIAL;
	static const I256 YELLOW_QUEENS_INITIAL;
	static const I256 YELLOW_KING_INITIAL;
	static const I256 GREEN_PAWNS_INITIAL;
	static const I256 GREEN_KNIGHTS_INITIAL;
	static const I256 GREEN_BISHOPS_INITIAL;
	static const I256 GREEN_ROOKS_INITIAL;
	static const I256 GREEN_QUEENS_INITIAL;
	static const I256 GREEN_KING_INITIAL;
	static const I256 CORNERS;
	static const I256 FILE_A;
	static const I256 FILE_B;
	static const I256 FILE_D;
	static const I256 FILE_G;
	static const I256 FILE_H;
	static const I256 FILE_K;
	static const I256 FILE_M;
	static const I256 FILE_N;
	static const I256 RANK_1;
	static const I256 RANK_4;
	static const I256 RANK_7;
	static const I256 RANK_8;
	static const I256 RANK_11;
	static const I256 RANK_14;
public:
	Board();
	Board(std::string positionString);
	Board(
		PlayerColor toMove,
		I256 rPawns,
		I256 rKnights,
		I256 rBishops,
		I256 rRooks,
		I256 rQueens,
		I256 rKing,
		I256 bPawns,
		I256 bKnights,
		I256 bBishops,
		I256 bRooks,
		I256 bQueens,
		I256 bKing,
		I256 yPawns,
		I256 yKnights,
		I256 yBishops,
		I256 yRooks,
		I256 yQueens,
		I256 yKing,
		I256 gPawns,
		I256 gKnights,
		I256 gBishops,
		I256 gRooks,
		I256 gQueens,
		I256 gKing);
	PlayerColor ToMove() const;
	void SetToMove(PlayerColor player);
	I256 GetRed() const;
	I256 GetRedPawns() const;
	I256 GetRedKnights() const;
	I256 GetRedBishops() const;
	I256 GetRedRooks() const;
	I256 GetRedQueens() const;
	I256 GetRedKing() const;
	I256 GetBlue() const;
	I256 GetBluePawns() const;
	I256 GetBlueKnights() const;
	I256 GetBlueBishops() const;
	I256 GetBlueRooks() const;
	I256 GetBlueQueens() const;
	I256 GetBlueKing() const;
	I256 GetYellow() const;
	I256 GetYellowPawns() const;
	I256 GetYellowKnights() const;
	I256 GetYellowBishops() const;
	I256 GetYellowRooks() const;
	I256 GetYellowQueens() const;
	I256 GetYellowKing() const;
	I256 GetGreen() const;
	I256 GetGreenPawns() const;
	I256 GetGreenKnights() const;
	I256 GetGreenBishops() const;
	I256 GetGreenRooks() const;
	I256 GetGreenQueens() const;
	I256 GetGreenKing() const;
	I256 GetEmptySquares() const;
	I256 GetOthersPieces() const;
private:
	PlayerColor toMove;
	I256 rPawns;
	I256 rKnights;
	I256 rBishops;
	I256 rRooks;
	I256 rQueens;
	I256 rKing;
	I256 bPawns;
	I256 bKnights;
	I256 bBishops;
	I256 bRooks;
	I256 bQueens;
	I256 bKing;
	I256 yPawns;
	I256 yKnights;
	I256 yBishops;
	I256 yRooks;
	I256 yQueens;
	I256 yKing;
	I256 gPawns;
	I256 gKnights;
	I256 gBishops;
	I256 gRooks;
	I256 gQueens;
	I256 gKing;
private:
	PositionStringParser parser;
};

#endif // !BOARD_HPP
