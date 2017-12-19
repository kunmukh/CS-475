// File: template-functions.cpp
// Examples of function templates to read data into a vector from keyboard
// and print data back out on screen

#include <iostream>
#include <vector>
#include <string>
#include "date.h"

template<class T>
void FillVector(std::vector<T> & v,  // P'Back: vector to fill
		int n)                 // Rec'd: number of items to read
{
   v.clear();
   T item;
   for (int i = 0; i < n; i++)
   {
      std::cout << "Enter an item: ";
      std::cin >> item;
      v.push_back(item);
   }
}

template<class T>
void PrintVector(const std::vector<T> & v) // Rec'd: vector to print
{
   for (int i = 0; i < v.size(); i++)
      std::cout << v[i] << std::endl;
}

int main ()
{
   using namespace std;

   vector<int> vec;
   vector<string> strVec;
   vector<Date> dateVec;
   
   cout << "Fill vector vec with 5 integers" << endl;
   FillVector(vec, 5);

   cout << "\nVector vec elements are:" << endl;
   PrintVector(vec);

   cout << "Fill vector strVec with 3 strings" << endl;
   FillVector(strVec, 3);

   cout << "\nVector strVec elements are:" << endl;
   PrintVector(strVec);

    cout << "Fill vector dateVec with 2 dates" << endl;
   FillVector(dateVec, 2);

   cout << "\nVector dateVec elements are:" << endl;
   PrintVector(dateVec);

   return 0;
}
