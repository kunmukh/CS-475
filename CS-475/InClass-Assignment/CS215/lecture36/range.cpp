// File: range.cpp
// Must be compiled with -std=c++11
// Examples of range-based for-loops, STL iterators, and auto type

#include <iostream>
#include <list>   // STL list<T>
#include <vector> // STL vector<T>

int main()
{
   using namespace std;
   
   int numArray[] = {1, 2, 3, 4, 5};  // typo p. 408, missing []
   cout << "Elements of numArray, using range-based for-loop" << endl;
   //"for each element e of numArray"
   //for (<element declaration>: <collection>)
   for (int e: numArray)
     cout << e << endl;
   
   // Initialization syntax for vectors and lists introduced in C++11
   list<int> numList = {16, 27, 42, 56, 75};
   

   cout << "Elements of numList, using an explicit iterator" << endl;
   for (list<int>::iterator iter = numList.begin(); //'pointer' to first item
	iter != numList.end(); // 'end' is "pointer" to one past the last item
	iter++) // 'increment' to the next item
     {
       cout << *iter << endl; //derefrence to get the item
     }
   
   cout << "Elements of numList, using range-based for-loop" << endl;
   for (int e: numList)
     cout << e << endl;

   
   vector<double> numVector = {85, 34, 53, 12, 61};

   cout << "Elements of numVector, using an explicit iterator" << endl;

   
   cout << "Elements of numVector, using range-based for-loop and auto" << endl;

   
   return 0;
}
