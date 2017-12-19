// File: unsorted.cpp
// Implementation file for UnsortedType class
// Based on Dale, et al., C++ Plus Data Structures 6/e, Chapter 3

#include "unsorted.h"

UnsortedType::UnsortedType()
{
   length = 0;  // empty list has no items
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

void UnsortedType::MakeEmpty()
{
   length = 0;  // empty list has no items
   currentPos = -1;
}

void UnsortedType::PutItem(ItemType item){
  info[length] = item;
  length++;
}

void UnsortedType::DeleteItem(ItemType item){
  // find the location of the item
  int location = 0;
  // loop until item that matches is found
  while(info[location].ComparedTo(item) != EQUAL)
    location++;
  info[location] = info[length-1];
  length--;
}

ItemType UnsortedType::GetItem(ItemType item, bool& found) const{
  bool moreToSearch;//flag that is true if there is still more to search for
  int location = 0; //index of the element to check
  found = false;    //item is not found yet

  moreToSearch = (location < length);

  // loop while there is more to search and the item is not found
  while(moreToSearch && !found){  //note no use of the == operator, it is not needed for boolean values
    if(item.ComparedTo(info[location]) == EQUAL)
      found = true;
    else{
      location++;
      moreToSearch = (location < length);
    }
  }
  if(found)
    return info[location];
  return item;
}

void UnsortedType::Reset(){
  currentPos = -1;
}

ItemType UnsortedType::GetNextItem(){
  currentPos++;
  return info[currentPos];
}
