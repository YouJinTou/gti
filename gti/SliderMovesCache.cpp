#include "SliderMovesCache.hpp"
#include "Board.hpp"

const std::set<int> SliderMovesCache::CORNERS
{
	1, 2, 3,
	12, 13, 14,
	15, 16, 17,
	26, 27, 28,
	29, 30, 31,
	40, 41, 42,
	155, 156, 157,
	166, 167, 168,
	169, 170, 171,
	180, 181, 182,
	183, 184, 185,
	194, 195, 196
};

const std::map<int, Border> SliderMovesCache::HORIZONTAL_BORDERS = InitializeHorizontalBorders();
const std::map<int, Border> SliderMovesCache::VERTICAL_BORDERS = InitializeVerticalBorders();

std::map<int, std::vector<I256>> SliderMovesCache::GetCache()
{
	std::map<int, std::vector<I256>> cache;

	for (int i = 1; i <= Board::TOTAL_SQUARES; i++)
	{
		I256 mask = (I256)1 << (Board::TOTAL_SQUARES - i);

		if ((mask & Board::CORNERS) != 0)
		{
			continue;
		}

		std::vector<I256> iterationCache;
		int downLeftUpRightShift = 15;
		int upLeftDownRightShift = 13;

		iterationCache.push_back(GetHorizontalMask(i));
		iterationCache.push_back(GetVerticalMask(i));
		iterationCache.push_back(GetDiagonalMask(i, downLeftUpRightShift));
		iterationCache.push_back(GetDiagonalMask(i, upLeftDownRightShift));

		cache.insert(std::make_pair(i, iterationCache));
	}

	return cache;
}

std::map<int, Border> SliderMovesCache::InitializeHorizontalBorders()
{
	std::map<int, Border> borders
	{
		{ 0, { 4, 11 } },
		{ 1, { 18, 25 } },
		{ 2, { 32, 39 } },
		{ 3, { 43, 56 } },
		{ 4, { 57, 70 } },
		{ 5, { 71, 84 } },
		{ 6, { 85, 98 } },
		{ 7, { 99, 112 } },
		{ 8, { 113, 126 } },
		{ 9, { 127, 140 } },
		{ 10, { 141, 154 } },
		{ 11, { 158, 165 } },
		{ 12, { 172, 179 } },
		{ 13, { 186, 193 } },
	};

	return borders;
}

std::map<int, Border> SliderMovesCache::InitializeVerticalBorders()
{
	std::map<int, Border> borders
	{
		{ 0, { 43, 141 } },
		{ 1, { 44, 142 } },
		{ 2, { 45, 143 } },
		{ 3, { 4, 186 } },
		{ 4, { 5, 187 } },
		{ 5, { 6, 188 } },
		{ 6, { 7, 189 } },
		{ 7, { 8, 190 } },
		{ 8, { 9, 191 } },
		{ 9, { 10, 192 } },
		{ 10, { 11, 193 } },
		{ 11, { 54, 152 } },
		{ 12, { 55, 153 } },
		{ 13, { 56, 154 } },
	};

	return borders;
}

I256 SliderMovesCache::GetHorizontalMask(int index)
{
	int row = index / Board::SQUARES_PER_SIDE;
	auto border = HORIZONTAL_BORDERS.at(row);
	I256 mask{ 0 };

	for (int i = border.point[0]; i <= border.point[1]; i++)
	{
		if (i != index)
		{
			mask |= ((I256)1 << (Board::TOTAL_SQUARES - i));
		}
	}

	return mask;
}

I256 SliderMovesCache::GetVerticalMask(int index)
{
	int column = SliderMovesCache::GetZeroBasedColumnIndex(index);
	auto border = VERTICAL_BORDERS.at(column);
	I256 mask{ 0 };

	for (int i = border.point[0]; i <= border.point[1]; i += Board::SQUARES_PER_SIDE)
	{
		if (i != index)
		{
			mask |= ((I256)1 << (Board::TOTAL_SQUARES - i));
		}
	}

	return mask;
}

I256 SliderMovesCache::GetDiagonalMask(int index, int shift)
{
	I256 mask{ 0 };
	int initialCol = SliderMovesCache::GetZeroBasedColumnIndex(index);
	int lastCol = initialCol;

	for (int i = index - shift; i > 0; i -= shift)
	{
		if (SliderMovesCache::CORNERS.find(i) != SliderMovesCache::CORNERS.end())
		{
			break;
		}

		int currentCol = SliderMovesCache::GetZeroBasedColumnIndex(i);

		if (std::abs((lastCol - currentCol)) != 1)
		{
			break;
		}

		lastCol = currentCol;
		mask |= ((I256)1 << (Board::TOTAL_SQUARES - i));
	}

	lastCol = initialCol;

	for (int i = index + shift; i < Board::TOTAL_SQUARES; i += shift)
	{
		if (SliderMovesCache::CORNERS.find(i) != SliderMovesCache::CORNERS.end())
		{
			break;
		}

		int currentCol = SliderMovesCache::GetZeroBasedColumnIndex(i);

		if (std::abs((currentCol - lastCol)) != 1)
		{
			break;
		}

		lastCol = currentCol;
		mask |= ((I256)1 << (Board::TOTAL_SQUARES - i));
	}

	return mask;
}

int SliderMovesCache::GetZeroBasedColumnIndex(int index)
{
	int col = (index % Board::SQUARES_PER_SIDE) - 1;
	col = (col == -1) ? (Board::SQUARES_PER_SIDE - 1) : col;

	return col;
}
