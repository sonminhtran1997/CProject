#include "CSinkTheFleet.h"
#include "textGraphics.h"
#include "CPlayer.h"
#include "CShip.h"
#include "CCell.h"
#include <ostream>
#include <sstream>
#include <cstring>
#include <cstdlib>
using namespace std;

//---------------------------------------------------------------------------------
// Function:	CSinkTheFleet::operator[]
// Title:		in-constant operator[] 
//
// Description:	overload operator[]
//				validates index and returns m_players[index]
//
// Programmer:	Xiao "Rita" Zhang
// 
// Date:		03/05/2015
//
// Version:		1.0
// 
// Environment: Hardware: AUXS i5 
//              Software: OS: Windows 8.1; 
//              Compiles under Visual Studio C++ 2012
// Output:		
//	
// Calls:		
//
// Called By:	 
//
// Parameters:	short index
// 
// Returns:		m_players[index]
//
// History Log: 
//		9/12/06 PB comleted v 1.0
//     
//----------------------------------------------------------------------------------
CPlayer & CSinkTheFleet::operator[] (short index)
{
	if (index >= NUMPLAYERS)
		throw range_error("index out of range");

	return m_players[index];
}; 


//---------------------------------------------------------------------------------
// Function:	CSinkTheFleet::operator[]
// Title:		constant operator[] 
//
// Description:	overload operator[]
//				validates index and returns m_players[index]
//
// Programmer:	Xiao "Rita" Zhang
// 
// Date:		03/05/2015
//
// Version:		1.0
// 
// Environment: Hardware: AUXS i5 
//              Software: OS: Windows 8.1; 
//              Compiles under Visual Studio C++ 2012
// Output:		
//	
// Calls:		
//
// Called By:	 
//
// Parameters:	short index
// 
// Returns:		m_players[index]
//
// History Log: 
//		9/12/06 PB comleted v 1.0
//     
//----------------------------------------------------------------------------------

const CPlayer & CSinkTheFleet::operator[] (short index) const
{
	if (index >= NUMPLAYERS)
		throw range_error("index out of range");

	return m_players[index];
}; 


//---------------------------------------------------------------------------------
// Function:	header()
// Title:		header 
// Description: Prints opening graphic
//				
// Programmer:	Xiao "Rita" Zhang
// 
// Date:		03/05/2015
//
// Version:		1.1
// 
// Environment: Hardware: i3 
//              Software: OS: Windows 7; 
//              Compiles under Microsoft Visual C++ 2012
//
// Output:	
//
// Calls:		boxTop()
//				boxLine()
//				boxBottom()
//
// Called By:	
//
// Parameters:	sout: ostream&;	the stream to print to
// 
// Returns:		void
//
// History Log: 
//		9/12/06 PB comleted v 1.0
//		3/5/15	XZ	competed v1.1
//--------------------------------------------------------------------------------
void CSinkTheFleet::header(ostream& sout)
{
	const string empty;
	const string sink("OOPs-- I Sank the Fleet!");
	const string name("by team: KURSK");
	const string by("Edmonds Community College CS 132");
	boxTop(sout, BOXWIDTH);
	boxLine(sout, empty, BOXWIDTH);
	boxLine(sout, sink , BOXWIDTH, 'C');
	boxLine(sout, empty, BOXWIDTH);
	boxLine(sout, name , BOXWIDTH, 'C');
	boxLine(sout, empty, BOXWIDTH);
	boxLine(sout, by, BOXWIDTH, 'C');
	boxLine(sout, empty, BOXWIDTH);
	boxBottom(sout, BOXWIDTH);
}

//---------------------------------------------------------------------------------
// Function:	endBox()
// Title:	End Box 
// Description:	prints closinging graphic
//		
// Programmer:	Paul Bladek
// 
// Date:		9/12/06
//
// Version:		1.0
// 
// Environment: Hardware: i3 
//              Software: OS: Windows 7; 
//              Compiles under Microsoft Visual C++ 2012
//
// Output:	
//
// Calls:		boxTop()
//				boxLine()
//				boxBottom()
//
// Called By:	
//
// Parameters:	player: short; the number of the winner (0 or 1)
// 
// Returns:		void
//
// History Log: 
//		9/12/06 PB comleted v 1.0
//     
//----------------------------------------------------------------------------------
void CSinkTheFleet::endBox(short player ,ostream& sout)
{
	const string empty;
	ostringstream msg;
	msg << "Congratulations player " << player + 1 << "!";
	boxTop(sout, BOXWIDTH);
	boxLine(sout, empty, BOXWIDTH);
	boxLine(sout, msg.str(), BOXWIDTH, 'C');
	boxLine(sout, empty, BOXWIDTH);
	boxBottom(sout, BOXWIDTH);
}


//---------------------------------------------------------------------------------
// Function:	main()
// Title:		Set ShipInfo
// Description:
//				Runs the Sink the Fleet Game
// Programmer:	MeetAgain (team member: Rami & Rita)
// modified by:
// 
// Date:		02/01/2015
//
// Version:		1.0
// 
// Environment: Hardware: i3 
//              Software: OS: Windows 7; 
//              Compiles under Microsoft Visual C++ 2012
//
// Input:		
//
// Output:		
//
// Calls:		initializePlayer()
//				allocMem()
//				safeChoice()
//				getGrid()
//				printGrid()
//				resetGrid()
//				setships()
//				header()
//				getCoord()
//				deleteMem()
//				endBox()
//
// Called By:	n/a
//
// Parameters:	void
// 
// Returns:		int -- EXIT_SUCCESS upon successful completion
//
// History Log: 
//				12/9/2012 PB completed v 0.5
//				02/01/2015 MA revise to v1.0
//				02/22/2015 MA revise to v1.1
//---------------------------------------------------------------------------------
short CSinkTheFleet::play()
{
	short numRows = SMALLROWS;			// total number of rows in the array
	short numCols = SMALLCOLS;			// total number of columns in the array
	bool gameOver = false;
	bool redo = false;
	CCell coord;
	string message;
	string filename = "";
	short i = 0 ;
	short current = 0;
	ostringstream tempStream;
	tempStream << ""; 
	char choice;
	int shipNumber = 0;
	system("cls");
	header(cout);
	cout << "Which size grid do you want to use? ";
	m_gridSize = safeChoice(tempStream.str(), 'S', 'L');

	if (m_gridSize == 'L')
	{
		numRows = LARGEROWS;
		numCols = LARGECOLS;
	}
	else
	{
		numRows = SMALLROWS;
		numCols = SMALLCOLS;
	}
	m_players[0].setGridSize(m_gridSize);
	m_players[1].setGridSize(m_gridSize);
	for (i = 0; i < NUMPLAYERS; i++) 
	{
		cout << "Player" << current + ONE
			<<",  Would you like to read starting grid from a file? ";				
		choice = safeChoice(tempStream.str(), 'Y', 'N');
		if (choice == 'Y')
		{
			cout << " Enter the file name:(.shp) ";
			cin >> filename;
			cin.ignore(BUFFER_SIZE, '\n');
			if (m_players[i].getGrid(filename) == false)
			{
				i--;
				continue;
			}
		}
		else
			m_players[i].setships();
	}
	system("CLS");
	header(cout);
	cout << " Press <enter> to start the battle..." << endl;
	while(gameOver == false)
	{
		m_players[current].printGrid(cout, ONE);
		cout << "Player" << current + ONE
			<<",  Enter coordinate for firing: ";
		coord.getCoord(cin, m_gridSize);
		if (m_players[!current].getCell(ZERO, coord) != CShip::NOSHIP)
		{
			cout << "HIT" << endl ;
			m_players[current].hitShip(m_players[!current].getCell(ZERO, coord));
			shipNumber = static_cast<int>(m_players[!current].getCell(ZERO, coord));
			if (m_players[!current][shipNumber].getPiecesLeft == 0)
				cout << shipNames[shipNumber] << " SUNK" << endl;
			m_players[current].setCell(ONE, coord, CShip::HIT);
			cout << "Press <enter>" << endl;
			cin.get();
			if (m_players[!current].getPiecesLeft == 0)
				gameOver = true;
			continue;
		}
		else
		{
			cout << "MISSED" << endl;
			m_players[current].setCell(ONE, coord, CShip::MISSED);
			current = !current;
		}
	}
	return current ;
}