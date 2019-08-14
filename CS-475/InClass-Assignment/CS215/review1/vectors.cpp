// File: vectors.cpp
// Driver for CS 215 Homework 5 vector problems

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "date.h"

void ReadIntoIntVector (std::vector<int> & v, std::istream &in);
void ReadIntoDateVector (std::vector<Date> & v, std::istream &in);
void PrintIntVector(std::vector<int> v);
void PrintDateVector(std::vector<Date> v);
void ReverseVector(std::vector<int> &v);


int main ()
{
   using namespace std;
   vector<int> intVector;
   vector<Date> dateVector;
   string filename;

   ifstream integers;
   do
   {
      cout << "Enter the name of a file of integers: ";
      cin >> filename;
      integers.open (filename.c_str());
      if (!integers)
	 cout << "Error opening file " << filename << ".  Try again" <<endl;
   } while (!integers);
   ReadIntoIntVector (intVector, integers);
   PrintIntVector(intVector);
   ReverseVector(intVector);
   PrintIntVector(intVector);
      
   ifstream dates;
   do
   {
      cout << "Enter the name of a file of dates: ";
      cin >> filename;
      dates.open (filename.c_str());
      if (!dates)
	 cout << "Error opening file " << filename << ".  Try again" <<endl;
   } while (!dates);
   ReadIntoDateVector (dateVector, dates);
   PrintDateVector(dateVector);
   
   return 0;
}

void ReverseVector(std::vector<int> &v)
{
  int temp;
  //iterate through half of the vector
  for (int i = 0; i < v.size()/2 ; i++)
    { //swap the "ends"
      temp = v[i];
      v[i] = v [v.size() -1 -i ];
      v [v.size() -1-i ] = temp;
    }
}

void ReadIntoIntVector (std::vector<int> & v, std::istream &in)
{
   int value;

   // make vector empty
   v.clear();

   // read in values
   while (in >> value)
      v.push_back(value);
}  // end read_vector_from_file

void ReadIntoDateVector (std::vector<Date> & v, std::istream &in)
{
   Date value;

   // make vector empty
   v.clear();

   // read in values
   while (in >> value)
      v.push_back(value);
}  // end read_vector_from_file

void PrintIntVector(std::vector<int> v)
{
   using namespace std;
   cout << "IntVector" << endl;
   for (int i = 0; i < v.size(); i++)
      cout << v[i] << endl;
}

void PrintDateVector(std::vector<Date> v)
{
   using namespace std;
   cout << "DateVector" << endl;
   for (int i = 0; i < v.size(); i++)
      cout << v[i] << endl;
}
