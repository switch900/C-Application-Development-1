// Assign 6 Main Program - used to "test drive" the TurtleGraphics class
// File Name: Assign6.cpp
// Author: Bob Langelaan
// Date: Nov. 7, 2013

// This program implements Turtle Graphics

// include and using statments


#include "TurtleGraphics.h"
#include <iostream>
#include <array>

using namespace std;

int main()
{
   // Declarations

	array<int, TurtleGraphics::ARRAY_SIZE> cmds = { 5,5,4,5,9,2,    // go to start of first letter and put pen down

				  // B
				  5,12, 1,3,5,1,4,2,5,1,1,3,5,1,2,5,2, 1,3,5,1,4,2,5,1, 1,3,5,1,2,5,11, 3,5,5,
				  1,3,5,12,3,5,5, 5,1,4,2,5,1, 1,3,5,1,2,5,2, 1,3,5,1,4,2,5,1, 1,3,5,1,2,5,11, 3,5,5,

				  1,5,5,3,5,22,2, // go to start of next letter and put pen down

				  // O
				  5,10, 1,3,5,1,4,2,5,1, 1,3,5,1,2,5,7, 1,3,5,1,4,2,5,1,
				  1,3,5,1,2,5,10, 1,3,5,1,4,2,5,1, 1,3,5,1,2,5,7, 1,3,5,1,4,2,5,1,

				  1,3,5,19,2,     // go to start of next letter and put pen down

				  // B
				  5,12, 1,3,5,1,4,2,5,1, 1,3,5,1,2,5,2, 1,3,5,1,4,2,5,1, 1,3,5,1,2,5,11, 3,5,5,
				  1,3,5,12,3,5,5, 5,1,4,2,5,1, 1,3,5,1,2,5,2, 1,3,5,1,4,2,5,1, 1,3,5,1,2,5,11, 3,5,5,

		// Test program bound checking and add border in the process

		//   Uncomment next line when ready to test bound checking
		1,5,100,2,4,5,100,4,5,100,4,5,100,4,5,100,4,5,100,

		1,6,9}; // finish off

   TurtleGraphics turtleOne;  // create a TurtleGraphics object

   turtleOne.processTurtleMoves(cmds); // have turtle process commands

   system("pause");
   return 0;  // we are finished, let's go home
}
