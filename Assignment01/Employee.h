/**
	Assignment 1 - COMP 2617 : Employee.h
	Definition of class Employee

	@author Andrew Hewitson
	@version Sept 19,2018
	*/

#pragma once
#include <string>

//class Employee definition
class Employee
{
public:
	explicit Employee(std::string, std::string, int);//constructor initializes data members
	string getFirstName() const;//return first name as string
	string getLastName() const;//return last name as string
	int getMonthlySalary() const;//return monthly salary as int
	void setFirstName(std::string);//set first name
	void setLastName(std::string);//set last name
	void setMonthlySalary(int);//set monthly salary

private:
	std::string firstName;//the employee's first name
	std::string lastName;//the employee's last name
	int monthlySalary;//the employee's monthly salary
};//end class Employee