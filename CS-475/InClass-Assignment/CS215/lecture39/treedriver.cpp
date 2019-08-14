// File: treedriver.cpp
// Test driver for TreeType, a binary search tree class
// Usage: ./treedriver
// Based on Dale, et al., C++ Plus Data Structures 6/e, Chapter 8

#include <iostream>
#include <string>

#include "tree.h"

void TraverseTree (TreeType &tree, std::ostream & out);

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
      cout << "Error opening input file" << argv[1] << endl;
      exit(2);
   }

   char item;             // ItemType is char
   TreeType tree;
   while (inFile >> item)
      tree.PutItem(item);

   bool found;
   string command;        // operation to be executed

   do  { 
      cout << "Enter a TreeType operation: ";
      cin >> command;

      if (command == "Copy")
      {
         TreeType copy = tree;
         cout << "Copied tree" << endl;
         copy.Print (cout);
	 cout << endl;
      }
      else if (command == "Assign")
      {
         TreeType assigned;
         assigned = tree;
         cout << "Assigned tree" << endl;
         assigned.Print (cout);
	 cout << endl;
      }
      else if (command == "PutItem")
      {
         cout << "Enter an item value: ";
         cin >> item; 
         tree.PutItem(item);
         cout << item << " is inserted." << endl;
      }
      else if (command == "DeleteItem")
      {
         cout << "Enter an item value: ";
         cin >> item; 
         tree.DeleteItem(item);
	 cout << item << " is deleted" << endl;
      }
      else if (command == "GetItem")
      {
         cout << "Enter an item value: ";
         cin >> item; 
	 item = tree.GetItem(item, found);
	 if (found)
	    cout << item << " found in list." << endl;
	 else
	    cout << item  << " not in list."  << endl;  
      } 
      else if (command == "GetLength")  
	 cout << "Number of nodes is " << tree.GetLength() << endl;
      else if (command == "IsEmpty")
	 if (tree.IsEmpty())
	    cout << "Tree is empty." << endl;
	 else
	    cout << "Tree is not empty."  << endl;  
  
      else if (command == "Print")
      {
	 tree.Print(cout);
	 cout << endl;
      }  
      else if (command == "TraverseTree")
      {
	 TraverseTree(tree, cout);
      }
      else if (command == "IsFull")
	 if (tree.IsFull())
	    cout << "Tree is full."  << endl;
	 else
	    cout << "Tree is not full." << endl;  
      else if (command == "MakeEmpty")
      {
	 tree.MakeEmpty();
	 cout << "Tree has been made empty." << endl;
      }  
      else if (command != "Quit")
         cout << " Command not recognized." << endl;

   }   while (command != "Quit");
 
   cout << "Testing completed."  << endl;
   return 0;
}

void TraverseTree (TreeType &tree, std::ostream & out)
{
   using namespace std;

   string orderItem;
   OrderType order;
   bool finished = false;
   char item;

   cout << "Enter an order value (PRE_ORDER, IN_ORDER, or POST_ORDER): ";
   cin >> orderItem;
   if (orderItem == "PRE_ORDER")
      order = PRE_ORDER;
   else if (orderItem == "IN_ORDER")
      order = IN_ORDER;
   else
      order = POST_ORDER;    
   
   tree.ResetTree(order);
   while (!finished)
   {
      item = tree.GetNextItem(order,finished);
      out << " " << item;
   }
   out << endl << orderItem << " traversal is complete." << endl;
}
