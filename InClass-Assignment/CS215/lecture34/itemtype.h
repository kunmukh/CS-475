// File: itemtype.h
// Defines a generic item that contains an int
// Based on Dale, et al., C++ Plus Data Structures 6/e, Chapter 3

#ifndef ITEMTYPE_H
#define ITEMTYPE_H

#include <iostream>

enum RelationType  {LESS, GREATER, EQUAL};

class ItemType 
{ 
  public:
   // Constructor - initializes value to 0
   ItemType();

   // Observer
   // Compares this item with otherItem and returns appropriate
   // RelationType value
   RelationType ComparedTo(ItemType otherItem) const;  // REC'D: rhs operand

   // Transformer - sets value to number
   void Initialize(int number);  // REC'D: new item value
   
   // Output operator - 
   friend std::ostream& operator<<
      (std::ostream &out,  // REC'D/P'BACK: output stream
       ItemType anItem);   // REC'D: item to be output

  private:
   int value;  // item value
};
 
#endif
