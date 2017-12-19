// File: stack.cpp
// Implementation of  StackType operations
// Array implementation
// Based on Dale, et al., C++ Plus Data Structures 6/e, Chapter 5

#include "stack.h"

StackType::StackType()
{
   top = -1;  // top is index of the top element
}

bool StackType::IsEmpty() const
{
   return (top == -1);  // top is index of the top element
}

bool StackType::IsFull() const
{
   return (top ==  MAX_ITEMS-1);  // last index is MAX_ITEMS-1
}

void StackType::Push(ItemType newItem)
{
   if( IsFull() )
      throw FullStack();
   top++;
   items[top] = newItem;
}

void StackType::Pop()
{
   if( IsEmpty() )
      throw EmptyStack();
   top--;
}

ItemType StackType::Top()
{
   if (IsEmpty())
      throw EmptyStack();
   return items[top];
}    
