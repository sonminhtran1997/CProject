#ifndef FLEET_H
#define FLEET_H

#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>
#include <string>
#include <sstream>
#include "textGraphics.h"
#include "safeio.h"

using namespace std;
	//---------------------------------------------------------------------------
//	Title:          CCell.h
//	Description:    This file contains the class definition for CCell
//	Programmer:     Kyle Graham
//	Date:           3/4/2015
//	Version:	1.00
//	Environment:	 Hardware: i7 
//              Software: OS: Windows 7; 
//              Compiles under Microsoft Visual C++ 2012
//	class CShip:
//	Properties:
//			m_row - the row of the coordinate
//			m_col - the column of the coordinate
//	Methods:
//		Inline:
//			Constructor CCell(unsigned short row = 0, short col = 0)
//			Accessors: unsigned short getRow()
//					   unsigned short getCol()
//			Void Print()
//		Non-Inline:
//				void CCell::getCoord(istream& sin, char size);
//				ostream& operator<<(ostream& sout, CCell& cell);
//				
//  History Log:
//				9/12/06 PB comleted v 0.5
//				1/26/2015 KG & HN completed v 0.6
//				1/27/2015 KG & HN completed v 0.7
//				1/28/2015 KG & HN completed v 0.8
//				1/29/2015 KG & HN completed v 0.9
//				3/04/2015 KG completed v 1.0
//     
//-----------------------------------------------------------------------------
class CCell
{
	public:
		static const short NUMPLAYERS = 2;	// number of players in game
		static const short SMALLROWS = 8;	// number of rows/columns in small sea array 
		static const short LARGEROWS = 10;	// number of rows/columns in large sea array
		static const short SMALLCOLS = 12;	// number of rows/columns in small sea array 
		static const short LARGECOLS = 24;	// number of rows/columns in large sea array
		static const short BOXWIDTH = 79;	// maximum screen line length
		static const short ASCIIA = 64; // value of A in ASCII
		static const short ONE = 1;

		CCell(unsigned short row = 0, unsigned short col = 0)
		{m_row = row; m_col = col;}
		void printCoord(ostream& sout)
		{cout << static_cast<char>(m_row + ASCIIA + ONE) << m_col + ONE;}
		void getCoord(istream& sin, char size);
		unsigned short getRow(){return m_row;}
		unsigned short getCol(){return m_col;}
		void print(){printCoord(cout);}
		void increaseCol(){m_col++;}
		void increaseRow(){m_row++;}
		
	private:
		unsigned short m_row;	// row
		unsigned short m_col;	// column
}; 
ostream& operator<<(ostream& sout, CCell& cell);

#endif