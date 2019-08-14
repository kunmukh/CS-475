// File: unsorted.h
// Defines UnsortedType, an unsorted list of items
// Based on Dale, et al., C++ Plus Data Structures 6/e, Chapter 3

#include <vector> //STL class definition
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
   // Assumes that item is not already in the list
   // Assumes that the list is not full
   void PutItem (ItemType item); // RED'D: item to be put in the list

   // Function: Removes an item from the list
   // Assumes that the key value of the item is set
   //Assumes that the key exists in the list
   void DeleteItem(ItemType item); //REC'D: item with key to be deleted

   // Function: Find the item with the given key, or the parameter item
                                                 //is not found
   // Assumes that the key value of the item is set
   ItemType GetItem(ItemType item,//REC'D: item with key to be searched
		bool &found) const; //P'BACK: true if the key is found or false
   
   // Function: Resets the itertaor current position
   void Reset();

   //Function: Returns the next item in order from the iterator
   //Assumes that there is a next item
   ItemType GetNextItem();
   
 private:
   std::vector<ItemType> info; // data storage of the list
   int currentPos; //current position of the iterator
                   //ie.e, the index of the last accessed element
};
