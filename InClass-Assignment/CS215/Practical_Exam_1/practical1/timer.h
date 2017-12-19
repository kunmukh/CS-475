// File: timer.h
// Definition of the Timer class
//
// ----------------------------------------------------------------------
// Class: CS 215                      
// Assignment: Programming Practical Exam 1, Problem 2
// Programmer: FILL IN YOUR NAME HERE!!
// Date: February 14 & 15, 2017

#ifndef TIMER_H_
#define TIMER_H_

#include <iostream>

enum RelationType {LESS, EQUAL, GREATER};

class Timer
{
   public:  // Operations

      // Default constructor
      Timer ();  // sets value to 00:00

      void Initialize (int newMinutes, int newSeconds); //done

      void Tick(); //done

      RelationType ComparedTo(Timer rhs);

      friend std::ostream& operator<< (std::ostream &out, Timer time);
      friend std::istream& operator>> (std::istream &in, Timer& time);

      // Accessors
      int GetMinutes() const;  // returns minutes attribute
      int GetSeconds() const;  // returns seconds attribute

   private:  // Attributes

      int minutes, seconds;  // Represents MM:SS 

};  // end Timer class

#endif // TIMER_H_
