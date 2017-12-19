// File: problem1.cpp
// Program to test SeatingChart class
//
// ----------------------------------------------------------------------
// Class: CS 215
// Date: March 28 & 30, 2017
// Assignment: Programming Practical Exam 2, Problem 2
// Programmer:Kunal Mukherjee

#include <iostream>
#include "chart.h"
#include <string>

int main ()
{
   using namespace std;

   // *** DECLARE A 10X4 SEATING CHART NAMED chart1 HERE ***
   SeatingChart chart1(10,4);

   int row, seat;
   char command;

   cout << "Chart 1: (10x4)" << endl;
   chart1.Write(cout);
   
   cout << "Do you want to check assignment (c), assign (a), unassigned (u),"
	<< " or quit (q): ";
   cin >> command;
   command = tolower(command);
   
   while (command != 'q')
   {
      cout << "Enter a row number and a seat number: ";
      cin >> row >> seat;

      if (command == 'a')
      {
	try
	  {
	   
	    chart1.Assign(row, seat);
	     cout << "Assigning this seat" << endl;
	  }
	catch (string exception)
	  {
	    cout << exception << endl;
	  }
      }
      
      else if (command == 'u')
      {
	try
	  {
	   
	    chart1.Unassign(row, seat);
	     cout << "Unassigning this seat" << endl;
	  }
	catch (string exception)
	  {
	    cout << exception << endl;
	  }
      }

      else if ( command == 'c')
	{	 
	  try
	    {
	      if (chart1.IsAssigned(row, seat))
		{
		  cout << "Sorry!! The seat is assigned" << endl;
		}
	      else
		cout << "You are lucky, the seat is not assigned" << endl;
	    }
	  catch (string exception)
	    {
	      cout << exception << endl;
	    }
	}
      
      else
	 cout << "Unknown command.  Try again." << endl;

      cout << "Chart 1: (10x4)" << endl;
      chart1.Write(cout);
   
      cout << "Do you want to check assignment (c), assign (a), unassigned (u), Check Assignment (c)"
	<< " or quit (q): ";
      cin >> command;
      command = tolower(command);
   }
   return 0;
}  // end main
