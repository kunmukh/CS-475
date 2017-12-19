// File: sorted.cpp
// Implementation file for SortedType class
// Based on Dale, et al., C++ Plus Data Structures 6/e, Chapter 4

#include "sorted.h"

// NodeType struct definition
struct NodeType
{
   ItemType info;
   NodeType* next;
};

SortedType::SortedType()  // Class constructor
{
   length = 0;
   listData = 0;
}

SortedType::~SortedType()
{
   NodeType* tempPtr;

   while (listData != 0)
   {
      tempPtr = listData;
      listData = listData->next;
      delete tempPtr;
   }
}

ItemType SortedType::GetItem (ItemType item, bool& found) const
{
   // Same as linked UnsortedType::GetItem except stop search if item is LESS

   bool moreToSearch;
   NodeType* location;

   location = listData;
   found = false;
   moreToSearch = (location != 0);

   while (moreToSearch && !found)
   {
      switch(item.ComparedTo(location->info))
      {
	 case GREATER:
	    location = location->next;
	    moreToSearch = (location != 0);
	    break;
	 case EQUAL:
	    found = true;
	    item = location->info;
	    break;
	 case LESS:  // rest of the list will be even larger, so stop
	    moreToSearch = false;
	    break;
      }
   }
   return item;
}

void SortedType::PutItem(ItemType item)
{
   NodeType* newNode;  	// pointer to node being inserted
   NodeType* location; 	// scanning pointer
   NodeType* predLoc; // pointer to the node before Node(location)
   bool moreToSearch;
   predLoc = 0; // no predecessor  node
   location = listData;
   moreToSearch = (location != 0);

   // Find insertion point.
   while (moreToSearch)
   {
      switch(item.ComparedTo(location->info))
      {
	 case GREATER:
	   predLoc = location; // move predLoc up by one node
	    location = location->next;
	    moreToSearch = (location != 0);
	    break;
	 case LESS:
	    moreToSearch = false;
	    break;
	 case EQUAL:
	    std::cout << "PutItem: EQUAL should not happen" << std::endl;
	    break;
      }
   }

   // Prepare node for insertion
   newNode = new NodeType;
   newNode->info = item;
   // Insert node into list.  Two cases.
   // Case 1: Insert as first
   if (predLoc == 0)// no predecessor, i.e. insert in front of the first element
     {
       newNode->next = listData;
       listData = newNode;
     }

   // Case 2: Insert in the middle/end
   else 
     {
       predLoc->next = newNode;
       newNode->next = location;

     }
   // Increment length
   length++;
}

void SortedType::DeleteItem(ItemType item)
{
   // Exactly the same as linked UnsortedType::DeleteItem

   NodeType* location = listData;  // Scanning pointer
   NodeType* tempLocation;         // Pointer to node to be deleted

   // Locate node to be deleted.  Two cases.
   // Case 1: Delete first item
   if (item.ComparedTo(listData->info) == EQUAL)
   {
      tempLocation = location;
      listData = listData->next;	// Delete first node.
   }
   // Case 2: Delete any other node
   else
   {
      // Find node to delete
      while (item.ComparedTo((location->next)->info) != EQUAL)
	 location = location->next;

      // Delete node at location->next
      tempLocation = location->next;
      // Make node at location point to the node after location->next
      location->next = (location->next)->next;
   }
   delete tempLocation;
   length--;
}

bool SortedType::IsFull() const
{
   NodeType* location;
   try
   {
      location = new NodeType;
      delete location;
      return false;
   }
   catch(std::bad_alloc exception)
   {
      return true;
   }
}

int SortedType::GetLength() const
{
   return length;
}

void SortedType::MakeEmpty()
{
   NodeType* tempPtr;

   while (listData != 0)
   {
      tempPtr = listData;
      listData = listData->next;
      delete tempPtr;
   }
   length = 0;
}

void SortedType::ResetList()
{
   currentPos = 0;
} 

ItemType SortedType::GetNextItem()
{
   ItemType item;
   if (currentPos == 0)
      currentPos = listData;
   item = currentPos->info; 
   currentPos = currentPos->next;
   return item;
} 
