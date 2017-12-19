// File: problem1.cpp
// A program that tests ExchangeSort
//
// Class: CS 215                     Instructor: Dr. Deborah Hwang
// Date: March 28 & 30, 2017
// Assignment: Practical Exam 2, Problem 1
// Programmer: KUnal Mukherjee

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

void ReadVector (std::vector<int> & v, std::istream & in);
void WriteVector (std::vector<int> theVector, std::ostream& out);
void ExchangeSort (std::vector<int> &theVector);

int main (int argc, char* argv[])
{
   using namespace std;
   if (argc != 3)
     {
       cout << "Usage" << argv[0] << "inputfile outfile" << endl;
       return 0;
     }

   ifstream infile(argv[1]);
   
   if(!infile)
     {
       cout << "Error opening input file" << endl;
       return 0;
     }

   ofstream outfile (argv[2]);
   if(!outfile)
     {
       cout << "Error opening output file" << endl;
       return 0;
     }

   vector<int> theVector;


   // Read in data from file
   ReadVector (theVector, infile);

   // Write the data to the screen
   cout << "The elements of vector v are: " << endl;
   // *** WRITE CALL TO WriteVector TO DISPLAY ON SCREEN HERE ***
   WriteVector (theVector, cout);

   // Sort the data
   // *** WRITE CALL TO ExchangeSort HERE ***
   ExchangeSort(theVector);


   // Write the sorted data to the file
   outfile << "\nAfter sorting, the elements of vector v are: " << endl;
   // *** WRITE CALL TO WriteVector TO WRITE TO OUTPUT FILE HERE ***
  WriteVector (theVector, outfile);
 
   return 0;
}

void ReadVector (std::vector<int> & v, std::istream & in)
{
   int value;
   v.clear();
   while (in >> value)
      v.push_back(value);
}

// *** WRITE THE WriteVector FUNCTION DEFINITION HERE ***
void WriteVector (std::vector<int> theVector, std::ostream & out)
{
  
  for (int i = 0;i < theVector.size(); i++)
    {
      int temp;
      temp = theVector[i];
      out << temp << std::endl;
    }
}
      


// *** WRITE THE ExchangeSort FUNCTION DEFINITION HERE ***
void ExchangeSort (std::vector<int> & theVector)
{
  int temp;
  int counter = 0;
  int size = theVector.size();
  
  while (theVector[counter] && size != 0)
    {
      for (int i =0; i < theVector.size(); i++)
	{
	  if (theVector[counter] < theVector[i])
	    {
	      temp = theVector[i];
	      theVector[i] = theVector[counter];
	      theVector[counter] = temp;	      
	    }	   
	    
	}
      counter++;
      size--;
    }
}

