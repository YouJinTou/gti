#ifndef MOVE_GENERATOR_HPP
#define MOVE_GENERATOR_HPP

#include <map>
#include <vector>

#include "Board.hpp"
#include "SliderMovesCache.hpp"
#include "Typedefs.hpp"
#include "Types.hpp"

class MoveGenerator
{
public:
	MoveGenerator(const Board& board);
	std::vector<Move> GetMoves() const;
	std::vector<Move> GetPawnMoves() const;
	std::vector<Move> GetKnightMoves() const;
	std::vector<Move> GetSliderMoves() const;
	std::vector<Move> GetKingMoves() const;
private:
	static constexpr int RED_PAWN_FORWARD_MOVE_SHIFT = 14;
	static constexpr int RED_PAWN_LEFT_CAPTURE_SHIFT = 15;
	static constexpr int RED_PAWN_RIGHT_CAPTURE_SHIFT = 13;
	static constexpr int BLUE_PAWN_FORWARD_MOVE_SHIFT = 1;
	static constexpr int BLUE_PAWN_LEFT_CAPTURE_SHIFT = 15;
	static constexpr int BLUE_PAWN_RIGHT_CAPTURE_SHIFT = 13;
	static constexpr int YELLOW_PAWN_FORWARD_MOVE_SHIFT = 14;
	static constexpr int YELLOW_PAWN_LEFT_CAPTURE_SHIFT = 13;
	static constexpr int YELLOW_PAWN_RIGHT_CAPTURE_SHIFT = 15;
	static constexpr int GREEN_PAWN_FORWARD_MOVE_SHIFT = 1;
	static constexpr int GREEN_PAWN_LEFT_CAPTURE_SHIFT = 15;
	static constexpr int GREEN_PAWN_RIGHT_CAPTURE_SHIFT = 13;
	static constexpr int KNIGHT_NNE_SHIFT = 29;
	static constexpr int KNIGHT_NE_SHIFT = 16;
	static constexpr int KNIGHT_SE_SHIFT = 12;
	static constexpr int KNIGHT_SSE_SHIFT = 27;
	static constexpr int KNIGHT_SSW_SHIFT = 29;
	static constexpr int KNIGHT_SW_SHIFT = 16;
	static constexpr int KNIGHT_NW_SHIFT = 12;
	static constexpr int KNIGHT_NNW_SHIFT = 27;
	static const I256 RANK_MASKS[14];
	static const I256 FILE_MASKS[14];
private:
	const Board& board;
	const SliderMovesCache cacheGenerator;
private:
	std::map<int, std::vector<I256>> cache;
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
	std::vector<Move> GetKnightMoves(I256 knights, I256 othersPieces) const;
	std::vector<Move> GetSliderMoves(I256 bishops, I256 rooks, I256 queens) const;
	std::vector<Move> GetSliderMoves(I256 slider, I256 mask) const;
};

#endif // !MOVE_GENERATOR_HPP
