// File: chart.cpp
// Skeleton class that models rectangular seating charts using 
// dynamic one-dimensional array of booleans.  
//    - seats[i][j] maps to seatArray[i*numSeats+j]
//    - seats[i][j] == false means seat is unassigned
//    - seats[i][j] == true means seat is assigned
//
// Row numbers are 0 ... numRows-1
// Seat numbers are 0 ... numSeats-1
// ----------------------------------------------------------------------
// Class: CS 215
// Date: March 28, & 30
// Assignment: Programming Practical Exam 2, Problem 2
// Programmer: Kunal Mukherjee

#include <iostream>
#include <string>
#include "chart.h"

// Explict-value constructor
// Creates dynamic 2D "array" of seats
SeatingChart::SeatingChart (int initRows, int initSeats)
{
   numRows = initRows;
   numSeats = initSeats;
   int total_seat;
   total_seat = numRows * numSeats;
   seatArray = new bool[total_seat];

   for (int i = 0; i < total_seat; i++)
     {
       seatArray[i] = false;
     }

}  // end explicit-value constructor




// *** DEFINITIONS FOR DESTRUCTOR AND IsAssigned GO HERE  ***
SeatingChart::~SeatingChart()
{
  delete [] seatArray;
}

bool SeatingChart::IsAssigned(int row, int seat)
{
  if((row >= 0 && row < numRows) &&
     (seat >= 0 && seat < numSeats))
    {
      if (seatArray[row * numSeats + seat] == true)
	return true;

      else
	return false;
    }
  
  else
    throw std::string ("The location is invalid.");
}

// Function: Assign
// Assigns seat numbered seatNum in row numbered row
void SeatingChart::Assign (int row, int seatNum)
{
  if((row >= 0 && row < numRows) &&
     (seatNum >= 0 && seatNum < numSeats))
    {
      seatArray[row*numSeats+seatNum] = true;
    }  // end Assign
  
  else
    {
      throw std::string ("The location is invalid.");
    }
}


// Function: Unassign
// Unassigns seat numbered seat_num in row numbered row
void SeatingChart::Unassign (int row, int seatNum)
{
 if((row >= 0 && row < numRows) &&
     (seatNum >= 0 && seatNum < numSeats))
    {
      seatArray[row*numSeats+seatNum] = false;
      // end Unassign
    }
  
  else
    throw std::string ("The location is invalid.");
}
 

// Function: Write
// Prints out X if the seat is assigned, 0 if seat is not assigned
void SeatingChart::Write (std::ostream & out)
{
   for (int i = 0; i < numRows; i++)
   {
      for (int j = 0; j < numSeats; j++)
         if (seatArray[i*numSeats+j])
            out << " X";
         else
            out << " O";
      out << std::endl;
   }  // end for each row
}  // end Write
