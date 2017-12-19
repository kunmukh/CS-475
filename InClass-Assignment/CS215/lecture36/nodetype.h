// File: nodetype.h
// Defines NodeType<T>, a template for doubly-linked list nodes

#ifndef NODETYPE_H_
#define NODETYPE_H_

template<class T>
struct NodeType
{
   T info;
   NodeType<T>* next;
   NodeType<T>* back;
};

#endif
