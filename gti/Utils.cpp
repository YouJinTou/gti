#include "Utils.hpp"

void Utils::PrintBinary(I256 n)
{
	for (int i = 195; i >= 0; i--)
	{
		std::cout << ((n >> i) & 1);
	}
}