#include <sstream>
#include "CShip.h"
#include "textGraphics.h"
#include "safeio.h"

//---------------------------------------------------------------------------------
// Function:	printShip()
// Title:	Print Ship 
// Description:
//		Print grid element for the proper ship
// Programmer:	Paul Bladek
// Date:	1/16/15
// Version:	1.0
// Environment: Hardware: i3 
//              Software: OS: Windows 7; 
//              Compiles under Microsoft Visual C++ 2012
// Input:
// Output:		three characters representing one ship to sout
// Calls:
// Called By:	
// Parameters:	sout: ostream&;	the stream to print to
// Returns:	void
// History Log:
//		12/20/05 PB completed v 1.0	    
//---------------------------------------------------------------------------------
void CShip::printShip(ostream & sout)
{	
	sout << ' ' ;
	switch(m_ship)
	{
	case NOSHIP: sout << ' ';
		break;
	case MINESWEEPER: sout << 'M';
		break;
	case SUB: sout << 'S';
		break;
	case FRIGATE: sout << 'F';
		break;
	case BATTLESHIP: sout << 'B';
		break;
	case CARRIER: sout << 'C';
		break;
	case HIT: sout << 'H';
		break;
	case MISSED: sout << MISS;
		break;
	default: sout << 'X';
	}
	sout << VERT ;
}

//---------------------------------------------------------------------------------
// Function:	printName()
// Title:	Print Name of Ship
// Description:
//		Print the name for the proper ship
// Programmer:	An Dien Tang
// Date:	3/3/15
// Version:	1.0
// Environment: Laptop Toshiba 
//				Software:   MS Windows 8
//				Compiles under Microsoft Visual C++.Net 2012
// Input:
// Output:		a string representing one ship's name to sout
// Calls:
// Called By:	
// Parameters:	sout: ostream&;	the stream to print to
// Returns:	void
// History Log:
//		3/3/15 AT completed v 1.0	    
//---------------------------------------------------------------------------------
void CShip::printName(ostream& sout)
{
	if (static_cast<int>(m_ship) >= ZERO &&
		static_cast<int>(m_ship) < SHIP_SIZE_ARRAYSIZE)
		sout << shipNames[m_ship];
}

//---------------------------------------------------------------------------------
// Function:	assignShip()
// Title:	Assign the Ship to class
// Description:
//		Assign the Ship to class
// Programmer:	An Dien Tang
// Date:	3/3/15
// Version:	1.0
// Environment: Laptop Toshiba 
//				Software:   MS Windows 8
//				Compiles under Microsoft Visual C++.Net 2012
// Input:
// Output:		
// Calls:
// Called By:	operator>>()
// Parameters:	int ship -- a ship used for assign m_ship
// Returns:	void
// History Log:
//		3/3/15 AT completed v 1.0	    
//---------------------------------------------------------------------------------
void CShip::assignShip(int ship)
{
	if (ship >= ZERO && ship <= ENUM_SIZE_SHIP)
		m_ship = static_cast<Ship>(ship);
	else
		m_ship = NOSHIP;
}

// ----------------------------------------------------------------------------
//	Function:       ostream& operator<<(ostream& sout, CShip& ship)
//	Description:    prints out the ship to the stream
//	Input:          None
//	Output:         Screen display of ship
//	Calls:          print()
//	Called By:      None
//	Parameters:     ostream & sout  -- the stream used for output
//	                CShip& ship -- the ship to print
//	Returns:        a reference to sout 
//	History Log:
//	                3/3/15  AT  completed version 1.0
// ----------------------------------------------------------------------------
ostream& operator<<(ostream& sout, CShip& ship)
{
	ship.print();
	return sout;
}

// ----------------------------------------------------------------------------
//	Function:        istream& operator>>(istream& ist, CShip& ship)
//	Description:     inputs the ship from the stream
//	Input:           a ship from the ist stream
//	Output:          None
//	Calls:           assignShip()
//	Called By:       None
//	Parameters:      ostream & sin  -- the stream used for input
//	                 CShip& ship -- the ship to read into
//	Returns:         a reference to sin 
//	History Log:
//	                 3/3/2015   AT  completed version 1.0
//-----------------------------------------------------------------------------
istream& operator>>(istream& sin, CShip& ship)
{
	string input;
	getline(sin, input);
	for (int i = 0; i < SHIP_SIZE_ARRAYSIZE; i++)
	{
		if (input == shipNames[i])
		{
			ship.assignShip(i);
			return sin;
		}
	}
	ship.assignShip(atoi(input.c_str()));
	return sin;
}