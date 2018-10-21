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
	const Board& board;
private:
	std::vector<I256> GetPawnMoves() const;
	std::vector<I256> GetKnightMoves() const;
	std::vector<I256> GetBishopMoves() const;
	std::vector<I256> GetRookMoves() const;
	std::vector<I256> GetQueenMoves() const;
	std::vector<I256> GetKingMoves() const;
};

#endif // !MOVE_GENERATOR_HPP
