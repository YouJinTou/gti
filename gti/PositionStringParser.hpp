#ifndef POSITION_STRING_PARSER_HPP
#define POSITION_STRING_PARSER_HPP

#include <string>

class Board;

class PositionStringParser
{
public:
	const std::string INITIAL_STRING{ "3rRrNrBrQrKrBrNrR3/3rPrPrPrPrPrPrPrP3/14/bRbP10gPgR/bNbP10gPgN/bBbP10gPgB/bQbP10/gPgK/bKbP10gPgQ/bBbP10gPgB/bNbP10gPgN/bRbP10gPgR/14/3yPyPyPyPyPyPyPyP3/3yRrNyByKyQyByNyR3 r rKrQbKbQyKyQgKgQ – 0 1" };
public:
	Board ParsePositionString(std::string positionString) const;
	std::string GetPositionString(const Board& board) const;
};

#endif // !POSITION_STRING_PARSER_HPP
