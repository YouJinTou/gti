#include "stdafx.h"
#include "CppUnitTest.h"
#include <vector>

#include "../gti/Board.hpp"
#include "../gti/MoveGenerator.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace gtiTests
{
	TEST_CLASS(MoveGeneratorTests)
	{
	public:
		TEST_METHOD(GetPawnMoves_InitialBoard_ValidRedMoves)
		{
			Board board{};

			board.SetToMove(PlayerColor::Red);
			
			MoveGenerator generator{ board };
			auto moves = generator.GetPawnMoves();
			std::vector<Move> expectedMoves
			{
				Move{ 18, 32 },
				Move{ 18, 46 },
				Move{ 19, 33 },
				Move{ 19, 47 },
				Move{ 20, 34 },
				Move{ 20, 48 },
				Move{ 21, 35 },
				Move{ 21, 49 },
				Move{ 22, 36 },
				Move{ 22, 50 },
				Move{ 23, 37 },
				Move{ 23, 51 },
				Move{ 24, 38 },
				Move{ 24, 52 },
				Move{ 25, 39 },
				Move{ 25, 53 }
			};

			for (auto move : expectedMoves)
			{
				if (std::find(moves.begin(), moves.end(), move) == moves.end())
				{
					Assert::Fail();
				}
			}
		}
	};
}