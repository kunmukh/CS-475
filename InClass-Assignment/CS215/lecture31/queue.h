// File: queue.h
// Defines QueueType, a queue of items
// Array implementation
// Based on Dale, et al., C++ Plus Data Structures 6/e, Chapter 5

#ifndef QUEUE_H
#define QUEUE_H

#include "itemtype.h"
//   The user of this file must provied a file "itemtype.h" that defines:
//       ItemType : the class definition of the objects on the stack.

class FullQueue
{};  

class EmptyQueue
{};  

class QueueType
{
  public: 
   // Class constructor.
   // Because there is a default constructor, the precondition 
   // that the queue has been initialized is omitted.
   QueueType();

   // Parameterized class constructor.
   QueueType(int max);

   // Class destructor.
   ~QueueType();

   // Function: Initializes the queue to an empty state.
   // Post: Queue is empty.
   void MakeEmpty();

   // Function: Determines whether the queue is empty.
   // Post: Function value = (queue is empty)
   bool IsEmpty() const;

   // Function: Determines whether the queue is full.
   // Post: Function value = (queue is full)
   bool IsFull() const;

   // Function: Adds newItem to the rear of the queue.
   // Post: If (queue is full) FullQueue exception is thrown
   //       else newItem is at rear of queue.
   void Enqueue(ItemType newItem);

   // Function: Removes front item from the queue and passes it back in item.
   // Post: If (queue is empty) EmptyQueue exception is thrown
   //       and item is undefined
   //       else front element has been removed from queue and
   //       item is a copy of removed element.
   void Dequeue(ItemType& item);

  private:
   int front;
   int rear;
   ItemType* items;
   int maxQue;
};

#endif
