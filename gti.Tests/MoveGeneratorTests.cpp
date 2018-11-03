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
				Move{ 142, 144 }
			};

			ValidateGeneratedMoves(moves, expectedMoves);
		}
		TEST_METHOD(GetPawnMoves_InitialBoard_ValidYellowMoves)
		{
			Board board{};

			board.SetToMove(PlayerColor::Yellow);

			MoveGenerator generator{ board };
			auto moves = generator.GetPawnMoves();
			std::vector<Move> expectedMoves
			{
				Move{ 172, 158 },
				Move{ 173, 159 },
				Move{ 174, 160 },
				Move{ 175, 161 },
				Move{ 176, 162 },
				Move{ 177, 163 },
				Move{ 178, 164 },
				Move{ 179, 165 },
				Move{ 172, 144 },
				Move{ 173, 145 },
				Move{ 174, 146 },
				Move{ 175, 147 },
				Move{ 176, 148 },
				Move{ 177, 149 },
				Move{ 178, 150 },
				Move{ 179, 151 }
			};

			ValidateGeneratedMoves(moves, expectedMoves);
		}
		TEST_METHOD(GetPawnMoves_InitialBoard_ValidGreenMoves)
		{
			Board board{};

			board.SetToMove(PlayerColor::Green);

			MoveGenerator generator{ board };
			auto moves = generator.GetPawnMoves();
			std::vector<Move> expectedMoves
			{
				Move{ 55, 54 },
				Move{ 69, 68 },
				Move{ 83, 82 },
				Move{ 97, 96 },
				Move{ 111, 110 },
				Move{ 125, 124 },
				Move{ 139, 138 },
				Move{ 153, 152 },
				Move{ 55, 53 },
				Move{ 69, 67 },
				Move{ 83, 81 },
				Move{ 97, 95 },
				Move{ 111, 109 },
				Move{ 125, 123 },
				Move{ 139, 137 },
				Move{ 153, 151 },
			};

			ValidateGeneratedMoves(moves, expectedMoves);
		}
		TEST_METHOD(GetKnightMoves_InitialBoard_ValidRedMoves)
		{
			Board board{};

			board.SetToMove(PlayerColor::Red);

			MoveGenerator generator{ board };
			auto moves = generator.GetKnightMoves();
			std::vector<Move> expectedMoves
			{
				Move{ 5, 32 },
				Move{ 5, 34 },
				Move{ 10, 37 },
				Move{ 10, 39 }
			};

			ValidateGeneratedMoves(moves, expectedMoves);
		}
		TEST_METHOD(GetKnightMoves_InitialBoard_ValidBlueMoves)
		{
			Board board{};

			board.SetToMove(PlayerColor::Blue);

			MoveGenerator generator{ board };
			auto moves = generator.GetKnightMoves();
			std::vector<Move> expectedMoves
			{
				Move{ 57, 45 },
				Move{ 57, 73 },
				Move{ 127, 115 },
				Move{ 127, 143 }
			};

			ValidateGeneratedMoves(moves, expectedMoves);
		}
		TEST_METHOD(GetKnightMoves_InitialBoard_ValidYellowMoves)
		{
			Board board{};

			board.SetToMove(PlayerColor::Yellow);

			MoveGenerator generator{ board };
			auto moves = generator.GetKnightMoves();
			std::vector<Move> expectedMoves
			{
				Move{ 187, 158 },
				Move{ 187, 160 },
				Move{ 192, 163 },
				Move{ 192, 165 }
			};

			ValidateGeneratedMoves(moves, expectedMoves);
		}
		TEST_METHOD(GetKnightMoves_InitialBoard_ValidGreenMoves)
		{
			Board board{};

			board.SetToMove(PlayerColor::Green);

			MoveGenerator generator{ board };
			auto moves = generator.GetKnightMoves();
			std::vector<Move> expectedMoves
			{
				Move{ 70, 54 },
				Move{ 70, 82 },
				Move{ 140, 124 },
				Move{ 140, 152 }				
			};

			ValidateGeneratedMoves(moves, expectedMoves);
		}
	private:
		void ValidateGeneratedMoves(std::vector<Move>& moves, std::vector<Move>& expectedMoves)
		{
			Assert::AreEqual(expectedMoves.size(), moves.size());

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