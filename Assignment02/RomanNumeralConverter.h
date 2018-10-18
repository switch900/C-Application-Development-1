#pragma once
/**
	Assignment 2 - COMP 2617 : RomanNumeralConverter.h
	Definition of class RomanNumeralConverter

	@author Andrew Hewitson
	@version Sept 19,2018
	*/

#include <string>

using namespace std;

//class RomanNumeralConverter definition
class RomanNumeralConverter
{
public:
	explicit RomanNumeralConverter(string);//constructor initializes data members
	string getRomanNumeral() const;//return roman numeral as string
	void setRomanNumeral(string);//set roman numeral
	int getValue(char);//get int value for single character
	int getTotal(string);//get total value of roman numeral as int

private:
	string romanNumeral;//the roman numeral
};//end class RomanNumeralConverter