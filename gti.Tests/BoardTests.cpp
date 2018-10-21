#include "stdafx.h"
#include "CppUnitTest.h"

#include "../gti/Board.hpp"
#include "../gti/Board.cpp"

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
	};
}