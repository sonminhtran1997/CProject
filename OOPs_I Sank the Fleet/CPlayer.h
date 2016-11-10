#ifndef CPLAYER_H
#define CPLAYER_H

#include <iostream>
#include "CCell.h"
#include "CShipInfo.h"
#include "CShip.h"
#include "CShipInfo.h"
#include "CDirection.h"
#include "textGraphics.h"
using namespace std;
const short ONE = 1;
class CPlayer
{
	//---------------------------------------------------------------------------
	//	Title:          CPlayer Class
	//	Description:    This file contains the class definition for CPlayer
	//	Programmer:     Hang Nguyen
	//	Date:           3/2/2015
	//	Version:	1.2
	//	Environment:	MacBook Pro Hardware: i5
	//					Software:   MS Windows 7	
	//					Compiles under Microsoft Visual C++ 2012
	//	class CDirection:
	//	Properties:
	//			
	//	Methods:
	//			Inline:
	//
	//			Non-Inline:
	//
	//  History Log:
	//					3/2/2015 HN completed v 1.0
	//					3/3/2015 HN completed v 1.1
	//					3/4/2015 HN completed v 1.2
	//-----------------------------------------------------------------------------
public:
	static const short NUMPLAYERS = 2;	// number of players in game
	static const short SMALLROWS = 8;	// number of rows/columns in small sea array 
	static const short LARGEROWS = 10;	// number of rows/columns in large sea array
	static const short SMALLCOLS = 12;	// number of rows/columns in small sea array 
	static const short LARGECOLS = 24;	// number of rows/columns in large sea array
	static const unsigned BUFFER_SIZE = 256;
	static const short MAXPIECE = 17;
	
	CPlayer(unsigned short whichPlayer = ONE, char gridSize = 'S');
	CPlayer(const CPlayer& copyCPlayer);
	~CPlayer();

	CPlayer operator=(const CPlayer& copyCPlayer);
	int getWhichPlayer()const {return m_whichPlayer;}
	int getPiecesLeft()const {return m_piecesLeft;}
	char getGridSize()const {return m_gridSize;}
	CShip getCell(short whichGrid, CCell cell) const;

	void setGridSize(char size);
	void setCell( short whichGrid, CCell cell, CShip ship);

	void printGrid(ostream & sout, short whichGrid) const;
	bool getGrid(string filename);
	void saveGrid();
	void setships();
	void hitShip(CShip Ship);

	bool isValidLocation(short whichShip);

	const CShipInfo& operator[] (short index) const;
	CPlayer CPlayer::operator--();



private:
	unsigned short m_whichPlayer;
	short m_piecesLeft;	// the number of parts of the fleet left unsunk
	CShipInfo m_ships[6];	// an array of the ships in the fleet (ignore 0)
	char m_gridSize;			// an 'L' or 'S' (large or small)
	CShip** m_gameGrid[2];	// an array of two 2-dimensional grids.  Same as in  project 1

	void allocateMemory();
	void deleteMemory(); 
};

inline CPlayer::~CPlayer()
{
	deleteMemory();
}

#endif