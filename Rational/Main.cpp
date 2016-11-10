#include <iostream>
#include <sstream>
#include "Rational_Number.h"

using namespace std;
using namespace AT_Rational;
//-----------------------------------------------------------------------------
//	Function:	main()
//	Title:		Using Fraction
//	Description:	This file contains function main()
//						which tests Fraction
//	WARNING:	THIS CODE, BY ITSELF, DOES NOT CONSTITUTE A SUFFICIENT
//						TESTING OF THE CRational CLASS 
//	Programmer:	An Dien Tang
//	Date:		2/27/15
//	Version:	1.0
//	Environment:	PC 
//				Software:   MS Windows 8
//				Compiles under Microsoft Visual C++.Net 2012
//	Input:		2 fractions from the consolde
//	Output:		Screen displays some algorithm of 2 fractions
//	Calls:		CRational class and related functions
//	Called By:	n/a
//	Parameters:	None
//	Returns:	EXIT_SUCCESS  = successful 
//	History Log:
//			2/27/15  AT  completed version 1.0
//-----------------------------------------------------------------------------
int main()
{
	try
	{
		CRational a;
		CRational b(2l);
		CRational c(-3);
		CRational d(9l, -6l);
		CRational e(-5l, 2l);
		CRational f(2.97854511);
		cout << "CRational a, b(2l), c(-3), d(9l, -6l), e(-5l, 2l),"
			"f(2.97854511)\n" << endl;
		cout << "a:  " << a << " b:  " << b << " c:  " << c;
		cout << " d:  " << d << " e:  " << e << " f:  " << f << endl 
			<< endl;
		cout << "e before: " << e << ", \"cout << ++e\" : ";
		cout << ++e << " e after: " << e << endl;
		cout << "d before: " << d << ", \"cout << ++d\" : ";
		cout << ++d << " d after: " << d << endl;
		cout << "e before: " << e << ", \"cout << e++\" : ";
		cout << e++ << " e after: " << e << endl;
		cout << "d before: " << d << ", \"cout << d++\" : ";
		cout << d++ << " d after: " << d << endl << endl;
		cout << "e before: " << e << ", \"cout << --e\" : ";
		cout << --e << " e after: " << e << endl;
		cout << "d before: " << d << ", \"cout << --d\" : ";
		cout << --d << " d after: " << d << endl;
		cout << "e before: " << e << ", \"cout << e--\" : ";
		cout << e-- << " e after: " << e << endl;
		cout << "d before: " << d << ", \"cout << d--\" : ";
		cout << d-- << " d after: " << d << endl << endl;
		cout << "input a number for a: ";
		cin >> a;
		cout << "a:  " << a << " -a:  " << -a << " +a:  " << +a
			<< endl;
		cout << "input a number for b: ";
		cin >> b;
		cout << "b:  " << b << " -b:  " << -b << " +b:  " << +b
			<< endl << endl;	
		cout << "a (" << a << ") as a bool is ";
		if(a)
			cout << "true" << endl;
		else
			cout << "false" << endl;
		cout << "!a !(" << a << ") is ";
		if(!a)
			cout << "true" << endl;
		else
			cout << "false" << endl;	
		cout << endl;
		cout << a << " <  " << b << " ?\t";
		if( a < b)
			cout << "true" << endl;
		else
			cout << "false" << endl;
		cout << a << " >  " << b << " ?\t";
		if( a > b)
			cout << "true" << endl;
		else
			cout << "false" << endl;
		cout << a << " <= " << b << " ?\t";
		if( a <= b)
			cout << "true" << endl;
		else
			cout << "false" << endl;
		cout << a << " >= " << b << " ?\t";
		if( a >= b)
			cout << "true" << endl;
		else
			cout << "false" << endl;
		cout << a << " == " << b << " ?\t";
		if( a == b)
			cout << "true" << endl;
		else
			cout << "false" << endl;

		cout << a << " != " << b << " ?\t";
		if( a != b)
			cout << "true" << endl;
		else
			cout << "false" << endl;
		cout << endl;
		cout << "~a:  " << ~a  << endl << endl;
		cout << "a + b = (" << a << ") + (" << b << ") = "
			<< (a + b) << endl;
		cout << "a += b = (" << a << ") += (" << b;
		a += b;
		cout << "); a = " << a << endl;
		cout << "a -= b = (" << a << ") -= (" << b;
		a -= b;
		cout << "); a = " << a << endl;
		cout << "a - b = (" << a << ") - (" << b << ") = "
			<< (a - b) << endl;	 
		cout << "a * b = (" << a << ") * (" << b << ") = "
			<< (a * b) << endl;
		cout << "a *= b = (" << a << ") += (" << b;
		a *= b;
		cout << "); a = " << a << endl;

		cout << "a /= b = (" << a << ") /= (" << b;
		a /= b;
		cout << "); a = " << a << endl;
		cout << "a / b = (" << a << ") / (" << b << ") = " << (a / b)
			<< endl;	
	}
	catch(exception e)
	{
		cerr << endl <<  "exception: " << e.what() << endl;
		cout << endl << "Press \"Enter\" to continue..." << endl;
		cin.get();
		return EXIT_FAILURE;
	}
	cout << endl << "Press \"Enter\" to continue..." << endl;
	cin.get();
	return EXIT_SUCCESS;
}

