/**
	Assignment 1 - COMP 2617 : Employee.h
	Definition of class Employee

	@author Andrew Hewitson
	@version Sept 19,2018
	*/

#pragma once
#include <string>

using namespace std;

//class Employee definition
class Employee
{
public:
	explicit Employee(string, string, int);//constructor initializes data members
	string getFirstName() const;//return first name as string
	string getLastName() const;//return last name as string
	int getMonthlySalary() const;//return monthly salary as int
	void setFirstName(string);//set first name
	void setLastName(string);//set last name
	void setMonthlySalary(int);//set monthly salary

private:
	string firstName;//the employee's first name
	string lastName;//the employee's last name
	int monthlySalary;//the employee's monthly salary
};//end class Employee