#include <iostream>
#include "Board.hpp"
#include "BoardDrawer.hpp"

int main() 
{
	BoardDrawer bd{ Board() };

	bd.DrawBoard();

	std::getchar();

	return 0;
}