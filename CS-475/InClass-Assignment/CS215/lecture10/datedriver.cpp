//  File: datedriver.cpp
//  Program to test Date class
//  Based on Dale, et al., C++ Plus Data Structures, Chapter 2 Case Study

#include <iostream>
#include "date.h"

int main()
{
   using namespace std;

   int month, day, year;
   Date date, date2;
  
   cout << "Input a month, day, and year on one line" << endl;
   cin >> month >> day >> year;
   try{
   date.Initialize(month, day, year);
   cout << "Initialize: " << date.GetMonthAsString() << " "
	<< date.GetDay() << ", "
	<< date.GetYear() << endl;	
   }
   catch (string ex)
     {
       cout << ex << endl;
     }
   
   cout << "GetMonth: "<< date.GetMonth() << endl;
   cout << "GetDay: " << date.GetDay() << endl;
   cout << "GetYear: "<< date.GetYear() << endl;
   cout << "GetMonthAsString: " << date.GetMonthAsString() << endl;

   // cout << "Input a month, day, and year on one line" << endl;
   //cin >> month >> day >> year;

   bool valid = false;
   while (!valid)
     {
       try
	 {
	   
   cout << "Input a date (mm/dd/yyyy) : ";
   cin >> month >> day >> year;   
   date2.Initialize(month, day, year);
   valid = true;
	 }
       catch (string ex)
	 {
	   cout << ex << endl;
	 }
     }
   
   // cout << "Second date: " << date2.GetMonthAsString() << " "
   // 	<< date2.GetDay() << ", "
   //  	<< date2.GetYear() << endl;

   cout << "Second date: " << date2 << endl;

   switch(date.CompareTo(date2)){
     case LESS:
       cout <<  date.GetMonthAsString() << " "
	    << date.GetDay() << ", "
	    << date.GetYear() << " is before "
	    << date2.GetMonthAsString() << " "
	    << date2.GetDay() << ", "
	    << date2.GetYear() << endl;
     case EQUAL:
       cout <<  date.GetMonthAsString() << " "
	    << date.GetDay() << ", "
	    << date.GetYear() << " is equal to "
	    << date2.GetMonthAsString() << " "
	    << date2.GetDay() << ", "
	    << date2.GetYear() << endl;

     case GREATER:
       // cout <<  date.GetMonthAsString() << " "
       // 	    << date.GetDay() << ", "
       // 	    << date.GetYear() << " is after "
       // 	    << date2.GetMonthAsString() << " "
       // 	    << date2.GetDay() << ", "
       // 	    << date2.GetYear() << endl;
       cout << date << " is after " << date2 << endl;
   }
   return 0;
}
