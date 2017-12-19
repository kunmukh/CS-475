// File: sweepercell.cpp
// Implementation of minesweeper cells
// DO NOT MODIFY THIS FILE!!
// -----------------------------------------------------------
// Assignment: Project 4
// Date Assigned: March 17, 2017

#include <iostream>
#include "sweepercell.h"

// Constructor
// Cell always starts out empty, covered, unmarked, and with 0
// adjacent bombs
SweeperCell::SweeperCell ()
{
   bomb = false;
   covered = true;
   marked = false;
   rep = '#';          // covered and unmarked
   numAdjacent = 0;
}  // end default constructor

// Accessors
bool SweeperCell::HasBomb () const
{
   return bomb;
}  // end HasBomb

bool SweeperCell::IsCovered () const
{
   return covered;
}  // end IsCovered

bool SweeperCell::IsMarked () const
{
   return marked;
}  // end IsMarked

int SweeperCell::GetNumAdjacent() const
{
   return numAdjacent;
}  // end GetNumAdjacent

// Mutators
void SweeperCell::IncrNumAdjacent()
{
   numAdjacent++;
   if (!bomb && !covered) // no bomb and not covered, so show numAdjacent
      rep = '0' + numAdjacent;
}  // end IncrNumAdjacent

void SweeperCell::DecrNumAdjacent()
{
   numAdjacent--;
   if (!bomb && !covered)  // no bomb and not covered, so show numAdjacent
      rep = '0' + numAdjacent;
}  // end DecrNumAdjacent

void SweeperCell::PlaceBomb ()
{
   bomb = true;
   if (!covered)  // not covered, so show bomb
      rep = '*';
}  // end PlaceBomb

void SweeperCell::RemoveBomb ()
{
   bomb = false;
   if (!covered)  // not covered, so show numAdjacent
      rep = '0' + numAdjacent;
}  // end RemoveBomb

bool SweeperCell::Uncover ()
{
   covered = false;
   if (bomb)  // has a bomb, so show it
      rep = '*';
   else       // no bomb, so show numAdjacent
      rep = '0' + numAdjacent;
   return (bomb);
}  // end Uncover

void SweeperCell::Mark ()
{
   marked = true;
   if (covered)  // covered, so show the mark
      rep = 'f';
}  // end Mark

void SweeperCell::Unmark ()
{
   marked = false;
   if (covered)  // covered, so remove the mark
      rep = '#';
}  // end Unmark

// Function: operator<<
// Outputs the character representation of the cell:
//   # - when covered and unmarked
//   f - when covered and marked
//   * - when uncovered containing a bomb
//   n - when uncovered and no bomb, where n is 
//       number of adjacent cells (all 8 directions) 
//       containing bombs
std::ostream& operator<< (std::ostream & out, const SweeperCell & aCell)
{
   out << aCell.rep;
   return out;
}  // end operator<<
