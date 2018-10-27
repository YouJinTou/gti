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
				Move{ 19, 33 },
				Move{ 20, 34 },
				Move{ 21, 35 },
				Move{ 22, 36 },
				Move{ 23, 37 },
				Move{ 24, 38 },
				Move{ 25, 39 },
				Move{ 18, 46 },
				Move{ 19, 47 },
				Move{ 20, 48 },
				Move{ 21, 49 },
				Move{ 22, 50 },
				Move{ 23, 51 },
				Move{ 24, 52 },
				Move{ 25, 53 }
			};

			ValidateGeneratedMoves(moves, expectedMoves);
		}
		TEST_METHOD(GetPawnMoves_InitialBoard_ValidBlueMoves)
		{
			Board board{};

			board.SetToMove(PlayerColor::Blue);

			MoveGenerator generator{ board };
			auto moves = generator.GetPawnMoves();
			std::vector<Move> expectedMoves
			{
				Move{ 44, 45 },
				Move{ 58, 59 },
				Move{ 72, 73 },
				Move{ 86, 87 },
				Move{ 100, 101 },
				Move{ 114, 115 },
				Move{ 128, 129 },
				Move{ 142, 143 },
				Move{ 44, 46 },
				Move{ 58, 60 },
				Move{ 72, 74 },
				Move{ 86, 88 },
				Move{ 100, 102 },
				Move{ 114, 116 },
				Move{ 128, 130 },
				Move{ 142, 144 },
			};

			ValidateGeneratedMoves(moves, expectedMoves);
		}
	private:
		void ValidateGeneratedMoves(std::vector<Move>& moves, std::vector<Move>& expectedMoves)
		{
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