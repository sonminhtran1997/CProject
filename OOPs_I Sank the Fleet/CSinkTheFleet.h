#ifndef CSINKTHEFLEET_H
#define CSINKTHEFLEET_H
#include <iostream>
#include "CPlayer.h"
#include "textGraphics.h"

using namespace std;
CPlayer player0;
CPlayer player1;
class CSinkTheFleet
{
	public:

		const short NUMPLAYERS = 2;	// number of players in game
		const short SMALLROWS = 8;	// number of rows/columns in small sea array 
		const short LARGEROWS = 10;	// number of rows/columns in large sea array
		const short SMALLCOLS = 12;	// number of rows/columns in small sea array 
		const short LARGECOLS = 24;	// number of rows/columns in large sea array
		const short BOXWIDTH = 79;	// maximum screen line length
		CSinkTheFleet (char gridSize = 'S')
		{
			m_players[0] = player0;
			m_players[1] = player1;
			m_gridSize = gridSize;
		}

		CPlayer & operator[] (short index); 
		const CPlayer & operator[] (short index) const;
		
		static void header(ostream& sout);
		static void endBox(short player,ostream& sout);

		short CSinkTheFleet::play();// return the index of the winner player

	private:
		CPlayer m_players[NUMPLAYERS];
		char m_gridSize; //'L' or 'S'
	
};

# endif



//---------------------------------------------------------------------------------
// File name:   CSinkTheFleet.h
// Title:		class CSinkTheFleet 
// Description: the class for players to play the game
//				
// Programmer:	Xiao "Rita" Zhang
// 
// Date:		03/05/2015
//
// Version:		1.0
// 
// Environment: Hardware: ASUS i5
//              Software: OS: Windows 8.1; 
//              Compiles under Visual Studio, C++ 2012
//
//
// class:		CSinkTheFleet
// properties:	Cplayer m_players[2]; char m_gridSize
//
// Methods:		a default constructor;
//				play;
//				operator[];
//				operator[] const;
//				static header;
//				static endbox;
//
// History Log: 
//		3/05/2015 XZ completed v 1.0
//--------------------------------------------------------------------------------