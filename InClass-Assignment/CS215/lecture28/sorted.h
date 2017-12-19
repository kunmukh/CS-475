// File: sorted.h
// Defines SortedType, a sorted list of items
// Linked list implementation
// Based on Dale, et al., C++ Plus Data Structures 6/e, Chapter 4

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

// Forward declaration of NodeType; definition in sorted.cpp
struct NodeType;

class SortedType
{
  public:
   // Constructor - creates an empty list
   SortedType();

   // Destructor - deletes nodes when object is destroyed
   ~SortedType();

   // Function: Returns the list to the empty state.
   // Post:  List is empty.
   void MakeEmpty();

   // Function:  Determines whether list is full.
   // Returns: true if list is full; false otherwise
   bool IsFull() const;

   // Function: Determines the number of elements in list.
   // Returns: number of elements in list
   int GetLength() const;

   // Function: Retrieves list element whose key matches item's key (if
   //           present).

   // Returns: an element someItem whose key matches item's key, and
   //       passes back found = true
   // 	 otherwise returns item and passes back found = false
   ItemType GetItem(ItemType item,       // REC'D: item to find
		    bool& found) const;  // P'BACK: true if item found
                                         //         false otherwise

   // Function: Adds item to list.
   // Assumes: List is not full, item is not in list.
   void PutItem(ItemType item);  // REC'D: item to insert

   // Function: Deletes the element whose key matches item's key.
   // Assumes: Exactly one element in list has a key matching item's key.
   void DeleteItem(ItemType item);  // REC'D: item with key to match

   // Function: Initializes current position for an iteration through the list.
   void ResetList();

   // Function: Gets the next element in list.
   // Assumes: List has not been changed since last call.
   //          Element at current position is not last in list.
   // Post: Current position is updated to next position.
   // Returns: a copy of element at the new current position.
   ItemType GetNextItem();

  private:
   int length;
   NodeType* listData;
   NodeType* currentPos;
};
