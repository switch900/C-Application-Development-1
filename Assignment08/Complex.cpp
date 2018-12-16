// Assignment 8: Complex.cpp
// Member-function definitions for class Complex.
// Author:  Andrew Hewitson
// Date: November 15,2018

#include "Complex.h" // include definition of class Complex from Complex.h
#include<iostream>
#include <iomanip>

using namespace std;

const static int DECIMAL_PRECISION = 4;//decimal precision for display method

//constructor for Complex class.  
//number for realPart as double or takes default
//number for imaginaryPart as double or takes default
Complex::Complex(const double & real, const double & imaginary)
{
	setComplex(real, imaginary);
}

//returns realPart as a double
double Complex::getRealPart() const
{
	return realPart;
}

//returns imaginaryPart as a double
double Complex::getImaginaryPart() const
{
	return imaginaryPart;
}

//sets realPart and imaginaryPart as doubles 
void Complex::setComplex(const double & real, const double & imaginary) {
	setRealPart(real);
	setImaginaryPart(imaginary);
}

//sets realPart to value of double
void Complex::setRealPart(const double & real)
{
	realPart = real;
}

//sets imaginaryPart to value of double
void Complex::setImaginaryPart(const double & imaginary)
{
	imaginaryPart = imaginary;
}

//Adds value to the Complex object invoked with this method and returns the result
const Complex & Complex::plusEq(const Complex & op)
{
	realPart += op.realPart;
	imaginaryPart += op.imaginaryPart;
	return (*this);
}

//Subtracts  value from the Complex object invoked with this method
//and returns the result
const Complex & Complex::minusEq(const Complex & op)
{
	realPart -= op.realPart;
	imaginaryPart -= op.imaginaryPart;
	return (*this);
}

// Outputs to standard output stream the Complex object
// in the format: < realPart , imaginaryPart >
void Complex::display(void) const
{
	cout  << setprecision(DECIMAL_PRECISION)<< fixed
		<< "< " << getRealPart() << " , "
		<< getImaginaryPart() << " >";
}