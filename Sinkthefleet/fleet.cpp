//----------------------------------------------------------------------------
// File:	fleet.cpp
// 
// Functions: 
//	  setShipInfo()	
//	  allocMem() 
//	  deleteMem()
//	  printShip() 
//	  printGrid() 
//	  initializePlayer() 
//	  setships()	      
//	  saveGrid()
//	  getGrid()
//	  getCoord()
//	  validLocation() 
//	  header() 
//	  endBox() 
//----------------------------------------------------------------------------
#include "fleet.h"
#include <cmath>
//---------------------------------------------------------------------------------
// YOU ARE RESPONSIBLE FOR CORRECT HEADERS -- one for each function
// include the definitions for each of the non-template functions
//    declared in fleet.h 
//---------------------------------------------------------------------------------

const char* shipNames[SHIP_SIZE_ARRAYSIZE] = 
{"No Ship", "Mine Sweeper", "Submarine", "Frigate",
"Battleship", "Aircraft Carrier"};
const int TOTALPIECES = 17; // total pieces in all ships

//---------------------------------------------------------------------------------
// Function:	setShipInfo()
// Title:		Set ShipInfo
// Description:
//		Sets struct ShipInfo fields
// Programmer:
// 
// Date:	12/20/05
//
// Version:	0.1
// 
// Environment: Intel Xeon PC 
//                Software:   MS Windows 7 for execution; 
//                Compiles under Microsoft Visual C++.Net 2012
//
// Calls:
//
// Called By:
//
// Parameters:	shipInfoPtr: ShipInfo *; pointer to the ShipInfo to be set
//				name: Ship;	enumerated name of type of ship; default: NOSHIP
//				orientation: Direction;	enumerated direction; default: HORIZONTAL
//				row: unsigned short; row-coordinate in grid; default: 0
//				col: unsigned short; column-coordinate in grid; default: 0
// 
// Returns:	void
//
// History Log:
//		12/20/05 PB completed v 0.1
//   
//---------------------------------------------------------------------------------
void setShipInfo(ShipInfo * shipInfoPtr, short pieces, Ship name, Direction orientation,
				 unsigned short row, unsigned short col)
{
	shipInfoPtr->m_name =  name;
	shipInfoPtr->m_orientation = orientation;
	shipInfoPtr->m_bowLocation.m_col = col;
	shipInfoPtr->m_bowLocation.m_row = row;
	shipInfoPtr->m_piecesLeft = pieces;

} 

//---------------------------------------------------------------------------------
// Function:	allocMem()
// Title:		Allocate Memory
// Description:
//		allocates memory for current grids
// Programmer:	Austin Khoa Truong Ngo
//				An Dien Tang
// Date:	1/19/15
// Version:	1.01
// Environment: Hardware: Laptop Toshiba 
//              Software: Windows 8; 
//              Compiles under Microsoft Visual C++ 2012
// Calls: deleteMem()
// Called By:	main()
// Parameters:	players: Player[]; 	the array of 2 players in the game
//		size: char;	'	S' or 'L' (small or large)
// Returns:	void
// History Log:
//		1/14/15 AK completed v 1.0 
//		1/19/15  AT completed v 1.01, adjust minor points
//---------------------------------------------------------------------------------
void allocMem(Player players[], char size)
{
	short numberOfRows = (toupper(size) == 'L') ? LARGEROWS : SMALLROWS;
	short numberOfCols = (toupper(size) == 'L') ? LARGECOLS : SMALLCOLS;

	try
	{
		for(short i = 0; i < NUMPLAYERS; ++i)
		{
			players[i].m_gameGrid[0] = nullptr;
			players[i].m_gameGrid[0] = new Ship*[numberOfRows];
			players[i].m_gameGrid[1] = nullptr;
			players[i].m_gameGrid[1] = new Ship*[numberOfRows];
			for(short j = 0; j < numberOfRows; ++j)
			{
				players[i].m_gameGrid[0][j] = nullptr; 
				players[i].m_gameGrid[0][j] = new Ship[numberOfCols];
				players[i].m_gameGrid[1][j] = nullptr;
				players[i].m_gameGrid[1][j] = new Ship[numberOfCols];
				//--------------------------------------------------
				for(short k = 0; k < numberOfCols; ++k)
				{
					players[i].m_gameGrid[0][j][k] = NOSHIP;
					players[i].m_gameGrid[1][j][k] = NOSHIP;
				} // end for k
			} // end for j
		} // end for i
	}
	catch(exception e)
	{
		deleteMem(players, size);
		cerr << "exception: " << e.what() << endl;
		cout << "shutting down" << endl;
		cin.ignore(BUFFER_SIZE, '\n');
		exit(EXIT_FAILURE);
	}
}

//---------------------------------------------------------------------------------
// Function:	deleteMem()
// Title:		Delete Memory
// Description:
//		Safely deletes memory for grids
// Programmer:  Austion Khoa Truong Ngo
//				An Dien Tang
// Date:	1/19/15
// Version:	1.0
// Environment: Hardware: Laptop Toshiba
//              Software: Windows 8; 
//              Compiles under Microsoft Visual C++ 2012
// Calls:
// Called By:	main()
//				allocMem()
// Parameters:	players: Player[]; 	the array of the 2 Players
//		size: char;	'	S' or 'L'
// Returns:	void
// History Log:
//		1/11/15 AK completed v 0.1
//		1/19/15 AT completed v 1.0, change positions of some codes
//---------------------------------------------------------------------------------
void deleteMem(Player players[], char size) 
{
	short numberOfRows = (toupper(size) == 'L') ? LARGEROWS : SMALLROWS;
	for (short i = 0; i < NUMPLAYERS ; i++)
	{
		for(short k = 0; k < NUMPLAYERS; k ++)
		{
			if (players[i].m_gameGrid[k] != nullptr)
			{
				for (short j = 0; j < numberOfRows; j++)
				{
					if (players[i].m_gameGrid[k][j] != nullptr)
						delete[] players[i].m_gameGrid[k][j];
				}
				delete[] players[i].m_gameGrid[k];
			}
		}
	}
}

//---------------------------------------------------------------------------------
// Function:	printShip()
// Title:	Print Ship 
// Description:
//		Print grid element for the proper ship
// Programmer:	Austin Khoa Truong Ngo
// Date:	1/12/15
// Version:	1.0
// Environment: Hardware: i3 
//              Software: OS: Windows 7; 
//              Compiles under Microsoft Visual C++ 2012
// Output:		three characters representing one ship to sout
// Calls:
// Called By:	printGrid()
// Parameters:	sout: ostream&;	the stream to print to
//				thisShip: Ship;	the Ship to be printed in the grid format
// Returns:	void
// History Log: 
//		1/16/15 AK completed v 1.0
//---------------------------------------------------------------------------------
void printShip(ostream & sout, Ship thisShip)
{	
	sout << ' ' ;
	switch(thisShip)
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
// Function:	printGrid()
// Title:	Print Ship 
// Description:	Print grid element for the proper ship
// Programmer: Austin Khoa Truong Ngo
//			   An Dien Tang
// Date:	1/19/15
// Version:	1.1
// Environment: Hardware: Laptop Toshiba 
//              Software: Windows 8; 
//              Compiles under Microsoft Visual C++ 2012
// Output:	a single grid to sout
// Calls:	printShip()
// Called By:	main()
//		setships()
//		saveGrid()
// Parameters:	sout: ostream&;	the stream to print to
//		grid: Ship**;	the 2-D array of Ships 
//		size: char;	'S' or 'L'
// Returns:	void
// History Log:
//		1/16/15 AK completed v 0.1
//      1/19/15 AT completed v 1.1, add frame / edit some minor points
//---------------------------------------------------------------------------------
void printGrid(ostream& sout, Ship** grid, char size)
{
	short numberOfRows = (toupper(size) == 'L') ? LARGEROWS : SMALLROWS;
	short numberOfCols = (toupper(size) == 'L') ? LARGECOLS : SMALLCOLS;

	for(short j = 1; j <= numberOfCols; ++j)
		sout << setw(3) << j;
	sout  << endl;
	for( short i = 1; i<= numberOfRows; ++i)
	{
		sout << static_cast<char>(FIRSTLETTER + (i - ONEDECREASE));
		for( short j = 1; j<= numberOfCols; ++j)
			printShip(sout, grid[i - ONEDECREASE][j - ONEDECREASE]);
		sout << endl;
		sout << HORIZ;
		for (  short k = 1; k <= numberOfCols * TRIPLE ; ++k)
		{
			if (k % BORDER == 0)
				sout << CR;
			else
				sout << HORIZ;
		}
		sout << endl;
	}

} 

//---------------------------------------------------------------------------------
// Function:	initializePlayer()
// Title:	Initialize Player 
// Description:
//		sets initial values for m_ships and m_piecesLeft
// Programmer:	Paul Bladek
// 
// Date:	9/12/06
//
// Version:	1.0
// 
// Environment: Hardware: i3 
//              Software: OS: Windows 7; 
//              Compiles under Microsoft Visual C++ 2012
//
// Calls:
//
// Called By:	main()
//
// Parameters:	playerPtr: Player*;	a pointer to the current Player
// 
// Returns:	void
//
// History Log: 
//		9/12/06 PB comleted v 1.0
//     
//---------------------------------------------------------------------------------
void initializePlayer(Player* playerPtr)
{
	for(short i = 0; i < SHIP_SIZE_ARRAYSIZE; i++)
		setShipInfo(playerPtr->m_ships + i, shipSize[i], static_cast<Ship>(i));

	playerPtr->m_piecesLeft = TOTALPIECES; 
}

//---------------------------------------------------------------------------------
// Function:	setships()
// Title:	Set Ships 
// Description:
//		Allows user to put ships in grid
// Programmer:	Paul Bladek
// modified by:	
// 
// Date:	9/12/06
//
// Version:	0.5
// 
// Environment: Hardware: i3 
//              Software: OS: Windows 7; 
//              Compiles under Microsoft Visual C++ 2012
//
// Input:	location and orientation using getCoord from cin
//
// Output:	prompts to cout
//
// Calls:	printGrid()
//		safeChoice()
//		getCoord()
//		saveGrid()
//
// Called By:	main()
//
// Parameters:	players: Player[];	the array of 2 players 
//		size: char;		'S' or 'L'
//		whichPlayer: short;	the player number (0 or 1)
// 
// Returns:	void
//
// History Log: 
//		9/12/06 PB comleted v 0.5
//     
//---------------------------------------------------------------------------------
void setships(Player players[], char size, short whichPlayer)
{
	char input = 'V';
	char ok = 'Y';
	char save = 'N';
	ostringstream outSStream;
	Cell location = {0, 0};
	for(short j = 1; j < SHIP_SIZE_ARRAYSIZE; j++)
	{
		do{

			do{
				system("cls");
				printGrid(cout, players[whichPlayer].m_gameGrid[0], size);
				outSStream.str("");
				outSStream << "Player " << whichPlayer + 1 << " Enter "
					<< shipNames[j] << " orientation";
				input =  safeChoice(outSStream.str(), 'V', 'H');
				players[whichPlayer].m_ships[j].m_orientation
					= (input == 'V') ? VERTICAL : HORIZONTAL;
				cout << "Player " << whichPlayer + 1 << " Enter " << shipNames[j] <<
					" bow coordinates <row letter><col #>: ";
				players[whichPlayer].m_ships[j].m_bowLocation = getCoord(cin, size);

				// if ok
				if(!validLocation(players[whichPlayer], j, size))
				{
					cout << "invalid location. Press <enter>" ;
					cin.get();
					j--; // redo
					continue;
				}
				// your code goes here ...
			}while(!validLocation(players[whichPlayer], j, size));

			printGrid(cout, players[whichPlayer].m_gameGrid[0], size);
			outSStream.str("");
			outSStream << "Player " << whichPlayer + 1 << shipNames[j]
			<< "OK? ";
			ok =  safeChoice(outSStream.str(), 'Y', 'N');
		}while (ok != 'N');

	} // end for j
	save = safeChoice("\nSave starting grid?", 'Y', 'N');
	if(save == 'Y')
		saveGrid(players, whichPlayer, size);
}

//---------------------------------------------------------------------------------
// Function:	saveGrid()
// Title:	Save Grid 
// Description:
//		Saves the ship grid to a file
// Programmer:
// 
// Date:	12/20/05
//
// Version:	0.1
// 
// Environment: Hardware: i3 
//              Software: OS: Windows 7; 
//              Compiles under Microsoft Visual C++ 2012
//
// Output:	grid to specified file
//
// Calls:	printGrid()
//
// Called By:	setships()
//
// Parameters:	player: sPlayer[];	the array of 2 players
//		whichPlayer: short; the player number (0 or 1) 
//		size: char;	'S' or 'L'
// 
// Returns:	void
//
// History Log:
//		12/20/05 PB completed v 0.1
//     
//---------------------------------------------------------------------------------
void saveGrid(Player players[], short whichPlayer, char size)
{
	short numberOfRows = (toupper(size) == 'L') ? LARGEROWS : SMALLROWS;
	short numberOfCols = (toupper(size) == 'L') ? LARGECOLS : SMALLCOLS;	
	// your code goes here ...
	ofstream outputfile;
	string outname;
	Ship** playership = players->m_gameGrid[whichPlayer];
	cout << "enter name of file to be save (.shp)" << endl;
	cin >> outname;
	
}

//---------------------------------------------------------------------------------
// Function:	getGrid()
// Title:	GetGrid 
// Description:
//		Reads grid from a file and properly sets the ships
// Programmer:	Paul Bladek
// modified by:	
// 
// Date:	9/12/06
//
// Version:	0.5
// 
// Environment: Hardware: i3 
//              Software: OS: Windows 7; 
//              Compiles under Microsoft Visual C++ 2012
//
// Input:	grid from specified file
//
// Output:	prompts to cout
//
// Calls:
//
// Called By:	main()
//
// Parameters:	players: Player[];	the array of 2 players
//		whichPlayer: short;	the player number  (0 or 1) 
//		size: char;		'S' or 'L'
//		string fileName:	the name of the file to be opened for reading
// 
// Returns: bool -- 	true if the file is opened and read;
//			false otherwise
//
// History Log: 
//		9/12/06 PB comleted v 0.5
//     
//---------------------------------------------------------------------------------
bool getGrid(Player players[], short whichPlayer, char size, string fileName)
{
	//string line;
	//ifstream ifs;
	//Ship ship = NOSHIP;
	//short shipCount[SHIP_SIZE_ARRAYSIZE] = {0};
	//char cell = ' ';
	//char fsize = 'S';
	//short numberOfRows = (toupper(size) == 'L') ? LARGEROWS : SMALLROWS;
	//short numberOfCols = (toupper(size) == 'L') ? LARGECOLS : SMALLCOLS;

	//try
	//{
	//	ifs.open(fileName.c_str());
	//	if(!ifs)
	//	{
	//		cout << "could not open file " << fileName << endl
	//			<< " press <enter> to continue" << endl;
	//		cin.ignore(BUFFER_SIZE, '\n');
	//		return false;
	//	}
	//}
	//catch(exception e)
	//{
	//	cout << "could not open file " << fileName << endl
	//		<< " press <enter> to continue" << endl;
	//	cin.ignore(BUFFER_SIZE, '\n');
	//	return false;
	//}	
	//// your code goes here ...


	//fsize = ifs.get(); //does this belong in here
	//if(fsize != size)
	//{cout << "file is for wrong size grid" << endl;
	//cout << "press enter to continue" << endl;
	//return false;
	//}
	//else
	//{
	//	while(!ifs.eof)

	//		//getline or get 
	//			//for loop to read up until numberofcols, make sure is not less, if so flag it


	//}

	return true;
}

//---------------------------------------------------------------------------------
// Function:	getCoord()
// Title:	Get Coordinates 
// Description:
//		Returns a cell with coordinates set by user
// Programmer:	Paul Bladek
// 
// Date:	9/12/06
//
// Version:	1.0
// 
// Environment: Hardware: i3 
//              Software: OS: Windows 7; 
//              Compiles under Microsoft Visual C++ 2012
//
// Input:	cell coordinates (in the form "A13" from sin
//
// Output:	prompts to cout
//
// Calls:	none
//
// Called By:	main()
//		setships()
//
// Parameters:	sin: istream&;	the stream to read from
//		size: char;	'S' or 'L'
// 
// Returns:	Cell location -- a cell containing the input coordinates
//
// History Log: 
//		9/12/06 PB comleted v 1.0
//     
//---------------------------------------------------------------------------------
Cell getCoord(istream& sin, char size)
{
	short numberOfRows = (toupper(size)=='L') ? LARGEROWS : SMALLROWS;
	short numberOfCols = (toupper(size)=='L') ? LARGECOLS : SMALLCOLS;
	char highChar = static_cast<char>(numberOfRows - 1) + 'A';
	char row  = 'A';
	short col = 0;
	Cell location = {0, 0};
	do
	{
		col = 0;
		cout << "Row must be a letter from A to " << highChar 
			<< " and column must be  from 1 to "  << numberOfCols << ": ";
		while((row = toupper(sin.get())) < 'A' || row  > highChar)
		{
			sin.ignore(BUFFER_SIZE, '\n');
			cout << "Row must be a letter from A to " << highChar 
				<< " and column must be  from 1 to "  << numberOfCols << ": ";
		}
		sin >> col;
		if(!sin)
			sin.clear();
		sin.ignore(BUFFER_SIZE, '\n');
	}
	while(col < 1 || col > numberOfCols);

	location.m_col = col - 1;
	location.m_row = static_cast<short>(row - 'A');
	return location;
}

//---------------------------------------------------------------------------------
// Function:	validLocation()
// Title:	Valid Location 
// Description:
//		Can the ship legitimately go there?
// Programmer:
// 
// Date:	12/20/05
//
// Version:	0.1
// 
// Environment: Hardware: i3 
//              Software: OS: Windows 7; 
//              Compiles under Microsoft Visual C++ 2012
//
// Calls:
//
// Called By:
//
// Parameters:	player: const Player&;	a reference to the specific Player
//		shipNumber: short;	the number of the ship (1 - 5)
//					in the array player.m_ships[]
//		size: char;		'S' or 'L'
// 
// Returns: bool -- 	true if the ship would not go off the edge
//				or cross another ship;
//			false otherwise
//
// History Log:
//		12/20/05 PB completed v 0.1
//     
//---------------------------------------------------------------------------------
bool validLocation(const Player& player, short shipNumber, char size)
{
	short numberOfRows = (toupper(size)=='L') ? LARGEROWS : SMALLROWS;
	short numberOfCols = (toupper(size)=='L') ? LARGECOLS : SMALLCOLS;
	// your code goes here ...
	char a;
	Cell location = 
	{player.m_ships[shipNumber].m_bowLocation.m_row,
	player.m_ships[shipNumber].m_bowLocation.m_col};
	Direction direction = player.m_ships[shipNumber].m_orientation;

	short horizontaldistance = numberOfCols - location.m_col;
	short verticaldistance =numberOfRows - location.m_row;


	a = player.m_gameGrid[0][location.m_row][location.m_col];

	if(location.m_col < 0 || location.m_row < 0)
		return false;
	if(location.m_col > numberOfCols || location.m_row > numberOfRows)
		return false;
	if (a != NOSHIP)
	{
		return false;
	}
	else if (direction == HORIZONTAL)
	{
		if (abs(horizontaldistance) < shipSize[shipNumber]) 
		{
			return false;}
		else 
		{ 
			for (int j= location.m_col; j< (location.m_col + shipSize[shipNumber]) ; j++) 
			{
				if(player.m_gameGrid[0][location.m_row][j] != NOSHIP)
				{
					return false; }
			}
		}
	}			
	else if (direction == VERTICAL)
	{
		if (abs(verticaldistance) < shipSize[shipNumber]) 
		{
			return false;}
		else 
		{ 
			for (int j= location.m_row; j< (location.m_row + shipSize[shipNumber]) ; j++) 
			{
				if(player.m_gameGrid[0][j][location.m_col] != NOSHIP)
				{
					return false; 
				}
			}
		}
	}						  


	// replace the return value
	return true;//return true;	


};





//---------------------------------------------------------------------------------
// Function:	header()
// Title:	header 
// Description:
//		Prints opening graphic
// Programmer:	Paul Bladek
// 
// Date:	9/12/06
//
// Version:	1.0
// 
// Environment: Hardware: i3 
//              Software: OS: Windows 7; 
//              Compiles under Microsoft Visual C++ 2012
//
// Output:	
//
// Calls:	boxTop()
//		boxLine()
//		boxBottom()
//
// Called By:	main()
//
// Parameters:	sout: ostream&;	the stream to print to
// 
// Returns:	void
//
// History Log: 
//		9/12/06 PB comleted v 1.0
//     
//---------------------------------------------------------------------------------
void header(ostream& sout)
{
	const string empty;
	const string sink("SINK THE FLEET!");
	// your name goes here!
	const string by("Edmonds Community College CS 132");
	boxTop(sout, BOXWIDTH);
	boxLine(sout, empty, BOXWIDTH);
	boxLine(sout, sink , BOXWIDTH, 'C');
	boxLine(sout, empty, BOXWIDTH);
	boxLine(sout, by, BOXWIDTH, 'C');
	boxLine(sout, empty, BOXWIDTH);
	boxBottom(sout, BOXWIDTH);
}

//---------------------------------------------------------------------------------
// Function:	endBox()
// Title:	End Box 
// Description:
//		prints closinging graphic
// Programmer:	Paul Bladek
// 
// Date:	9/12/06
//
// Version:	1.0
// 
// Environment: Hardware: i3 
//              Software: OS: Windows 7; 
//              Compiles under Microsoft Visual C++ 2012
//
// Output:	
//
// Calls:	boxTop()
//		boxLine()
//		boxBottom()
//
// Called By:	main()
//
// Parameters:	player: short; the number of the winner (0 or 1)
// 
// Returns:	void
//
// History Log: 
//		9/12/06 PB comleted v 1.0
//     
//---------------------------------------------------------------------------------
void endBox(short player)
{
	const string empty;
	ostringstream msg;
	msg << "Congratulations player " << player + 1 << "!";
	boxTop(cout, BOXWIDTH);
	boxLine(cout, empty, BOXWIDTH);
	boxLine(cout, msg.str() , BOXWIDTH, 'C');
	boxLine(cout, empty, BOXWIDTH);
	boxBottom(cout, BOXWIDTH);
}

