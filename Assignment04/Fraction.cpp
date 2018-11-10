// Assignment 4: Fraction.cpp
// Member-function definitions for class Fraction.
// Author:  Andrew Hewitson
// Date: October 11,2018

#include "Fraction.h"
#include "GCD.h" // template function for calculating greatest common divisor
#include <iostream>
#include <cstdlib>
using namespace std;

const static long long DEFAULT_NUMERATOR = 0;
const static long long DEFAULT_DENOMINATOR = 1;

//Default constructor.  Assigns default values to numerator and denominator.
Fraction::Fraction(void)
	: numerator(DEFAULT_NUMERATOR), denominator(DEFAULT_DENOMINATOR)
{
}

//Overloaded constructor.  Assigns values to numerator and denominator.
//Calls simplify method to verify assigned values are lowest terms.
Fraction::Fraction(long long num, long long denom)
	:numerator(num), denominator(denom)
{
	if (denominator == 0) {
		numerator = DEFAULT_NUMERATOR;
		denominator = DEFAULT_DENOMINATOR;
		cerr << "\n\n Attempt was made to create a Fraction object with a denominator of 0 !!!\n\n";
	}
	else {
		simplify();
	}
}

//Implementation of the plusEq() member function
//Adds two fractions together.
//Calls simplify method to verify assigned values are lowest terms.
const Fraction & Fraction::plusEq(const Fraction & op)
{
	long long numerator1 = numerator * op.denominator;//first fraction numerator 
														//with common denominator
	long long numerator2 = op.numerator * denominator;//second fraction numerator 
														//with common denominator
	numerator = numerator1 + numerator2; //added total of first and second fractions numerators
	denominator = denominator * op.denominator;//common denominator
	simplify();  //total simplified to lowest terms
	return (*this); // returns the object which invoked the method
}

//Implementation of the minusEq() member function.
//Subtracts one fraction from another.
//Calls simplify method to verify assigned values are lowest terms.
const Fraction & Fraction::minusEq(const Fraction & op)
{
	long long numerator1 = numerator * op.denominator;//first fraction numerator 
														//with common denominator
	long long numerator2 = op.numerator * denominator;//second fraction numerator 
														//with common denominator
	numerator = numerator1 - numerator2; //subtracted total of first second fractions numerators
	denominator = denominator * op.denominator;//common denominator
	simplify();  //total simplified to lowest terms
	return (*this); // returns the object which invoked the method
}

//Implementation of the timesEq() member function
//Performs similar operation as the *= operator on the built-in types
//Calls simplify method to verify assigned values are lowest terms.
const Fraction & Fraction::timesEq(const Fraction & op)
{
	numerator *= op.numerator; //first fraction numerator multiplied by second fraction numerator
	denominator *= op.denominator;//first fraction denominator 
									//multiplied by second fraction denominator
	simplify(); //total simplified to lowest terms
	return (*this); // returns the object which invoked the method
}

//Implementation of the divideEq() member function
//Performs similar operation as the /= operator on the built-in types
//Calls simplify method to verify assigned values are lowest terms.
const Fraction & Fraction::divideEq(const Fraction & op)
{
	numerator *= op.denominator;//first fraction numerator multiplied by second fraction denominator
	denominator *= op.numerator;//first fraction denominator multiplied by second fraction numerator
	simplify(); //total simplified to lowest terms
	return (*this); // returns the object which invoked the method
}

//Implementation of the negate() member function
//Reverses the value of the numerator to it's opposite corresponding negative or positive value.
Fraction Fraction::negate(void) const
{
	long long tempNumerator = -numerator;	//temporary variable to hold opposite numerator
	return Fraction(tempNumerator, denominator);//create new Fraction 
												//with reversed numerator
												//value and original denominator
}

//Return numerator as long long
long long Fraction::getNum(void) const
{
	return numerator;
}

//Return denominator as long long
long long Fraction::getDenom(void) const
{
	return denominator;
}

//Implementation of display() member function
//Prints value of numerator and denominator to screen
void Fraction::display(void) const
{
	cout << numerator << "/" << denominator;
}

//Implementation of simplify() member function
//Checks to see if denominator is positive value.  
//If denominator is not positive than it makes denominator a positive number
//and makes the numerator a negative value.
void Fraction::simplify(void)
{
	if (denominator < 0) {
		denominator = abs(denominator);//denominator is made positive
		numerator = -numerator;//numerator is made negative
	}
	long long greatestCommonDenominator = gcd(numerator, denominator);//find greatest
																	//common denominator(G.C.D.)
	denominator /= greatestCommonDenominator;//denominator becomes value of 
											//denominator divided by G.C.D.
	numerator /= greatestCommonDenominator;//numerator becomes value of numerator 
											//divided by G.C.D.
}