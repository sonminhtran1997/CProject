#ifndef CSHIP_H
#define CSHIP_H
#include <iostream>
using namespace std;

const int SHIP_SIZE_ARRAYSIZE = 6;
const string shipNames[SHIP_SIZE_ARRAYSIZE]= {"No Ship", "Mine Sweeper", "Submarine", "Frigate",
	"Battleship", "Aircraft Carrier"};
class CShip
{
//---------------------------------------------------------------------------
//	Title:          CShip Class
//	Description:    This file contains the class definition for CShip
//	Programmer:     An Dien Tang
//	Date:           3/3/2015
//	Version:	1.00
//	Environment:	Laptop Toshiba 
//				Software:   MS Windows 8
//				Compiles under Microsoft Visual C++.Net 2012
//	class CShip:
//	Properties:
//			m_ship -- an enum Ship type
//	Methods:
//			Inline:
//				CShip(Ship ship = NOSHIP)
//					constructor;
//					initialize m_ship
//					Parameters:
//						Ship ship: an enum Ship type
//				operator Ship()
//					return Ship type of m_ship
//				void print()
//				void operator=(const CShip& ship)
//					Parameters:
//						CShip ship: a reference of CShip class
//			Non-Inline:
//				void printShip(ostream & sout)
//					Parameter: ostream & sout -- the stream used for output
//				void printName(ostream& sout);
//					Parameter: ostream & sout -- the stream used for output
//				void assignShip(int ship);
//					Parameter: int ship -- a ship used for assign m_ship
//  History Log:
//			3/3/2015 AT completed v1.00
//-----------------------------------------------------------------------------
public:
	enum Ship
	{
		NOSHIP,		 // 0
		MINESWEEPER, // 1 (1-5) -- used only for owner
		SUB,		 // 2
		FRIGATE,	 // 3
		BATTLESHIP,	 // 4
		CARRIER,	 // 5
		HIT,		 // 6 (6-7)-- used only for other side
		MISSED,		 // 7 
	}; 
	static const int ZERO = 0;
	static const int ENUM_SIZE_SHIP = 8;
	CShip(Ship ship = NOSHIP)
		:m_ship(ship){}

	operator Ship() const{return m_ship;}
	void printShip(ostream & sout);
	void print(){printShip(cout);}
	void printName(ostream& sout);
	void assignShip(int ship = 0);
	void operator=(const CShip& ship){m_ship = Ship(ship);}
private:
	Ship m_ship;
};

ostream& operator<<(ostream& sout, CShip& ship);
istream& operator>>(istream& sin, CShip& ship);

#endif