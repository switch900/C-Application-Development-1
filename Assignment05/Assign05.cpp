// Assignment 5 Assign05.cpp
// Creates an array of ints and stores user entered values.
// If user entered values are unique and valid program stores
// values in array and outputs to display.

// Created by: Andrew Hewitson
// Date:       October, 25th 2018

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <array>
#include <iomanip>

using namespace std;

const unsigned int LOWEST_NUMBER = 10; //lowest number user may enter
const unsigned int HIGHEST_NUMBER = 100; //highest number user may enter
const unsigned int COLUMN_COUNT = 5; //total amount of columns displayed
const unsigned int COLUMN_SPACING = 6; //space between columns being displayed
static const unsigned int SIZE1 = 20; //size of array

// Function prototypes

// Takes user input.  if input is unique and valid then stores to array.
template <size_t SIZE>
void inputValues(array<int, SIZE> &);

// Outputs values from array in table format.
template <size_t SIZE>
void printDisplay(const array<int, SIZE> &);

// Checks to make sure user input is a new number not already in the array.
// Return bool of False if array already contains value.
template <size_t SIZE>
bool isUnique(const array<int, SIZE> &, int value);

// Main method. 
int main()
{
	array<int, SIZE1> arr1; //creates array
	inputValues(arr1); //accepts user input
	printDisplay(arr1); //prints array
	system("pause");
}

// Takes user input.  if input is unique and valid then stores to array.
template <size_t SIZE>
void inputValues(array<int, SIZE> & arr1)
{
	int x = 0;

	while(x<arr1.size()){

		int answer = 0;//answer that user enters
		cout << "\nEnter # " << x + 1 << " : ";
		cin >> answer;

		while (cin.rdstate()) {

			cerr << "The number entered is not in the valid range of "
				<< LOWEST_NUMBER << " to " << HIGHEST_NUMBER << endl;
			cin.clear();
			cin.ignore(256, '\n');
			cout << "\nEnter # " << x + 1 << " : ";
			cin >> answer;
		}

		if (answer < LOWEST_NUMBER || answer > HIGHEST_NUMBER) {
			cerr << "The number entered is not in the valid range of "
				<< LOWEST_NUMBER << " to " << HIGHEST_NUMBER << endl; 
			x--; // if input is not in valid range decrements x in for loop
		}
		else if (!(isUnique(arr1, answer))) {
			arr1[x] = 0; //if input is not unique default value of 0 entered in array
		}
		else {
			cout << "The number: " << answer << " is unique" << endl;
			arr1[x] = answer; //if input is unique and valid value is added to array
		}
		x++;
	}
}

// Outputs values from array in table format.
template <size_t SIZE>
void printDisplay(const array<int, SIZE> & arr1)
{
	cout << "\n\nThe unique numbers are:\n\n";

	for (const auto &output : arr1) {
		static int rowcounter = 1;

		if (output != 0)
		{
			if (rowcounter % COLUMN_COUNT == 0) {
				cout << setw(COLUMN_SPACING) << output << endl;
			}
			else {
				cout << setw(COLUMN_SPACING) << output;
			}
			rowcounter++;
		}
	}
	cout << "\n\n";
}

// Checks to make sure user input is a new number not already in the array.
// Return bool of False if array already contains value.
template <size_t SIZE>
bool isUnique(const array<int, SIZE> & a, int value)
{
	for (unsigned int x = 0; x < a.size(); x++) {
		if (a[x] == value) {
			return false;
		}
	}
	return true;
}