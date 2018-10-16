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
	static const std::string RED_PAWNS_INITIAL_MASK;
	static const std::string RED_KNIGHTS_INITIAL_MASK;
	static const std::string RED_BISHOPS_INITIAL_MASK;
	static const std::string RED_ROOKS_INITIAL_MASK;
	static const std::string RED_QUEENS_INITIAL_MASK;
	static const std::string RED_KINGS_INITIAL_MASK;
private:
	I256 rPawns;
	I256 rKnights;
	I256 rBishops;
	I256 rRooks;
	I256 rQueens;
	I256 rKings;
	I256 bPawns;
	I256 bKnights;
	I256 bBishops;
	I256 bRooks;
	I256 bQueens;
	I256 bKings;
	I256 yPawns;
	I256 yKnights;
	I256 yBishops;
	I256 yRooks;
	I256 yQueens;
	I256 yKings;
	I256 gPawns;
	I256 gKnights;
	I256 gBishops;
	I256 gRooks;
	I256 gQueens;
	I256 gKings;
};

#endif // !BOARD_HPP
