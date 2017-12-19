// File: sorted.h
// Defines SortedType<ItemType>, a template for a sorted list of items
// Circular Linked list implementation
// Based on Dale, et al., C++ Plus Data Structures 6/e, Chapter 6

//  An ItemType must define the following:
//  RelationType:  {LESS, GREATER, EQUAL}
//  Member function ComparedTo(ItemType item) which returns 
//       LESS, if self "comes before" item 
//       GREATER, if self "comes after" item 
//       EQUAL, if self and item are the same 
//
// Its header file must be included _before_ this header file

template<class ItemType>
struct NodeType
{
   ItemType info;
   NodeType* next;
};

template<class ItemType>
class SortedType
{
  public:
   // Constructor - creates an empty list
   SortedType();

   // Destructor - deletes nodes when object is destroyed
   ~SortedType();

   // Function: Returns the list to the empty state.
   // Post:  List is empty.
   void MakeEmpty();

   // Function:  Determines whether list is full.
   // Returns: true if list is full; false otherwise
   bool IsFull() const;

   // Function: Determines the number of elements in list.
   // Returns: number of elements in list
   int GetLength() const;

   // Function: Retrieves list element whose key matches item's key (if
   //           present).

   // Returns: an element someItem whose key matches item's key, and
   //       passes back found = true
   // 	 otherwise returns item and passes back found = false
   ItemType GetItem(ItemType item,       // REC'D: item to find
		    bool& found) const;  // P'BACK: true if item found
                                         //         false otherwise

   // Function: Adds item to list.
   // Assumes: List is not full, item is not in list.
   void PutItem(ItemType item);  // REC'D: item to insert

   // Function: Deletes the element whose key matches item's key.
   // Assumes: Exactly one element in list has a key matching item's key.
   void DeleteItem(ItemType item);  // REC'D: item with key to match

   // Function: Initializes current position for an iteration through the list.
   void ResetList();

   // Function: Gets the next element in list.
   // Assumes: List has not been changed since last call.
   //          Element at current position is not last in list.
   // Post: Current position is updated to next position.
   // Returns: a copy of element at the new current position.
   ItemType GetNextItem();

private:
  int length;
  NodeType<ItemType>* listData;
  NodeType<ItemType>* currentPos;
};

template<class ItemType>
SortedType<ItemType>::SortedType()  // Class constructor
{
   length = 0;
   listData = NULL;
}

template<class ItemType>
SortedType<ItemType>::~SortedType()
{
   NodeType<ItemType>* tempPtr;
   NodeType<ItemType>* lastNode = listData;  // keep track of end of list
   listData = listData->next;                // start with first node

   while (listData != lastNode)  // stop when get to end of list
   {
      tempPtr = listData;
      listData = listData->next;
      delete tempPtr;
   }
   delete lastNode;
}

template<class ItemType>
void SortedType<ItemType>::MakeEmpty()
{
   NodeType<ItemType>* tempPtr;
   NodeType<ItemType>* lastNode = listData;  // keep track of end of list
   listData = listData->next;                // start with first node
   
   while (listData != lastNode)  // stop when get to end of list
   {
      tempPtr = listData;
      listData = listData->next;
      delete tempPtr;
   }
   delete lastNode;
   listData = NULL;
   length = 0;
}

// Helper function that finds item in the list
template<class ItemType>
void FindItem(NodeType<ItemType>* listData,  // REC'D: tail pointer
              ItemType item,                 // REC'D: item to search for
              NodeType<ItemType>*& location, // P'BACK: ptr to node with item
              NodeType<ItemType>*& predLoc,  // P'BACK: ptr to predeceesor
              bool& found)                   // P'BACK: true if found
// Pre: List is not empty.
// Post:If there is an element someItem whose key matches item's
//      key, then found = true; otherwise, found = false.
//      If found, location contains the address of someItem and
//      predLoc contains the address of someItem's predecessor;
//      otherwise, location contains the address of item's logical
//      successor and predLoc contains the address of item's
//      logical predecessor.
{
   // Scan list starting with listData->next looking for item
  bool moreToSearch = true;
  location = listData->next; //first item in the list
  predLoc = listData; // predecessor of the first item is the last item

  while (moreToSearch && !found)
    {
      if(item.ComparedTo(location->info) == LESS)
	moreToSearch = false;

      else if (item.ComparedTo(location->info) == EQUAL)
	found = true;
      else //Keep searching
	{
	  predLoc = location;
	  location = location -> next;
	  moreToSearch = (location != listData->next); // true if not first node
	}

    }
}

template<class ItemType>
ItemType SortedType<ItemType>::GetItem (ItemType item, bool& found) const
{
   NodeType<ItemType> *location;
   NodeType<ItemType> *predLoc;

   FindItem(listData, item, location, predLoc, found);
   if (found)  // return Info(location)
      item = location->info;

   return item;
}

template<class ItemType>
void SortedType<ItemType>::PutItem(ItemType item)
{
  NodeType<ItemType>* newNode;
  NodeType<ItemType>* predLoc;
  NodeType<ItemType>* location;
  bool found;
  
  newNode = new NodeType<ItemType>;
  newNode->info = item;
  if (listData != NULL)
  {
    FindItem(listData, item, location, predLoc, found);
    // Insert newNode between predLoc and location
    predLoc->next = newNode;
    newNode->next = location;

    // If this is last node in list, reassign listData.
    if ((listData->info).ComparedTo(item) == LESS) //Node goes after tail
      listData = newNode;

  }
  else // Inserting into an empty list.
  {
    newNode-> next= newNode; // Node's next poins to itself
    listData = newNode; // Node is the "tail" of this list

  }
  length++;
}

template<class ItemType>
void SortedType<ItemType>::DeleteItem(ItemType item)
{
  NodeType<ItemType>* location;
  NodeType<ItemType>* predLoc;
  bool found;
  
  FindItem(listData, item, location, predLoc, found);
  // Check if only node in list?
  if (predLoc == location)
    listData == NULL; //no more items

  // Otherwise delete node at location
  else
    {
      predLoc->next = location->next;     
    // Check if deleting last node in list?
      if(location == listData)
	listData = predLoc; // predLoc is the new last item
    }
  delete location;
  length--;
}

template<class ItemType>
bool SortedType<ItemType>::IsFull() const
{
   NodeType<ItemType>* location;
   try
   {
      location = new NodeType<ItemType>;
      delete location;
      return false;
   }
   catch(std::bad_alloc exception)
   {
      return true;
   }
}

template<class ItemType>
int SortedType<ItemType>::GetLength() const
{
   return length;
}

template<class ItemType>
void SortedType<ItemType>::ResetList()
{
   currentPos = NULL;
} 

template<class ItemType>
ItemType SortedType<ItemType>::GetNextItem()
{
   ItemType item;
   if (currentPos == NULL)
      currentPos = listData->next;
   item = currentPos->info; 
   currentPos = currentPos->next;
   return item;
} 
