//File: document.h
// Declare a document class program that allows a user
// to interactively edit a test file
//-----------------------------------------------------------------
// Class: CS 215                     Instructor: Dr. Deborah Hwang
// Assignment:    editor             Date assigned:  2/23/2017
// Programmer:    Kunal Mukherjee    Date completed: 2/28/2017

#include <string>
#include <iostream>
#include <vector>

#ifndef DOCUMENT_H
#define DOCUMENT_H

class Document
{
 public:
  //The default constructor
  Document();

  //It reads lines from an input stream,
  //replacing any lines that already exists.
  void Load (std::istream &in);

  //Function clears the document of any lines
  void MakeEmpty();

  //Returns true if the document has no lines, false otherwise
  bool IsEmpty() const;

  //Inserts a line in front of the current line
  void Insert (std::string newLine);

  //Inserts a line at the end of he document
  void Append (std::string newLine);

  //Replace the content of the current line
  void Replace (std::string new_line);

  //removes the current line from the document
  void Erase();

  //finds the first line in the document containing the
  //target string and makes it the current line. Returns
  //true if the line is found or false
  bool Find (std::string target);

  //sets the current line (index) to n
  void SetCurrent( int n);

  //moves the current line |n| places. If n> 0, it moves
  //in the forward direction, if n < 0, it moves in the
  //backward direction
  void MoveCurrent( int n);

  //writes the current line, including a newline, to an
  //output stream
  void WriteLine (std::ostream &out) const;

  //Writes the document to an output stream
  void WriteAll (std::ostream &out) const;		    

  
 private:

  //The vector to store new lines
  std::vector<std::string> lines;
  //The current linex index unless the vector is empty
  int currentPos; 

};

#endif
