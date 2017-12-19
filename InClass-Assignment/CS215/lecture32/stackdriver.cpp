// File: stackdriver.h
// Test program for StackedType class
// Based on Dale, et al., C++ Plus Data Structures 6/e, Chapter 5

#include <iostream>
#include "stack.h"

int main()
{
   using namespace std;
   string command;        // operation to be executed
  
   int item;
   StackType<int> stack;
   string strItem;
   StackType<string> strStack;

   cout << "Enter a StackType operation: ";
   cin >> command;

   while (command != "Quit")
   { 
      try 
      {
	 if (command == "Push")
	 {
	    cout << "Enter an integer item: ";
	    cin >> item; 
	    stack.Push(item);
	    cout << "Enter a string item: ";
	    cin>> strItem;
	    str.Stack.Push(strItem);
	 }
	 else if (command == "Pop")
	    stack.Pop();
	 else if (command == "Top")
	 {
	    item = stack.Top(); 
	    cout << "Top element is " << item << endl;
	 } 
	 else if (command == "IsEmpty") 
	    if (stack.IsEmpty())
	       cout << "Stack is empty." << endl;
	    else 
	       cout << "Stack is not empty." << endl;
	 else if (command == "IsFull")
	    if (stack.IsFull())
	       cout << "Stack is full." << endl;
	    else
	       cout << "Stack is not full."  << endl;  
	 else
	    cout << command << " not found" << endl;
      }
      catch (FullStack)
      {
	 cout << "FullStack exception thrown." << endl;
      }
      catch (EmptyStack)
      {
	 cout << "EmptyStack exception thrown." << endl;
      }    

      cout << "Enter a StackType operation: ";
      cin >> command;
   }
 
   cout << "Testing completed."  << endl;
   return 0;
}
