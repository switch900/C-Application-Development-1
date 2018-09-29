/**
	Assignment 1 - COMP 2617 : Employee.cpp
	Member-function definitions for class Employee

	@author Andrew Hewitson
	@version Sept 19,2018
	*/

#include "Employee.h"//include definitions of class Employee from Employee.h
#include <string>
#include <iostream>

const int SHORTEST_NAME = 1;//minimum  amount of letters allowed in first or last name
const int LOWEST_MONTHLY_SALARY = 0;//minimum monthly salary allowed

/**Employee constructor that confirms values are valid and
initializes the three data members for first name, last name and monthly salary*/
Employee::Employee(string _firstName, string _lastName, int _monthlySalary)
{
	if (_firstName.length() > SHORTEST_NAME) {
		setFirstName(_firstName);
	}
	else {
		cerr << "\nWarning - invalid length string entered for first name in ctor: " << _firstName << "\nThe string that was entered will be used for now." << endl;
		firstName = _firstName;
	}

	if (_lastName.length() > SHORTEST_NAME) {
		setLastName(_lastName);
	}
	else {
		cerr << "\nWarning - invalid length string entered for last name in ctor: " << _lastName << "\nThe string that was entered will be used for now." << endl;
		lastName = _lastName;
	}

	if (_monthlySalary >= LOWEST_MONTHLY_SALARY) {
		setMonthlySalary(_monthlySalary);
	}
	else {
		cerr << "\nInvalid salary amount specified in ctor : $" << _monthlySalary << "\nSalary set to $0 instead." << endl;
		monthlySalary = LOWEST_MONTHLY_SALARY;
	}
}

//return firstName
string Employee::getFirstName() const
{
	return firstName;
}

//return lastName
string Employee::getLastName() const
{
	return lastName;
}

//return monthlySalary
int Employee::getMonthlySalary() const
{
	return monthlySalary;
}

//set firstName
void Employee::setFirstName(string _firstName)
{
	//if input valid
	if (_firstName.length() > SHORTEST_NAME) {
		firstName = _firstName;
	}
	else { //output error message
		cerr << "\nERROR - invalid length string entered for first name in setFirstName() : " << _firstName << endl;
		cerr << "The first name was left unchanged: " << firstName << endl;
	}
}

//set lastName
void Employee::setLastName(string _lastName)
{
	//if input valid
	if (_lastName.length() > SHORTEST_NAME) {
		lastName = _lastName;
	}
	else { //output error message
		cerr << "\nERROR - invalid length string entered for last name in setLastName() : " << _lastName << endl;
		cerr << "The last name was left unchanged: " << lastName << endl;
	}
}

//set monthlySalary
void Employee::setMonthlySalary(int _monthlySalary)
{
	//if input valid
	if (_monthlySalary >= LOWEST_MONTHLY_SALARY) {
		monthlySalary = _monthlySalary;
	}
	else {//output error message
		cerr << "\nERROR - Invalid salary amount specified: $" << _monthlySalary << endl;
		cerr << "Salary was left unchanged at: $" << monthlySalary << endl;
	}
}