// File: sortediter.h
// Defines SortedTypeIterator<T>, a template for an Iterator type for the
// SortedType list of items using the circular, doubly-linked with header
// node implementation
// Based on Dale, et al., C++ Plus Data Structures 6/e, Chapter 6

#ifndef SORTEDTYPEITERATOR_H
#define SORTEDTYPEITERATOR_H

#include "nodetype.h" // doubly-linked list node

template<class T>
class SortedTypeIterator
{
  public:
   // Constructor receives data that will allow access to an element
   // Receives a node pointer in this case
   SortedTypeIterator(NodeType<T>* start);

   // The dereference operator.
   // Returns the data the iterator is "pointing" to
   T& operator*();

   // The "increment" operator
   // Makes this iterator "point" to the successor element and
   // returns this iterator
   SortedTypeIterator<T>& operator++();

   // The comparison operator
   // Returns false if this iterator is the same as it,
   //         true if this iterator is not the same as it
   bool operator!=(const SortedTypeIterator<T>& it) const;

  private:
   // The way to access the item that this iterator "points" to
   // In this case it is a pointer to a node
   NodeType<T>* item;
};


template<class T>
SortedTypeIterator<T>::SortedTypeIterator(NodeType<T> *start)
{
   // "this" is a keyword that is a pointer to this object
   this->item = start;
}

template<class T>
T& SortedTypeIterator<T>::operator*()
{
   // In this case, access to the data is using operator->
   return item->info;
}

template<class T>
SortedTypeIterator<T>& SortedTypeIterator<T>::operator++()
{
   // In this case, the successor element is at ->next
   item = item->next;
   // return reference to self; "this" is a pointer, so need to dereference
   return *this;  
}

template<class T>
bool SortedTypeIterator<T>::operator!=(const SortedTypeIterator<T> &it) const
{
   // is it pointing to the same places as this object?
   return item != it.item;
}

#endif
