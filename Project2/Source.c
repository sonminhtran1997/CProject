//---------------------------------------------------------------------------------
//   File:        StandardDeviation.c
//
//   Functions:
//                main()
//---------------------------------------------------------------------------------

#include <stdio.h>
#include <math.h> 
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable: 4996)

#define length_of_the_string 1000
#define decrease_by_one 1
#define square 2
#define check_positive 0
#define check_more_than_one 1
#define true 1
#define false 0
//---------------------------------------------------------------------------------
//   Function:    main()
//   Title:       Standard Deviation
//   Description: Write information about standard deviation in a file
//   Programmer:  An Dien Tang
//   Date:        10/25/2014
//   Version:     1.0
//   Environment: Laptop Toshiba 
//                Software: Microsoft Windows 8.1 64 bit for execution; 
//							Microsoft Visual Studio 2012
//   Output:      write the result to a file
//   Returns:     EXIT_SUCCESS (successful execution)
//   History Log:
//				  10/25/2014 AT completed version 1.0 
//                
// --------------------------------------------------------------------------------

int main(void)
{
	char name_of_file[length_of_the_string] = "";
	FILE * file_input;
	FILE * file_output;
	int number_of_the_elements = 0;
	int summation = 0;
	int lowest_number = 0;
	int highest_number = 0;
	int header_number_in_file = 0;
	int value_of_element = 0;
	int token = 0;
	double squares_summation = 0;
	double mean = 0;
	double variance = 0;
	double standard_deviation = 0;
	int very_first_input = true;

	printf("Welcome to Standard Deviation Program written by An Dien Tang.\n");
	printf("Please enter a name for an input file (source): ");
	fgets(name_of_file, length_of_the_string, stdin);

	//Make up the string and clean up the buffer
	if(name_of_file[strlen(name_of_file) - decrease_by_one] == '\n')
		name_of_file[strlen(name_of_file) - decrease_by_one] = '\0';
	else
		while(getchar() != '\n');

	//Print out name of the input file
	printf("\tInput file: \"%s\"\n\n", name_of_file);
	file_input = fopen(name_of_file, "r");
	if (file_input == NULL)
	{
		printf("Could not open the file %s for reading.\n", name_of_file);
		printf("Quitting!!!\n");
	}
	else //If opened successfully, ask for the name of the output file
	{
		printf("Please enter a name for an output file: ");
		fgets(name_of_file, length_of_the_string, stdin);
		//Make up the string and clean up the buffer
		if(name_of_file[strlen(name_of_file) - decrease_by_one] == '\n')
			name_of_file[strlen(name_of_file) - decrease_by_one] = '\0';
		else
			while(getchar() != '\n');

		//Print out name of the output file
		printf("\tOutput file: \"%s\"\n\n", name_of_file);
		file_output = fopen(name_of_file, "w");


		if (file_output == NULL)
		{
			printf("Could not open the file %s for writing.\n", 
				name_of_file);
			printf("Quitting!!!\n");
		}
		else //If opened successfully, start calculating and writing out
		{
			fprintf(file_output, "_____________________________________");
			fprintf(file_output, "___________________________________\n");
			fprintf(file_output, "|# of data|  sum  |   range    |"
				"mean  |");
			fprintf(file_output, " variance | standard deviation|\n");
			fprintf(file_output, "_____________________________________");
			fprintf(file_output, "___________________________________\n");

			while(fscanf(file_input, "%d", &header_number_in_file) != EOF)
			{
				//Check if the header number is > 0
				if (header_number_in_file > 0)
					number_of_the_elements += header_number_in_file;

				//If the header number is > 0, start calculating and 
				//writing out
				for (token = 0; token < header_number_in_file; token++)
				{
					fscanf(file_input, "%d", &value_of_element);

					//Check if it is the very first input
					if (very_first_input == true)
					{
						highest_number = value_of_element;
						lowest_number = value_of_element;
						very_first_input = false;
					}
					else
					{
						if (highest_number <= value_of_element)
							highest_number = value_of_element;

						if (lowest_number >= value_of_element)
							lowest_number = value_of_element;
					}

					summation += value_of_element;
					squares_summation += pow((double)value_of_element
						, square);

					//Check if the number of elements is > 0
					if (number_of_the_elements > check_positive)
						mean = ((double)summation) / 
						number_of_the_elements;
					else
						mean = 0;

					//Check if the number of elements is > 1
					if (number_of_the_elements > check_more_than_one)
					{
						variance = (squares_summation - 
							pow((double)summation, square) / 
							number_of_the_elements)
							/ (number_of_the_elements -
							decrease_by_one);

						standard_deviation = sqrt(variance);
					}
					else
						variance = standard_deviation = 0;
				}

				//Print out the result
				fprintf(file_output, "|%9d|%7d|%4d to %4d|%8.3f|%10.3f|"
					"%18.3f|\n",
					number_of_the_elements, summation, lowest_number, 
					highest_number,	mean, variance,
					standard_deviation);
				fprintf(file_output, "__________________"
					"___________________");
				fprintf(file_output, "__________________"
					"_________________\n");			}

			printf("The writing has been done, the program will exit. \n");
			fclose(file_output);
		}
		fclose(file_input);
	}
	getchar();
	return EXIT_SUCCESS;
}


