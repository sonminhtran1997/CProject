#ifndef SAFEIO_H
#define SAFEIO_H
//---------------------------------------------------------------------------------
// File:	textGraphics.h
//
// Function:	template<class T>
//		void safeRead(istream& sin, T& input, const char* prompt) 
//---------------------------------------------------------------------------------
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;
const unsigned BUFFER_SIZE = 256;
char safeChoice(string prompt, char choice1 = 'Y', char choice2 = 'N');

template<class T>
void safeRead(istream& sin, T& input, 
	const char* prompt = "invalid input--please input a NUMBER: ");


#endif