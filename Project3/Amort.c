#include "Amort.h"
#define CENT_VALUE 100
#define PERCENTAGE_IN_DECIMAL 100
#define HALF 0.5
#define ROUND_1_OVER_8 0.125
#define INCREASE_BY_ONE 1
#define DECREASE_BY_ONE 1
#define ROUND_UP 1
#define ROUND_OFF 2
#define TRUE 1
#define FALSE 2
#define ORIGIN 0
#define NO_VALUE 0
#define NEGATIVE -1
#define ERROR 0.0001
#define TOTAL_MONTH_IN_1_YEAR 12
#define SEVERAL_TIME 20

double roundNumber(double number, double roundingType)
{
	double quotient = 0;
	//check to round 1/8th
	if (roundingType == ROUND_1_OVER_8)
	{
		quotient = number / ROUND_1_OVER_8;
		if (quotient <  (int)quotient + HALF)
			return (int)quotient * ROUND_1_OVER_8;
		else
			return ((int)quotient + INCREASE_BY_ONE) * ROUND_1_OVER_8;
	}

	//check to round off and round down
	if (roundingType == ROUND_OFF && number < (int)number + HALF)
	{
		number = (int)number;
		return number;
	}

	//round up
	number = (int)number + INCREASE_BY_ONE;
	return number;

}

double getPaymentAmount(double totalLoan, double monthlyInterestRate, int month)
{
	double monthlyPayment = 0;
	if (monthlyInterestRate == NO_VALUE)
		monthlyPayment = totalLoan / month;
	else
	{
		monthlyPayment = pow(INCREASE_BY_ONE + monthlyInterestRate, month)
			* totalLoan * monthlyInterestRate / 
			(pow(INCREASE_BY_ONE + monthlyInterestRate, month) 
			- DECREASE_BY_ONE);
		// convert to cent unit, round up then return to dollar unit
		monthlyPayment = roundNumber(monthlyPayment * CENT_VALUE, ROUND_UP)
			/ CENT_VALUE;
	}

	return monthlyPayment;
}

double getLoanAmount(double monthlyPayment, double monthlyInterestRate, int month)
{
	double totalLoan = 0;
	if (monthlyInterestRate == NO_VALUE)
		totalLoan = monthlyPayment * month;
	else
	{
		totalLoan = (pow(INCREASE_BY_ONE + monthlyInterestRate, month)
			- DECREASE_BY_ONE) * monthlyPayment / (monthlyInterestRate *
			pow(INCREASE_BY_ONE + monthlyInterestRate, month));
		// convert to cent unit, round off then return to dollar unit
		totalLoan = roundNumber(totalLoan * CENT_VALUE, ROUND_OFF) / CENT_VALUE;
	}

	return totalLoan;
}

int getNumberOfMonths(double totalLoan, double monthlyPayment, 
					  double monthlyInterestRate)
{
	double month = 0;
	if (monthlyInterestRate == NO_VALUE)
		month = totalLoan / monthlyPayment;
	else
	{
		month = (log10(monthlyPayment) - log10(monthlyPayment - totalLoan 
			* monthlyInterestRate))	/ log10(INCREASE_BY_ONE 
			+ monthlyInterestRate);
	}

	//round up month (double type)
	month = roundNumber(month, ROUND_UP);

	//convert to int type and return
	return (int)month;
}

double getInterestRate(double totalLoan, double monthlyPayment, int month)
{
	double interestRate = 0;
	double totalPaidMoney = 0;
	double difference = 0;
	double averageInterestPaid = 0;
	double differenceRate = 0;
	int token = 0;
	//check invalid interest rate
	if(monthlyPayment < roundNumber(totalLoan * CENT_VALUE / month,
		ROUND_OFF) / CENT_VALUE)
		return NEGATIVE;
	//no interest rate
	if(monthlyPayment == roundNumber(totalLoan * CENT_VALUE / month,
		ROUND_OFF) / CENT_VALUE)
		return NO_VALUE;
	//assume 1st interest rate
	totalPaidMoney = monthlyPayment * month;
	difference = totalPaidMoney - totalLoan;
	averageInterestPaid = difference / month;
	interestRate = averageInterestPaid / (totalLoan * HALF);

	// adjust interest rate base on the different between estimated and real
	//payment (20 times adjustment)
	for(token = 0; token <SEVERAL_TIME; token++)
	{
		differenceRate = getPaymentAmount(totalLoan, interestRate, month)
			/ monthlyPayment;
		interestRate /= differenceRate;
	}
	return interestRate;
}

double readAPR()
{
	double APR = 0;
	int checkNonNegative = TRUE;
	do
	{
		if (checkNonNegative == FALSE)
			printf("Please enter a non-negative number!\n");
		printf("Please enter the anual interest rate"
			" (will be rounded to the nearest 1/8 point):");
		scanf("%lf", &APR);
		while (getchar() != '\n');
		//check non-negative
		if (APR < ORIGIN)
			checkNonNegative = FALSE;
		else //everything is ok, round 1/8 and print out
		{
			checkNonNegative = TRUE;
			APR = roundNumber(APR, ROUND_1_OVER_8);
			printf("Anual interest (APR): %.3lf%%\n", APR);
			APR /= PERCENTAGE_IN_DECIMAL; 
		}
	}
	while (checkNonNegative == FALSE);
	return APR;
}

double readTotalLoan()
{
	double totalLoan = 0;
	int checkPositive = TRUE;
	do
	{
		if (checkPositive == FALSE)
			printf("Please enter a positive number!\n");
		printf("Please enter the amount of the loan: $");
		scanf("%lf", &totalLoan);
		while (getchar() != '\n');
		// check positive
		if (totalLoan <= ORIGIN)
			checkPositive = FALSE;
		else //everything is ok, round off and print out
		{
			checkPositive = TRUE;
			totalLoan = roundNumber(totalLoan * CENT_VALUE, ROUND_OFF)
				/ CENT_VALUE;
			printf("Principal: $%.2lf\n", totalLoan);
		}
	}
	while (checkPositive == FALSE);
	return totalLoan;
}

double readMonthlyPayment(double minimumValue)
{
	double monthlyPayment = 0;
	int checkGreaterThanMinimumValue = TRUE;
	int checkPositive = TRUE;
	do
	{
		if (checkPositive == FALSE)
		{
			printf("Please enter a positive number!\n");
			//if the program goes to this situation, prevent it
			//from going to the next situation
			checkGreaterThanMinimumValue = TRUE;
		}
		if (checkGreaterThanMinimumValue == FALSE)
			printf("Monthly payment must be greater than $%.2lf!\n"
			, minimumValue);
		printf("Please enter the amount of the monthly payment: $");
		scanf("%lf", &monthlyPayment);
		while (getchar() != '\n');
		//check positive
		if (monthlyPayment <= ORIGIN)
			checkPositive = FALSE;
		//the value is > 0, if the minimum value exists, compare with it
		else if (minimumValue > NO_VALUE && monthlyPayment <= minimumValue)
		{
			checkGreaterThanMinimumValue = FALSE;
			checkPositive = TRUE;
		}
		else // everthing is ok, round off and print out
		{
			checkPositive = TRUE;
			checkGreaterThanMinimumValue = TRUE;
			monthlyPayment = roundNumber(monthlyPayment * CENT_VALUE
				, ROUND_OFF) / CENT_VALUE;
			printf("Monthly payment: $%.2lf\n", monthlyPayment);
		}
	}
	while (checkPositive == FALSE || checkGreaterThanMinimumValue == FALSE);
	return monthlyPayment;
}

int readNumberOfPayment()
{
	int month = 0;
	int checkPositive = TRUE;
	do
	{
		if (checkPositive == FALSE)
			printf("Please enter a positive number!\n");
		printf("Please enter the number of month you will making payment: ");
		scanf("%d", &month);
		while (getchar() != '\n');
		//check positive
		if (month <= ORIGIN)
			checkPositive = FALSE;
		else //everything is ok, print out
		{
			checkPositive = TRUE;
			printf("Number of months to pay: %d\n", month);
		}
	}
	while (checkPositive == FALSE);
	return month;
}

void printTable(double totalLoan, double monthlyInterestRate, int month)
{
	char token1 = ' ';
	FILE * fileOutput = NULL;
	int token2 = 0;
	int countPay = 1;
	double monthlyPayment = 0;
	double principalPaid = 0;
	double interestPaid = 0;
	double loanBalance = totalLoan;
	printf("Do you wish to print an Amortization Table (Y/y for Yes"
		", other keys for No)?\n");
	token1 = getche();
	if(token1 == 'Y' || token1 == 'y')
	{
		//users agree to print table
		fileOutput = fopen("AmTable.txt", "w");
		if(fileOutput != NULL)
		{
			//print introduction
			fprintf(fileOutput, "Amortization Table for $%.2lf Loan at"
				" %.3lf%% interest for %d month(s)\n\n", totalLoan, 
				roundNumber(monthlyInterestRate * TOTAL_MONTH_IN_1_YEAR
				* PERCENTAGE_IN_DECIMAL, ROUND_1_OVER_8), month);
			fprintf(fileOutput, "Payments         Principal Paid  "
				"Interest Paid   Loan Balance\n");
			//when interest rate is 0
			if(monthlyInterestRate == 0)
			{
				interestPaid = 0;
				principalPaid = monthlyPayment =
					roundNumber(totalLoan * CENT_VALUE / 
					month, ROUND_OFF) / CENT_VALUE;
				for(token2 = month; token2 > ORIGIN; token2--)
				{
					//print normally until the previous
					//before the last
					if(token2 > ORIGIN + INCREASE_BY_ONE)
						loanBalance -= principalPaid;
					//print the last time
					else
					{
						principalPaid = monthlyPayment = loanBalance;
						loanBalance = 0;
					}
					fprintf(fileOutput, "%4d(%9.2lf) $", countPay, 
						monthlyPayment);
					fprintf(fileOutput, "%14.2lf $", principalPaid);
					fprintf(fileOutput, "%14.2lf $", interestPaid);
					fprintf(fileOutput," %14.2lf $\n", loanBalance);
					countPay++;
				}
			}
			//when interest rate is different than zero
			else
				for(token2 = month; token2 > ORIGIN; token2-- )
				{
					interestPaid = roundNumber(monthlyInterestRate *
						loanBalance * CENT_VALUE, ROUND_OFF)
						/CENT_VALUE;
					//print normally until the previous
					//before the last
					if(token2 > ORIGIN + INCREASE_BY_ONE)
					{
						monthlyPayment = getPaymentAmount(loanBalance, 
							monthlyInterestRate, token2);
						principalPaid = monthlyPayment - interestPaid;
						loanBalance -= principalPaid;
					}
					//print the last time
					else
					{
						principalPaid = loanBalance;
						monthlyPayment = principalPaid + interestPaid;
						loanBalance = 0;
					}
					fprintf(fileOutput, "%4d(%9.2lf) $", countPay, 
						monthlyPayment);
					fprintf(fileOutput, "%14.2lf $", principalPaid);
					fprintf(fileOutput, "%14.2lf $", interestPaid);
					fprintf(fileOutput," %14.2lf $\n", loanBalance);
					countPay++;
				}
				fclose(fileOutput);
				system("notepad AmTable.txt");
		}
	}
}
