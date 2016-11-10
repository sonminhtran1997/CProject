#ifndef LIB_H
#define LIB_H
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define ROW 20
#define COLUMN 39
#define FILENAME_MAX 256
#define TRUE 1
#define FALSE 2
#define ONE 1
#define ORIGIN 0
#define BIRTH 3
#define CROWDED 3
#define LONELY 2
#define NONE 0
#define LIVE 1

//---------------------------------------------------------------------
//   Function:    printGeneration(const int generation[][COLUMN])
//   Title:       Print out Generation
//   Description: Print out the game of life
//   Programmer:  An Dien Tang
//   Date:        11/29/2014
//   Version:     1.00
//   Environment: Laptop Toshiba 
//                Software:   MS Windows 8 for execution; 
//                Compiles under Microsoft Visual Studio.Net 2012
//   Parameter:   const int generation[][COLUMN]
//   Input:       NONE
//   Output:      Generation with frame
//   Calls:       NONE
//   Return:      NONE
//   History Log:
//                11/29/2014 AT completed version 1.0
// --------------------------------------------------------------------
void printGeneration(const int generation[][COLUMN]);

//---------------------------------------------------------------------
//   Function:    swapPointer(int (**pointerOne)[COLUMN], 
//				  int (**pointerTwo)[COLUMN]) 
//   Title:       Swap pointer
//   Description: Swap the addresses of 2 pointers
//   Programmer:  An Dien Tang
//   Date:        11/29/2014
//   Version:     1.00
//   Environment: Laptop Toshiba 
//                Software:   MS Windows 8 for execution; 
//                Compiles under Microsoft Visual Studio.Net 2012
//   Parameter:   int (**pointerOne)[COLUMN], 
//				  int (**pointerTwo)[COLUMN])
//   Input:       NONE
//   Output:      NONE
//   Calls:       NONE
//   Return:      NONE
//   History Log:
//                11/29/2014 AT completed version 1.0
// --------------------------------------------------------------------
void swapPointer(int (**pointerOne)[COLUMN], 
				 int (**pointerTwo)[COLUMN]);

//---------------------------------------------------------------------
//   Function:    readlife(int file[][COLUMN]) 
//   Title:       Read the text file
//   Description: Read numbers in text file to the program
//   Programmer:  TSZ HIN FUNG
//   Date:        12/1/2014
//   Version:     1.00
//   Environment: Intel Xeon PC 
//                Software:   MS Windows 7 for execution; 
//                Compiles under Microsoft Visual Studio.Net 2010
//   Parameter:   int file[][COLUMN]
//   Input:       fileName
//   Output:      Guidance for input warning when fail
//   Calls:       countNeighbors
//   Return:      successful
//   History Log:
//                12/1/2014 THF completed version 1.0
// --------------------------------------------------------------------
int readlife(int file[][COLUMN]);

//---------------------------------------------------------------------
//   Function:    countNeighbors(int row , int column, 
//						const int generation[][COLUMN]) 
//   Title:       Count the Neighbors
//   Description: Count number of neighbors for each cell
//   Programmer:  Ngo Austin Khoa
//   Date:        11/25/2014
//   Version:     1.00
//   Environment: Intel Xeon PC 
//                Software:   MS Windows 7 for execution; 
//                Compiles under Microsoft Visual Studio.Net 2010
//   Parameter:   int row , int column, 
//					const int generation[][COLUMN]
//   Input:       NONE
//   Output:      NONE
//   Calls:       NONE
//   Return:      Number of the neighbors (int type)
//   History Log:
//                11/25/14  NAK completed version 1.0
// --------------------------------------------------------------------
int countNeighbors(int row , int column, 
				   const int generation[][COLUMN]);

//---------------------------------------------------------------------
//   Function:    calcNextGeneration(const int generation[][COLUMN],
//					   int nextGeneration[][COLUMN])
//   Title:       Calculate next generation
//   Description: Create next generation based on the previous one
//   Programmer:  Ngo Austin Khoa
//   Date:        11/25/2014
//   Version:     1.00
//   Environment: Intel Xeon PC 
//                Software:   MS Windows 7 for execution; 
//                Compiles under Microsoft Visual Studio.Net 2010
//   Parameter:   const int generation[][COLUMN],
//					   int nextGeneration[][COLUMN]
//   Input:       NONE
//   Output:      NONE
//   Calls:       countNeighbors
//   Return:      NONE
//   History Log:
//                11/25/14  NAK completed version 1.0
// --------------------------------------------------------------------
void calcNextGeneration(const int generation[][COLUMN],
					   int nextGeneration[][COLUMN]);
#endif 
