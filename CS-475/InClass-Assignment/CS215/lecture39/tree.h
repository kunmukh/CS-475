// File: tree.h
// Defines TreeType class, a binary search tree
// Based on Dale, et al., C++ Plus Data Structures 6/e, Chapter 8

#include <string>
#include <fstream>
#include <queue>

#ifndef TREE_H_
#define TREE_H_

typedef char ItemType;
struct TreeNode;
enum OrderType {PRE_ORDER, IN_ORDER, POST_ORDER};
class TreeType
{
  public:
   // Default constructor
   TreeType();

   // Copy constructor
   TreeType(const TreeType& originalTree);
   
   // Destructor
   ~TreeType();
   
   // Function: Returns the tree to the empty state.
   // Post:  Tree is empty.
   void MakeEmpty();
   
   // Assignment operator
   TreeType & operator=(const TreeType& originalTree);

   // Function: Determines whether tree is empty
   // Returns true if there is no data in tree; false otherwise
   bool IsEmpty() const;
   
   // Function:  Determines whether tree is full.
   // Returns: true if tree is full; false otherwise
   bool IsFull() const;

   // Function: Determines the number of elements in tree.
   // Returns: number of nodes in the tree
   int GetLength() const; 

   // Function: Adds item to tree.
   // Assumes: Tree is not full, item is not in tree.
   ItemType GetItem(ItemType item, bool& found);

   // Function: Adds item to tree.
   // Assumes: Tree is not full, item is not in tree.
   void PutItem(ItemType item);

   // Function: Deletes the element whose key matches item's key.
   // Assumes: Exactly one element in tree has a key matching item's key.
   void DeleteItem(ItemType item);

   // Function: Prints info member of items in tree in sorted order on
   // an output stream
   void Print(std::ostream& out) const;

   // Function: Initializes current position for an iteration through the tree.
   void ResetTree(OrderType order); 

   // Function: Returns the next item in the desired order.
   // Post: For the desired order, item is the next item in the queue.
   //       If item is the last one in the queue, finished is true; 
   //       otherwise finished is false.
   ItemType GetNextItem(OrderType order, bool& finished);

  private:
   TreeNode* root;
   std::queue<ItemType> preQue;
   std::queue<ItemType> inQue;
   std::queue<ItemType> postQue;
};

#endif // TREE_H_
