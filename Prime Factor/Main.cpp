#include <iostream>
#include <sstream>
using namespace std;

string primeFactor(long number);
const int BUFFER_SIZE = 256;
const long NOTHING = 0;
const long EVEN = 2;
//---------------------------------------------------------------------
//   Function:    main()
//   Title:       Main
//   Description: Main function for prime factorization
//   Programmer:  An Dien Tang
//   Date:        2/15/2015
//   Version:     1.00
//   Environment: Laptop Toshiba 
//                Software:   MS Windows 8 for execution; 
//                Compiles under Microsoft Visual Studio.Net 2012
//   Parameter:   void
//   Input:       a number greater than 1
//   Output:	  the result of being prime or not
//   Calls:       primeFactor()
//	 Called by:   None
//   Return:      EXIT_SUCCESS
//   History Log:
//                2/15/2011  AT completed version 1.0
// --------------------------------------------------------------------
int main()
{
	long number = 0;
	char repeat = 'Y';
	cout << "Prime Factorization by An Dien Tang \n" << endl;
	while (repeat == 'Y')
	{
		cout << "Enter a Whole Number greater than 1: ";
		cin >> number;
		cin.clear();
		while(cin.get() != '\n');
		if(number < 2)
		{
			cout << "Invalid Entry." << endl;
			continue;
		}
		cout << number << " = ";
		cout << primeFactor(number) << endl;
		cout << "Continue? (Y/y for yes, others for no): ";
		cin >> repeat;
		cin.clear();
		while(cin.get() != '\n');
		repeat = toupper(repeat);
		number = 0;
	}
	return EXIT_SUCCESS;
}

//---------------------------------------------------------------------
//   Function:    primeFactor()
//   Title:       Prime Factorization
//   Description: find possible factor of a number
//   Programmer:  An Dien Tang
//   Date:        2/15/2015
//   Version:     1.00
//   Environment: Laptop Toshiba 
//                Software:   MS Windows 8 for execution; 
//                Compiles under Microsoft Visual Studio.Net 2012
//   Parameter:   long number: a number for factorization
//   Input:       none
//   Output:	  none
//   Calls:       primeFactor()
//	 Called by:   primeFactor()
//				  main()
//   Return:      string contain possible factors
//   History Log:
//                2/15/2011  AT completed version 1.0
// --------------------------------------------------------------------
string primeFactor(long number)
{
	static long countDivision = 0;
	static long constanceNum = static_cast<long>(sqrt(number));
	static long div = 2;
	ostringstream out;
	if (constanceNum == 0)
		constanceNum = number;
	if (div <= constanceNum)
	{
		if(number % div == 0)
		{
			number /= div;
			out << "<" << div << ">";
			countDivision++;
			return out.str() + primeFactor(number);
		}
		else
		{
			do
			{
				if (div == EVEN)
					div++;
				else 
					div += EVEN; 
			}
			while(sqrt(div) - static_cast<long>(sqrt(div)) == 0.0);
			return primeFactor(number);
		}
	}
	if (number != 1)
		out << "<" << number << ">";
	if (countDivision == NOTHING)
		out << " : PRIME!";
	countDivision = 0;
	div = 2;
	constanceNum = 0;
	return out.str();
}
