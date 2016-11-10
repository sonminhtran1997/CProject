//-----------------------------------------------------------------------------
//	File:           Rational_Number.h
//	class:		CRational
//-----------------------------------------------------------------------------
#ifndef RATIONAL_NUMBER
#define RATIONAL_NUMBER
#include <iostream>
using namespace std;

namespace AT_Rational
{
	//---------------------------------------------------------------------------
//	Title:          Rational Number Class
//	Description:    This file contains the class definition for CRational
//	Programmer:     An Dien Tang
//	Date:           2/26/2015
//	Version:	1.03
//	Environment:	Laptop Toshiba 
//				Software:   MS Windows 8
//				Compiles under Microsoft Visual C++.Net 2012
//	class CRational:
//	Properties:
//			long m_numerator; -- the numerator of the fraction
//  		long m_denominator;    -- the denominator of the fraction
//	Methods:
//			CRational(long numerator = 0, long denominator = 1)
//					constructor;
//					initialize m_numerator and m_denominator
//					Parameters:
//						long numerator: the numerator
//						long denominator: the denominator
//
//  		CRational(int number)
//					constructor;
//					initialize m_numerator and m_denominator
//					Parameter:
//						int number: an integer
//
//  		CRational(double number)
//					constructor;
//					initialize m_numerator and m_denominator
//					Parameter:
//						double number: a floating number
//
//			long getNum()
//				return m_numerator
//
//			long getDen()
//				return m_denominator
//
//			void printCR(ostream & sout)
//
//			CRational invert()
//				Inverse the fration
//				return a reversed fraction
//
//			CRational toThePower(int number)
//				Power the fraction
//				Parameter: int number: a power number
//				return a powered fraction
//
//			static long compareTo(const CRational first, 
//								const CRational second)
//				Compare 2 fraction
//				Parameters:
//					const CRational first: first fraction to compare
//					const CRational second: second fraction to compare
//				return a result between the 1st and the 2nd
//					negative for smaller, 0 for equal and 
//					positive for bigger
//
//			CRational operator*(const CRational number)const
//				Multiplication
//				Parameters:
//					const CRational number: a fraction for multiplication
//				return a multiplied fraction
//
//			CRational operator/(const CRational number)const
//				Division
//				Parameters:
//					const CRational number: a fraction for division
//				return a divided fraction
//
//			CRational operator+(const CRational number)const
//				Addtion
//				Parameters:
//					const CRational number: a fraction for addition
//				return a added fraction
//
//			CRational operator+()
//				Returns: a fraction -- the value of *this
//
//			CRational operator-(const CRational number)const
//				Subtraction
//				Parameters:
//					const CRational number: a fraction for subtraction
//				return a subtracted fraction
//
//			CRational operator-()
//				Returns: a fraction -- the negative value of *this
//
//			CRational operator*=(const CRational number)
//				Parameters:
//					const CRational number: a fraction for multiplication
//				return a fraction with the value of *this after multiplication
//
//			CRational operator/=(const CRational number)
//				Parameters:
//					const CRational number: a fraction for division
//				return a fraction with the value of *this after division
//
//			CRational operator+=(const CRational number)
//				Parameters:
//					const CRational number: a fraction for addition
//				return a fraction with the value of *this after addition
//
//			CRational operator-=(const CRational number)
//				Parameters:
//					const CRational number: a fraction for subtraction
//				return a fraction with the value of *this after subtraction
//
//			CRational operator++()
//				Pre-increment, increase the fraction by 1
//
//			CRational operator++(int)
//				Post-increment, increase the fraction by 1
//			
//			CRational operator--()
//				Pre-decrement, decrease the fraction by 1
//
//			CRational operator--(int)
//				Post-decrement, decrease the fraction by 1
//
//			bool operator==(const CRational number)const
//				Parameter:
//					const CRational number: a fraction to compare	
//				Returns: true if the two are the same
//
//			bool operator!=(const CRational number)const
//				Parameter:
//					const CRational number: a fraction to compare	
//				Returns: true if the two are not the same
//
//			bool operator<(const CRational number)const
//				Parameter:
//					const CRational number: a fraction to compare	
//				Returns: true if *this is smaller than that fraction
//
//			bool operator<=(const CRational number)const
//				Parameter:
//					const CRational number: a fraction to compare	
//				Returns: true if *this is smaller than or equal
//							to that fraction
//
//			bool operator>(const CRational number)const
//				Parameter:
//					const CRational number: a fraction to compare	
//				Returns: true if *this is bigger than that fraction
//
//			bool operator>=(const CRational number)const
//				Parameter:
//					const CRational number: a fraction to compare	
//				Returns: true if *this is bigger than or equal 
//							to that fraction
//
//			bool operator!()
//				Returns: true if the numerator is 0
//				
//			CRational operator~()
//				return the inversed fraction of *this
//
//			operator bool() const
//				return the bool version of the fraction
//
//			operator double() const
//				return the double version of the fraction
//
//			operator string() const
//				return the string version of the fraction
//
//			static long GCF(long bigger, long smaller)
//				Parameters:
//					long bigger: the first number
//					long smaller: the second number
//				return the greatest common factor of the 2 numbers
//
//			void setProperForm()
//
//			static long LCD(const CRational first, const CRational second)
//				Parameters:
//					const CRational first: the first fraction
//					const CRational second: the second fraction
//				return the least common denominator of the 2 fractions
//  History Log:
//			2/10/15  AT  completed version 1.0
//			2/18/15  AT  modified  version 1.02
//			2/26/15  AT  modified  version 1.03
//-----------------------------------------------------------------------------
	class CRational
	{

	public:
		CRational(long numerator = 0L, long denominator = 1L)
			:m_numerator(numerator), m_denominator(denominator)
		{setProperForm();}
		CRational(int number);
		CRational(double number);
		long getNum() const {return m_numerator;}
		long getDen() const {return m_denominator;}
		void printCR(ostream & sout);
		CRational invert();
		CRational toThePower(int number);
		static long compareTo(const CRational first, 
			const CRational second);
		CRational operator*(const CRational number)const;
		CRational operator/(const CRational number)const;
		CRational operator+(const CRational number)const;
		CRational operator+();
		CRational operator-(const CRational number)const;
		CRational operator-();
		CRational operator*=(const CRational number);
		CRational operator/=(const CRational number);
		CRational operator+=(const CRational number);
		CRational operator-=(const CRational number);
		CRational operator++();
		CRational operator++(int);
		CRational operator--();
		CRational operator--(int);
		bool operator==(const CRational number)const;
		bool operator!=(const CRational number)const;
		bool operator<(const CRational number)const;
		bool operator<=(const CRational number)const;
		bool operator>(const CRational number)const;
		bool operator>=(const CRational number)const;
		bool operator!();
		CRational operator~();
		operator bool() const;
		operator double() const;
		operator string() const;
		static long GCF(long bigger, long smaller);
	private:
		long m_numerator;
		long m_denominator;
		void setProperForm();
		static long LCD(const CRational first, const CRational second);
	};

	ostream& operator<<(ostream& sout, const CRational& number);
	istream& operator>>(istream& sin, CRational& number);
}


#endif
