// File: sorted.h
// Defines SortedType, a sorted list of items
// Array implementation
// Based on Dale, et al., C++ Plus Data Structures 6/e, Chapter 4

#ifndef SORTED_H
#define SORTED_H

#include "itemtype.h" 
// File itemtype.h must be provided by the user of this class. 
//  itemtype.h must contain the following definitions: 
//  ItemType:      the definition of the objects on the list 
//  RelationType:  {LESS, GREATER, EQUAL}
//  Member function ComparedTo(ItemType item) which returns 
//       LESS, if self "comes before" item 
//       GREATER, if self "comes after" item 
//       EQUAL, if self and item are the same 

const int MAX_ITEMS = 5;

class SortedType 
{
  public:
  
  //Constructor
  SortedType(); //Default Constructor - has no parameter
  SortedType(int size); //Explicit-value Constructor- has parameter
  ~SortedType(); //Destructor

   // Function: Returns list to the empty state
   // Post:  List is empty.
   void MakeEmpty();
  
   // Function:  Determines whether list is full.
   // Pre:  List has been initialized.
   // Post: Function value = (list is full)
   bool IsFull() const;

   // Function: Determines the number of elements in list.
   // Pre:  List has been initialized.
   // Post: Function value = number of elements in list
   int GetLength() const;

   // Function: Retrieves list element whose key matches item's key (if
   //           present).
   // Pre:  List has been initialized.
   //       Key member of item is initialized.
   // Post: If there is an element someItem whose key matches
   //       item's key, then found = true and item is returned;
   //       someItem; otherwise found = false and item is returned.
   //       List is unchanged.
   ItemType GetItem(ItemType item, bool& found);

   // Function: Adds item to list.
   // Pre:  List has been initialized.
   //       List is not full.
   //       item is not in list.
   //       List is sorted.
   // Post: item is in list.
   //       List is sorted
   void PutItem(ItemType item);

   // Function: Deletes the element whose key matches item's key.
   // Pre:  List has been initialized.
   //       Key member of item is initialized.
   //       One and only one element in list has a key matching item's key.
   // Post: No element in list has a key matching item's key.
   //       List is sorted.
   void DeleteItem(ItemType item);

   // Function: Initializes current position for an iteration through the list.
   // Pre:  List has been initialized.
   // Post: Current position is prior to list.
   void ResetList();

   // Function: Gets the next element in list.
   // Pre:  List has been initialized and has not been changed since last call.
   //       Current position is defined.
   //       Element at current position is not last in list.
   //	     
   // Post: Current position is updated to next position.
   //       Returns a copy of element at current position.
   ItemType GetNextItem();



  private:
   int length;
   ItemType* info; //pointer to an array
   int maxItems; //number of elements in the array
   int currentPos;
};
#endif
