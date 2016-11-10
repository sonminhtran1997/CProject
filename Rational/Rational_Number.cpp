//-----------------------------------------------------------------------------
//	File:		CRational.cpp
//
//	Functions:	
//			CRational::CRational(int number)
//			CRational::CRational(double number)
//			void CRational::printCR(ostream & sout)
//			CRational CRational::invert()
//			CRational CRational::toThePower(int number)
//			long CRational::compareTo(const CRational first, 
//						  const CRational second)
//			CRational CRational::operator*(const CRational number)const
//			CRational CRational::operator/(const CRational number)const
//			CRational CRational::operator+(const CRational number)const
//			CRational CRational::operator+()
//			CRational CRational::operator-(const CRational number)const
//			CRational CRational::operator-()
//			CRational CRational::operator*=(const CRational number)
//			CRational CRational::operator/=(const CRational number)
//			CRational CRational::operator+=(const CRational number)
//			CRational CRational::operator-=(const CRational number)
//			CRational CRational::operator++()
//			CRational CRational::operator++(int)
//			CRational CRational::operator--()
//			CRational CRational::operator--(int)
//			bool CRational::operator==(const CRational number)const
//			bool CRational::operator!=(const CRational number)const
//			bool CRational::operator<(const CRational number)const
//			bool CRational::operator<=(const CRational number)const
//			bool CRational::operator>(const CRational number)const
//			bool CRational::operator>=(const CRational number)const
//			bool CRational::operator!()
//			CRational CRational::operator~()
//			CRational::operator bool() const
//			CRational::operator double() const
//			CRational::operator string() const
//			long CRational::GCF(long bigger, long smaller)
//			void CRational::setProperForm()
//			long CRational::LCD(const CRational first, const CRational second)
//			ostream& AT_Rational::operator<<(ostream& sout, const CRational& number)
//			istream& AT_Rational::operator>>(istream& sin, CRational& number)			
//-----------------------------------------------------------------------------
#include "Rational_Number.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
namespace AT_Rational
{
//-----------------------------------------------------------------------------
//	Class:          CRational
//	Title:          Rational Number Class
//	Description:    Definitions for CRational methods and related functions
//	Programmer:     An Dien Tang
//	Date:           2/27/2015
//	Version:        1.0
//	Environment:	PC 
//				Software:   MS Windows 7
//				Compiles under Microsoft Visual C++.Net 2012
//	class: CRational
//	Properties:
//			long m_numerator; -- the numerator of the fraction
//  		long m_denominator;  -- the denominator of the fraction
//	History Log:
//                	2/27/2015  AT completed version 1.0
//-----------------------------------------------------------------------------
const int DECIMAL = 10;
const int NOTHING = 0;
const int ASCIIZERO = 48;
const int STARTINGVALUE = 1;
const int ONE = 1;
const int LONGDIGIT = 9;

//-----------------------------------------------------------------------------
//	Class:         CComplex
//	Method:        CRational(int number)
//	Description:   Constructor for integer
//	Input:         None
//	Output:        None
//	Calls:         None
//	Called By:     Other methods
//	Parameters:    int number -- the integer used for create a fraction
//	Returns:       None 
//	History Log:
//	               2/28/15  AT  completed version 1.0
//-----------------------------------------------------------------------------
CRational::CRational(int number)
{
	m_numerator = number;
	m_denominator = STARTINGVALUE;
}

//-----------------------------------------------------------------------------
//	Class:         CComplex
//	Method:        CRational(double number)
//	Description:   Constructor for float
//	Input:         None
//	Output:        None
//	Calls:         Contructor
//	Called By:     Other methods
//	Parameters:    double number -- the float used for create a fraction
//	Returns:       None 
//	History Log:
//	               2/28/15  AT  completed version 1.0
//-----------------------------------------------------------------------------
CRational::CRational(double number)
{
	double tempNum = number;
	long tempDen = 1;
	long token = static_cast<long>(number);
	int countLongDigit = 1;
	while(token /= DECIMAL)
		++countLongDigit;
	for (int i = 1 ; i <= LONGDIGIT - countLongDigit; i++)
		tempDen *= DECIMAL;
	tempNum *= tempDen;
	CRational temp(static_cast<long>(tempNum), tempDen);
	*this = temp;
}

//-----------------------------------------------------------------------------
//	Class:         CComplex
//	Method:        void printCR(ostream & sout)
//	Description:   Print fraction to screen
//	Input:         None
//	Output:        A fraction in form of p/q
//	Calls:         None
//	Called By:     operator<<()
//	Parameters:    ostream & sout -- the stream used for output
//	Returns:       None 
//	History Log:
//	               2/28/15  AT  completed version 1.0
//-----------------------------------------------------------------------------
void CRational::printCR(ostream & sout)
{
	sout << m_numerator;
	if(m_denominator != 1)
		sout << "/" << m_denominator;
}

//-----------------------------------------------------------------------------
//	Class:         CComplex
//	Method:        CRational invert()
//	Description:   Inverse a fraction
//	Input:         None
//	Output:        None
//	Calls:         setProperForm()
//	Called By:     None
//	Parameters:    None
//	Returns:       A fraction itself 
//	History Log:
//	               2/28/15  AT  completed version 1.0
//-----------------------------------------------------------------------------
CRational CRational::invert()
{
	long temp = m_denominator;
	m_denominator = m_numerator;
	m_numerator = temp;
	setProperForm();
	return *this;
}

//-----------------------------------------------------------------------------
//	Class:         CComplex
//	Method:        CRational toThePower(int number)
//	Description:   Power a fraction
//	Input:         None
//	Output:        None
//	Calls:         Constructor
//	Called By:     None
//	Parameters:    int number -- a power number
//	Returns:       A powered fraction 
//	History Log:
//	               2/28/15  AT  completed version 1.0
//-----------------------------------------------------------------------------
CRational CRational::toThePower(int number)
{
	long numVal = m_numerator;
	long denVal = m_denominator;
	if (number == NOTHING)
	{
		if (m_numerator == NOTHING)
			throw exception("Zero to the zero power");
		numVal = 1;
		denVal = 1;
	}
	else
	{
		for (int i = 2; i <= abs(number); i++)
		{
			numVal *= m_numerator;
			denVal *= m_denominator;
		}
		if (number < 0)
		{
			long temp = numVal;
			numVal = denVal;
			denVal = temp;
		}
	}
	CRational temp(numVal, denVal);
	return temp;
}

//-----------------------------------------------------------------------------
//	Class:         CComplex
//	Method:        long compareTo(const CRational first, 
//						  const CRational second)
//	Description:   Compare two fractions
//	Input:         None
//	Output:        None
//	Calls:         LCD
//	Called By:     None
//	Parameters:    const CRational first -- first fraction
//	  			   const CRational second -- second fraction
//	Returns:       A result from comparing 2 fractions
//	History Log:
//	               2/28/15  AT  completed version 1.0
//-----------------------------------------------------------------------------
long CRational::compareTo(const CRational first, 
						  const CRational second)
{
	long leastCD = LCD(first, second);
	long convertFirstNum = leastCD / first.getDen() * first.getNum();
	long convertSecondNum = leastCD / second.getDen() * second.getNum();

	if (convertFirstNum < convertSecondNum)
		return -1;
	if (convertFirstNum > convertSecondNum)
		return 1;
	return 0;
}

//-----------------------------------------------------------------------------
//	Class:         CComplex
//	Method:        CRational operator*(const CRational number)const
//	Description:   Multiplication
//	Input:         None
//	Output:        None
//	Calls:         Constructor
//	Called By:     CRational operator*=(const CRational number)
//	Parameters:    const CRational number -- another fraction 
//					for multiplication
//	Returns:       A multiplication between 2 fractions
//	History Log:
//	               2/28/15  AT  completed version 1.0
//-----------------------------------------------------------------------------
CRational CRational::operator*(const CRational number)const
{
	CRational temp(m_numerator * number.getNum(), 
		m_denominator * number.getDen());
	return temp;
}

//-----------------------------------------------------------------------------
//	Class:         CComplex
//	Method:        CRational operator/(const CRational number)const
//	Description:   Division
//	Input:         None
//	Output:        None
//	Calls:         Constructor
//	Called By:     CRational operator/=(const CRational number)
//	Parameters:    const CRational number -- another fraction 
//					for division
//	Returns:       A division between 2 fractions
//	History Log:
//	               2/28/15  AT  completed version 1.0
//-----------------------------------------------------------------------------
CRational CRational::operator/(const CRational number)const
{
	CRational temp(m_numerator * number.getDen(), 
		m_denominator * number.getNum());
	return temp;
}

//-----------------------------------------------------------------------------
//	Class:         CComplex
//	Method:        CRational operator+(const CRational number)const
//	Description:   Addition
//	Input:         None
//	Output:        None
//	Calls:         Constructor
//				   LCD
//	Called By:     CRational operator+=(const CRational number)
//	Parameters:    const CRational number -- another fraction 
//					for addition
//	Returns:       An addition between 2 fractions
//	History Log:
//	               2/28/15  AT  completed version 1.0
//-----------------------------------------------------------------------------
CRational CRational::operator+(const CRational number)const
{
	long leastCD = LCD(*this, number);
	long convertFirstNum = leastCD / this->getDen() * this->getNum();
	long convertSecondNum = leastCD / number.getDen() * number.getNum();
	CRational temp(convertFirstNum + convertSecondNum, leastCD);
	return temp;
}

//-----------------------------------------------------------------------------
//	Class:         CComplex
//	Method:        CRational operator+()
//	Description:   Positive fraction
//	Input:         None
//	Output:        None
//	Calls:         Constructor
//	Called By:     None
//	Parameters:    None
//	Returns:       A positive version of the fraction
//	History Log:
//	               2/28/15  AT  completed version 1.0
//-----------------------------------------------------------------------------
CRational CRational::operator+()
{
	CRational temp(m_numerator, m_denominator);
	return temp;
}

//-----------------------------------------------------------------------------
//	Class:         CComplex
//	Method:        CRational operator-(const CRational number)const
//	Description:   Subtraction
//	Input:         None
//	Output:        None
//	Calls:         Constructor
//				   LCD
//	Called By:     CRational operator-=(const CRational number)
//	Parameters:    const CRational number -- another fraction 
//					for Subtraction
//	Returns:       A subtraction between 2 fractions
//	History Log:
//	               2/28/15  AT  completed version 1.0
//-----------------------------------------------------------------------------
CRational CRational::operator-(const CRational number)const
{
	long leastCD = LCD(*this, number);
	long convertFirstNum = leastCD / this->getDen() * this->getNum();
	long convertSecondNum = leastCD / number.getDen() * number.getNum();
	CRational temp(convertFirstNum - convertSecondNum, leastCD);
	return temp;
}

//-----------------------------------------------------------------------------
//	Class:         CComplex
//	Method:        CRational operator-()
//	Description:   Negative fraction
//	Input:         None
//	Output:        None
//	Calls:         Constructor
//	Called By:     None
//	Parameters:    None
//	Returns:       A negative version of the fraction
//	History Log:
//	               2/28/15  AT  completed version 1.0
//-----------------------------------------------------------------------------
CRational CRational::operator-()
{
	CRational temp(-m_numerator, m_denominator);
	return temp;
}

//-----------------------------------------------------------------------------
//	Class:         CComplex
//	Method:        CRational operator*=(const CRational number)const
//	Description:   Multiplication
//	Input:         None
//	Output:        None
//	Calls:         CRational operator*(const CRational number)const
//	Called By:     None
//	Parameters:    const CRational number -- another fraction 
//					for multiplication
//	Returns:       A multiplication between 2 fractions
//	History Log:
//	               2/28/15  AT  completed version 1.0
//-----------------------------------------------------------------------------
CRational CRational::operator*=(const CRational number)
{
	return *this = *this * number;
}

//-----------------------------------------------------------------------------
//	Class:         CComplex
//	Method:        CRational operator/=(const CRational number)const
//	Description:   Division
//	Input:         None
//	Output:        None
//	Calls:         CRational operator/(const CRational number)const
//	Called By:     None
//	Parameters:    const CRational number -- another fraction 
//					for division
//	Returns:       A division between 2 fractions
//	History Log:
//	               2/28/15  AT  completed version 1.0
//-----------------------------------------------------------------------------
CRational CRational::operator/=(const CRational number)
{
	return *this = *this / number;
}

//-----------------------------------------------------------------------------
//	Class:         CComplex
//	Method:        CRational operator+=(const CRational number)const
//	Description:   Addition
//	Input:         None
//	Output:        None
//	Calls:         CRational operator+(const CRational number)const
//	Called By:     None
//	Parameters:    const CRational number -- another fraction 
//					for addition
//	Returns:       A addition between 2 fractions
//	History Log:
//	               2/28/15  AT  completed version 1.0
//-----------------------------------------------------------------------------
CRational CRational::operator+=(const CRational number)
{
	return *this = *this + number;
}

//-----------------------------------------------------------------------------
//	Class:         CComplex
//	Method:        CRational operator-=(const CRational number)const
//	Description:   Subtraction
//	Input:         None
//	Output:        None
//	Calls:         CRational operator-(const CRational number)const
//	Called By:     None
//	Parameters:    const CRational number -- another fraction 
//					for subtraction
//	Returns:       A subtraction between 2 fractions
//	History Log:
//	               2/28/15  AT  completed version 1.0
//-----------------------------------------------------------------------------
CRational CRational::operator-=(const CRational number)
{
	return *this = *this - number;
}

//-----------------------------------------------------------------------------
//	Class:         CComplex
//	Method:        CRational operator++()
//	Description:   Pre-increment
//	Input:         None
//	Output:        None
//	Calls:         None
//	Called By:     None
//	Parameters:    None
//	Returns:       An increased by 1 fraction
//	History Log:
//	               2/28/15  AT  completed version 1.0
//-----------------------------------------------------------------------------
CRational CRational::operator++()
{
	return *this += ONE;
}

//-----------------------------------------------------------------------------
//	Class:         CComplex
//	Method:        CRational operator++(int)
//	Description:   Post-increment
//	Input:         None
//	Output:        None
//	Calls:         None
//	Called By:     None
//	Parameters:    int -- to distinct with the other increment
//	Returns:       A fraction before increasing by 1
//	History Log:
//	               2/28/15  AT  completed version 1.0
//-----------------------------------------------------------------------------
CRational CRational::operator++(int)
{
	CRational temp = *this;
	*this += ONE;
	return temp;
}

//-----------------------------------------------------------------------------
//	Class:         CComplex
//	Method:        CRational operator--()
//	Description:   Post-increment
//	Input:         None
//	Output:        None
//	Calls:         None
//	Called By:     None
//	Parameters:    None
//	Returns:       A decreased by 1 fraction
//	History Log:
//	               2/28/15  AT  completed version 1.0
//-----------------------------------------------------------------------------
CRational CRational::operator--()
{
	return *this -= ONE;
}

//-----------------------------------------------------------------------------
//	Class:         CComplex
//	Method:        CRational operator--(int)
//	Description:   Post-increment
//	Input:         None
//	Output:        None
//	Calls:         None
//	Called By:     None
//	Parameters:    int -- to distinct with the other decrement
//	Returns:       A fraction before decreasing by 1
//	History Log:
//	               2/28/15  AT  completed version 1.0
//-----------------------------------------------------------------------------
CRational CRational::operator--(int)
{
	CRational temp = *this;
	*this -= ONE;
	return temp;
}

//-----------------------------------------------------------------------------
//	Class:         CComplex
//	Method:        bool operator==(const CRational number)const
//	Description:   Compare equally
//	Input:         None
//	Output:        None
//	Calls:         compareTo()
//	Called By:     None
//	Parameters:    const CRational number -- a number used to compare
//	Returns:       Result between the parameter and *this fraction
//	History Log:
//	               2/28/15  AT  completed version 1.0
//-----------------------------------------------------------------------------
bool CRational::operator==(const CRational number)const
{
	long difference = compareTo(*this, number);
	if (difference == 0)
		return true;
	return false;
}

//-----------------------------------------------------------------------------
//	Class:         CComplex
//	Method:        bool operator!=(const CRational number)const
//	Description:   Compare differently
//	Input:         None
//	Output:        None
//	Calls:         compareTo()
//	Called By:     None
//	Parameters:    const CRational number -- a number used to compare
//	Returns:       Result between the parameter and *this fraction
//	History Log:
//	               2/28/15  AT  completed version 1.0
//-----------------------------------------------------------------------------
bool CRational::operator!=(const CRational number)const
{
	long difference = compareTo(*this, number);
	if (difference == 0)
		return false;
	return true;
}

//-----------------------------------------------------------------------------
//	Class:         CComplex
//	Method:        bool operator<(const CRational number)const
//	Description:   Compare smaller than
//	Input:         None
//	Output:        None
//	Calls:         compareTo()
//	Called By:     None
//	Parameters:    const CRational number -- a number used to compare
//	Returns:       Result between the parameter and *this fraction
//	History Log:
//	               2/28/15  AT  completed version 1.0
//-----------------------------------------------------------------------------
bool CRational::operator<(const CRational number)const
{
	long difference = compareTo(*this, number);
	if (difference < 0)
		return true;
	return false;
}

//-----------------------------------------------------------------------------
//	Class:         CComplex
//	Method:        bool operator<=(const CRational number)const
//	Description:   Compare smaller than or equal to
//	Input:         None
//	Output:        None
//	Calls:         compareTo()
//	Called By:     None
//	Parameters:    const CRational number -- a number used to compare
//	Returns:       Result between the parameter and *this fraction
//	History Log:
//	               2/28/15  AT  completed version 1.0
//-----------------------------------------------------------------------------
bool CRational::operator<=(const CRational number)const
{
	long difference = compareTo(*this, number);
	if (difference <= 0)
		return true;
	return false;
}

//-----------------------------------------------------------------------------
//	Class:         CComplex
//	Method:        bool operator>(const CRational number)const
//	Description:   Compare greater than
//	Input:         None
//	Output:        None
//	Calls:         compareTo()
//	Called By:     None
//	Parameters:    const CRational number -- a number used to compare
//	Returns:       Result between the parameter and *this fraction
//	History Log:
//	               2/28/15  AT  completed version 1.0
//-----------------------------------------------------------------------------
bool CRational::operator>(const CRational number)const
{
	long difference = compareTo(*this, number);
	if (difference >= 0)
		return true;
	return false;
}

//-----------------------------------------------------------------------------
//	Class:         CComplex
//	Method:        bool operator>=(const CRational number)const
//	Description:   Compare greater than or equal to
//	Input:         None
//	Output:        None
//	Calls:         compareTo()
//	Called By:     None
//	Parameters:    const CRational number -- a number used to compare
//	Returns:       Result between the parameter and *this fraction
//	History Log:
//	               2/28/15  AT  completed version 1.0
//-----------------------------------------------------------------------------
bool CRational::operator>=(const CRational number)const
{
	long difference = compareTo(*this, number);
	if (difference >= 0)
		return true;
	return false;
}

//-----------------------------------------------------------------------------
//	Class:         CComplex
//	Method:        bool operator!()
//	Description:   Check numerator different than 0
//	Input:         None
//	Output:        None
//	Calls:         getNum()
//	Called By:     None
//	Parameters:    None
//	Returns:       Result from the numerator
//	History Log:
//	               2/28/15  AT  completed version 1.0
//-----------------------------------------------------------------------------
bool CRational::operator!()
{
	if (m_numerator == 0)
		return true;
	return false;
}

//-----------------------------------------------------------------------------
//	Class:         CComplex
//	Method:        CRational operator~()
//	Description:   Create an inverse fraction
//	Input:         None
//	Output:        None
//	Calls:         Constructor
//	Called By:     None
//	Parameters:    None
//	Returns:       An inversed fraction
//	History Log:
//	               2/28/15  AT  completed version 1.0
//-----------------------------------------------------------------------------
CRational CRational::operator~()
{
	CRational temp(this->getDen(), this->getNum());
	return temp;
}

//-----------------------------------------------------------------------------
//	Class:         CComplex
//	Method:        operator bool() const
//	Description:   Converse fraction to bool
//	Input:         None
//	Output:        None
//	Calls:         None
//	Called By:     None
//	Parameters:    None
//	Returns:       A result from converting
//	History Log:
//	               2/28/15  AT  completed version 1.0
//-----------------------------------------------------------------------------
CRational::operator bool() const
{
	if (this->getNum() != 0)
		return true;
	return false;
}

//-----------------------------------------------------------------------------
//	Class:         CComplex
//	Method:        operator double() const
//	Description:   Converse fraction to double
//	Input:         None
//	Output:        None
//	Calls:         None
//	Called By:     None
//	Parameters:    None
//	Returns:       A result from converting
//	History Log:
//	               2/28/15  AT  completed version 1.0
//-----------------------------------------------------------------------------
CRational::operator double() const
{
	return (static_cast<double>(this->getNum())/this->getDen());
}

//-----------------------------------------------------------------------------
//	Class:         CComplex
//	Method:        operator string() const
//	Description:   Converse fraction to string
//	Input:         None
//	Output:        None
//	Calls:         None
//	Called By:     None
//	Parameters:    None
//	Returns:       A result from converting
//	History Log:
//	               2/28/15  AT  completed version 1.0
//-----------------------------------------------------------------------------
CRational::operator string() const
{
	ostringstream temp;
	temp << *this;
	return temp.str();
}

//-----------------------------------------------------------------------------
//	Class:         CComplex
//	Method:        long GCF(long bigger, long smaller)
//	Description:   Finding greatest common factor
//	Input:         None
//	Output:        None
//	Calls:         None
//	Called By:     LCD()
//				   setProperform()
//	Parameters:    long bigger -- the first number to calculate
//				   long smaller -- the second number to calculate
//	Returns:       The greatest common factor
//	History Log:
//	               2/28/15  AT  completed version 1.0
//-----------------------------------------------------------------------------
long CRational::GCF(long bigger, long smaller)
{
	if (bigger == 0 || smaller == 0)
		return 0;
	bigger = abs(bigger);
	smaller = abs(smaller);
	long temp = smaller;
	if (smaller > bigger)
	{
		temp = smaller;
		smaller = bigger;
		bigger = temp;
	}

	while (bigger % smaller != 0)
	{
		temp = smaller;
		smaller = bigger % smaller;
		bigger = temp;
	}
	return smaller;
}

//-----------------------------------------------------------------------------
//	Class:         CComplex
//	Method:        void setProperForm()
//	Description:   Set the fraction to it proper form
//	Input:         None
//	Output:        None
//	Calls:         None
//	Called By:     Constructor
//	Parameters:    None
//	Returns:       None
//	History Log:
//	               2/28/15  AT  completed version 1.0
//-----------------------------------------------------------------------------
void CRational::setProperForm()
{
	if(m_denominator == 0)
	{
		m_denominator = 1;
		m_numerator = 0;
		throw exception ("Divide by Zero. \n");
	}
	if(m_denominator < 0)
	{
		m_numerator *= -STARTINGVALUE;
		m_denominator *= -STARTINGVALUE;
	}
	if (m_numerator == 0)
		m_denominator = 1;
	long commonFactor = GCF(m_denominator, m_numerator);
	if (commonFactor != 0)
	{
		m_numerator /= commonFactor;
		m_denominator /= commonFactor;
	}
}

//-----------------------------------------------------------------------------
//	Class:         CComplex
//	Method:        long LCD(const CRational first, const CRational second)
//	Description:   Finding least common denominator
//	Input:         None
//	Output:        None
//	Calls:         GFC()
//	Called By:     None
//	Parameters:    const CRational first--the first fraction to calculate
//				   const CRational second--the second fraction to
//					calculate
//	Returns:       The Least common denominator
//	History Log:
//	               2/28/15  AT  completed version 1.0
//-----------------------------------------------------------------------------
long CRational::LCD(const CRational first, const CRational second)
{
	long greatestCF = GCF(first.getDen(), second.getDen());
	return (first.getDen()/greatestCF)*second.getDen();
}

// ----------------------------------------------------------------------------
//	Method:         ostream& operator<<(ostream& sout, const CRational& number)
//	Description:    Prints out the fraction to the stream
//	Input:          None
//	Output:         Screen display of Fraction
//	Calls:          printCR()
//	Called By:      None
//	Parameters:     ostream & sout  -- the stream used for output
//	                const CRational& number -- the object to print
//	Returns:        a reference to sout 
//	History Log:
//	                2/28/15  AT  completed version 1.0
// ----------------------------------------------------------------------------
ostream& AT_Rational::operator<<(ostream& sout, const CRational& number)
{
	CRational temp = number;
	temp.printCR(sout);
	return sout;
}

// ----------------------------------------------------------------------------
//	Function:        istream& operator>>(istream& sin, CRational& number)
//	Description:     Inputs the fraction from the stream
//	Input:           A fraction from the sin stream
//	Output:          None
//	Calls:           Constructor
//	Called By:       None 
//	Parameters:      ostream & sin  -- the stream used for input
//	                 CRational& number -- the fraction to read into
//	Returns:         a reference to sin 
//	History Log:
//	                 2/28/15  AT  completed version 1.0
//-----------------------------------------------------------------------------
istream& AT_Rational::operator>>(istream& sin, CRational& number)
{
	bool haveSlash = false;
	bool haveDec = false;
	unsigned int i = 0;
	unsigned int slashPlace = -STARTINGVALUE;
	string input;
	bool valid = true;
	do
	{
		getline(sin, input);
		sin.clear();
		for (i = 0; i < input.size(); i++) //delete all spaces
			if (input[i] == ' ')
			{
				input.erase(i, ONE);
				--i;
			}
			if (input[NOTHING] == '-') //if user input negative at numerator
			{
				if (input[STARTINGVALUE] < '0' || input[STARTINGVALUE] > '9')
					valid = false;
				else
					valid = true;
			}
			else //if the number is positive or negative at the denominator
			{
				if (input[NOTHING] < '0' || input[NOTHING] >
					'9')
					valid = false;
				else
					valid = true;
			}
			if (valid == false)
				cout << "Invalid input, please input again\n";
	}
	while(valid == false);

	//find the place where the string starts to be invalid
	for (i = 0; i < input.size(); i++) 
	{
		if (i == slashPlace + ONE) //check for the negative sign
			if (input[i] == '-')
				continue;
		//any characters beside . / and number are invalid 
		if (input[i] < '.' || input[i] > '9') 
			break;
		if (input[i] == '/') //make sure the / appears only once
			if (haveDec == true || haveSlash == true)
				break;
			else
			{
				haveSlash = true;
				slashPlace = i; //take the place of that /
			}
			if (input[i] == '.') //make sure the . appears only once
				if (haveDec == true || haveSlash == true)
					break;
				else
					haveDec = true;
	}
	input.resize(i); //resize the string
	if (haveDec == true) //if it is float number
		number = (atof(input.c_str()));
	else if (haveSlash == true) // if the user input fraction
	{
		long numerator = atol(input.c_str());
		input.erase( NOTHING, slashPlace + ONE);
		long denominator = atol(input.c_str());
		CRational temp(numerator, denominator);
		number = temp;
	}
	else //if it is a long number
		number = atol(input.c_str());
	return sin;
}
}