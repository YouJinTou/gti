#include "stdafx.h"
#include "CppUnitTest.h"

#include "../gti/Board.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace gtiTests
{		
	TEST_CLASS(BoardTests)
	{
	public:
		TEST_METHOD(GetEmptySquares_InitialBoard_EmptySquares)
		{
			Board board{};
			auto emptySquares = board.GetEmptySquares();
			I256 expectedEmptySquares{ "46591068453637164260361794096484197643923981598720" };

			Assert::AreEqual(emptySquares.str(), expectedEmptySquares.str());
		}

		TEST_METHOD(GetRed_InitialBoard_Red)
		{
			Board board{};
			auto red = board.GetRed();
			I256 expectedRed{ "12505926868080732774944114433913560689973096351229437542400" };

			Assert::AreEqual(red.str(), expectedRed.str());
		}

		TEST_METHOD(GetBlue_InitialBoard_Blue)
		{
			Board board{};
			auto blue = board.GetBlue();
			I256 expectedBlue{ "4181644952077523914472180097270081996718080" };

			Assert::AreEqual(blue.str(), expectedBlue.str());
		}

		TEST_METHOD(GetYellow_InitialBoard_Yellow)
		{
			Board board{};
			auto yellow = board.GetYellow();
			I256 expectedYellow{ "33425400" };

			Assert::AreEqual(yellow.str(), expectedYellow.str());
		}

		TEST_METHOD(GetGreen_InitialBoard_Green)
		{
			Board board{};
			auto green = board.GetGreen();
			I256 expectedGreen{ "17128017723709537953678049678418255858557255680" };

			Assert::AreEqual(green.str(), expectedGreen.str());
		}
	};
}