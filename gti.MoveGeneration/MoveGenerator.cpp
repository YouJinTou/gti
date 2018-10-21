#include "MoveGenerator.hpp"

MoveGenerator::MoveGenerator(const Board& board) :
	board{ board }
{
}

std::vector<I256> MoveGenerator::GetMoves() const
{
	std::vector<I256> moves;
	auto pawnMoves = GetPawnMoves();
	auto knightMoves = GetKnightMoves();
	auto bishopMoves = GetBishopMoves();
	auto rookMoves = GetRookMoves();
	auto queenMoves = GetQueenMoves();
	auto kingMoves = GetKingMoves();

	moves.insert(moves.end(), pawnMoves.cbegin(), pawnMoves.cend());
	moves.insert(moves.end(), knightMoves.cbegin(), knightMoves.cend());
	moves.insert(moves.end(), bishopMoves.cbegin(), bishopMoves.cend());
	moves.insert(moves.end(), rookMoves.cbegin(), rookMoves.cend());
	moves.insert(moves.end(), queenMoves.cbegin(), queenMoves.cend());
	moves.insert(moves.end(), kingMoves.cbegin(), kingMoves.cend());

	return moves;
}

std::vector<I256> MoveGenerator::GetPawnMoves() const
{
	return std::vector<I256>();
}

std::vector<I256> MoveGenerator::GetKnightMoves() const
{
	return std::vector<I256>();
}

std::vector<I256> MoveGenerator::GetBishopMoves() const
{
	return std::vector<I256>();
}

std::vector<I256> MoveGenerator::GetRookMoves() const
{
	return std::vector<I256>();
}

std::vector<I256> MoveGenerator::GetQueenMoves() const
{
	return std::vector<I256>();
}

std::vector<I256> MoveGenerator::GetKingMoves() const
{
	return std::vector<I256>();
}
