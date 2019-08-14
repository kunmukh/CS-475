// File: stack.cpp
// Implementation of StackType operations
// Linked implementation
// Based on Dale, et al., C++ Plus Data Structures 6/e, Chapter 5

#include "stack.h"
#include <new>  // bad_alloc exception

struct NodeType
{
   ItemType info;
   NodeType* next;
};

StackType::StackType()	// Class constructor.
{
   topPtr = 0;
}

StackType::~StackType()
{
   // Same as other linked implementations
   NodeType* tempPtr;

   while (topPtr != 0)
   {
      tempPtr = topPtr;
      topPtr = topPtr->next;
      delete tempPtr;
   }
}

void StackType::Push(ItemType newItem)
{
   if (IsFull())
      throw FullStack();
   else
   {
      // Same as linked UnsortedType::PutItem
      NodeType* location;
      location = new NodeType;
      location->info = newItem;
      location->next = topPtr;
      topPtr = location;
   }
}

void StackType::Pop()
{
   if (IsEmpty())
      throw EmptyStack();
   else
   {  
      // Reverse of Push
      NodeType* tempPtr;
      tempPtr = topPtr;
      topPtr = topPtr->next;
      delete tempPtr;
   }
}

ItemType StackType::Top()
{
   if (IsEmpty())
      throw EmptyStack();
   else
      // return the first element
      return topPtr->info;  
}

bool StackType::IsFull() const
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

bool StackType::IsEmpty() const
{
   // check if there are any elements
   return (topPtr == 0);
}  
