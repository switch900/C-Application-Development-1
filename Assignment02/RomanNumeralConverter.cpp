//Assignment 2 : RomanNumeralConverter.cpp
//Decode Roman numerals into integers
//Andrew Hewitson
//Sept. 27th, 2018
#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

//function main begins program execution
int main()
{
	char romanNumeral = 0;//the Roman Numeral to decode
	int counter = 1;//how many turns the user has taken
	int number1 = 0;//the first value of a Roman Numeral to compare
	int number2 = 0;//the second value of a Roman Numeral to compare
	int total = 0;//the total value of the Roman numeral
	bool error = false;//loop stops if error becomes true

	cout << "10 Roman numeral values will be input and converted into"
		<< "\ntheir equivalent Hindu-Arabic numeric values.";

	while (counter <= 10) {
		cout << "\n\nInput Roman numeral # " << counter << ": ";//displays 
		counter++;//increase counter by 1;
		total = 0;//reinitializes total to 0;
		number1 = 0;//reinitializes number1 to 0;
		number2 = 0;//reinitializes number2 to 0;

		//read each character user enters.  Convert to uppercase.  
		//Finish reading when new line is reached.
		while ((romanNumeral = toupper(cin.get())) != '\n')
		{
			//if program is not in error state begin switch statement
			if (!error) {
				cout << romanNumeral;//display roman numeral being decoded

				//get value of roman numeral.  If input is not valid display error
				//and put program into error state.
				switch (romanNumeral)
				{
				case('I'):
					number1 = 1;
					break;
				case('V'):
					number1 = 5;
					break;
				case('X'):
					number1 = 10;
					break;
				case('L'):
					number1 = 50;
					break;
				case('C'):
					number1 = 100;
					break;
				case('D'):
					number1 = 500;
					break;
				case('M'):
					number1 = 1000;
					break;
				default:
					cout << " Error - last character was not valid!!!";
					number1 = 0;
					total = 0;
					error = true;
					break;
				}

				//test value of roman numeral to see if total should be increased or decreased.
				if (number2 == 0) {
					total = number1;
				}
				else if (number1 <= number2 && number2 != 0) {
					total += number1;
				}
				else {
					total = (total - number2) + (number1 - number2);
				}
				number2 = number1;//assign value of number1 to number2 for comparison on next iteration
			}
		}
		
		cout<< " = "<< total;	
		error = false;//reset error state to false for next entry.
	}
	//display to tell user that the end of the program has been reached.
	cout << "\n\nTHAT'S ALL FOLKS :)\n" << endl;
	system("pause");
}//end main
