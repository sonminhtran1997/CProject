#ifndef AMORT_H
#define AMORT_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
//-------------------------------------------------------------------------------
//   Function:    roundNumber()
//   Title:       Round Number
//   Description: Round a value within 3 options (round up, round off, round
//				  to the nearest 1/8 point)
//   Programmer:  An Dien Tang
//   Date:		  11/16/2014
//   Version:     1.0
//   Environment: Laptop Toshiba 
//                MS Windows 8; 
//                Microsoft Visual Studio.Net 2012
//	 Input:		  None
//   Output:      None
//   Calls:       None
//	 Parameter:	  number(double type)
//				  roundingType(double type)
//   Returns:     The rounded value (double type)
//   History Log:
//                11/16/2014 AT complete version 1.0
// ------------------------------------------------------------------------------
double roundNumber(double number, double roundingType);

//-------------------------------------------------------------------------------
//   Function:    getPaymentAmount()
//   Title:       Get Payment Amount
//   Description: Calculate the monthly payment value
//   Programmer:  An Dien Tang
//   Date:		  11/16/2014
//   Version:     1.0
//   Environment: Laptop Toshiba 
//                MS Windows 8; 
//                Microsoft Visual Studio.Net 2012
//	 Input:		  None
//   Output:      None
//   Calls:       roundNumber()
//	 Parameter:	  totalLoan(double type)
//				  monthlyInterestRate(double type)
//				  month (int type)
//   Returns:     The calculated monthly payment value (double type)
//   History Log:
//                11/16/2014 AT complete version 1.0
// ------------------------------------------------------------------------------
double getPaymentAmount(double totalLoan, double monthlyInterestRate, int month);

//-------------------------------------------------------------------------------
//   Function:    getLoanAmount()
//   Title:       Get Loan Amount
//   Description: Calculate the loan value
//   Programmer:  An Dien Tang
//   Date:		  11/16/2014
//   Version:     1.0
//   Environment: Laptop Toshiba 
//                MS Windows 8; 
//                Microsoft Visual Studio.Net 2012
//	 Input:		  None
//   Output:      None
//   Calls:       roundNumber()
//	 Parameter:	  monthlyPayment(double type)
//				  monthlyInterestRate(double type)
//				  month (int type)
//   Returns:     The calculated loan value (double type)
//   History Log:
//                11/16/2014 AT complete version 1.0
// ------------------------------------------------------------------------------
double getLoanAmount(double monthlyPayment, double monthlyInterestRate, int month);

//-------------------------------------------------------------------------------
//   Function:    getNumberOfMonths()
//   Title:       Get Number of Months
//   Description: Calculate the month value
//   Programmer:  An Dien Tang
//   Date:		  11/16/2014
//   Version:     1.0
//   Environment: Laptop Toshiba 
//                MS Windows 8; 
//                Microsoft Visual Studio.Net 2012
//	 Input:		  None
//   Output:      None
//   Calls:       roundNumber()
//	 Parameter:	  totalLoan(double type)
//				  monthlyPayment(double type)
//				  monthlyInterestRate(double type)
//   Returns:     The calculated month value (int type)
//   History Log:
//                11/16/2014 AT complete version 1.0
// ------------------------------------------------------------------------------
int getNumberOfMonths(double totalLoan, double monthlyPayment, 
					  double monthlyInterestRate);

//-------------------------------------------------------------------------------
//   Function:    getInterestRate()
//   Title:       Get Interest Rate
//   Description: Calculate the interest rate value
//   Programmer:  An Dien Tang
//   Date:		  11/16/2014
//   Version:     1.0
//   Environment: Laptop Toshiba 
//                MS Windows 8; 
//                Microsoft Visual Studio.Net 2012
//	 Input:		  None
//   Output:      None
//   Calls:       roundNumber()
//				  getPaymentAmount()
//	 Parameter:	  totalLoan(double type)
//				  monthlyPayment(double type)
//				  month(int type)
//   Returns:     The calculated interest rate value (double type)
//   History Log:
//                11/16/2014 AT complete version 1.0
// ------------------------------------------------------------------------------
double getInterestRate(double totalLoan, double monthlyPayment, int month);

//-------------------------------------------------------------------------------
//   Function:    readAPR()
//   Title:       Read APR
//   Description: Safely read APR
//   Programmer:  An Dien Tang
//   Date:		  11/16/2014
//   Version:     1.0
//   Environment: Laptop Toshiba 
//                MS Windows 8; 
//                Microsoft Visual Studio.Net 2012
//	 Input:		  1 value from the users
//   Output:      Direction for the users to input safely
//   Calls:       roundNumber()
//	 Parameter:	  none
//   Returns:     The safely read interest rate value (double type)
//   History Log:
//                11/16/2014 AT complete version 1.0
// ------------------------------------------------------------------------------
double readAPR();

//-------------------------------------------------------------------------------
//   Function:    readTotalLoan()
//   Title:       Read Loan
//   Description: Safely read Loan
//   Programmer:  An Dien Tang
//   Date:		  11/16/2014
//   Version:     1.0
//   Environment: Laptop Toshiba 
//                MS Windows 8; 
//                Microsoft Visual Studio.Net 2012
//	 Input:		  1 value from the users
//   Output:      Direction for the users to input safely
//   Calls:       roundNumber()
//	 Parameter:	  none
//   Returns:     The safely read loan value (double type)
//   History Log:
//                11/16/2014 AT complete version 1.0
// ------------------------------------------------------------------------------
double readTotalLoan();

//-------------------------------------------------------------------------------
//   Function:    readMonthlyPayment()
//   Title:       Read Monthly Payment
//   Description: Safely read monthly payment
//   Programmer:  An Dien Tang
//   Date:		  11/16/2014
//   Version:     1.0
//   Environment: Laptop Toshiba 
//                MS Windows 8; 
//                Microsoft Visual Studio.Net 2012
//	 Input:		  1 value from the users
//   Output:      Direction for the users to input safely
//   Calls:       roundNumber()
//	 Parameter:	  minimumValue(double type)
//   Returns:     The safely read monthly payment value (double type)
//   History Log:
//                11/16/2014 AT complete version 1.0
// ------------------------------------------------------------------------------
double readMonthlyPayment(double minimumValue);

//-------------------------------------------------------------------------------
//   Function:    readNumberOfPayment()
//   Title:       Read Month
//   Description: Safely read month
//   Programmer:  An Dien Tang
//   Date:		  11/16/2014
//   Version:     1.0
//   Environment: Laptop Toshiba 
//                MS Windows 8; 
//                Microsoft Visual Studio.Net 2012
//	 Input:		  1 value from the users
//   Output:      Direction for the users to input safely
//   Calls:       none
//	 Parameter:	  minimumValue(double type)
//   Returns:     The safely read month value (int type)
//   History Log:
//                11/16/2014 AT complete version 1.0
// ------------------------------------------------------------------------------
int readNumberOfPayment();

//-------------------------------------------------------------------------------
//   Function:    printTable()
//   Title:       Print Amortization Table
//   Description: Print out Amortization Table as txt file (if desirable)
//   Programmer:  An Dien Tang
//   Date:		  11/16/2014
//   Version:     1.0
//   Environment: Laptop Toshiba 
//                MS Windows 8; 
//                Microsoft Visual Studio.Net 2012
//	 Input:		  1 character from the users (for agreeing to print table or not)
//   Output:      File txt (if desirable)
//   Calls:       getPaymentAmount()
//				  roundNumber()
//	 Parameter:	  totalLoan(double type)
//				  monthlyInterestRate(double type)
//				  month (int type)
//   Returns:     none
//   History Log:
//                11/16/2014 AT complete version 1.0
// ------------------------------------------------------------------------------
void printTable(double totalLoan, double monthlyInterestRate, int month);

#endif
