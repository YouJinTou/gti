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
	const I256 RED_PROMOTION_RANK{ "5191979945884770571180122153418752" };
private:
	const Board& board;
private:
	std::vector<I256> GetPawnMoves() const;
	std::vector<I256> GetRedPawnMoves() const;
	std::vector<I256> GetBluePawnMoves() const;
	std::vector<I256> GetYellowPawnMoves() const;
	std::vector<I256> GetGreenPawnMoves() const;
private:
	std::vector<I256> GetKnightMoves() const;
	std::vector<I256> GetBishopMoves() const;
	std::vector<I256> GetRookMoves() const;
	std::vector<I256> GetQueenMoves() const;
	std::vector<I256> GetKingMoves() const;
};

#endif // !MOVE_GENERATOR_HPP
