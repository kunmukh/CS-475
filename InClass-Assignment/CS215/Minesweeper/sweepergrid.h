//File: sweepergrid.h
// Declare a sweepergrid class program that allows a user
// enter the number of row,col and bombs to play minesweeper 
//-----------------------------------------------------------------
// Class: CS 215                     Instructor: Dr. Deborah Hwang
// Assignment:    Minesweeper        Date assigned:  3/17/2017
// Programmer:    Kunal Mukherjee    Date completed: 2/24/2017

#include <iostream>

#ifndef SWEEPERGRID_H
#define SWEEPERGRID_H

#include "sweepercell.h"

class SweeperGrid
{
 public:
  //Explicit-Value Constructor
  //Function: takes the number of rows and cols and places bombs
  SweeperGrid(int initialRows, //intial number of rows are RECD
	      int initialCols, //intial number of cols are RECD
	      int initialBombs); //intial number of bombs are RECD

  //Default Constructor
  //Function:creates a SweeperGrid with 8 rows, 8 cols and 10 bombs
  SweeperGrid();

  //Destructor
  //Function: Deallocates the grid array
  ~SweeperGrid();

  //GetRows
  //Function: returns the number of rows in the grid
  int GetRows() const;

  //GetColumns
  //Function: returns the number of columns in the grid
  int GetColumns() const;

  //GetBombs
  //Function: returns the number of bombs in the grid
  int GetBombs() const;

  //GameWon
  //Function: return true if game has been won or false otherwise
  bool GameWon() const;

  //PlaceBomb
  //Function: places the bomb in the grid cell at a location
  void PlaceBomb(int row, //Row number is REC'D
		 int col); //col  number is REC'D

  //RemoveBomb
  //Function: removes a bomb from the grid cell at a location
  void RemoveBomb(int row, int col);//Row and col number is REC'D

  //Uncover
  //Function: uncovers the grid cell at a location,
  // true if a bomb is uncovered or false otherwise
  bool Uncover(int row, int col);//Row and col number is REC'D
                                 //a bool value is passed-back

  //Mark
  //Function: mark the grid cell at the location
  void Mark(int row, int col) ; //Row and col number is REC'D

  //Unmark
  //Function: Unmark the grid cell at the location
  void Unmark(int row, int col);//Row and col number is REC'D

  //WriteGrid
  //Function:output the SWeeperGrid in a 2D grid to an output stream
  void WriteGrid (std::ostream &out) const;// output stream  RECD && PASSBK

  //Place
  //Function: It computes the grid number based on row and columns
  int Place(int row, int column) const; //a function to compute place
  

 private:
  int numRows; //number of rows
  int numColumns; //number of columns
  int numBombs; //number of bombs in the grid
  SweeperCell* gridArray; //pointer to grid
 

};
#endif
