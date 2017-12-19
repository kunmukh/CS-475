// File: unsorted.cpp
// Implementation file for UnsortedType class
// Based on Dale, et al., C++ Plus Data Structures 6/e, Chapter 3

#include "unsorted.h"

void Unsorted::SplitLists(ItemType Item, UnsortedType& list1,
			  UnsortedType& list2)
{
  //loop over each element
  for ( int i = 0; i < length; i++)
    {
      // figure which list info[i] goes in
      if (item.ComparedTo(info[i]) == GREATER)
	{
	  //put info[i] into list2
	  list2.PutItem(info[i]);
	}
      else
	{
	  //put info[i] into list1
	  list1.PutItem(info[i]);
	}
    }
}
bool UnsortedType::IsThere (ItemType item) const
{
  bool found;  //returned object
  bool moreToSearch;
  int location = 0;
  found = false;
  moreToSearch = (location < length);

   while (moreToSearch && !found) 
     {
       switch (item.ComparedTo(info[location]))
	 {
	 case LESS    : 
	 case GREATER : location++;
	   moreToSearch = (location < length);
	   break;
	 case EQUAL   : found = true;
	   break;
	 }
     }
   return found;
}

UnsortedType::UnsortedType()
{
   length = 0;
   currentPos = -1;
}

bool UnsortedType::IsFull() const
{
   return (length == MAX_ITEMS);
}

int UnsortedType::GetLength() const
{
   return length;
}

ItemType UnsortedType::GetItem(ItemType item, bool& found) const
{
   bool moreToSearch;
   int location = 0;
   found = false;

   moreToSearch = (location < length);

   while (moreToSearch && !found) 
   {
      switch (item.ComparedTo(info[location]))
      {
	 case LESS    : 
	 case GREATER : location++;
	    moreToSearch = (location < length);
	    break;
	 case EQUAL   : found = true;
	    item = info[location];
	    break;
      }
   }
   return item;
}

void UnsortedType::MakeEmpty()
{
   length = 0;
   currentPos = -1;
}

void UnsortedType::PutItem(ItemType item)
{
   info[length] = item;
   length++;
}

void UnsortedType::DeleteItem(ItemType item)
{
   int location = 0;

   while (item.ComparedTo(info[location]) != EQUAL)
      location++;

   info[location] = info[length - 1];
   length--;
}

void UnsortedType::ResetList()
{
   currentPos = -1;
}

ItemType UnsortedType::GetNextItem()
{
   currentPos++;
   return info[currentPos];
}

