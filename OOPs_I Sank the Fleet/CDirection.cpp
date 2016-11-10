#include "CDirection.h"
#include <sstream>
#include "safeio.h"

//---------------------------------------------------------------------------------
// Function:	printDirection()
// Title:	Print Direction 
// Description:
//		Print grid element for the proper direction
// Programmer:	An Dien Tang
// Date:	3/4/15
// Version:	1.0
// Environment: Laptop Toshiba 
//				Software:   MS Windows 8
//				Compiles under Microsoft Visual C++.Net 2012
// Input:
// Output:		three characters representing one direction to sout
// Calls:
// Called By:	
// Parameters:	sout: ostream&;	the stream to print to
// Returns:	void
// History Log:
//		3/4/15 AT completed v 1.0	    
//---------------------------------------------------------------------------------
void CDirection::printDirection(ostream & sout)
{
	sout << ' ';
	if (m_direction == VERTICAL)
		sout << "V" << endl;
	else
		sout << "H" << endl;
}

//---------------------------------------------------------------------------------
// Function:	assignDirection()
// Title:	Assign the Direction to class
// Description:
//		Assign the Direction to class
// Programmer:	An Dien Tang
// Date:	3/4/15
// Version:	1.0
// Environment: Laptop Toshiba 
//				Software:   MS Windows 8
//				Compiles under Microsoft Visual C++.Net 2012
// Input:
// Output:		
// Calls:
// Called By:	operator>>()
// Parameters:	int dir -- a direction used for assign m_direction
// Returns:	void
// History Log:
//		3/4/15 AT completed v 1.0	    
//---------------------------------------------------------------------------------
void CDirection::assignDirection(int dir)
{
	if (dir > ZERO && dir <= ENUM_SIZE_DIRECTION)
		m_direction = static_cast<Direction>(dir);
	else
		m_direction = HORIZONTAL;
}

// ----------------------------------------------------------------------------
//	Function:       ostream& operator<<(ostream& sout, CDirection& dir)
//	Description:    prints out the direction to the stream
//	Input:          None
//	Output:         Screen display of direction
//	Calls:          print()
//	Called By:      None
//	Parameters:     ostream & sout  -- the stream used for output
//	                CDirection& dir -- the direction to print
//	Returns:        a reference to sout 
//	History Log:
//	                3/4/15  AT  completed version 1.0
// ----------------------------------------------------------------------------
ostream& operator<<(ostream& sout, CDirection& dir)
{
	dir.print();
	return sout;
}

// ----------------------------------------------------------------------------
//	Function:        istream& operator>>(istream& ist, CDirection& dir)
//	Description:     inputs the direction from the stream
//	Input:           a direction from the ist stream
//	Output:          None
//	Calls:           assignDirection()
//	Called By:       None
//	Parameters:      ostream & sin  -- the stream used for input
//	                 CDirection& dir -- the direction to read into
//	Returns:         a reference to sin 
//	History Log:
//	                 3/4/2015   AT  completed version 1.0
//-----------------------------------------------------------------------------
istream& operator>>(istream& sin, CDirection& dir)
{
	string input;
	getline(sin, input);
	for (int i = 0; i < DIRECTION_SIZE_ARRAYSIZE; i++)
	{
		if (toupper(input[ZERO]) == directionNames[i][ZERO])
		{
			dir.assignDirection(i);
			return sin;
		}
	}
	dir.assignDirection(atoi(input.c_str()));
	return sin;
}