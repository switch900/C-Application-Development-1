// Assignment 6 : TurtleGraphics.cpp
// TurtleGraphics Class for Assign6
// Defines member functions Assign6 Turtlegraphic program.
// Author: Andrew Hewitson
// Date: November 3, 2018

#include "TurtleGraphics.h"
#include <iostream>

using namespace std;

//Constructor. 
//Initializes turtle's starting point, direction and pen position.
//Initializes m_Floor array's elements to false.
TurtleGraphics::TurtleGraphics(void) :
	penPosition(STARTING_PEN_POSITION),
	compass(STARTING_DIRECTION),
	y_axis(STARTING_ROW),
	x_axis(STARTING_COL)
{
	for (auto & rows : m_Floor) { // iterate through all of the rows of m_Floor
		for (auto & arrayValue : rows) { // iterate through all of the columns of m_Floor
			arrayValue = false; //set value to false
		}
	}
};

//Processes turtle moves based on an input of an array of int.
void TurtleGraphics::processTurtleMoves(const std::array<int, ARRAY_SIZE>& a)
{
	unsigned int distance; //distance turtle is supposed to move
	unsigned int index = 0; //index of array 
	bool endOfData = false; //sentinel value to exit program

	while(index<a.size() && endOfData!=true){
		unsigned int temp_move = 0; //how far turtle can move
		switch (static_cast<Cmds>(a[index])) {
		case(Cmds::PEN_UP)://pen position is changed to up
			penPosition = false; 
			break;
		case(Cmds::PEN_DWN):// pen position is changed to down
			penPosition = true;
			break;
		case(Cmds::TURN_RIGHT): //turtle directions is changed to the next element in the enum Directions
			compass = static_cast<Directions>((static_cast<unsigned int>(compass) + 1) % (static_cast<unsigned int>(Directions::WEST) + 1));
			break;
		case(Cmds::TURN_LEFT): //turtle directions is changed to the previous element in the enum Directions
			compass = static_cast<Directions>((static_cast<unsigned int>(compass) - 1) % (static_cast<unsigned int>(Directions::WEST) + 1));
			break;
		case(Cmds::MOVE): //turtle moves forward in the direction they are pointing
			index++; //advance to the next element in the array
			distance = a[index]; // distance equals the next value in the array after move command

			switch (compass) {
			case(Directions::NORTH): //moves on the y_axis decrementing
				while (temp_move < distance && y_axis>0) {
					if (penPosition) {
						m_Floor[y_axis][x_axis] = true;//if penPosition is true then element in array becomes true
					}
					y_axis--;
					temp_move++;
				}
				break;
			case(Directions::SOUTH): //moves on the y_axis incrementing
				while (temp_move < distance && y_axis < NROWS - 1) {
					if (penPosition) {
						m_Floor[y_axis][x_axis] = true;//if penPosition is true then element in array becomes true
					}
					y_axis++;
					temp_move++;
				}
				break;
			case(Directions::EAST): //moves on the x_axis incrementing
				while (temp_move < distance && x_axis < NCOLS - 1) {
					if (penPosition) {
						m_Floor[y_axis][x_axis] = true;//if penPosition is true then element in array becomes true
					}
					x_axis++;
					temp_move++;
				}
				break;
			case(Directions::WEST): //moves on the x_axis decrementing
				while (temp_move < distance && x_axis>0) {
					if (penPosition) {
						m_Floor[y_axis][x_axis] = true;//if penPosition is true then element in array becomes true
					}
					x_axis--;
					temp_move++;
				}			
			}		
			break;
		case(Cmds::DISPLAY):
			displayFloor();
			break;
		case(Cmds::END_OF_DATA):
			endOfData = true;
			cout << "\n";
			break;
		default:
			cerr << "Input not valid." << endl;
			break;
		}
		index++;//advance index of array
	}
}

//Displays output of m_Floor array elements.
//Displays * if element is true and a blank if it is false
void TurtleGraphics::displayFloor() const
{
	for (auto & rows : m_Floor) { // iterate through all of the rows of myArray
		for (auto & arrayValue : rows) { // iterate through all of the columns of myArray
			arrayValue ? cout << "*" : cout << " ";
		}
		cout << "\n";
	}
}