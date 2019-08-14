// File: unsorted.h
// Defines UnsortedType, an unsorted list of items
// Based on Dale, et al., C++ Plus Data Structures 6/e, Chapter 3

#include "itemtype.h" 
// File itemtype.h must be provided by the user of this class. 
//  itemtype.h must contain the following definitions: 
//
//  ItemType:      the definition of the objects on the list 
//  RelationType:  {LESS, GREATER, EQUAL}
//  Member function ComparedTo(ItemType item) which returns 
//       LESS, if self "comes before" item 
//       GREATER, if self "comes after" item 
//       EQUAL, if self and item are the same 


const int MAX_ITEMS = 5;

class UnsortedType 
{
  public:
   // Constructor - creates an empty list
   UnsortedType();

   // Function: Returns the list to the empty state.
   // Post:  List is empty.
   void MakeEmpty();

   // Function:  Determines whether list is full.
   // Returns: true if list is full; false otherwise
   bool IsFull() const;

   // Function: Determines the number of elements in list.
   // Returns: number of elements in list
   int GetLength() const;

   // Function: Adds an item to the list
   // Assumes item is not already in list
   // Assumes list is not full
   // Returns: no returned item
   void PutItem(ItemType item);

   // Function: Removes an item from the list
   // Assumes that key value of item is set
   // Returns: nothing, void function
   void DeleteItem(ItemType item);

   // Function: Find the item with the given key
   // Assumes that the key exists in the list
   ItemType GetItem(ItemType item, bool& found) const;

   // Function: resets iterator current position
   void Reset();

   // Function: returns next item in the order from the iterator
   ItemType GetNextItem();

  private:
   int length;
   ItemType info[MAX_ITEMS];
   int currentPos; // current postition of the iterator
                   //index of the last accessed element
};
