//File: edito2r.cpp
// A driver program written to test the document class and to create
// a editor program
//-----------------------------------------------------------------
// Class: CS 215                     Instructor: Dr. Deborah Hwang
// Assignment:    Project 6          Date assigned:  4/7/2017
// Programmer:    Kunal Mukherjee    Date completed: 4/16/2017

//directives are included
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "document2.h"

int main (int argc, char *argv[])
{
  using namespace std; //using the stadard namesspace
  
  if (argc != 2) // to see the proper usage in the commandline
    {
      cout << "Usage:" << argv[0] << "inputfile" << endl;
    }
  
  ifstream in(argv[1]); //open file  

  if (!in) //check for sucess
    {
      cout << "Error opening input file: " << argv[1] << endl;
    }
  
  //creating the document class
  Document text;
  text.Load(in);

  in.close();

  //the command
  char command;
  //the line to be entered or modified
  string line;
  //the number of line to be moved
  int n;

  //get command
  cout << "> ";
  cin >> command;
  
  while (toupper(command) != 'Q')
    {
      //display current line
      if (toupper(command) == 'C')
	{	 
	  try
	    {
	      text.WriteLine(cout);
	    }
	  catch (string exception)
	    {
	      cout << exception << endl;
	    }
	}

      // display entire document
      if (toupper(command) == 'P')
	{
	  text.WriteAll(cout);
	}

      //delete
      if (toupper(command) == 'D')
	{
	  try
	    {
	      text.Erase();
	    }
	  catch (string exception)
	    {
	      cout << exception << endl;
	    }
	}

      //empty
      if (toupper(command) == 'E')
	{	  
	      text.MakeEmpty();	   
	}
      
      // write document to file
      if (toupper(command) == 'W')
	{
	  cin.ignore();
	  getline(cin, line);
	  ofstream out2(line.c_str());  // open output file
	  if (!out2)
	    {
	      cout << "Could not open " << line << endl;	     
	    }
	  else
	    {
	      text.WriteAll(out2);
	      out2.close();
	    }
	}
      // load a new document
       if (toupper(command) == 'L')
      	{
	  cin.ignore();
      	  getline(cin, line);
      	  ifstream in2(line.c_str());
      	  if (!in2)
      	    {
      	      cout << "Error opening file " << line
      	  	   << ".  Try again" <<endl;
      	    }
	  else
	    {
	      text.MakeEmpty();
	      text.Load(in2);
	      in2.close();
	    }
      	}

	//insert
	if (toupper(command) == 'I')
	  {
	    cin.ignore();
	    getline(cin,line);
	    text.Insert(line);
	  }

	// append
	if (toupper(command) == 'A')
	  {
	    cin.ignore();
	    getline(cin, line);
	    text.Append(line);
	  }

	// replace
	if (toupper(command) == 'R')
	  {
	    cin.ignore();
	    getline(cin, line);
	    try
	      {
		text.Replace(line);
	      }
	    catch (const string exception)
	      {
		cout << exception << endl;
	      }
	  }

	// find
	if (toupper(command) == 'F')
	  {
	    cin.ignore();
	    getline(cin, line);
	    if (!text.Find(line))
	      cout << "Cannot find the line." << endl;
	  }
	
	//set the current line number
	if (toupper(command) == 'S')
	  {
	    cin.ignore();
	    cin >> n;
	    try
	      {
		text.SetCurrent(n);
	      }
	    catch (const string exception)
	      {
		cout << exception << endl;
	      }
	  }

	// move
	if (toupper(command) == 'M')
	  {
	    cin.ignore();
	    cin >> n;
	    try
	      {
		text.MoveCurrent(n);
	      }
	    catch (const string exception)
	      {
		cout << exception << endl;
	      }
	  }

	// help menu
	if (toupper(command) == 'H')
	  {
	    cout << "This line editor can do the following commands:"
		 << endl;
	    cout << endl;
	    cout << " L file    - load a text document from a file"
		 << endl;
	    cout << " E         - clear document" << endl;
	    cout << " I line    - insert a line in front of current line"
		 << endl;
	    cout << " A line    - append line to end of document"
		 << endl;
	    cout << " R line    - replace current line"
		 << endl;
	    cout << " D         - delete the current line"
		 << endl;
	    cout << " F target  - makes line containing target current line"
		 << endl;
	    cout << " S n       - set current line to nth line"
		 << endl;
	    cout << " M n       - move current line n places"
		 << endl;
	    cout << " C         - display current line to screen"
		 << endl;
	    cout << " P         - displace entire document to screen"
		 << endl;
	    cout << " W file    - write document to file"
		 << endl;
	    cout << " H         - display this list of commands"
		 << endl;
	    cout << " Q         - quit the editor (does not save changes)"
		 << endl;
	    cout << endl;
	}

	if (toupper(command) != 'L' &&
	    toupper(command) != 'E' &&
	    toupper(command) != 'I' &&
	    toupper(command) != 'A' &&
	    toupper(command) != 'R' &&
	    toupper(command) != 'D' &&
	    toupper(command) != 'F' &&
	    toupper(command) != 'S' &&
	    toupper(command) != 'M' &&
	    toupper(command) != 'C' &&
	    toupper(command) != 'P' &&
	    toupper(command) != 'W' &&
	    toupper(command) != 'H' &&
	    toupper(command) != 'Q' )
	    
	  {
	    cout << "Incorrect Command" << endl;
	  }
	// get next command from user
	cout << "> ";
	cin >> command;
      };
     
    }



	
  

  
