#ifndef BOARD_HPP
#define BOARD_HPP

#include "Typedefs.hpp"

class Board 
{
public:
	static constexpr int TOTAL_SQUARES = 196;
	static constexpr int SQUARES_PER_SIDE = 14;
public:
	Board();
	I256 getRedPawns() const;
	I256 getRedKnights() const;
	I256 getRedBishops() const;
	I256 getRedRooks() const;
	I256 getRedQueens() const;
	I256 getRedKing() const;
	I256 getBluePawns() const;
	I256 getBlueKnights() const;
	I256 getBlueBishops() const;
	I256 getBlueRooks() const;
	I256 getBlueQueens() const;
	I256 getBlueKing() const;
	I256 getYellowPawns() const;
	I256 getYellowKnights() const;
	I256 getYellowBishops() const;
	I256 getYellowRooks() const;
	I256 getYellowQueens() const;
	I256 getYellowKing() const;
	I256 getGreenPawns() const;
	I256 getGreenKnights() const;
	I256 getGreenBishops() const;
	I256 getGreenRooks() const;
	I256 getGreenQueens() const;
	I256 getGreenKing() const;
private:
	typedef boost::multiprecision::uint256_t I256;
private:
	const std::string RED_PAWNS_INITIAL{ "763254615079690740002692367037751644185114211243786240" };
	const std::string RED_KNIGHTS_INITIAL{ "3236630582308757268852828921341452995802777026051767795712" };
	const std::string RED_BISHOPS_INITIAL{ "1765434863077503964828815775277156179528787468755509706752" };
	const std::string RED_ROOKS_INITIAL{ "6326141592694389207303256528076476309978155096373909782528" };
	const std::string RED_QUEENS_INITIAL{ "784637716923335095479473677900958302012794430558004314112" };
	const std::string RED_KING_INITIAL{ "392318858461667547739736838950479151006397215279002157056" };
	const std::string BLUE_PAWNS_INITIAL{ "2787763301385015942981453398180054664478720" };
	const std::string BLUE_KNIGHTS_INITIAL{ "85070591730234615865915709451979980800" };
	const std::string BLUE_BISHOPS_INITIAL{ "5192296858536008220151213740523520" };
	const std::string BLUE_ROOKS_INITIAL{ "1393796574908163946345982392044920640634880" };
	const std::string BLUE_QUEENS_INITIAL{ "316912650057057350374175801344" };
	const std::string BLUE_KING_INITIAL{ "19342813113834066795298816" };
	const std::string YELLOW_PAWNS_INITIAL{ "33423360" };
	const std::string YELLOW_KNIGHTS_INITIAL{ "528" };
	const std::string YELLOW_BISHOPS_INITIAL{ "288" };
	const std::string YELLOW_ROOKS_INITIAL{ "1032" };
	const std::string YELLOW_QUEENS_INITIAL{ "128" };
	const std::string YELLOW_KING_INITIAL{ "64" };
	const std::string GREEN_PAWNS_INITIAL{ "5709339241236512651226016559472751952852418560" };
	const std::string GREEN_KNIGHTS_INITIAL{ "696898287454081973173581491830620002713600" };
	const std::string GREEN_BISHOPS_INITIAL{ "42535295865126979339478742962368675840" };
	const std::string GREEN_ROOKS_INITIAL{ "11417981541647679048466287755631989888080936960" };
	const std::string GREEN_QUEENS_INITIAL{ "158456325028528675187087900672" };
	const std::string GREEN_KING_INITIAL{ "2596148429267413814265248164610048" };
private:
	I256 rPawns;
	I256 rKnights;
	I256 rBishops;
	I256 rRooks;
	I256 rQueens;
	I256 rKing;
	I256 bPawns;
	I256 bKnights;
	I256 bBishops;
	I256 bRooks;
	I256 bQueens;
	I256 bKing;
	I256 yPawns;
	I256 yKnights;
	I256 yBishops;
	I256 yRooks;
	I256 yQueens;
	I256 yKing;
	I256 gPawns;
	I256 gKnights;
	I256 gBishops;
	I256 gRooks;
	I256 gQueens;
	I256 gKing;
};

#endif // !BOARD_HPP
