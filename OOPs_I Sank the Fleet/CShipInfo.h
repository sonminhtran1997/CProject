#ifndef CSHIPINFO_H
#define CSHIPINFO_H

#include"CDirection.h"
#include"CCell.h"
#include"CShip.h"

using namespace std;
const CShip shipToken = CShip::NOSHIP;
const CDirection directionToken = CDirection::HORIZONTAL;
const CCell cellToken(0,0);
const short shipSize[SHIP_SIZE_ARRAYSIZE] = {0, 2, 3, 3, 4, 5};
class CShipInfo
{
	public:		
		static const short shipSize[SHIP_SIZE_ARRAYSIZE];
		CShipInfo(CShip CShipDefault = shipToken, 
			CDirection CDirectionDefault = directionToken, 
			CCell userCell = cellToken, short piecesofShip = ZERO)
			:m_name(CShipDefault), m_orientation(CDirectionDefault),
			m_bowLocation(userCell) , piecesLeft(piecesofShip){}

		void printShipInfo(ostream & sout);
		void print(){printShipInfo(cout);}
		short getPiecesLeft(){return piecesLeft;}
		CCell getCell(){return m_bowLocation;}
		CShip getName(){return m_name;}
		CDirection getOrientation(){return m_orientation;}

		void setName(int shipToBeSet){this->m_name.assignShip(shipToBeSet);}
		void setOrientation(int userDirection)
		{this->m_orientation.assignDirection(userDirection);}
		void setBowLocation(const CCell & somelocation){this->m_bowLocation = somelocation;}
		void setPiecesLeft(short pieces){this->piecesLeft = pieces;};

		CShipInfo operator--();
		bool isSunk();

		
	private:
		CShip m_name;				// which ship?
		CDirection m_orientation;	// which direction is the ship facing? 
		CCell m_bowLocation;		// which cell is the bow location?
		short piecesLeft;		// how many sections are left undestroyed?
};
ostream& operator<<(ostream& sout,CShipInfo & Cshipinfo);

#endif
//---------------------------------------------------------------------------
//	Title:          CShipInfo Class
//	Description:    This file contains the class definition for CShipInfo
//	Programmer:     Ngo Austin Khoa
//	Date:           3/3/2015
//	Version:	1.00
//	Environment:	Laptop Toshiba 
//				Software:   MS Windows 8
//				Compiles under Microsoft Visual C++.Net 2012
//	class CShip:
//	Properties:
//			CShip name,  a CShip type
//			CDirection orientation, a CDirection type
//			CCell bowLocation, a CCell type
//			short piecesLeft, number of pieces of the CShip
//	Methods:
//			Inline:
//			Constructor

//			CShipInfo(CShip CShipDefault = CShip(), CDirection CDirectionDefault CDirection(), CCell userCell = CCell() ,short piecesofShip = shipSize[6])
//					
//					initialize name,orientation,bowlocation,piecesLeft
//					Parameters:
//						CShip CShipDefault,  a CShip type
//						CDirection CDirectionDefault, a CDirection type
//						CCell userCell, a CCell type	
//						short piecesofShip, number of pieces of the CShip
//			
//			Accessor

//			short getPiecesLeft(){return piecesLeft;}
//					return short number of pieces of Shipinfo
//			CDirection getOrientation(){return orientation;}
//			CCell getCell(){return bowLocation;}
//			CShip getName(){return name;}
//			
//			Mutator
//			CShip setName(int&shipToBeSet){this->name.assignShip(shipToBeSet);}; 
//			CDirection setOrientation(CDirection & userDirection){this->orientation = userDirection;};
//			CCell setBowLocation(CCell & somelocation){this->bowLocation = somelocation;};
//			short setPiecesLeft(short pieces){this->piecesLeft = pieces;};


//			void print(){printShipInfo(cout);}
//			Non-Inline:
//				void printShipInfo(ostream & sout)
//					Parameter: ostream & sout -- the stream used for output
//				bool CShipInfo::isSunk()
//				CShipInfo  CShipInfo::operator--()
//				printShipInfo()
//  History Log:
//			3/3/2015 AT completed v1.00
//-----------------------------------------------------------------------------