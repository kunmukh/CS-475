// File: queue.cpp
// Implementation of  QueueType operations
// Dyanmic array, circular implementation
// Based on Dale, et al., C++ Plus Data Structures 6/e, Chapter 5

#include "queue.h"

QueueType::QueueType()          // Default class constructor
{
   maxQue = 501;
   front = maxQue - 1;
   rear = maxQue - 1;
   items = new ItemType[maxQue];
}

QueueType::QueueType(int max)
{
   maxQue = max + 1;
   front = maxQue - 1;
   rear = maxQue - 1;
   items = new ItemType[maxQue];
}

QueueType::~QueueType()         // Class destructor
{
   delete [] items;
}

void QueueType::MakeEmpty()
// Post: front and rear have been reset to the empty state.
{
   front = maxQue - 1;
   rear = maxQue - 1;
}

bool QueueType::IsEmpty() const
{
   // Return true if the queue is empty; false otherwise.
  return (front == rear);
}

bool QueueType::IsFull() const
{
   // Return true if the queue is full; false otherwise.
  //queue is full if front is equal to " real +1"
  return front == (rear +1) % maxQue; // modular increment

}

void QueueType::Enqueue(ItemType newItem)
// Post: If (queue is not full) newItem is at the rear of the queue;
//       otherwise a FullQueue exception is thrown.  
{
   if (IsFull())
      throw FullQueue();
   else
   {
      // "increment" rear
     rear = (rear+1)% maxQue;

      // place newItem
      items[rear] = newItem;
   }
}

void QueueType::Dequeue(ItemType& item)
// Post: If (queue is not empty) the front of the queue has been 
//       removed and a copy returned in item; 
//       othersiwe a EmptyQueue exception has been thrown.
{
   if (IsEmpty())
      throw EmptyQueue();
   else
   {
      // "increment" front
     front = (front+1)%maxQue; 
      // pass back the front item
      item = items[front];
   }
}
