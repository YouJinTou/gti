#include "Board.hpp"

const I256 Board::EMPTY_BOARD{ "12505926914688933427949940309752947308315809521094006540280" };
const I256 Board::RED_PAWNS_INITIAL{ "763254615079690740002692367037751644185114211243786240" };
const I256 Board::RED_KNIGHTS_INITIAL{ "3236630582308757268852828921341452995802777026051767795712" };
const I256 Board::RED_BISHOPS_INITIAL{ "1765434863077503964828815775277156179528787468755509706752" };
const I256 Board::RED_ROOKS_INITIAL{ "6326141592694389207303256528076476309978155096373909782528" };
const I256 Board::RED_QUEENS_INITIAL{ "784637716923335095479473677900958302012794430558004314112" };
const I256 Board::RED_KING_INITIAL{ "392318858461667547739736838950479151006397215279002157056" };
const I256 Board::BLUE_PAWNS_INITIAL{ "5709339241236512651226016559472751952852418560" };
const I256 Board::BLUE_KNIGHTS_INITIAL{ "696898287454081973173581491830620002713600" };
const I256 Board::BLUE_BISHOPS_INITIAL{ "42535295865126979339478742962368675840" };
const I256 Board::BLUE_ROOKS_INITIAL{ "11417981541647679048466287755631989888080936960" };
const I256 Board::BLUE_QUEENS_INITIAL{ "2596148429267413814265248164610048" };
const I256 Board::BLUE_KING_INITIAL{ "158456325028528675187087900672" };
const I256 Board::YELLOW_PAWNS_INITIAL{ "33423360" };
const I256 Board::YELLOW_KNIGHTS_INITIAL{ "528" };
const I256 Board::YELLOW_BISHOPS_INITIAL{ "288" };
const I256 Board::YELLOW_ROOKS_INITIAL{ "1032" };
const I256 Board::YELLOW_QUEENS_INITIAL{ "128" };
const I256 Board::YELLOW_KING_INITIAL{ "64" };
const I256 Board::GREEN_PAWNS_INITIAL{ "2787763301385015942981453398180054664478720" };
const I256 Board::GREEN_KNIGHTS_INITIAL{ "85070591730234615865915709451979980800" };
const I256 Board::GREEN_BISHOPS_INITIAL{ "5192296858536008220151213740523520" };
const I256 Board::GREEN_ROOKS_INITIAL{ "1393796574908163946345982392044920640634880" };
const I256 Board::GREEN_QUEENS_INITIAL{ "19342813113834066795298816" };
const I256 Board::GREEN_KING_INITIAL{ "316912650057057350374175801344" };
const I256 Board::CORNERS{ "87927700851497958793422690461569715349321877590330545666055" };
const I256 Board::FILE_A{ "11418678482473025302452033118945503905704837120" };
const I256 Board::FILE_D{ "6277484882657350768155134829386217820998656632002608890880" };
const I256 Board::FILE_G{ "784685610332168846019391853673277227624832079000326111360" };
const I256 Board::FILE_H{ "392342805166084423009695926836638613812416039500163055680" };
const I256 Board::FILE_K{ "49042850645760552876211990854579826726552004937520381960" };
const I256 Board::FILE_N{ "50219879061258806145241078635089742567989253056020871127040" };
const I256 Board::RANK_1{ "100427497784023428665939197383214061420903212154935817797632" };
const I256 Board::RANK_4{ "22834569286720449932986229528799881659529822208" };
const I256 Board::RANK_7{ "5191979945884770571180122153418752" };
const I256 Board::RANK_8{ "316893307243943516307380502528" };
const I256 Board::RANK_11{ "72053195991416832" };
const I256 Board::RANK_14{ "16383" };

Board::Board() :
	toMove{ PlayerColor::Red },
	rPawns{ RED_PAWNS_INITIAL },
	rKnights{ RED_KNIGHTS_INITIAL },
	rBishops{ RED_BISHOPS_INITIAL },
	rRooks{ RED_ROOKS_INITIAL },
	rQueens{ RED_QUEENS_INITIAL },
	rKing{ RED_KING_INITIAL },
	bPawns{ BLUE_PAWNS_INITIAL },
	bKnights{ BLUE_KNIGHTS_INITIAL },
	bBishops{ BLUE_BISHOPS_INITIAL },
	bRooks{ BLUE_ROOKS_INITIAL },
	bQueens{ BLUE_QUEENS_INITIAL },
	bKing{ BLUE_KING_INITIAL },
	yPawns{ YELLOW_PAWNS_INITIAL },
	yKnights{ YELLOW_KNIGHTS_INITIAL },
	yBishops{ YELLOW_BISHOPS_INITIAL },
	yRooks{ YELLOW_ROOKS_INITIAL },
	yQueens{ YELLOW_QUEENS_INITIAL },
	yKing{ YELLOW_KING_INITIAL },
	gPawns{ GREEN_PAWNS_INITIAL },
	gKnights{ GREEN_KNIGHTS_INITIAL },
	gBishops{ GREEN_BISHOPS_INITIAL },
	gRooks{ GREEN_ROOKS_INITIAL },
	gQueens{ GREEN_QUEENS_INITIAL },
	gKing{ GREEN_KING_INITIAL }
{
}

PlayerColor Board::ToMove() const
{
	return toMove;
}

void Board::SetToMove(PlayerColor player)
{
	toMove = player;
}

I256 Board::GetRed() const
{
	return rPawns | rKnights | rBishops | rRooks | rQueens | rKing;
}

I256 Board::GetRedPawns() const
{
	return rPawns;
}

I256 Board::GetRedKnights() const
{
	return rKnights;
}

I256 Board::GetRedBishops() const
{
	return rBishops;
}

I256 Board::GetRedRooks() const
{
	return rRooks;
}

I256 Board::GetRedQueens() const
{
	return rQueens;
}

I256 Board::GetRedKing() const
{
	return rKing;
}

I256 Board::GetBlue() const
{
	return bPawns | bKnights | bBishops | bRooks | bQueens | bKing;
}

I256 Board::GetBluePawns() const
{
	return bPawns;
}

I256 Board::GetBlueKnights() const
{
	return bKnights;
}

I256 Board::GetBlueBishops() const
{
	return bBishops;
}

I256 Board::GetBlueRooks() const
{
	return bRooks;
}

I256 Board::GetBlueQueens() const
{
	return bQueens;
}

I256 Board::GetBlueKing() const
{
	return bKing;
}

I256 Board::GetYellow() const
{
	return yPawns | yKnights | yBishops | yRooks | yQueens | yKing;
}

I256 Board::GetYellowPawns() const
{
	return yPawns;
}

I256 Board::GetYellowKnights() const
{
	return yKnights;
}

I256 Board::GetYellowBishops() const
{
	return yBishops;
}

I256 Board::GetYellowRooks() const
{
	return yRooks;
}

I256 Board::GetYellowQueens() const
{
	return yQueens;
}

I256 Board::GetYellowKing() const
{
	return yKing;
}

I256 Board::GetGreen() const
{
	return gPawns | gKnights | gBishops | gRooks | gQueens | gKing;
}

I256 Board::GetGreenPawns() const
{
	return gPawns;
}

I256 Board::GetGreenKnights() const
{
	return gKnights;
}

I256 Board::GetGreenBishops() const
{
	return gBishops;
}

I256 Board::GetGreenRooks() const
{
	return gRooks;
}

I256 Board::GetGreenQueens() const
{
	return gQueens;
}

I256 Board::GetGreenKing() const
{
	return gKing;
}

I256 Board::GetEmptySquares() const
{
	return
		EMPTY_BOARD ^
		rPawns ^
		rKnights ^
		rBishops ^
		rRooks ^
		rQueens ^
		rKing ^
		bPawns ^
		bKnights ^
		bBishops ^
		bRooks ^
		bQueens ^
		bKing ^
		yPawns ^
		yKnights ^
		yBishops ^
		yRooks ^
		yQueens ^
		yKing ^
		gPawns ^
		gKnights ^
		gBishops ^
		gRooks ^
		gQueens ^
		gKing;
}

I256 Board::GetOthersPieces() const
{
	switch (toMove)
	{
	case Red:
		return GetBlue() | GetYellow() | GetGreen();
		break;
	case Blue:
		return GetRed() | GetYellow() | GetGreen();
		break;
	case Yellow:
		return GetRed() | GetBlue() | GetGreen();
		break;
	case Green:
		return GetRed() | GetBlue() | GetYellow();
		break;
	default:
		throw "Invalid player to move when calling GetOthersPieces().";
	}
}
