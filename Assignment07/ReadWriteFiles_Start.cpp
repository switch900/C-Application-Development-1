// Assignment 7 - ReadWriteFiles_Start.cpp
// Calculate gross pay, net pay, pension and deductions for 
// employees of Rogers Hostpital Supplies Company.
//
// Andrew Hewitson & Bob Langelaan
// November 8, 2018
//

#include <iostream>
#include <conio.h>  // Required for _getch() function
#include <fstream>  // Required for file input/output
#include <cstring>
#include <iomanip>

using namespace std;

//global constants

// One way to specify a file name:
const char * IN_FILE = "EmployeePayInput.txt";

const int SIN_LENGTH = 9//maximum length of social insurance number
, COL1_WIDTH = 10//column width for console error display
, COL2_WIDTH = 42//first column width for output data
, COL3_WIDTH = 14//second column width for output data
, COL4_WIDTH = 11//colum width for output summary data
, MOST_EXCEPTIONS = 19
, FEWEST_EXCEPTIONS = 0;

const double LOWEST_PAYRATE = 0
, HIGHEST_PAYRATE = 99.99
, LOWEST_HOURS_WORKED = 0.0
, MOST_HOURS_WORKED = 54.0
, OVERTIME_RATE = .5
, MAX_REGULAR_HOURS = 40.0
, PROV_TAXRATE = .35
, MAX_PENSION = 16.50
, PENSION_PERCENT = .077
, TAX_EXEMPT1 = 14.00
, TAX_EXEMPT2 = 11.00
, TAX_EXEMPT3 = .14
, TAX_EXEMPT4 = .00023;

// A second way to specify a file name:
#define OUT_FILE "EmployeePayOutput.txt"

int main()
{
	//Declare variables
	long socialInsuranceNum;  // Will store social security number of employee
	int numberOfExemptions;  // Will store number of excemptions for employee
	double payRate,			// Will store the pay rate for the employee
		hoursWorked;		// Will store hours worked for the employee
	bool goodValue = true;
	int employeesProcessed = 0;
	double grossIncomeAllEmployees = 0,
		netIncomeAllEmployees = 0,
		pensionWithheldAllEmployees = 0,
		totalDeductionsAllEmployees = 0;

	//Define ifstream object and open file
	ifstream ins;
	ins.open(IN_FILE);

	//Check that file opened without any issues
	if (ins.fail())
	{
		cerr << "ERROR--> Unable to open input file : " << IN_FILE << endl;
		cerr << '\n' << endl;
		_getch(); // causes execution to pause until a char is entered
		return -1; //error return code
	}

	//Define ofstream object and open file
	ofstream outs;
	outs.open(OUT_FILE);

	//Check that file opened without any issues
	if (outs.fail())
	{
		cerr << "ERROR--> Unable to open output file : " << OUT_FILE << endl;
		cerr << '\n' << endl;
		_getch(); // causes execution to pause until a char is entered
		return -2; //error return code
	}

	outs << "Rogers Hospital Supplies Company" << endl;
	outs << "---------------------------------" << endl;
	outs << "\n";
	outs << "Social insurance no.   gross pay    net pay    pension    deductions" << endl;
	outs << "--------------------------------------------------------------------" << endl;

	// Read in first social security number
	ins >> socialInsuranceNum;

	// Process data until end of file is reached
	while (!ins.eof())
	{
		goodValue = true;
		// Read in other data for the employee
		ins >> payRate >> numberOfExemptions >> hoursWorked;

		//enter social insurance number as long if valid or error message recorded.
		int length = 1;
		int sinLength = socialInsuranceNum;

		while (sinLength /= 10)
			length++;
		if (length != SIN_LENGTH)
		{
			cerr << right << setw(COL1_WIDTH) << socialInsuranceNum << "     "
				<< left << "INPUT DATA ERROR:  Invalid social insurance #" << endl;
			goodValue = false;
		}

		//enter pay rate as double if valid or error message recorded
		if (payRate < LOWEST_PAYRATE || payRate > HIGHEST_PAYRATE)
		{
			cerr << right << setw(COL1_WIDTH) << socialInsuranceNum << "     "
				<< left << "INPUT DATA ERROR:  Invalid pay rate: "
				<< fixed << setprecision(2) << payRate << endl;
			goodValue = false;
		}

		//enter amount of tax exceptions as int if valid or error message recorded
		if (numberOfExemptions < FEWEST_EXCEPTIONS || numberOfExemptions> MOST_EXCEPTIONS)
		{
			cerr << right << setw(COL1_WIDTH) << socialInsuranceNum << "     "
				<< left << "INPUT DATA ERROR:  Invalid number of exemptions: "
				<< fixed << setprecision(2) << numberOfExemptions << endl;
			goodValue = false;
		}

		//enter amount of hours worked as double if valid or error message recorded
		if (hoursWorked < LOWEST_HOURS_WORKED || hoursWorked > MOST_HOURS_WORKED)
		{
			cerr << right << setw(COL1_WIDTH) << socialInsuranceNum << "     "
				<< left << "INPUT DATA ERROR:  Invalid hours worked: "
				<< fixed << setprecision(2) << hoursWorked << endl;
			goodValue = false;
		}

		//if the inputed value is valid do the following
		if ((goodValue))
		{
		//regular pay - payrate mulitiplied by amount of hours worked
		double regularPay = payRate * hoursWorked;
		//overtime pay - payrate multiplied by current overtime rate multiplied by overtime qualifying hours
		double overtime = (payRate*OVERTIME_RATE) * (hoursWorked - MAX_REGULAR_HOURS);
		//gross pay - if overtime hours worked gross pay equals overtime pay plus regular pay
		//otherwise gross pay equals regular pay
		double grossPay = hoursWorked > MAX_REGULAR_HOURS ? overtime + regularPay : regularPay;

		//taxable amount 
		double taxable = (grossPay - (TAX_EXEMPT1 * numberOfExemptions) - TAX_EXEMPT2);
		double federalTax = (taxable * (TAX_EXEMPT3 + (TAX_EXEMPT4  * taxable)));
		//if federal tax is greater than 0 becomes amount.  If not it becomes 0.
		federalTax = federalTax > 0 ? federalTax : 0;
		//provincial tax is 35% of federal tax rate
		double provincialTax = federalTax * PROV_TAXRATE;

		//pension amount - gross pay multiplied by current pension percentage
		double pension = grossPay * PENSION_PERCENT;
		//if pension amount is less than maximum pension contribution use percentage
		//otherwise use maximum pension contribution.
		pension = pension < MAX_PENSION ? pension : MAX_PENSION;

		//total deductions equal federal tax plus provincial tax plus total pension contribution
		double deductions = federalTax + provincialTax + pension;
		//net income equals gross pay minus deductions
		double netIncome = grossPay - deductions;

			employeesProcessed++;//increase count of employees processed
			grossIncomeAllEmployees += grossPay; //increase total of all gross income from valid entries
			netIncomeAllEmployees += netIncome; // increase total of all net income from valid entries
			pensionWithheldAllEmployees += pension;//increase total of all pension from valid entries
			totalDeductionsAllEmployees += deductions;//increase total of all deductions from valid entries

			//print social insurance number, gross pay, net income, pension and deductions to file
			outs << socialInsuranceNum
				<< setw(COL4_WIDTH + 12) << right << fixed << setprecision(2) << grossPay
				<< setw(COL4_WIDTH) << right << netIncome
				<< setw(COL4_WIDTH) << right << fixed << setprecision(2) << pension
				<< setw(COL4_WIDTH + 3) << right << fixed << setprecision(2) << deductions
				<< "\n";
		}
		// Read in next social security number
		ins >> socialInsuranceNum;
	}

	//print to file totals for employees processed, total employee gross income, 
	//total employee net income, total employee pension, total deductions from all employees
	outs << "\n\n\nSummary" << endl;
	outs << "-------\n" << endl;
	outs << left << setw(COL2_WIDTH) << "Number of employees processed: "
		<< right << setw(COL3_WIDTH) << employeesProcessed << endl;
	outs << left << setw(COL2_WIDTH) << "Total gross pay for all employees: "
		<< right << setw(COL3_WIDTH) << grossIncomeAllEmployees << endl;
	outs << left << setw(COL2_WIDTH) << "Total net pay for all employees: "
		<< right << setw(COL3_WIDTH) << netIncomeAllEmployees << endl;
	outs << left << setw(COL2_WIDTH) << "Total pension withheld for all employees: "
		<< right << setw(COL3_WIDTH) << pensionWithheldAllEmployees << endl;
	outs << left << setw(COL2_WIDTH) << "Total deductions for all employees: "
		<< right << setw(COL3_WIDTH) << totalDeductionsAllEmployees;

	// Close files
	ins.close();
	outs.close();

	cout << '\n' << endl;

	_getch(); // causes execution to pause until char is entered
}