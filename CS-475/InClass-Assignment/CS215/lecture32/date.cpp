// File: date.cpp
// Contains the implementation of class Date
// Based on Dale, et al., C++ Plus Data Structures, Chapter 2 Case Study

#include "date.h"
#include <fstream>
#include <iostream>
#include <sstream>

// Number of days in each month
static int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30,
                            31, 30, 31};	

// Names of the months
static std::string conversionTable[] = {"Error", "January", "February", 
					"March", "April", "May", "June",
					"July", "August", "September",
					"October", "November", "December"};

// Default constructor
Date::Date()
{
   month = 1;
   day = 1;
   year = 2017;
}

void Date::Initialize (int newMonth, int newDay, int newYear)
// Post: If newMonth, newDay and newYear represent a valid date,
//       year is set to newYear;
//       month is set to newMonth;
//       day is set to newDay;
//       otherwise a string exception is thrown, stating the
//       first incorrect parameter.
{
   using std::string;

   if (newMonth < 1 || newMonth > 12)
      throw string("Month is invalid");
   else if (newDay < 1 || newDay > daysInMonth[newMonth])
      throw string("Day is invalid");
   else if (newYear < 1583)
      throw string("Year is invalid");
   year = newYear;
   month = newMonth;
   day = newDay;
}

int Date::GetMonth() const
// Accessor function for data member month.
{
   return month;
}

std::string Date::GetMonthAsString() const
// Returns data member as a string
{
   return conversionTable[month];
}

int Date::GetYear() const
// Accessor function for data member year.
{
   return year;
}

int Date::GetDay() const
// Accessor function for data member day.
{
   return day;
}

std::string Date::ToString() const
{
   std::ostringstream ostr;
   ostr << GetMonthAsString() << " " << day << ", " << year;
   return ostr.str();
}

RelationType Date::ComparedTo(Date aDate) const
// Pre:  Self and aDate have been initialized.
// Post: Function value = LESS, if self comes before aDate.
//                      = EQUAL, if self is the same as aDate.
//                      = GREATER, if self comes after aDate.
{
   if (year < aDate.year)
      return LESS;
   else if (year > aDate.year)
      return GREATER;
   else if (month < aDate.month)
      return LESS;
   else if (month > aDate.month)
      return GREATER;
   else if (day < aDate.day)
      return LESS;
   else if (day > aDate.day)
      return  GREATER;
   else return EQUAL;
}

Date Date::Adjust(int daysAway) const
// Pre:  Self has been initialized
// Post: Function value = newDate daysAway from self
{
   int newDay = day + daysAway;
   int newMonth = month;
   int newYear = year;
   bool finished = false;
   int daysInThisMonth;
   Date returnDate;
   while (! finished)
   {
      daysInThisMonth = daysInMonth[newMonth];
      if (newMonth == 2)
	 if (((newYear % 4 == 0) && !(newYear % 100 == 0)) 
	     || (newYear % 400 == 0))
	    daysInThisMonth++;
      if (newDay <= daysInThisMonth)
	 finished = true;
      else
      {
	 newDay = newDay - daysInThisMonth;
	 newMonth = (newMonth % 12) + 1;
	 if (newMonth == 1)
	    newYear++;
      }
   }
  
   returnDate.Initialize(newMonth, newDay, newYear);
   return returnDate;
}

std::ostream& operator<< (std::ostream &out, Date aDate)
{
   out << aDate.month << '/' << aDate.day << '/' << aDate.year;
   return out;
}

std::istream& operator>> (std::istream &in, Date &aDate)
{
   in >> aDate.month; in.ignore();
   in >> aDate.day; in.ignore();
   in >> aDate.year;
   return in;
}
