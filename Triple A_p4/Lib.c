#include "Lib.h"

void printGeneration(const int generation[][COLUMN])
{
	int token1 = 0;
	int token2 = 0;
	//print out the first line of frame
	printf("%c", (char)201); //upper left corner frame ╔
	for(token1 = ORIGIN; token1 < COLUMN; token1++)
	{
		printf("%c", (char)205); //slot frame ═
		if(token1 != COLUMN - ONE) //dividing-collumn frame ╦
			printf("%c", (char)203);
		else //upper right corner frame ╗
			printf("%c\n", (char)187);
	}

	for(token1 = ORIGIN; token1 < ROW; token1++)
	{
		for(token2 = ORIGIN; token2 < COLUMN; token2++)
		{
			//seperating-frame ║
			printf("%c", (char)186);
			//print the symbol of the residents
			printf("%c", (char)generation[token1][token2]);		
		}
		//end of the line
		printf("%c\n", (char)186);
		if(token1 != ROW - ONE)
		{
			//dividing-frame line ╠
			printf("%c", (char)204);
			for(token2 = ORIGIN; token2 < COLUMN; token2++)
			{
				//slot frame ═
				printf("%c", (char)205);
				if(token2 != COLUMN - ONE)
					//dividing-frame ╬
						printf("%c", (char)206);
				else //last frame on the line ╣
					printf("%c\n", (char)185);
			}
		}
	}
	//the last line of frame
	printf("%c", (char)200); //lower left corner frame ╚
	for(token1 = 0; token1 < COLUMN; token1++)
	{
		printf("%c", (char)205); //slot frame ═
		if(token1 != COLUMN - ONE)
			//dividing-collumn frame ╩
				printf("%c", (char)202);
		else
			//lower right corner frame ╝
			printf("%c\n", (char)188);
	}
}

void swapPointer(int (**pointerOne)[COLUMN], 
				 int (**pointerTwo)[COLUMN])
{
	int (*pointerTemp)[COLUMN] = *pointerOne;
	*pointerOne = *pointerTwo;
	*pointerTwo = pointerTemp;
}

int readlife(int file[][COLUMN])
{
	int row = 0;
	int column = 0;
	int successful = 1;
	char fileName[FILENAME_MAX] = "";
	FILE * infile = NULL;
	printf("Please enter a file name: \n");

	//get file name
	while(infile == NULL)
	{
		fgets(fileName, FILENAME_MAX, stdin);
		if(fileName[strlen(fileName) - ONE] == '\n')
			fileName[strlen(fileName) - ONE] = '\0';
		else
			while(getchar() != '\n');

		infile = fopen(fileName, "r");

		if(infile == NULL)// file not found exception handler
		{
			printf("Could not open file %s \n"
			"Please enter an valid file name:\n", fileName );
		}
	}

	for(row = 0; row < ROW; row++)
		for(column = 0; column < COLUMN; column++)
			fscanf(infile, "%d", &file[row][column]);

	fclose(infile);
	return successful;
}

int countNeighbors(int row, int column, 
				   const int generation[][COLUMN])
{

	int numberNeighbor = 0;
	if((row == ORIGIN) && (column == ORIGIN))
	{
		if(generation[row][column + ONE] == ONE)
			numberNeighbor++; 
		if(generation[row + ONE][column] == ONE)
			numberNeighbor++; 
		if(generation[row + ONE][column + ONE] == ONE)
			numberNeighbor++;
	}

	else if((row != ORIGIN) && (column == ORIGIN) &&
		(row !=(ROW  - ONE)))
	{

		if(generation[row - ONE][column] == ONE)
			numberNeighbor++; 
		if(generation[row - ONE][column + ONE] == ONE)
			numberNeighbor++; 
		if(generation[row][column + ONE] == ONE)
			numberNeighbor++;
		if(generation[row + ONE][column + ONE] == ONE)
			numberNeighbor++; 
		if(generation[row + ONE][column] == ONE)
			numberNeighbor++; 
	}

	else if((row == (ROW - ONE)) && (column != (COLUMN - ONE))
		&& (column != ORIGIN) )
	{
		if(generation[row][column - ONE] == ONE)
			numberNeighbor++; 
		if(generation[row - ONE][column - ONE] == ONE)
			numberNeighbor++; 
		if(generation[row - ONE][column] == ONE)
			numberNeighbor++; 
		if(generation[row - ONE][column + ONE] == ONE)
			numberNeighbor++; 
		if(generation[row ][column + ONE] == ONE)
			numberNeighbor++;
	}

	else if((row == ORIGIN) && (column == (COLUMN - ONE)))
	{
		if(generation[row][column - ONE] == ONE)
			numberNeighbor++; 
		if(generation[row + ONE][column] == ONE)
			numberNeighbor++; 
		if(generation[row + ONE][column - ONE] == ONE)
			numberNeighbor++; 
	}

	else if((row == ORIGIN) && (column != ORIGIN) && 
		(column !=(COLUMN - ONE)))
	{
		if(generation[row][column + ONE] == ONE)
			numberNeighbor++; 
		if(generation[row + ONE][column] == ONE)
			numberNeighbor++; 
		if(generation[row + ONE][column + ONE] == ONE)
			numberNeighbor++; 
		if(generation[row][column - ONE] == ONE)
			numberNeighbor++; 
		if(generation[row + ONE][column - ONE] == ONE)
			numberNeighbor++; 
	}

	else if((row == (ROW - ONE)) && (column == ORIGIN))
	{
		if(generation[row - ONE][column] == ONE)
			numberNeighbor++; 
		if(generation[row][column + ONE] == ONE)
			numberNeighbor++; 
		if(generation[row + ONE][column + ONE] == ONE)
			numberNeighbor++; 
	}

	else if((row == (ROW - ONE)) && (column == (COLUMN - ONE)))
	{
		if(generation[row][column - ONE] == ONE)
			numberNeighbor++; 
		if(generation[row - ONE][column] == ONE)
			numberNeighbor++; 
		if(generation[row - ONE][column - ONE] == ONE)
			numberNeighbor++; 
	}

	else if((row != (ROW - ONE)) && (column == (COLUMN - ONE))  
		&& (row != ORIGIN))
	{
		if(generation[row - ONE][column] == ONE)
			numberNeighbor++; 
		if(generation[row - ONE][column - ONE] == ONE)
			numberNeighbor++; 
		if(generation[row ][column - ONE] == ONE)
			numberNeighbor++; 
		if(generation[row + ONE][column - ONE] == ONE)
			numberNeighbor++; 
		if(generation[row + ONE ][column ] == ONE)
			numberNeighbor++;
	}

	else if((row < (ROW - ONE)) && (row > ORIGIN) &&
		(column < (COLUMN  - ONE)) && (column > ORIGIN))
	{
		if(generation[row - ONE][column] == ONE)
			numberNeighbor++; 
		if(generation[row - ONE][column - ONE] == ONE)
			numberNeighbor++; 
		if(generation[row - ONE][column + ONE] == ONE)
			numberNeighbor++; 
		if(generation[row ][column - ONE] == ONE)
			numberNeighbor++; 
		if(generation[row ][column + ONE] == ONE)
			numberNeighbor++; 
		if(generation[row + ONE][column - ONE] == ONE)
			numberNeighbor++; 
		if(generation[row + ONE ][column ] == ONE)
			numberNeighbor++;
		if(generation[row + ONE ][column + ONE] == ONE)
			numberNeighbor++;
	}
	return numberNeighbor;
}

void calcNextGeneration(const int generation[][COLUMN],
					   int nextGeneration[][COLUMN])
{	
	int token1 = 0;
	int token2 = 0;
	for(token1 = 0; token1 < ROW; token1++)
		for(token2 = 0; token2 < COLUMN; token2++)
		{
			if(generation[token1][token2] == NONE)
			{
				if(countNeighbors(token1, token2, generation) == BIRTH)
					nextGeneration[token1][token2] = LIVE;
				else
					nextGeneration[token1][token2] = NONE;
			}
			else
			{
				if(countNeighbors(token1, token2, generation) < LONELY)
					nextGeneration[token1][token2] = NONE;
				else if(countNeighbors(token1, token2, generation)
				> CROWDED)
					nextGeneration[token1][token2] = NONE;
				else
					nextGeneration[token1][token2] = LIVE;
			}
		}
}