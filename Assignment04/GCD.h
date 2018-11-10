#pragma once
// Assignment 4: GCD.h
// Template for greatest common denominator formula.
// Author:  Andrew Hewitson
// Date: October 11,2018
#include <cstdlib>

//definition of function tempmlate that verifies that both input values are positive
//and then finds the greatest common denominator between the two values.
template < class T >
T gcd(T value1, T value2)
{
	T gcd = 1;
	if (value1 < 0) {
		value1 = -value1;
	}

	if (value2 < 0) {
		value2 = -value2;
	}

	for (long x = 2; x <= ((value1 < value2) ? value1 : value2); x++) {
		if (value1 % x == 0 && value2 % x == 0)
		{
			gcd = x; //assigns value of x to gcd if x is divisible evenly into both value1 and value2
		}
	}
	return gcd; 
}