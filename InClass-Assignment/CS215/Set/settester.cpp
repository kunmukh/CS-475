//File: settester.cpp
// A main program file is written to test the SetCard.cpp
//
//-----------------------------------------------------------------
// Class: CS 215                     Instructor: Dr. Deborah Hwang
// Assignment:    settester.cpp      Date assigned:  2/2/2017
// Programmer:    Kunal Mukherjee    Date completed: 9/2/2017


//directives are included
#include <iostream>
#include <fstream>
#include <iostream>
#include <sstream>
#include "setcard.h"

int main (int argc, char *argv[])
{
  using namespace std; //using the stadard namesspace
  
  if (argc != 3) // to see the proper usage in the commandline
    {
      cout << "Usage:" << argv[0] << "inputfile outputfile" << endl;
    }
  
  ifstream inFile (argv[1]); //open file

  if (!inFile) //check for sucess
    {
      cout << "Error opening input file: " << argv[1] << endl;
    }

  ofstream outFile (argv[2]);

  if (!outFile)
    {
      cout << "Error opening output file: " << argv[2] << endl;
    }

  SetCard card, card2, card3;

  int num;  //the number of setcard sets in the input file
  inFile >> num; 

  outFile << "SET TESTER" << endl; //a message to be printed in the
                                   // output file  
  
  for (int i = 0; i < num; i++)  //so that all the card are in the input
                                  // are read
    {

      inFile >> card >> card2 >> card3 ; //the overloader operator reads in the
                                         //encoded message from the file

      if(card.IsSet(card2, card3))  //it checks if the cards make a set or not
    {    
      // prints out the encoded message in expanded form and lets the
      //result out- "has it made a set or not"
      outFile << endl;
      outFile << card << " " << ":" << " " << card.ToString() << endl;
      outFile << card2 << " " << ":" << " " << card2.ToString() << endl;
      outFile << card3 << " " << ":" << " " << card3.ToString() << endl;
      outFile << "make up a set" << endl;
     
    }
      
  else
    {
      outFile << endl;
      outFile << card << " " << ":" << " " << card.ToString() << endl;
      outFile << card2 << " " << ":" << " " << card2.ToString() << endl;
      outFile << card3 << " " << ":" << " " << card3.ToString() << endl;
      outFile << "do not make up a set" << endl;
      
    }
  }

  //closes file
  
    inFile.close(); 
    outFile.close();
    return 0;
    
}
  




