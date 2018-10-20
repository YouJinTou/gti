#include "Board.hpp"

const std::string Board::RED_PAWNS{ "763254615079690740002692367037751644185114211243786240" };
const std::string Board::RED_KNIGHTS{ "3236630582308757268852828921341452995802777026051767795712" };
const std::string Board::RED_BISHOPS{ "1765434863077503964828815775277156179528787468755509706752" };
const std::string Board::RED_ROOKS{ "6326141592694389207303256528076476309978155096373909782528" };
const std::string Board::RED_QUEENS{ "784637716923335095479473677900958302012794430558004314112" };
const std::string Board::RED_KING{ "392318858461667547739736838950479151006397215279002157056" };
const std::string Board::BLUE_PAWNS{ "2787763301385015942981453398180054664478720" };
const std::string Board::BLUE_KNIGHTS{ "85070591730234615865915709451979980800" };
const std::string Board::BLUE_BISHOPS{ "5192296858536008220151213740523520" };
const std::string Board::BLUE_ROOKS{ "1393796574908163946345982392044920640634880" };
const std::string Board::BLUE_QUEENS{ "316912650057057350374175801344" };
const std::string Board::BLUE_KING{ "19342813113834066795298816" };
const std::string Board::YELLOW_PAWNS{ "33423360" };
const std::string Board::YELLOW_KNIGHTS{ "528" };
const std::string Board::YELLOW_BISHOPS{ "288" };
const std::string Board::YELLOW_ROOKS{ "1032" };
const std::string Board::YELLOW_QUEENS{ "128" };
const std::string Board::YELLOW_KING{ "64" };
const std::string Board::GREEN_PAWNS{ "5709339241236512651226016559472751952852418560" };
const std::string Board::GREEN_KNIGHTS{ "696898287454081973173581491830620002713600" };
const std::string Board::GREEN_BISHOPS{ "42535295865126979339478742962368675840" };
const std::string Board::GREEN_ROOKS{ "11417981541647679048466287755631989888080936960" };
const std::string Board::GREEN_QUEENS{ "158456325028528675187087900672" };
const std::string Board::GREEN_KING{ "2596148429267413814265248164610048" };

Board::Board() :
	rPawns{ RED_PAWNS },
	rKnights{ RED_KNIGHTS },
	rBishops{ RED_BISHOPS },
	rRooks{ RED_ROOKS },
	rQueens{ RED_QUEENS },
	rKing{ RED_KING },
	bPawns{ BLUE_PAWNS },
	bKnights{ BLUE_KNIGHTS },
	bBishops{ BLUE_BISHOPS },
	bRooks{ BLUE_ROOKS },
	bQueens{ BLUE_QUEENS },
	bKing{ BLUE_KING },
	yPawns{ YELLOW_PAWNS },
	yKnights{ YELLOW_KNIGHTS },
	yBishops{ YELLOW_BISHOPS },
	yRooks{ YELLOW_ROOKS },
	yQueens{ YELLOW_QUEENS },
	yKing{ YELLOW_KING },
	gPawns{ GREEN_PAWNS },
	gKnights{ GREEN_KNIGHTS },
	gBishops{ GREEN_BISHOPS },
	gRooks{ GREEN_ROOKS },
	gQueens{ GREEN_QUEENS },
	gKing{ GREEN_KING }
{
}

I256 Board::getRedPawns() const
{
	return rPawns;
}

I256 Board::getRedKnights() const
{
	return rKnights;
}

I256 Board::getRedBishops() const
{
	return rBishops;
}

I256 Board::getRedRooks() const
{
	return rRooks;
}

I256 Board::getRedQueens() const
{
	return rQueens;
}

I256 Board::getRedKing() const
{
	return rKing;
}

I256 Board::getBluePawns() const
{
	return bPawns;
}

I256 Board::getBlueKnights() const
{
	return bKnights;
}

I256 Board::getBlueBishops() const
{
	return bBishops;
}

I256 Board::getBlueRooks() const
{
	return bRooks;
}

I256 Board::getBlueQueens() const
{
	return bQueens;
}

I256 Board::getBlueKing() const
{
	return bKing;
}

I256 Board::getYellowPawns() const
{
	return yPawns;
}

I256 Board::getYellowKnights() const
{
	return yKnights;
}

I256 Board::getYellowBishops() const
{
	return yBishops;
}

I256 Board::getYellowRooks() const
{
	return yRooks;
}

I256 Board::getYellowQueens() const
{
	return yQueens;
}

I256 Board::getYellowKing() const
{
	return yKing;
}

I256 Board::getGreenPawns() const
{
	return gPawns;
}

I256 Board::getGreenKnights() const
{
	return gKnights;
}

I256 Board::getGreenBishops() const
{
	return gBishops;
}

I256 Board::getGreenRooks() const
{
	return gRooks;
}

I256 Board::getGreenQueens() const
{
	return gQueens;
}

I256 Board::getGreenKing() const
{
	return gKing;
}