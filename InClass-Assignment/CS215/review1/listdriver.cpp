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

   int number;
   ItemType item;
   UnsortedType list;
   while (inFile >> number)
   {
      item.Initialize (number);
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
	 cin >> number; 
	 item.Initialize(number);
	 list.PutItem(item);
	 cout << item << " is in list." << endl;
      }
      else if (command == "DeleteItem")
      {
	 cout << "Enter an item value: ";
	 cin >> number; 
	 item.Initialize(number);
	 if (list.IsThere(item))
	   {
	     list.DeleteItem(item);
	     cout << item << " is deleted." << endl;
	   }
	 else
	   cout << item << " is not in this list." << endl;
      }
      else if (command == "GetItem")
      {
	 cout << "Enter an item value: ";
	 cin >> number; 
	 item.Initialize(number);
	 item = list.GetItem(item, found);
	 if (found)
	    cout << number << " found in list." << endl;
	 else
	    cout << number  << " not in list."  << endl;  
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
   list.ResetList();
   length = list.GetLength();
   if (length == 0)
      out << "List is empty." << endl;
   else
      for (int counter = 0; counter < length; counter++)
      {
	 item = list.GetNextItem();
	 out << item << endl;
      }
}

//Free function version
void  SplitLists(UnsortedType list, ItemType item,
		 UnsortedType& list1, UnsortedType& list2)
{
  ItemType info;
  list.ResetList();
  length = list.GetLength();
  for (int counter = 0;counter < length; counter++)
    {
      info = list.GetNextItem();
      if (item.ComparedTo(info) == GREATER)
	{
	  //put info[i] into list2
	  list2.PutItem(info[i]);
	}
      else
	{
	  //put info[i] into list1
	  list1.PutItem(info);
	}
    }
}
