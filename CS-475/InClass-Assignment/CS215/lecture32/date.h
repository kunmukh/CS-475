// File: date.h
// Declare a class to represent the Date ADT
// Baed on Dale, et al., C++ Plus Data Structures, Chapter 2 Case Study

#ifndef _DATE_H_
#define _DATE_H_

#include <string>
#include <iostream>

enum RelationType {LESS, EQUAL, GREATER};

class Date
{
  public:
   // Default constructor - initializes date to 1/1/2017
   Date();

   // initializes this date (called self in textbook)
   void Initialize(int newMonth, int newDay, int newYear);

   // returns month
   int GetMonth() const;

   // returns month name
   std::string GetMonthAsString() const;

   // returns year
   int GetYear() const;							

   // returns day
   int GetDay() const;

   // returns date value in English; e.g. "January 1, 2017"
   std::string ToString() const;

   // return a date that is daysAway from this date.
   Date Adjust(int daysAway) const;

   // compares self with someDate
   RelationType ComparedTo(Date someDate) const;
   
   // overloaded I/O operators
   // format: mm/dd/yyyy
   friend std::ostream& operator<< (std::ostream &out, Date aDate);
   friend std::istream& operator>> (std::istream &in, Date &aDate);

  private:
   int  year;
   int  month;
   int  day;				
};

#endif
