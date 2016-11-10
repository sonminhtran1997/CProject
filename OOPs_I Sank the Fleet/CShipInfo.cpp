#include "CShipInfo.h"

//---------------------------------------------------------------------------------
// Function:	printShipInfo()
// Title:	Print Entire Ship Info 
// Description:
//		Print the Ship Info: Name, Direction, Coordinates
// Programmer:	Ngo Austin Khoa Truong
// Date:	3/3/15
// Version:	1.0
// Environment: Intel Xeon 
//				Software:   MS Windows 7
//				Compiles under Microsoft Visual C++.Net 2012
// Input:
// Output:		Three strings showing name, direction and coordinates of teh ship
// Calls:		CShip::print() , CDirection::print() , CCell:: print()
// Called By:	
// Parameters:	sout: ostream&;	the stream to print to
// Returns:	void
// History Log:
//		3/3/15 AT completed v 1.0	    
//---------------------------------------------------------------------------------
void CShipInfo::printShipInfo(ostream & sout)
{

	m_name.print();
	m_orientation.print(); //Please write ()_() i need someones constrcutor
	m_bowLocation.print(); //Please write ()_() i need someones constrcutor
};


// ----------------------------------------------------------------------------
//	Function:       CShipInfo  CShipInfo::operator--()
//	Description:    Remove one piece from the number of pieces in ShipInfo
//	Programmer:		Ngo Austin Khoa Truong
//	Date:			3/3/15
//	Version:		1.0
//	Environment:	Intel Xeon 
//					Software:   MS Windows 7
//					Compiles under Microsoft Visual C++.Net 2012
//	Input:          None
//	Output:         None
//	Calls:          None
//	Called By:      None
//	Parameters:     None
//	               
//	Returns:        CShipInfo
//	History Log:
//	                3/3/15  NAK  completed version 1.0
// ----------------------------------------------------------------------------
CShipInfo  CShipInfo::operator--()
{
	
	--piecesLeft;
	return *this;

};

// ----------------------------------------------------------------------------
//	Function:       bool CShipInfo::isSunk()
//	Description:    Check if the ship has no pieces left
//	Programmer:		Ngo Austin Khoa Truong
//	Date:			3/3/15
//	Version:		1.0
//	Environment:	Intel Xeon 
//					Software:   MS Windows 7
//					Compiles under Microsoft Visual C++.Net 2012
//	Input:          None
//	Output:         None
//	Calls:          None
//	Called By:      None
//	Parameters:     None
//	               
//	Returns:        CShipInfo
//	History Log:
//	                3/3/15  NAK  completed version 1.0
// ----------------------------------------------------------------------------
bool CShipInfo::isSunk()
{
	if(this->piecesLeft == 0)
		return true;
	else
		return false;
}

// ----------------------------------------------------------------------------
//	Function:       ostream& operator<<(ostream& sout,CShipInfo & Cshipinfo)
//	Description:    Print the ship info
//	Programmer:		Ngo Austin Khoa Truong
//					An Dien Tang
//	Date:			3/3/15
//	Version:		1.0
//	Environment:	Intel Xeon 
//					Software:   MS Windows 7
//					Compiles under Microsoft Visual C++.Net 2012
//	Input:          ostream&;	the stream to print to
//	Output:         ostream&;	the stream to print to
//	Calls:          None
//	Called By:      None
//	Parameters:     None
//	               
//	Returns:        ostream&;	
//	History Log:
//	                3/3/15  NAK  completed version 1.0
// ----------------------------------------------------------------------------
ostream& operator<<(ostream& sout,CShipInfo & Cshipinfo)
{
	Cshipinfo.print();
	return sout;
};