// File: sweepercell.h
// Minesweeper game cells, can contain a bomb or not,
// can be covered or not, can be marked or not
// DO NOT MODIFY THIS FILE!!
// -----------------------------------------------------------
// Assignment: Project 4
// Date Assigned: March 17, 2017

#ifndef CELL_H_
#define CELL_H_

#include <iostream>

class SweeperCell
{
   public:
      // Constructor: cell always starts out empty, covered, unmarked,
      // and with 0 adjacent bombs
      SweeperCell ();

      // Accessors
      bool HasBomb () const;       // returns true if cell contains a bomb
      bool IsCovered () const;     // returns true if cell is covered
      bool IsMarked () const;      // returns true if cell is marked
      int GetNumAdjacent() const;  // returns number of adjacent bombs

      // Mutators
      void IncrNumAdjacent();      // increment number of adjacent bombs by 1
      void DecrNumAdjacent();      // decrement number of adjacent bombs by 1
      void PlaceBomb();            // places a bomb in the cell
      void RemoveBomb();           // removes a bomb from the cell
      bool Uncover ();             // uncovers cell; returns true if cell
                                   // contains a bomb, false otherwise
      void Mark ();                // marks cell
      void Unmark ();              // unmarks cell
	 
      // Friends
      // output the character rep of the cell, see below
      // returns the output stream
      friend std::ostream& operator<<
	 (std::ostream & out,         // REC'D & pb: output stream
	  const SweeperCell & aCell); // REC'D: cell to output
	 
   private:
      bool bomb,          // true if contains a bomb
	   covered,       // true if covered
	   marked;        // true if marked
      char rep;           // character representation of cell state
                          //   # - when covered and unmarked
                          //   f - when covered and marked
                          //   * - when uncovered containing a bomb
                          //   n - when uncovered and no bomb, where n is 
                          //       number of adjacent cells (all 8 directions) 
                          //       containing bombs
      int numAdjacent;    // number of adjacent cells (all 8 directions)
                          // containing bombs

}; // end class SweeperCell

#endif // CELL_H_
