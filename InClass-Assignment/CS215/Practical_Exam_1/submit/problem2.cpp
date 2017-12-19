// File: problem2.cpp
// A program to test the Timer class
//
// ----------------------------------------------------------------------
// Class: CS 215                      
// Assignment: Programming Practical Exam 1, Problem 2
// Programmer: FILL IN YOUR NAME HERE!!
// Date: February 14 & 15, 2017

#include <iostream>      // <<, >>, endl;
#include "timer.h"       // Timer class

int main ()  // no command line arguments
{
   using namespace std;

   Timer t1, t2;       // Default constructed: 00:00
   int minutes, seconds;
   
   cout << " Timer 1: Input a time that the clock will be set to in one line e.g: 2 58. The clock will be set to 2 minutes  58 seconds "  << endl;
   
   cin >> minutes >> seconds;
   t1.Initialize(minutes, seconds);

   cout << "Timer 2: Input a time that the clock will be set to in one line e.g: 2 58. The clock will be set to 2 minutes 58 seconds" << endl;

   cin >> minutes >> seconds;
   t2.Initialize(minutes, seconds);

   int n_tick;
   cout << "Enter the number of time twice will be used timer 1:" << endl;
   cin >> n_tick;
  
   for (int i = 0; i < n_tick; i++)
     {
       t1.Tick();
     }
   cout << "The time left in Timer 1 is : " << t1  << endl;
   
   switch(t1.ComparedTo(t2))
     {
     case LESS:
       cout << t1 << "   is less than "
	    << t2 << endl ;
       break;
     case EQUAL:
       cout << t1 << "   is equal to "
	    << t2 << endl;
       break;
     case GREATER:
       cout << t1 << "  is greater than"
	    << t2 << endl;
       break;
     }
   return 0;  

   

   cout << "Default constructed t1" << endl;
   cout << "   minutes: " << t1.GetMinutes() << endl;
   cout << "   seconds: " << t1.GetSeconds() << endl;

  
   
   return 0;
}  // end main
