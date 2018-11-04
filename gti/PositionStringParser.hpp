#ifndef POSITION_STRING_PARSER_HPP
#define POSITION_STRING_PARSER_HPP

#include <string>
#include <vector>

#include "Constants.hpp"
#include "Typedefs.hpp"

class Board;

class PositionStringParser
{
public:
	static constexpr const char* INITIAL_STRING = "3rRrNrBrQrKrBrNrR3/3rPrPrPrPrPrPrPrP3/14/bRbP10gPgR/bNbP10gPgN/bBbP10gPgB/bQbP10gPgK/bKbP10gPgQ/bBbP10gPgB/bNbP10gPgN/bRbP10gPgR/14/3yPyPyPyPyPyPyPyP3/3yRyNyByKyQyByNyR3 r rKrQbKbQyKyQgKgQ rbyg 0 1";
	static constexpr const char* RED = "r";
	static constexpr const char* BLUE = "b";
	static constexpr const char* YELLOW = "y";
	static constexpr const char* GREEN = "g";
	static constexpr const char* RED_PAWN = "rP";
	static constexpr const char* RED_KNIGHT = "rN";
	static constexpr const char* RED_BISHOP = "rB";
	static constexpr const char* RED_ROOK = "rR";
	static constexpr const char* RED_QUEEN = "rQ";
	static constexpr const char* RED_NEW_QUEEN = "rq";
	static constexpr const char* RED_KING = "rK";
	static constexpr const char* BLUE_PAWN = "bP";
	static constexpr const char* BLUE_KNIGHT = "bN";
	static constexpr const char* BLUE_BISHOP = "bB";
	static constexpr const char* BLUE_ROOK = "bR";
	static constexpr const char* BLUE_QUEEN = "bQ";
	static constexpr const char* BLUE_NEW_QUEEN = "bq";
	static constexpr const char* BLUE_KING = "bK";
	static constexpr const char* YELLOW_PAWN = "yP";
	static constexpr const char* YELLOW_KNIGHT = "yN";
	static constexpr const char* YELLOW_BISHOP = "yB";
	static constexpr const char* YELLOW_ROOK = "yR";
	static constexpr const char* YELLOW_QUEEN = "yQ";
	static constexpr const char* YELLOW_NEW_QUEEN = "yq";
	static constexpr const char* YELLOW_KING = "yK";
	static constexpr const char* GREEN_PAWN = "gP";
	static constexpr const char* GREEN_KNIGHT = "gN";
	static constexpr const char* GREEN_BISHOP = "gB";
	static constexpr const char* GREEN_ROOK = "gR";
	static constexpr const char* GREEN_QUEEN = "gQ";
	static constexpr const char* GREEN_NEW_QUEEN = "gq";
	static constexpr const char* GREEN_KING = "gK";
	static constexpr const char* RED_KING_CASTLE = "rK";
	static constexpr const char* RED_QUEEN_CASTLE = "rQ";
	static constexpr const char* BLUE_KING_CASTLE = "bK";
	static constexpr const char* BLUE_QUEEN_CASTLE = "bQ";
	static constexpr const char* YELLOW_KING_CASTLE = "yK";
	static constexpr const char* YELLOW_QUEEN_CASTLE = "yQ";
	static constexpr const char* GREEN_KING_CASTLE = "gK";
	static constexpr const char* GREEN_QUEEN_CASTLE = "gQ";
private:
	const int SLASH_DELIMITED_TOKENS = 14;
	const int LAST_TOKEN_TOKENS = 6;
public:
	Board ParsePositionString(const std::string& positionString);
	std::string GetPositionString(const Board& board) const;
private:
	void SetPosition(const std::string& positionString);
	void SetSquare(const std::string& matchString, int position);
	void SetToMove(const std::string& toMoveString);
	void SetCastlingRights(const std::string& castleString);
	void SetRemainingPlayers(const std::string& remainingPlayersString);
	void SetHalfMoveClock(const std::string& halfMoveClockString);
	void SetFullMoveNumber(const std::string& fullMoveNumberString);
private:
	PlayerColor toMove{ PlayerColor::Red };
	int castlingRights{ 0 };
	int remainingPlayers{ 0 };
	int halfMoveClock{ 0 };
	int fullMoveNumber{ 0 };
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
};

#endif // !POSITION_STRING_PARSER_HPP
