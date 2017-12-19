// File: stack.h
// Defines StackType, a stack of items
// Linked implementation
// Based on Dale, et al., C++ Plus Data Structures 6/e, Chapter 5

#ifndef STACK_H
#define STACK_H

#include "itemtype.h"
//   The user of this file must provied a file "itemtype.h" that defines:
//       ItemType : the class definition of the objects on the stack.

// Forward declaration
struct NodeType;

// Exception class thrown by Push when stack is full.
class FullStack
{};

// Exception class thrown by Pop and Top when stack is emtpy.
class EmptyStack
{};

class StackType
{
  public:

   // Default constructor - creates an empty stack
   StackType();

   // Destructor - deallocate all nodes
   ~StackType();

   // Function: Determines whether the stack is full.
   // Pre:  Stack has been initialized.
   // Post: Function value = (stack is full)
   bool IsFull() const;

   // Function: Determines whether the stack is empty.
   // Pre:  Stack has been initialized.
   // Post: Function value = (stack is empty)
   bool IsEmpty() const;

   // Function: Adds newItem to the top of the stack.
   // Pre:  Stack has been initialized.
   // Post: If (stack is full), FullStack exception is thrown;
   //     otherwise, newItem is at the top of the stack.
   void Push(ItemType newItem);  // REC'd: item to put on the stack

   // Function: Removes top item from the stack.
   // Pre:  Stack has been initialized.
   // Post: If (stack is empty), EmptyStack exception is thrown;
   //     otherwise, top element has been removed from stack.
   void Pop();

   // Function: Returns a copy of top item on the stack.
   // Pre:  Stack has been initialized.
   // Post: If (stack is empty), EmptyStack exception is thrown;
   //     otherwise, top element has been removed from stack.
   ItemType Top();

  private:
   NodeType *topPtr;
};

#endif
