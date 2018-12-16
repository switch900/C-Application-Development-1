#pragma once
// Assignment 8 : Complex.h
// Declaration of class Complex.
// Member functions are defined in Complex.cpp.
// Author: Andrew Hewitson 
// Date: November 15, 2018

#ifndef Complex_h
#define Complex_h

class Complex //Complex class
{
public:

	static const int REAL_DEFAULT = 1 //default for real part of number
		, IMAGINARY_DEFAULT = 0; //default for imaginary part of number

	//constructor for Complex class.  
	//number for realPart as double or takes default
	//number for imaginaryPart as double or takes default
	Complex(const double& realPart = REAL_DEFAULT, const double& imaginaryPart = IMAGINARY_DEFAULT);

	//returns realPart as a double
	double getRealPart(void) const;
	//returns imaginaryPart as a double
	double getImaginaryPart(void) const;
	//sets realPart and imaginaryPart as doubles  
	void setComplex(const double&, const double&);
	//sets realPart to value of double
	void setRealPart(const double&);
	//sets imaginaryPart to value of double
	void setImaginaryPart(const double&);

	//Adds RHS to the Complex object invoked with this method and returns the result
	const Complex & plusEq(const Complex & RHS);
	//Subtracts RHS from the Complex object invoked with this method
	//and returns the result
	const Complex & minusEq(const Complex & RHS);

	// Outputs to standard output stream the Complex object
	// in the format: < realPart , imaginaryPart >
	void display(void) const;

private:

	double realPart//real part of a complex number
		, imaginaryPart;//imaginary part of a complex number
};

#endif