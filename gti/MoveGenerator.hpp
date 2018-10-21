#ifndef MOVE_GENERATOR_HPP
#define MOVE_GENERATOR_HPP

#include <vector>

#include "Board.hpp"
#include "Typedefs.hpp"

class MoveGenerator
{
public:
	MoveGenerator(const Board& board);
	std::vector<I256> GetMoves() const;
private:
	static constexpr int RED_PAWN_FORWARD_MOVE_SHIFT = 14;
	static constexpr int RED_PAWN_LEFT_CAPTURE_SHIFT = 15;
	static constexpr int RED_PAWN_RIGHT_CAPTURE_SHIFT = 13;
private:
	const Board& board;
private:
	std::vector<I256> GetPawnMoves() const;
	std::vector<I256> GetPawnMoves(
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
	std::vector<I256> GetKnightMoves() const;
	std::vector<I256> GetBishopMoves() const;
	std::vector<I256> GetRookMoves() const;
	std::vector<I256> GetQueenMoves() const;
	std::vector<I256> GetKingMoves() const;
};

#endif // !MOVE_GENERATOR_HPP
