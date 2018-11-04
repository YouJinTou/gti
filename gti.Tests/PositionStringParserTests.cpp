#include "stdafx.h"
#include "CppUnitTest.h"

#include "../gti/Board.hpp"
#include "../gti/PositionStringParser.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace gtiTests
{
	TEST_CLASS(PositionStringParserTests)
	{
	public:
		TEST_METHOD(ParsePositionString_InitialString_Red)
		{
			PositionStringParser parser{};
			Board board{};
			auto parsedBoard = parser.ParsePositionString(PositionStringParser::INITIAL_STRING);

			Assert::AreEqual(board.GetRed().str(), parsedBoard.GetRed().str());
		}
		TEST_METHOD(ParsePositionString_InitialString_Blue)
		{
			PositionStringParser parser{};
			Board board{};
			auto parsedBoard = parser.ParsePositionString(PositionStringParser::INITIAL_STRING);

			Assert::AreEqual(board.GetBlue().str(), parsedBoard.GetBlue().str());
		}
		TEST_METHOD(ParsePositionString_InitialString_Yellow)
		{
			PositionStringParser parser{};
			Board board{};
			auto parsedBoard = parser.ParsePositionString(PositionStringParser::INITIAL_STRING);

			Assert::AreEqual(board.GetYellow().str(), parsedBoard.GetYellow().str());
		}
		TEST_METHOD(ParsePositionString_InitialString_Green)
		{
			PositionStringParser parser{};
			Board board{};
			auto parsedBoard = parser.ParsePositionString(PositionStringParser::INITIAL_STRING);

			Assert::AreEqual(board.GetGreen().str(), parsedBoard.GetGreen().str());
		}
		TEST_METHOD(ParsePositionString_InitialString_EmptySquares)
		{
			PositionStringParser parser{};
			Board board{};
			auto parsedBoard = parser.ParsePositionString(PositionStringParser::INITIAL_STRING);

			Assert::AreEqual(board.GetEmptySquares().str(), parsedBoard.GetEmptySquares().str());
		}
		TEST_METHOD(ParsePositionString_InitialString_ToMove)
		{
			PositionStringParser parser{};
			Board board{};
			auto parsedBoard = parser.ParsePositionString(PositionStringParser::INITIAL_STRING);

			Assert::AreEqual((int)board.ToMove(), (int)parsedBoard.ToMove());
		}
		TEST_METHOD(ParsePositionString_InitialString_CastlingRights)
		{
			PositionStringParser parser{};
			Board board{};
			auto parsedBoard = parser.ParsePositionString(PositionStringParser::INITIAL_STRING);

			Assert::AreEqual(board.GetCastlingRights(), parsedBoard.GetCastlingRights());
		}
		TEST_METHOD(ParsePositionString_InitialString_RemainingPlayers)
		{
			PositionStringParser parser{};
			Board board{};
			auto parsedBoard = parser.ParsePositionString(PositionStringParser::INITIAL_STRING);

			Assert::AreEqual(board.GetRemainingPlayers(), parsedBoard.GetRemainingPlayers());
		}
		TEST_METHOD(ParsePositionString_InitialString_HalfMoveClock)
		{
			PositionStringParser parser{};
			Board board{};
			auto parsedBoard = parser.ParsePositionString(PositionStringParser::INITIAL_STRING);

			Assert::AreEqual(board.GetHalfMoveClock(), parsedBoard.GetHalfMoveClock());
		}
		TEST_METHOD(ParsePositionString_InitialString_FullMoveNumber)
		{
			PositionStringParser parser{};
			Board board{};
			auto parsedBoard = parser.ParsePositionString(PositionStringParser::INITIAL_STRING);

			Assert::AreEqual(board.GetFullMoveNumber(), parsedBoard.GetFullMoveNumber());
		}
	};
}