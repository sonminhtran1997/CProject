#ifndef CDIRECTION_H
#define CDIRECTION_H

#include <iostream>
using namespace std;
const int DIRECTION_SIZE_ARRAYSIZE = 6;
const string directionNames[DIRECTION_SIZE_ARRAYSIZE]= {"Vertical",
	"Horizontal"};
static const int ZERO = 0;
class CDirection
{
//---------------------------------------------------------------------------
//	Title:          CDirection Class
//	Description:    This file contains the class definition for CDirection
//	Programmer:     An Dien Tang
//	Date:           3/4/2015
//	Version:	1.00
//	Environment:	Laptop Toshiba 
//				Software:   MS Windows 8
//				Compiles under Microsoft Visual C++.Net 2012
//	class CDirection:
//	Properties:
//			m_direction -- an enum Direction type
//	Methods:
//			Inline:
//				CDirection(Direction direction = HORIZONTAL)
//					constructor;
//					initialize m_direction
//					Parameters:
//						Direction direction: an enum Direction type
//				operator Direction()
//					return Direction type of m_direction
//				void print()
//				void operator=(const CDirection& dir)
//					Parameters:
//						Direction dir: a reference of CDirection class
//			Non-Inline:
//				void printDirection(ostream & sout)
//					Parameter: ostream & sout -- the stream used for 
//								output
//				void assignDirection(int dir);
//					Parameter: int ship -- a diraction used for 
//								assign m_direction
//  History Log:
//			3/4/2015 AT completed v1.00
//-----------------------------------------------------------------------------
public:
	enum Direction
	{
		HORIZONTAL, // 0
		VERTICAL	// 1
	};
	static const int ENUM_SIZE_DIRECTION = 2;
	CDirection(Direction direction = HORIZONTAL)
		:m_direction(direction){}
	operator Direction() const{return m_direction;}
	void printDirection(ostream & sout);
	void print(){printDirection(cout);}
	void assignDirection(int dir = 0);
	void operator=(const CDirection& dir){m_direction = Direction(dir);}
private:
	Direction m_direction;
};
ostream& operator<<(ostream& sout, CDirection& dir);
istream& operator>>(istream& sin, CDirection& dir);

#endif