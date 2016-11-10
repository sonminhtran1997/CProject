//-------------------------------------------------------------------------------
//   File:        Amortization Library
//
//   Functions:
//main()
//roundNumber()
//getPaymentAmount()
//getLoanAmount()
//getNumberOfMonths()
//getInterestRate()
//readAPR()
//readTotalLoan()
//readMonthlyPayment()
//readNumberOfPayment()
//printTable()
//-------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include "Amort.h"


#define TOTAL_MONTH_IN_1_YEAR 12
#define TRUE 0
#define FALSE 1
#define CENT_VALUE 100
#define ROUND_OFF 2
#define ROUND_UP 1
#define ROUND_1_OVER_8 0.125
#define PERCENTAGE_IN_DECIMAL 100
#define ORIGIN 0
//-------------------------------------------------------------------------------
//   Function:    main()
//   Title:       AmortDriver
//   Description: Calculate value and print out file text (if desirable)
//   Programmer:  An Dien Tang
//   Date:		  11/16/2014
//   Version:     1.0
//   Environment: Laptop Toshiba 
//                MS Windows 8; 
//                Microsoft Visual Studio.Net 2012
//	 Input:		  Value from the user
//   Output:      Display calculated value and print out file text (if desirable)
//   Calls:       getPaymentAmount()
//				  roundNumber()
//				  getLoanAmount()
//				  getNumberOfMonths()
//				  getInterestRate()
//				  readAPR()
//				  readTotalLoan()
//				  readMonthlyPayment()
//				  readNumberOfPayment()
//				  printTable()
//	 Parameter:	  void
//   Returns:     EXIT_SUCCESS (successful execution)
//   History Log:
//                11/16/2014 AT complete version 1.0
// ------------------------------------------------------------------------------
int main(void)
{
	double monthlyPayment = 0;
	double anualInterestRate = 0;
	double monthlyInterestRate = 0;
	double totalLoan = 0;
	double minimumValue = 0;
	int month = 0;
	int stop = FALSE;
	printf("Welcome to Amortization Program by An Dien Tang\n\n");
	do
	{
		printf("Menu option:\n\n");
		printf("<1> Calculate <P>ayment Size\n");
		printf("<2> Calculate <L>oan Size\n");
		printf("<3> Calculate <N>umber of Payments\n");
		printf("<4> Calculate <I>terest Rate (APR)\n");
		printf("<5> <Q>uit\n\n");
		printf("Please press a menu option: ");

		switch (getche())
		{
		case '1':
		case 'P':
		case 'p':
			printf("\n");
			anualInterestRate = readAPR();
			monthlyInterestRate = anualInterestRate / 12;
			totalLoan = readTotalLoan();
			month = readNumberOfPayment();

			monthlyPayment = getPaymentAmount(totalLoan, 
				monthlyInterestRate, month);
			printf("\nPayment: $%.2lf per month\n", monthlyPayment);
			break;
		case '2':
		case 'L':
		case 'l':
			printf("\n");
			anualInterestRate = readAPR();
			monthlyInterestRate = anualInterestRate / 12;
			monthlyPayment = readMonthlyPayment(minimumValue);
			month = readNumberOfPayment();

			totalLoan = getLoanAmount(monthlyPayment,
				monthlyInterestRate, month);
			printf("\nLoan Amount : $%.2lf \n", totalLoan);
			break;
		case '3':
		case 'N':
		case 'n':
			printf("\n");
			anualInterestRate = readAPR();
			monthlyInterestRate = anualInterestRate / 12;
			totalLoan = readTotalLoan();
			minimumValue = totalLoan * monthlyInterestRate;

			//print warning
			printf("Monthly payment must be greater than $%.2lf!\n"
				, minimumValue);
			monthlyPayment = readMonthlyPayment(minimumValue);

			month = getNumberOfMonths(totalLoan, monthlyPayment, 
				monthlyInterestRate);
			printf("\nNumber of months to pay the loan : %d\n", month);
			break;
		case '4':
		case 'I':
		case 'i':
			printf("\n");
			totalLoan = readTotalLoan();
			month = readNumberOfPayment();

			//print suggestion
			printf("Monthly Payment should be equal to "
				"or greater than $%.2lf\n", roundNumber(totalLoan 
				* CENT_VALUE / month, ROUND_OFF) / CENT_VALUE);
			monthlyPayment = readMonthlyPayment(minimumValue);
			monthlyInterestRate = getInterestRate(totalLoan, monthlyPayment,
				month);

			//when the rate is negative
			if(monthlyInterestRate < ORIGIN)
				printf("Can not calculate Interest Rate");
			//when the rate is not negative
			else
			{
				anualInterestRate = roundNumber(monthlyInterestRate 
					* TOTAL_MONTH_IN_1_YEAR * PERCENTAGE_IN_DECIMAL
					, ROUND_1_OVER_8);
				printf("\nInterest Rate : %.3lf%%\n", 
					anualInterestRate);
			}
			break;
		case '5':
		case 'Q':
		case 'q':
			printf("\nThank you for using the program!\n");
			getch();
			stop = TRUE;
			break;
		default:
			printf("\nPlease enter a valid menu choice! \n\n");
			continue;
		}
		if(stop == FALSE)
		{
			if(monthlyInterestRate >= ORIGIN)
				printTable(totalLoan, monthlyInterestRate, month);
			printf("\nPress any keys to continue... ");
			getche();
			system("cls");
			minimumValue = ORIGIN;
		}
	}

	while(stop == FALSE);
	return EXIT_SUCCESS;
}