#include <numeric>
#include <boost/algorithm/string.hpp>
#include <regex>

#include "PositionStringParser.hpp"
#include "Board.hpp"
#include "Utils.hpp"

Board PositionStringParser::ParsePositionString(const std::string& positionString)
{
	SetPosition(positionString);

	return Board(
		PlayerColor::Red,
		rPawns,
		rKnights,
		rBishops,
		rRooks,
		rQueens,
		rKing,
		bPawns,
		bKnights,
		bBishops,
		bRooks,
		bQueens,
		bKing,
		yPawns,
		yKnights,
		yBishops,
		yRooks,
		yQueens,
		yKing,
		gPawns,
		gKnights,
		gBishops,
		gRooks,
		gQueens,
		gKing
	);
}

std::string PositionStringParser::GetPositionString(const Board& board) const
{
	return std::string();
}

void PositionStringParser::SetPosition(const std::string& positionString)
{
	if (positionString.empty())
	{
		throw;
	}

	std::vector<std::string> slashTokens;

	boost::split(slashTokens, positionString, [](char c) {return c == '/'; });

	if (slashTokens.size() != SLASH_DELIMITED_TOKENS)
	{
		throw;
	}

	std::vector<std::string> emptySpaceTokens;

	boost::split(emptySpaceTokens, slashTokens.back(), [](char c) {return c == ' '; });

	if (emptySpaceTokens.size() != LAST_TOKEN_TOKENS)
	{
		throw;
	}

	slashTokens.pop_back();

	std::vector<std::string> positionTokens(slashTokens);

	positionTokens.push_back(emptySpaceTokens.front());

	std::regex regex("(\\d+)|(rP)|(rN)|(rB)|(rR)|(rQ)|(rq)|(rK)|(bP)|(bN)|(bB)|(bR)|(bQ)|(bq)|(bK)|(yP)|(yN)|(yB)|(yR)|(yQ)|(yq)|(yK)|(gP)|(gN)|(gB)|(gR)|(gQ)|(gq)|(gK)");

	int position = Board::TOTAL_SQUARES;

	for (auto& token : positionTokens)
	{
		std::vector<int> squares;
		std::vector<std::string> pieces;
		std::smatch match;
		std::string matchable(token);

		while (std::regex_search(matchable, match, regex))
		{
			std::string matchString = match[0].str();
			bool isNumber =
				!matchString.empty() &&
				std::find_if(
					matchString.cbegin(),
					matchString.cend(),
					[](char c) { return !std::isdigit(c); }) == matchString.cend();

			if (isNumber)
			{
				int number = std::stoi(match[0]);
				position -= number;

				if (number <= 0 || number > Board::TOTAL_SQUARES)
				{
					throw;
				}

				squares.push_back(number);
			}
			else
			{
				position--;

				SetSquare(matchString, position);

				pieces.push_back(matchString);
			}

			matchable = match.suffix();
		}

		int totalOccupancy = std::accumulate(squares.cbegin(), squares.cend(), 0) + pieces.size();

		if (totalOccupancy != Board::SQUARES_PER_SIDE)
		{
			throw;
		}
	}
}

void PositionStringParser::SetSquare(const std::string& matchString, int position)
{
	auto mask = (I256{ 1 } << position);

	if (matchString == RED_PAWN)
	{
		rPawns |= mask;
	}
	else if (matchString == RED_KNIGHT)
	{
		rKnights |= mask;
	}
	else if (matchString == RED_BISHOP)
	{
		rBishops |= mask;
	}
	else if (matchString == RED_ROOK)
	{
		rRooks |= mask;
	}
	else if (matchString == RED_QUEEN || matchString == RED_NEW_QUEEN)
	{
		rQueens |= mask;
	}
	else if (matchString == RED_KING)
	{
		rKing |= mask;
	}
	else if (matchString == BLUE_PAWN)
	{
		bPawns |= mask;
	}
	else if (matchString == BLUE_KNIGHT)
	{
		bKnights |= mask;
	}
	else if (matchString == BLUE_BISHOP)
	{
		bBishops |= mask;
	}
	else if (matchString == BLUE_ROOK)
	{
		bRooks |= mask;
	}
	else if (matchString == BLUE_QUEEN || matchString == BLUE_NEW_QUEEN)
	{
		bQueens |= mask;
	}
	else if (matchString == BLUE_KING)
	{
		bKing |= mask;
	}
	else if (matchString == YELLOW_PAWN)
	{
		yPawns |= mask;
	}
	else if (matchString == YELLOW_KNIGHT)
	{
		yKnights |= mask;
	}
	else if (matchString == YELLOW_BISHOP)
	{
		yBishops |= mask;
	}
	else if (matchString == YELLOW_ROOK)
	{
		yRooks |= mask;
	}
	else if (matchString == YELLOW_QUEEN || matchString == YELLOW_NEW_QUEEN)
	{
		yQueens |= mask;
	}
	else if (matchString == YELLOW_KING)
	{
		yKing |= mask;
	}
	else if (matchString == GREEN_PAWN)
	{
		gPawns |= mask;
	}
	else if (matchString == GREEN_KNIGHT)
	{
		gKnights |= mask;
	}
	else if (matchString == GREEN_BISHOP)
	{
		gBishops |= mask;
	}
	else if (matchString == GREEN_ROOK)
	{
		gRooks |= mask;
	}
	else if (matchString == GREEN_QUEEN || matchString == GREEN_NEW_QUEEN)
	{
		gQueens |= mask;
	}
	else if (matchString == GREEN_KING)
	{
		gKing |= mask;
	}
}
