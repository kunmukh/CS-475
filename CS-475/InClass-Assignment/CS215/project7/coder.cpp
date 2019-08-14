//File: coder.cpp
// A driver program written to test the huffman  class and to create
// a binary tree of huffman code
//-----------------------------------------------------------------
// Class: CS 215                     Instructor: Dr. Deborah Hwang
// Assignment:    Project 7          Date assigned:  4/19/2017
// Programmer:    Kunal Mukherjee    Date completed: 4/26/2017

//directives are included
#include <string>
#include <iostream>
#include <fstream>

#include "huffman.h"

int main (int argc, char *argv[])
{
  using namespace std; //using the stadard namesspace
  
  if (argc != 2) // to see the proper usage in the commandline
    {
      cout << "Usage:" << argv[0] << "codefile" << endl;
    }
  
  ifstream in(argv[1]); //open file  

  if (!in) //check for sucess
    {
      cout << "Error opening code file: " << argv[1] << endl;
    }
  
  //creating the huffman  class
  HuffmanTree tree;
  tree.Load(in);
  tree.Write(cout);

  in.close();

  char command;
  string line, line2;

  cout << "Please choose one of:" << "\n"
       << "\n" << " " << "E - Encode a message"
       << "\n" << " " << "D - Decode a message"
       << "\n" << " " << "Q - Quit the program" << endl;

  cout << "Enter your choice: ";
  cin >> command;

   while (toupper(command) != 'Q')
    {
      if (toupper(command) == 'E')
	{
	  cout << "Enter the name of a plaintext message file: ";
	  getline(cin, line);
	  cout << "Enter the name of output file: ";
	  getline(cin, line2);
      	  ifstream in2(line.c_str());
	  ofstream in3(line2.c_str());
      	  if (!in2)
      	    {
      	      cout << "Error plaintext message file " << line
      	  	   << ".  Try again" <<endl;
      	    }
	  if (!in3)
      	    {
      	      cout << "Error output " << line
      	  	   << ".  Try again" <<endl;
      	    }
	  else
	    {
	      tree.MakeEmpty();
	      tree.Encode(in2,in3 );
	      in2.close();
	    }	    
	}

      if (toupper(command) == 'D')
	{
	  cout << "Enter the name of a compressed message file: ";
	  getline(cin, line);
	  cout << "Enter the name of output file: ";
	  getline(cin, line2);
      	  ifstream in2(line.c_str());
	  ofstream in3(line2.c_str());
      	  if (!in2)
      	    {
      	      cout << "Error compressed message file " << line
      	  	   << ".  Try again" <<endl;
      	    }
	  if (!in3)
      	    {
      	      cout << "Error output " << line
      	  	   << ".  Try again" <<endl;
      	    }
	  else
	    {
	      tree.MakeEmpty();
	      tree.Decode(in2,in3);
	      in2.close();
	    }	    
	}

      if (toupper(command) != 'E' &&
	  toupper(command) != 'Q' &&
	  toupper(command) != 'D' )
	    
	  {
	    cout << "Incorrect Command" << endl;
	  }

      cout << "Please choose one of:" << "\n"
	   << "\n" << " " << "E - Encode a message"
	   << "\n" << " " << "D - Decode a message"
	   << "\n" << " " << "Q - Quit the program" << endl;

      cout << "Enter your choice: ";
      cin >> command;
    };
}

      

      

  
