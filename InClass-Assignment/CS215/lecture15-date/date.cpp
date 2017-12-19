// File: date.cpp
// Contains the implementation of class Date
// Based on Dale, et al., C++ Plus Data Structures, Chapter 2 Case Study

#include "date.h"

// Names of the months
static std::string conversionTable[] = {"Error", "January", "February", 
					"March", "April", "May", "June",
					"July", "August", "September",
					"October", "November", "December"};


// to tell compiler that these functions belong to the class
// use <classname> :: in front of operation names
// allows functions to access the class data attributes directly

Date::Date(){
  month = 1;
  day = 1;
  year = 2017;
}

void Date::Initialize (int newMonth, int newDay, int newYear)
{
  if(newMonth<1 or newMonth>12)
    throw std::string("Date::Initialize() - error in newMonth value.");
  if(newDay<1 or newDay>31)
    throw std::string("Date::Initialize() - error in newDay value.");
  if(newYear<1583)
    throw std::string("Date::Initialize() - error in newYear value.");
  month = newMonth;
  day = newDay;
  year = newYear;
}

int Date::GetMonth() const
{
   return month;
}

std::string Date::GetMonthAsString() const // :: is called scope operator
{
   return conversionTable[month];
}

int Date::GetYear() const
{
   return year;
}

int Date::GetDay() const
{
   return day;
}

//const goes in both prototype and function definition
RelationType Date::ComparedTo(Date rhs) const{
  if(year < rhs.GetYear())
    return LESS;
  if(year > rhs.GetYear())
    return GREATER;
  if(month < rhs.GetMonth())
    return LESS;
  if(month > rhs.GetMonth())
    return GREATER;

  if(day < rhs.GetDay())
    return LESS;
  if(day > rhs.GetDay())
    return GREATER;

  return EQUAL;
}

//friend functions are not member functions, so there is no scope operator
//NOTE: no scope operator for friend operators/functions
//no friend keyword either
std::istream& operator>>(std::istream& in, Date& aDate){
  //in >> aDate.month >> aDate.day >> aDate.year;
  in >> aDate.month;
  in.ignore();
  in >>aDate.day;
  in.ignore();
  in >> aDate.year;
  return in;
}
std::ostream& operator<<(std::ostream& out, Date aDate){
  out << aDate.GetMonth() << " / " << aDate.GetDay() << " / " << aDate.GetYear();
  return out;
}
