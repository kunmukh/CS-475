// File: listdriver.cpp
// Test driver for UnsortedType list class, reads items from a list
// Usage: ./listdriver inputfile
// Based on Dale, et al., C++ Plus Data Structures 6/e, Chapter 3

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>

#include "unsorted.h"
#include "date.h"
#include "itemtype.h"



// Function: prints the items in an UnsortedType list
void PrintList(std::ostream& out,   // REC'D/P'BACK: ouput stream
	       UnsortedType& list); // REC'D/P'BACK: list to be printed

int main(int argc, char *argv[])
{
   using namespace std;

   if (argc != 2)
   {
      cout << "Usage: " << argv[0] << " inputfile" << endl;
      exit(1);
   }

   ifstream inFile(argv[1]);       // file containing operations
   if(!inFile)
   {
      cout << "Error opening input file" << argv[2] << endl;
      exit(2);
   }

   int month, day, year;
   Date item;
   UnsortedType list;
   while (inFile >> month >> day >> year)
   {
     item.Initialize (month, day, year);
      list.PutItem(item);
   }

   bool found;
   string command;

   do {
      cout << "Enter an UnsortedType operation: ";
      cin >> command;

      if (command == "PutItem")
      {
	 cout << "Enter an item value: ";
	 cin >> month >> day >> year; 
	 item.Initialize(month, day, year);
	 list.PutItem(item);
	 cout << item << " is in list." << endl;
      }
      else if (command == "DeleteItem")
      {
	 cout << "Enter an item value: ";
	 cin >> month >> day >> year; 
	 item.Initialize(month, day, year);
	 list.DeleteItem(item);
	 cout << item << " is deleted." << endl;
      }
      else if (command == "GetItem")
      {
	 cout << "Enter an item value: ";
	 cin >> month >> day >> year; 
	 item.Initialize(month, day, year);
	 item = list.GetItem(item, found);
	 if (found)
	   cout << item << " was found in list." << endl;
	 else
	   cout << item << " was not in list."  << endl;  
      } 
      else if (command == "GetLength")  
	 cout << "Length is " << list.GetLength() << endl;
      else if (command == "IsFull")
	 if (list.IsFull())
	    cout << "List is full." << endl;
	 else
	    cout << "List is not full."  << endl;  
      else if (command == "MakeEmpty")
	 list.MakeEmpty();
      else if (command == "PrintList")
	 PrintList(cout, list);
      else if (command != "Quit")
	 cout << " Command not recognized." << endl;

   } while (command != "Quit");
 
   cout << "Testing completed."  << endl;
   return 0;
}


// Function: prints the items in the list to an output stream
// Assumes: stream is open for writing.   
void PrintList(std::ostream& out, UnsortedType& list)
{
   using std::endl;

   int length;
   ItemType item;
   out << "PrintList" << endl;
   // ADD CODE TO PRINT LIST HERE
   length = list.GetLength();
   list.Reset();
   for(int i=0; i<length; i++)
     out << list.GetNextItem() << endl;
}
