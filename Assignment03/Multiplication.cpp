//Assignment 3 : Multiplication.cpp
//Multiplication program
//Andrew Hewitson
//October 4, 2018

#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;

const int MIN = 0;
const int MAX = 9;
const int EXIT = -1;

void multiplication();
void correctMessage();
void inCorrectMessage();
int getAnswer();

/**Main class. Prompts user with how to exit program. Runs multiplication method.  
Displays exit message when program is terminated.*/
int main() {
	srand(static_cast<unsigned int>(time(MIN)));
	multiplication();
	system("pause");
	return 0;
}

/**randomly generates a number from 1-4 and selects a message for a 
correct answer based on the result*/
void correctMessage() {
	unsigned int tempNumber = 1 + rand() % 4;//random number to assign message
	
	switch (tempNumber) {
	case 1: cout<< "Very good" << endl; break;
	case 2: cout<< "Excellent" << endl; break;
	case 3: cout<< "Nice work!" << endl; break;
	case 4: cout<< "Keep up the good work!" << endl; break;
	default: cerr<< "Error.  Incorrect input" << endl;
	}
}

/**randomly generates a number from 1-4 and selects a message for an 
incorrect answer based on the result.*/
void inCorrectMessage() {
	unsigned int tempNumber = 1 + rand() % 4;//random number to assign message

	switch (tempNumber) {
	case 1: cout<< "No. Please try again." << endl; break;
	case 2: cout<< "Wrong. Try once more." << endl; break;
	case 3: cout<< "Don't give up!" << endl; break;
	case 4: cout<< "No. Keep trying." << endl; break;
	default: cerr<< "Error. Input incorrect" << endl;
	}
}

/**Randomly selects two numbers between 1 and 9.  Multiplies numbers together to get a total.
User is prompted with the two numbers and enters the answer that they think matches the total.  
If it matches they will be shown a confirmation and a new problem is generated.  If it doesn't
match then they are shown an error message and allowed to guess again. 
If user enters -1 then program exits.*/
void multiplication() {
	cout << "Enter - 1 to End." << endl;
	int answer = 0;
	while (answer != EXIT) {
		unsigned int number1 = MIN + rand() % MAX;//random first number to multiply
		unsigned int number2 = MIN + rand() % MAX;//random second number to multiply
		int total = number1 * number2;//total for user to match

		cout << "How much is " << number1 << " times " << number2 << " (-1 to End) ? ";
		answer = getAnswer();
		while (answer != total && answer != EXIT) {
			inCorrectMessage();
			cout << "? ";
			answer = getAnswer();
		}
		if (answer == total) {
			correctMessage();
		}
	}
	cout << "\nThat's all for now. Bye." << endl;
}

//Allows user to enter answer and checks to see if it is a valid integer was input. 
int getAnswer() {
	int answer = 0;//answer that user enters
	cin >> answer;
	while (cin.fail()) {
		cout << "Invalid input entered - try again: ";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> answer;
	}
	return answer;
}
