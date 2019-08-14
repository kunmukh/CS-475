// Implementation of ItemType class operations
// Based on Dale, et al., C++ Plus Data Structures 6/e, Chapter 3

#include <iostream>
#include "itemtype.h"

ItemType::ItemType()
{ 
  value = 0;
}

RelationType ItemType::ComparedTo(ItemType otherItem) const 
{
  if (value < otherItem.value)
    return LESS;
  else if (value > otherItem.value)
    return GREATER;
  else return EQUAL;
}

void ItemType::Initialize(int number) 
{
  value = number;
}

std::ostream& operator<< (std::ostream& out, ItemType item)
{
  out << item.value;
  return out;
}
