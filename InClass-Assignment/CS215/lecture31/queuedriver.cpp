// File: queuedriver.h
// Test program for QueueType class
// Based on Dale, et al., C++ Plus Data Structures 6/e, Chapter 5

#include <iostream>
#include "queue.h"

int main()
{
   using namespace std;
   string command;        // operation to be executed
  
   int item;
   QueueType queue;

   cout << "Enter a QueueType operation: ";
   cin >> command;

   while (command != "Quit")
   { 
      try 
      {
	 if (command == "Enqueue")
	 {
	    cout << "Enter an item: ";
	    cin >> item; 
	    queue.Enqueue(item);
	    cout << item << " is enqueued." << endl;
	 }
	 else if (command == "Dequeue")
	 {
	    queue.Dequeue(item);
	    cout << item << " is dequeued." << endl;
	 }
	 else if (command == "IsEmpty") 
	    if (queue.IsEmpty())
	       cout << "Queue is empty." << endl;
	    else 
	       cout << "Queue is not empty." << endl;
	 else if (command == "IsFull")
	    if (queue.IsFull())
	       cout << "Queue is full." << endl;
	    else
	       cout << "Queue is not full."  << endl;  
	 else
	    cout << command << " not found" << endl;
      }
      catch (FullQueue)
      {
	 cout << "FullQueue exception thrown." << endl;
      }
      catch (EmptyQueue)
      {
	 cout << "EmptyQueue exception thrown." << endl;
      }    

      cout << "Enter a QueueType operation: ";
      cin >> command;
   }
 
   cout << "Testing completed."  << endl;
   return 0;
}
