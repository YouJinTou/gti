#include "Utils.hpp"

void Utils::PrintBinary(I256 n)
{
	for (int i = 196; i >= 0; i--)
	{
		std::cout << ((n >> i) & 1);
	}

	std::cout << std::endl << std::endl;
}

I256 Utils::ReverseBits(I256 n)
{
	I256 reversed{ 0 };

	for (size_t i = 0; i < 196; i++)
	{
		reversed |= (((n >> i) & 1) << (196 - i));
	}

	return reversed;
}