#ifndef SLIDER_MOVES_CACHE_HPP
#define SLIDER_MOVES_CACHE_HPP

#include <map>
#include <set>
#include <vector>

#include "Typedefs.hpp"

struct Border
{
	int point[2];
};

class SliderMovesCache
{
public:
	static std::map<int, std::vector<I256>> GetCache();
private:
	static const std::set<int> CORNERS;
	static const std::map<int, Border> HORIZONTAL_BORDERS;
	static const std::map<int, Border> VERTICAL_BORDERS;
private:
	static std::map<int, Border> InitializeHorizontalBorders();
	static std::map<int, Border> InitializeVerticalBorders();
	static I256 GetHorizontalMask(int horizontalIndex);
	static I256 GetVerticalMask(int verticalIndex);
};

#endif // !SLIDER_MOVES_CACHE_HPP
