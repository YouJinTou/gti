#ifndef MOVE_GENERATOR_HPP
#define MOVE_GENERATOR_HPP

#include <vector>

#include "Board.hpp"
#include "Typedefs.hpp"
#include "Types.hpp"

class MoveGenerator
{
public:
	MoveGenerator(const Board& board);
	std::vector<Move> GetMoves() const;
	std::vector<Move> GetPawnMoves() const;
	std::vector<Move> GetKnightMoves() const;
	std::vector<Move> GetBishopMoves() const;
	std::vector<Move> GetRookMoves() const;
	std::vector<Move> GetQueenMoves() const;
	std::vector<Move> GetKingMoves() const;
private:
	static constexpr int RED_PAWN_FORWARD_MOVE_SHIFT = 14;
	static constexpr int RED_PAWN_LEFT_CAPTURE_SHIFT = 15;
	static constexpr int RED_PAWN_RIGHT_CAPTURE_SHIFT = 13;
	static constexpr int BLUE_PAWN_FORWARD_MOVE_SHIFT = 1;
	static constexpr int BLUE_PAWN_LEFT_CAPTURE_SHIFT = 15;
	static constexpr int BLUE_PAWN_RIGHT_CAPTURE_SHIFT = 13;
private:
	const Board& board;
private:
	std::vector<Move> GetPawnMoves(
		I256 pawns,
		bool increasing,
		int forwardShift,
		int leftShift,
		int rightShift,
		I256 twoForwardLine,
		I256 othersPieces,
		I256 promotionLine,
		I256 leftCaptureOpposingLine,
		I256 rightCaptureOpposingLine) const;
};

#endif // !MOVE_GENERATOR_HPP
