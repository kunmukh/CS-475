// File: unsorted.cpp
// Implementation file for UnsortedType class
// Based on Dale, et al., C++ Plus Data Structures 6/e, Chapter 3

#include "unsorted.h"

UnsortedType::UnsortedType()
{
   currentPos = -1; 
}

bool UnsortedType::IsFull() const
{
  return false; //vector can always have more items added to it
}

int UnsortedType::GetLength() const
{
  return info.size();
}

void UnsortedType::MakeEmpty()
{
  info.clear(); 
}

void UnsortedType::PutItem (ItemType item)
 {
   info.push_back(item);
   //  info[length] = item; // put item into info
   // length++;            // add it
 }

void UnsortedType::DeleteItem(ItemType item)
{
  // Find the location of the item
  int location = 0; // start searching at the first element
  // loop until we find the item that matches
  while(info[location].ComparedTo(item) != EQUAL)
    location++;
  info[location] = info.back(); // move the last item
  info.pop_back();             // to this location
  location--; //get rid of the last item;
}
  
ItemType UnsortedType::GetItem(ItemType item, bool& found)const
{
  bool moreToSearch; // flag that is true if there is still more to search for
  int location = 0; //index of the element to check
  found = false;    //item is not found yet
  int length = info.size();
  moreToSearch = (location < length);

  // loop while there is more to search and the item is not find
  while (moreToSearch && !found)
    {
      //  Test if this element is the target
      if (item.ComparedTo(info[location]) == EQUAL)
	found = true;
      // Otherwise, go to the next element
      else
	{
	  location++;
	  moreToSearch = (location < length); // see if this was the last one
	}      
    }

  if (found)
    return info[location];
  return item;
}

void UnsortedType::Reset()
{
  
  currentPos = -1;// reset the iterator to the beginning
  
}

ItemType UnsortedType::GetNextItem() 
{
  // Go to the next position
  currentPos++;
  // Return the element there
  return info[currentPos];
}
