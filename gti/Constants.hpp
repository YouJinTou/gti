#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

enum PlayerColor
{
	Red,
	Blue,
	Yellow,
	Green
};

enum CastlingRight
{
	RedKingSide = 1,
	RedQueenSide = 2,
	BlueKingSide = 4,
	BlueQueenSide = 8,
	YellowKingSide = 16,
	YellowQueenSide = 32,
	GreenKingSide = 64,
	GreenQueenSide = 128,
};

inline CastlingRight operator|(CastlingRight a, CastlingRight b)
{
	return static_cast<CastlingRight>(static_cast<int>(a) | static_cast<int>(b));
}

#endif // !CONSTANTS_HPP
