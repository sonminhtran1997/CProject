#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>
#include <string>
#include <sstream>
#include "textGraphics.h"
#include "safeio.h"
#include "fleet.h"

int main()
{
	Player gamer[2];
	initializePlayer(&gamer[0]);
	allocMem(gamer,'s');
	printGrid(cout, gamer[0].m_gameGrid[0], 's');
	deleteMem(gamer, 's');
	return EXIT_SUCCESS;
}