#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Lib.h"
#define ROW 20
#define COLUMN 39

//---------------------------------------------------------------------
//   Function:    main(void)
//   Title:       Main
//   Description: Main function for the game of life
//   Programmer:  
//   Date:        12/1/2014
//   Version:     1.00
//   Environment: Intel Xeon PC 
//                Software:   MS Windows 7 for execution; 
//                Compiles under Microsoft Visual Studio.Net 2010
//   Parameter:   void
//   Input:       NONE
//   Output:      Generation with frame
//   Calls:       printGeneration
//                swapPointer
//                calcNextGeneration
//                readlife
//   Return:      EXIT_SUCCESS
//   History Log:
//                12/1/2014  completed version 1.0
// --------------------------------------------------------------------
int main(void)
{
	int generation[ROW][COLUMN] = {0};
	int nextGeneration[ROW][COLUMN] = {0};
	int (*pointerOne)[COLUMN] = generation;
	int (*pointerTwo)[COLUMN] = nextGeneration;
	int numberOfGeneration = 0;
	char token = ' ';
	readlife(pointerOne);
	do
	{
		system("cls");
		printf("Generation: %d\n", numberOfGeneration);
		numberOfGeneration++;
		printGeneration(pointerOne);
		calcNextGeneration(pointerOne, pointerTwo);
		swapPointer(&pointerOne, &pointerTwo);
		printf("Press Enter to continue, other keys to quit...");
		token = getch();
	}
	while(token == '\r' || token == '\n' );
	return EXIT_SUCCESS;
}