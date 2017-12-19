// File: stack.h
// Defines StackType<ItemType> template, a stack of items
// Array implementation
// Based on Dale, et al., C++ Plus Data Structures 6/e, Chapter 6.1

#ifndef STACK_H
#define STACK_H


//   The user of this file must provied a file "itemtype.h" that defines:
//       ItemType : the class definition of the objects on the stack.

const int MAX_ITEMS = 5;

// Exception class thrown by Push when stack is full.
class FullStack
{};

// Exception class thrown by Pop and Top when stack is emtpy.
class EmptyStack
{};

template<class ItemType> // ItemType is a type parameter for this class
class StackType
{
  public:

   // Default constructor - creates an empty stack
   StackType();

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
   int top;
   ItemType items[MAX_ITEMS];
};

// File: stack.cpp
// Implementation of  StackType operations
// Array implementation
// Based on Dale, et al., C++ Plus Data Structures 6/e, Chapter 5

template<class ItemType>
StackType<ItemType>::StackType()
{
   top = -1;  // top is index of the top element
}

template<class ItemType>
bool StackType<ItemType>::IsEmpty() const
{
   return (top == -1);  // top is index of the top element
}

template<class ItemType>
bool StackType<ItemType>::IsFull() const
{
   return (top ==  MAX_ITEMS-1);  // last index is MAX_ITEMS-1
}

template<class ItemType>
void StackType<ItemType>::Push(ItemType newItem)
{
   if( IsFull() )
      throw FullStack();
   top++;
   items[top] = newItem;
}

template<class ItemType>
void StackType<ItemType>::Pop()
{
   if( IsEmpty() )
      throw EmptyStack();
   top--;
}

template<class ItemType>
ItemType StackType<ItemType>::Top()
{
   if (IsEmpty())
      throw EmptyStack();
   return items[top];
}    


#endif
