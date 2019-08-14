// File: unsorted.cpp
// Implementation file for UnsortedType class
// Based on Dale, et al., C++ Plus Data Structures 6/e, Chapter 3

#include "unsorted.h"
#include <iostream>

UnsortedType::UnsortedType()
{
   length = 0;
   listData = 0; // null pointer, the list is empty
   currentPos = 0;
   
}

UnsortedType::~UnsortedType()
{
  std::cout << "Destructor." << std::endl;
  // scan through the list and delete the nodes
  //use listData as the scanning pointer
  NodeType *tempPtr; //pointer to the node to be deleted
  while (listData != 0) //scan until the end of the list
    {
      // make tempPtr point to the node to be deleted
      tempPtr = listData;
      //increment listData to the next node
      listData = listData->next;
      //delete the node
      delete tempPtr;
    }

  //MakeEmpty();
}

void UnsortedType::PutItem(ItemType item)
{
  // Create a node at a location
  NodeType* location = new NodeType;
  
  // Set Info(location) to item
  location->info = item;

  // Set Next(location) to the first node of the list
  location->next = listData; // listData points to the first node

  // Make listData point to the new node
  listData = location; //location points to the new node

  // Increment length
  length++;
}

ItemType UnsortedType::GetItem(ItemType item, bool& found) const
{
   bool moreToSearch;
   NodeType *location = listData; //scanning pointer starting
                                  //at first element   
   found = false;

   moreToSearch = (location != 0);
   while (moreToSearch && !found) 
   {
      switch (item.ComparedTo(location->info)) // typo in text, p. 181
      {
	 case LESS    :
	   //"increment" location to the next node
	   location = location->next;	    
	   moreToSearch = (location != 0);
	   break;
	 case GREATER :
	   //"increment" location to the next node
	   location = location->next;	    
	   moreToSearch = (location != 0);
	    break;
	 case EQUAL   : found = true;
	   item = location->info;
	    break;
      }
   }
   return item;
}

void UnsortedType::MakeEmpty()
{
  // scan through the list and delete the nodes
  //use listData as the scanning pointer
  NodeType *tempPtr; //pointer to the node to be deleted
  while (listData != 0) //scan until the end of the list
    {
      // make tempPtr point to the node to be deleted
      tempPtr = listData;
      //increment listData to the next node
      listData = listData->next;
      //delete the node
      delete tempPtr;
    }
   length = 0;
   currentPos = 0;
   
}

void UnsortedType::DeleteItem(ItemType item)
{
   NodeType *location = listData,
      *tempLocation;

   // Assuming exactly one match...
   // Check if it is the first node
   if (item.ComparedTo(listData->info) == EQUAL)  // typo, using ==, p. 182
   {
      tempLocation = location;
      // make the next node the first one
      listData = listData->next;
   }
   else
   {  // Look at the next node and beyond
      // typo, missplaced (, p. 183
     while(item.ComparedTo(location->next->info) != EQUAL)
	 location = location->next; // not equal, so "increment"	   
     // Here location points to the node before the one to be deleted
     tempLocation = location->next;
     //Make Next(location) to point to the node after the one being deleted
     location->next = location->next->next; //tempLocation->next    

   }
   delete tempLocation;  // deallocated the node with item to be deleted
   length--;
}

bool UnsortedType::IsFull() const
{
   try  // attempt to allocation a node, then immediately delete it
   {
      NodeType *location = new NodeType;
      delete location;
      return false;
   }
   catch (std::bad_alloc ex)  // new throws bad_alloc exception
   {
      return true;
   }
}

int UnsortedType::GetLength() const
{
   return length;
}

void UnsortedType::ResetList()
{
   currentPos = 0;
}

ItemType UnsortedType::GetNextItem()
{
   // Check for null pointer, make it start at beginning of list
   if (currentPos == 0)
      currentPos = listData;
   else
      currentPos = currentPos->next;
   return currentPos->info;
}
