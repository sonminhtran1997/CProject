#include "CPlayer.h"

CPlayer::CPlayer( unsigned short whichPlayer, char gridSize)
	: m_whichPlayer(whichPlayer), m_gridSize(gridSize), m_gameGrid()
{
	allocateMemory();
	m_piecesLeft = MAXPIECE;
	for (int i = 0; i < SHIP_SIZE_ARRAYSIZE; i++)
	{
		m_ships[i].setName(i);
		m_ships[i].setBowLocation(cellToken);
		m_ships[i].setOrientation(CDirection::HORIZONTAL);
		m_ships[i].setPiecesLeft(shipSize[i]);
	}
}

CPlayer::CPlayer(const CPlayer& copyCPlayer)
{
	allocateMemory();
	*this = copyCPlayer;
}

void CPlayer::allocateMemory()
{
	char * p = nullptr;
	short numberOfRows = (toupper(getGridSize()) == 'L') ? LARGEROWS : SMALLROWS;
	short numberOfCols = (toupper(getGridSize()) == 'L') ? LARGECOLS : SMALLCOLS;

	for(short i = 0; i < NUMPLAYERS; ++i)
	{
		m_gameGrid[0] = nullptr;
		m_gameGrid[0] = new CShip*[numberOfRows];
		m_gameGrid[1] = nullptr;
		m_gameGrid[1] = new CShip*[numberOfRows];
		for(short j = 0; j < numberOfRows; ++j)
		{
			m_gameGrid[0][j] = nullptr;
			m_gameGrid[0][j] = new CShip[numberOfCols];
			m_gameGrid[1][j] = nullptr;
			m_gameGrid[1][j] = new CShip[numberOfCols];
			for(short k = 0; k < numberOfCols; ++k)
			{
				m_gameGrid[0][j][k] = CShip::NOSHIP;
				m_gameGrid[1][j][k] = CShip::NOSHIP;
			} // end for k
		} // end for j
	} // end for i

}

void CPlayer::deleteMemory()
{
	short numberOfRows = (toupper(getGridSize()) == 'L') ? LARGEROWS : SMALLROWS;
	short numberOfCols = (toupper(getGridSize()) == 'L') ? LARGECOLS : SMALLCOLS;
	for(short i = 0; i < NUMPLAYERS; ++i)
	{
		if (m_gameGrid[0] != nullptr)
		{
			for(short j = 0; j < numberOfRows; ++j)
			{
				if (m_gameGrid[0][j] != nullptr)
					delete[] m_gameGrid[0][j];
			} // end for i
			delete[] m_gameGrid[0];
			m_gameGrid[0] = nullptr;
		}
		if (m_gameGrid[1] != nullptr)
		{	
			for(short j = 0; j < numberOfRows; ++j)
			{
				if (m_gameGrid[1][j] != nullptr)
					delete[] m_gameGrid[1][j];
			} // end for i
			delete[] m_gameGrid[1];
			m_gameGrid[1] = nullptr;
		}
	} // end for j
}

CPlayer CPlayer::operator=(const CPlayer& copyCPlayer)
{
	m_whichPlayer = !copyCPlayer.getWhichPlayer(); 
	m_gridSize = copyCPlayer.getGridSize();
	short numberOfRows = (toupper(getGridSize()) == 'L') ? LARGEROWS : SMALLROWS;
	short numberOfCols = (toupper(getGridSize()) == 'L') ? LARGECOLS : SMALLCOLS;
	m_piecesLeft = copyCPlayer.getPiecesLeft();
	for (int i = 0; i < SHIP_SIZE_ARRAYSIZE; i++)
		m_ships[i] = copyCPlayer.m_ships[i];
	CCell token(0,0);
	for (int i = 0; i < NUMPLAYERS; i++)
		for (int j = 0; j < numberOfRows; j++)
		{
			for (int k = 0; k <numberOfCols; k++)
			{
				m_gameGrid[i][j][k] = copyCPlayer.getCell(i, token);
				token.increaseCol();
			}
			token.increaseRow();
		}
		return *this;
}

CShip CPlayer::getCell(short whichGrid, CCell cell) const
{
	return m_gameGrid[whichGrid][cell.getRow()][cell.getCol()];
}

void CPlayer::setGridSize(char size)
{
	cout << "Which grid size do you want to use ? ";
	m_gridSize = safeChoice(" ", 'S', 'L');
}

void CPlayer::setCell( short whichGrid, CCell cell, CShip ship)
{
	m_gameGrid[whichGrid][cell.getRow()][cell.getCol()] = ship;
}

bool CPlayer::isValidLocation(short whichShip)
{
	short numberOfRows = (toupper(getGridSize())=='L') ? LARGEROWS : SMALLROWS;
	short numberOfCols = (toupper(getGridSize())=='L') ? LARGECOLS : SMALLCOLS;

	// our code
	if (m_ships[whichShip].getOrientation() == CDirection::VERTICAL)
	{
		if(shipSize[whichShip] == 2)
		{
			if(m_ships[whichShip].getCell().getRow() == (numberOfRows - 1))
				return false;
		}
		if (shipSize[whichShip] == 3)
		{
			if (m_ships[whichShip].getCell().getRow() == (numberOfRows - 1))
				return false;
			if(m_ships[whichShip].getCell().getRow() == (numberOfRows - 2))
				return false;
		}
		if (shipSize[whichShip] == 4)
		{
			if (m_ships[whichShip].getCell().getRow() == (numberOfRows - 1))
				return false;
			if (m_ships[whichShip].getCell().getRow() == (numberOfRows - 2))
				return false;
			if (m_ships[whichShip].getCell().getRow() == (numberOfRows - 3))
				return false;
		}
		if (shipSize[whichShip] == 5)
		{
			if (m_ships[whichShip].getCell().getRow() == (numberOfRows - 1))
				return false;
			if (m_ships[whichShip].getCell().getRow() == (numberOfRows - 2))
				return false;
			if (m_ships[whichShip].getCell().getRow() == (numberOfRows - 3))
				return false;
			if (m_ships[whichShip].getCell().getRow() == (numberOfRows - 4))
				return false;
		}
	} // end for 'V'
	if (m_ships[whichShip].getOrientation() == CDirection::HORIZONTAL)
	{
		if (shipSize[whichShip] == 2)
		{
			if (m_ships[whichShip].getCell().getCol() == (numberOfCols - 1))
				return false;
		}
		if (shipSize[whichShip] == 3)
		{
			if (m_ships[whichShip].getCell().getCol() == (numberOfCols - 1))
				return false;
			if (m_ships[whichShip].getCell().getCol() == (numberOfCols - 2))
				return false;
		}
		if (shipSize[whichShip] == 4)
		{
			if (m_ships[whichShip].getCell().getCol() == (numberOfCols - 1))
				return false;
			if (m_ships[whichShip].getCell().getCol() == (numberOfCols - 2))
				return false;
			if (m_ships[whichShip].getCell().getCol() == (numberOfCols - 3))
				return false;
		}
		if (shipSize[whichShip] == 5)
		{
			if (m_ships[whichShip].getCell().getCol() == (numberOfCols - 1))
				return false;
			if (m_ships[whichShip].getCell().getCol() == (numberOfCols - 2))
				return false;
			if (m_ships[whichShip].getCell().getCol() == (numberOfCols - 3))
				return false;
			if (m_ships[whichShip].getCell().getCol() == (numberOfCols - 4))
				return false;
		}
	} // end for 'H'
	if (m_ships[whichShip].getOrientation() == CDirection::HORIZONTAL)
	{
		int i = static_cast<int>(shipSize[whichShip]);
		for (int x = 0; x < (i-1); x++)
		{
			if (m_gameGrid[0][m_ships[whichShip].getCell().getRow()]
			[m_ships[whichShip].getCell().getCol() + x] != CShip::NOSHIP)
				return false;
		}	
	}
	if (m_ships[whichShip].getOrientation() == CDirection::VERTICAL)
	{
		int i = static_cast<int>(shipSize[whichShip]);
		for (int x = 0; x < i; x++)
		{
			if (m_gameGrid[0][m_ships[whichShip].getCell().getRow() + x]
			[m_ships[whichShip].getCell().getCol()] != CShip::NOSHIP)
				return false;
		}	
	}
	return true;
}

const CShipInfo& CPlayer::operator[] (short index) const
{
	if (index >= NUMPLAYERS)
		throw range_error("index out of range");
	return m_ships[index];
}

void CPlayer::printGrid(ostream & sout, short whichGrid) const
{
	short numberOfRows = (toupper(getGridSize()) == 'L') ? LARGEROWS : SMALLROWS;
	short numberOfCols = (toupper(getGridSize()) == 'L') ? LARGECOLS : SMALLCOLS;

	for(short j = 1; j <= numberOfCols; ++j)
	{
		sout << setw(3) << j;	
	}
	sout << endl;

	for(short i = 1; i <= numberOfRows; ++i)
	{
		sout  << static_cast<char>(64 + i);
		for(short j = 1; j <= numberOfCols; ++j)
		{
			m_gameGrid[whichGrid][i][j].printShip(sout);
		} 
		sout  << endl;
		sout  << " ";
		for(short j = 1; j <= numberOfCols; ++j)
		{
			sout << HORIZ << HORIZ << CL;
		}
		sout  << endl;
	}
}

bool CPlayer::getGrid(string fileName)
{
	string line;
	ifstream ifs;
	CShip ship = CShip::NOSHIP;
	short shipCount[SHIP_SIZE_ARRAYSIZE] = {0};
	char cell = ' ';
	//char fsize = 'S';
	char size_of_grid;
	short numberOfRows = (toupper(getGridSize()) == 'L') ? LARGEROWS : SMALLROWS;
	short numberOfCols = (toupper(getGridSize()) == 'L') ? LARGECOLS : SMALLCOLS;
	CCell location;
	ifs.open(fileName.c_str());
	if(!ifs)
	{

		cout << "could not open file " << fileName << endl
			<< " press <enter> to continue" << endl;
		cin.ignore(BUFFER_SIZE, '\n');
		return false;
	}	
	size_of_grid = ifs.get();
	if (m_gridSize != size_of_grid)
	{ 
		cout << "The input file size is not compatible with the " <<
			"grid size that you chose from the beginning.";
		cout << endl;
		ifs.close();
		return false;
	}
	for (int i = 1; i < SHIP_SIZE_ARRAYSIZE; i++)
	{
		int input_orientation;
		int input_row;
		int input_col;
		ifs >> input_orientation;
		ifs >> input_row;
		ifs >> input_col;

		location = (input_row, input_col);
		m_ships[i].setBowLocation(location);
		m_ships[i].setOrientation(input_orientation);

		for(int j = 0; j < shipSize[i]; i++)
		{
			if (m_ships[i].getOrientation() == CDirection::VERTICAL)
			{
				setCell(ZERO, location, m_ships[i].getName());
				location.increaseRow();
			}
			else
			{
				setCell(ZERO, location, m_ships[i].getName());
				location.increaseCol();
			}
		}
	}
	system("CLS");
	printGrid(cout, ZERO);
	char ok = safeChoice("Position okay? ", 'Y', 'N');
	// choice not ok
	if (ok == 'N')
	{
		for (int i = 0; i < numberOfRows; i++)
			for (int j = 0; j < numberOfCols; j++)
				m_gameGrid[ZERO][i][j] = CShip::NOSHIP;
		return false;
	}
	cin.clear();
	cin.ignore(BUFFER_SIZE, '\n');
	fflush(stdin);
	cout << "press <enter>  . . ." << endl;
	cin.get();
	system("CLS");
	ifs.close();	
	return true;
}

void CPlayer::saveGrid()
{
	short numberOfRows = (toupper(getGridSize()) == 'L') ? LARGEROWS : SMALLROWS;
	short numberOfCols = (toupper(getGridSize()) == 'L') ? LARGECOLS : SMALLCOLS;	
	std::ofstream;
	string name_output_file;
	string name_output_file_final;
	char size_of_grid;
	cout <<"Enter the name of an output file: ";
	cin >> name_output_file;
	name_output_file_final = name_output_file + ".shp"; 
	ofstream ofs;
	ofs.open(name_output_file_final);
	if(!ofs)
	{
		cout << "could not open file " << name_output_file << endl;
	}
	// print out the grid size for the 1st line of the output file
	else
	{
		if  (getGridSize() == 'L')
		{
			size_of_grid = 'L';
			ofs.put(size_of_grid);
			ofs << endl;
		}
		else if (getGridSize() == 'S')
		{
			size_of_grid = 'S';
			ofs.put(size_of_grid);
			ofs << endl;
		}
		// print out the location of the ship
		// 1st number is the orientation
		// 2nd number is the row
		// 3nd number is the column
		// one ship per line
		for (int i = 1; i < SHIP_SIZE_ARRAYSIZE; i++)
		{
			ofs << static_cast<int>(CDirection::Direction((m_ships[i].getOrientation())));
			ofs << " ";
			ofs << m_ships[i].getCell().getRow();
			ofs << " ";
			ofs << m_ships[i].getCell().getCol();
			ofs << endl;
		}
		cout << name_output_file_final << " is saved." << endl;
		ofs.close();
	}
}

void CPlayer::setships()
{
	char input = 'V';
	char ok = 'Y';
	char save = 'N';
	ostringstream outSStream;
	CCell location;

	for(short j = 1; j < SHIP_SIZE_ARRAYSIZE; j++)
	{
		system("cls");
		printGrid(cout, ZERO);
		outSStream.str("");
		outSStream << "Player " << m_whichPlayer + ONE << " Enter " 
			<< shipNames[j] << " orientation";
		input = safeChoice(outSStream.str(), 'V', 'H');
		if (input == 'V')
			m_ships[j].setOrientation(ONE);
		else
			m_ships[j].setOrientation(ZERO);
		cout << "Player " << m_whichPlayer + ONE << " Enter " << shipNames[j] 
		<< " bow coordinates <row letter><col #>: ";
		location.getCoord(cin, m_gridSize);
		m_ships[j].setBowLocation(location);
		// if ok
		if(!isValidLocation(j))
		{
			cout << "invalid location. Press <enter>" ;
			cin.ignore(BUFFER_SIZE, '\n');
			cin.get();
			j--; // redo
			continue;
		}
		// our code
		location = m_ships[j].getCell();
		for(int i = 0; i < shipSize[j]; i++)
		{
			if (input == 'V')
			{
				setCell(ZERO, location, m_ships[j].getName());
				location.increaseRow();
			}
			else
			{
				setCell(ZERO, location, m_ships[j].getName());
				location.increaseCol();
			}
		}
		system("CLS");
		printGrid(cout, ZERO);
		ok = safeChoice("Position okay? ", 'Y', 'N');
		// choice not ok
		if (ok == 'N')
		{
			location = m_ships[j].getCell(); 
			for(int i = 0; i < shipSize[j]; i++)
			{
				if (input == 'V')
				{
					setCell(ZERO, location, CShip::NOSHIP);
					location.increaseRow();
				}
				else
				{
					setCell(ZERO, location, CShip::NOSHIP);
					location.increaseCol();
				}
			}
			j--;
		}
	} // end for j
	save = safeChoice("\nSave starting grid?", 'Y', 'N');
	if(save == 'Y')
		saveGrid();
}

CPlayer CPlayer::operator--()
{
	m_piecesLeft --;
	return *this;
}

void CPlayer::hitShip(CShip Ship)
{
	m_piecesLeft--;
	--m_ships[static_cast<int>(Ship)];
}