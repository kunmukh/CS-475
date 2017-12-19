//File: document2.h
// Declare a document class program that allows a user
// to interactively edit a test file
//-----------------------------------------------------------------
// Class: CS 215                     Instructor: Dr. Deborah Hwang
// Assignment:    Project 5          Date assigned:  4/7/2017
// Programmer:    Kunal Mukherjee    Date completed: 4/16/2017

#include <string>
#include <iostream>
#include <algorithm>


#ifndef DOCUMENT_H
#define DOCUMENT_H


template<class T>
struct NodeType
{
  //The part to hold the data
  T info;
  //The next pointer
  NodeType<T>* next;
  //THe back pointer
  NodeType<T>* back;
};


class Document
{
 public:
  //Default Constructor
  Document();

  // Copy Constructor
  Document (const Document & original); //REC'D & PASSBK: the document class

  //Destructor
  ~Document();

  //Assignmnt operator
  Document & operator= (const Document & original);//REC'D & PASSBK: the document class

  //It reads lines from an input stream,
  //replacing any lines that already exists.
  void Load (std::istream &in);

  //Function clears the document of any lines
  void MakeEmpty();

  //Returns true if the document has no lines, false otherwise
  bool IsEmpty() const;

  //Inserts a line in front of the current line
  void Insert (std::string newLine); //REC'D: a string

  //Inserts a line at the end of he document
  void Append (std::string newLine);//REC'D: a string

  //Replace the content of the current line
  void Replace (std::string new_line);//REC'D: a string

  //removes the current line from the document
  void Erase();

  //finds the first line in the document containing the
  //target string and makes it the current line. Returns
  //true if the line is found or false
  bool Find (std::string target);//REC'D: a string

  //sets the current line (index) to n
  void SetCurrent( int n);//REC'D: a int or the number of places to move

  //moves the current line |n| places. If n> 0, it moves
  //in the forward direction, if n < 0, it moves in the
  //backward direction
  void MoveCurrent(int n);//REC'D: a int

  //writes the current line, including a newline, to an
  //output stream
  void WriteLine (std::ostream &out) const; //REC'D & PASSBK: the output stream

  //Writes the document to an output stream
  void WriteAll (std::ostream &out) const;//REC'D & PASSBK: the output stream
  

 private:
  NodeType<std::string>* headPtr; //pointing to the header node
  NodeType<std::string>* currentPtr; //pointing to the current node

};

#endif
