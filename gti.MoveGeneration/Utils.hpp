#ifndef UTILS_HPP
#define UTILS_HPP

#include "Typedefs.hpp"

class Utils 
{
private:
	typedef boost::multiprecision::uint256_t I256;
public:
	void PrintBinary(I256 n) const;
};

#endif // !UTILS_HPP
