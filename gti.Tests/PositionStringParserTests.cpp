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
		TEST_METHOD(ParsePositionString_InitialString_InitialBoard)
		{
			PositionStringParser parser{};
			Board board{};
			auto parsedBoard = parser.ParsePositionString(PositionStringParser::INITIAL_STRING);

			Assert::AreEqual(board.GetRed().str(), parsedBoard.GetRed().str());
			Assert::AreEqual(board.GetBlue().str(), parsedBoard.GetBlue().str());
			Assert::AreEqual(board.GetYellow().str(), parsedBoard.GetYellow().str());
			Assert::AreEqual(board.GetGreen().str(), parsedBoard.GetGreen().str());
			Assert::AreEqual(board.GetEmptySquares().str(), parsedBoard.GetEmptySquares().str());
		}
	};
}