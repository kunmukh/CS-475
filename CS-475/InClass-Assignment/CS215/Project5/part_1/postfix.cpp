// File: postfix.cpp
// This programs taken in a postfix expression and 
// evaluates the result
// ­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­
// Class: CS 215                     Instructor: Dr. Deborah Hwang
// Assignment: Programming Project 5 Date assigned: 3/31/2017
// Programmer: Kunal Mukherjee       Date completed:4/4/2017
//-------------------------------------------------------------------

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cctype>
#include <stack>
#include <cstdlib>

double EvaluatePostfix (std::string s1); // REC'D - a string and return double



int main(int argc, char *argv[])
{
   using namespace std;

   if (argc != 3)   // Check to see if all commandline
                    //argumenst have been correctly entered
   {
     cout << "Usage: " << argv[0] << " inputfile outfile"
	  <<  endl;
      exit(1);
   }
   
   ifstream inFile (argv[1]);   //Check to see if the input file opens correctly
   if (!inFile)
   {
      cout << "Error: unable to open input File" << endl;
      exit(1);
   }

   ofstream outFile (argv[2]); //Check to see of the output file opens correctly            
   if (!outFile)                 
    {
       cout << "Error: unable to open output File" << argv[2] << endl;
       exit(1);
    }

   string s1; // a string is created

   while (getline(inFile, s1)) //get the line from the document
     {      
       double result;
       try
	 {
	   result = EvaluatePostfix(s1); //check to see if a result is found
	   outFile << result << endl; // print the result to the outfile
	 }
       catch (string exception) // if a exception is caught 
	 { 
	   outFile << exception << endl; // print the exception
	 }
     }

   // the files are close
   inFile.close();
   outFile.close();
   return 0;
}

double EvaluatePostfix (std::string s1)
{

  std::stack<double> value; //a stack declaration
  
  double result; // declaration of a real number
  double temp_1; // declaration of the first temporary stoarage variable
  double temp_2; // declaration of the second temporaray storage variable
  double first; // check to see if the first character is a digit or not
  
  first = s1[0] - '0'; // checks the first digit
  
  if (first < 0 || first > 10) // if the first character is not a digit
                               // then it should throw an exception
    {
      throw std::string("Invalid input");      
    }
  
  
  for (int i = 0; i < s1.size(); i++) // go through the entire string
    {
      if (s1[i] == ' ') // to ignore the empty spaces
	result = 0;
      
      else if(isdigit(s1[i])) // if it is a digit then it should be placed
	// into the stack
	{
	  value.push(s1[i]); // the characters are pushed into
	}
      
      else if(ispunct(s1[i])) // check to see if it is an character
	                      //or expression
	{	 
	 
	  temp_1 = (value.top() - '0'); // find the temprary value
	  
	  if (temp_1 < -10 || temp_1 > 10) // if the value is more than
	    // single digits then it shouldnot be converted to single digits
	    temp_1 = value.top();
	  
	  
	  value.pop(); // then should then remove the first value

	  if (value.empty()) // if the stack is empty then it means the
	    //stack was incorrectly formed
	    {
	      throw std::string("Invalid input");      
	    }	  
	 
	  temp_2 = (value.top() - '0'); //convert the second digit
	  
	  if (temp_2 < -10 || temp_2 > 10) 
	    temp_2 = value.top();
	  
	 
	  value.pop();
	  
	  //the expressions are evaluated here and placed inside the stack
	  
	  if (s1[i] == '*') 
	    value.push(temp_1 * temp_2);

	  if (s1[i] == '/')
	    value.push(temp_2 / temp_1);

	  if (s1[i] == '+')
	    value.push(temp_1 + temp_2);

	  if (s1[i] == '-')
	    value.push(temp_2 - temp_1);	       
	}
    }
  
  //the result if the last value left
  result = (value.top());
  //the stack is made empty and it should happen if the expression is
  // correctly formed
  value.pop();

  if (!value.empty()) //if it is not empty then an exception is thrown
    {
      throw std::string("Invalid input");      
    }

  return result; // if everything goes back great then the result is sent back
}

 
