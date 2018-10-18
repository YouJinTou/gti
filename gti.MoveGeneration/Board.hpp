#ifndef BOARD_HPP
#define BOARD_HPP

#include "Typedefs.hpp"

class Board 
{
public:
	Board();
private:
	typedef boost::multiprecision::uint256_t I256;
private:
	static const std::string RED_PAWNS;
	static const std::string RED_KNIGHTS;
	static const std::string RED_BISHOPS;
	static const std::string RED_ROOKS;
	static const std::string RED_QUEENS;
	static const std::string RED_KING;
	static const std::string BLUE_PAWNS;
	static const std::string BLUE_KNIGHTS;
	static const std::string BLUE_BISHOPS;
	static const std::string BLUE_ROOKS;
	static const std::string BLUE_QUEENS;
	static const std::string BLUE_KING;
	static const std::string YELLOW_PAWNS;
	static const std::string YELLOW_KNIGHTS;
	static const std::string YELLOW_BISHOPS;
	static const std::string YELLOW_ROOKS;
	static const std::string YELLOW_QUEENS;
	static const std::string YELLOW_KING;
	static const std::string GREEN_PAWNS;
	static const std::string GREEN_KNIGHTS;
	static const std::string GREEN_BISHOPS;
	static const std::string GREEN_ROOKS;
	static const std::string GREEN_QUEENS;
	static const std::string GREEN_KING;
private:
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

#endif // !BOARD_HPP
