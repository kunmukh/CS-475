///File: document2.cpp
// IMplementtaion of the  document class program that allows a user
// to interactively edit a test file
//-----------------------------------------------------------------
// Class: CS 215                     Instructor: Dr. Deborah Hwang
// Assignment:    Project 5          Date assigned:  4/7/2017
// Programmer:    Kunal Mukherjee    Date completed: 4/16/2017


//header file
#include "document2.h"
#include <algorithm>

//Default Constructor
Document::Document()
{
  //creation of the head Ptr
  headPtr = new NodeType<std::string>;
  //attaching the header next and back to itself
  headPtr->next = headPtr;
  headPtr->back = headPtr;
}

//Copy Constructor
Document::Document(const Document & original)
{
  // Creation of the header node
  headPtr = new NodeType<std::string>;
  headPtr->next = headPtr;
  headPtr->back = headPtr;

  //copy of the current ptr
  currentPtr = original.currentPtr;

  //Copy data noded
  // Start at first data node of orginal
  NodeType<std::string> *scanPtr = original.headPtr->next;
  //Stop at the original header node
  while (scanPtr != original.headPtr)
    {
      //Create copy node
      NodeType<std::string> *newNode = new NodeType<std::string>;
      newNode->info = scanPtr->info;
      // Insert between the last node and the header node
      //back points to the last node
      newNode->back = headPtr->back;
      //next point to header node
      newNode->next = headPtr;
      //predecessor next points to new node
      headPtr->back->next = newNode;
      //sucessor back points to new node
      headPtr->back = newNode;
      //increment scanPtr
      scanPtr = scanPtr->next;	
    }
    }

//Destructore
Document::~Document()
{
  NodeType<std::string>* tempPtr;
  NodeType<std::string>* header = headPtr;  // header node
  headPtr = headPtr -> next;      // start with first data node
   
  // Delete the the nodes
  while (headPtr != header)  // stop when get to header
    {
      tempPtr = headPtr;
      headPtr = headPtr->next;
      delete tempPtr;
    }
  delete header;
 
}

//Assignment operator
Document & Document::operator= (const Document & original)
{
  // Make a copy of the original
  Document theCopy(original);
  // Swap contents of this object with the copy
  // Using std::swap from the STL <algorithm> library
  std::swap(theCopy.headPtr, headPtr);
  std::swap(theCopy.currentPtr, currentPtr);
  // Return this object -- upon return, theCopy containing the
  //                       original data will be destroyed
  return *this;  // 'this' is a pointer, so need to dereference.
}

//Load
void Document::Load (std::istream& in)  // REC'D/P'BACK: input stream
{   
  std::string line;   
  // insert each line of text into document
  while (std::getline(in, line))
    {
      //create a new line
      NodeType<std::string>* newNode;
      newNode = new NodeType<std::string>;

      //put the data into the info
      newNode->info = line;  
      //attach the next and back accordingly
      newNode->next = headPtr;  
      newNode->back = headPtr->back;
      headPtr->back->next = newNode;   
      headPtr->back = newNode;     
    }

  // set current to first line
  currentPtr = headPtr->next; 
}

//Make Empty
void Document::MakeEmpty()
{
   NodeType<std::string>* tempPtr;
   NodeType<std::string>* header = headPtr;  // header node
   headPtr = headPtr -> next;            // start with first data node
   
   // Delete the data nodes
   while (headPtr != header)  // stop when get to header
   {
      tempPtr = headPtr;
      headPtr = headPtr->next;
      delete tempPtr;
   }
   // Reset header node links for empty list
   headPtr->next = headPtr;
   headPtr->back = headPtr;
   
   currentPtr = 0;
}

//IsEmpty
bool Document::IsEmpty() const
{
  // true only if the header is pointing to itself
  if (headPtr-> next == headPtr)
      return true;
   return false;
}

//Insert
void Document::Insert (std::string newLine)
{

  if(IsEmpty())
    {
      //The new cretaed for insertion
      NodeType<std::string>* newNode;
      newNode = new NodeType<std::string>;
      //put the info into the newLIne
      newNode->info = newLine;  
      //attach the newNode first
      newNode->next = headPtr;  
      newNode->back = headPtr->back;
      //connect to the newNode
      headPtr->back->next = newNode;   
      headPtr->back = newNode;
      //update the currentPtr;
      currentPtr = headPtr->next;
    }
  
  else
    {
      // NodeType<std::string>* location = new NodeType<std::string>;
      // location =  currentPtr;

      NodeType<std::string>* location = currentPtr;

      NodeType<std::string>* newNode;
      newNode = new NodeType<std::string>;
  
      newNode->info = newLine;
      // Set new node links
      newNode->next = location;
      newNode->back = location->back;
      
      // Set predecessor next link
      location->back->next = newNode;
      // Set successor back link      
      location->back = newNode;
      
      currentPtr = location->back;
    }
}

//Append
void Document::Append (std::string newLine)
{
  //create the new node
  NodeType<std::string>* newNode;
   newNode = new NodeType<std::string>;

   newNode->info = newLine;  
    // Set new node links
   newNode->next = headPtr;  
   newNode->back = headPtr->back;
    // Set predecessor next link and back link
   headPtr->back->next = newNode;   
   headPtr->back = newNode;

   currentPtr = headPtr->back;

}

//Replace
void Document::Replace (std::string new_Line)
{
  if (IsEmpty())
    throw std::string("This document is empty");
  //if not empty then replace the current value
  else
    currentPtr->info = new_Line;
}

//Erase
void Document::Erase ()
{

  if( !IsEmpty())
    {
      //make the temp pointer point to the current node
      NodeType<std::string>* tempPtr = currentPtr;

      if (currentPtr->next == headPtr)
	{
	  //reattach the current pointer
	  currentPtr = currentPtr->back;
	  //isolate the tempPtr by reattching the predecessor node's nexta nd back
	  tempPtr->back->next = tempPtr->next;
	  tempPtr->next->back = tempPtr->back;
	}
      else
	{
	  currentPtr = currentPtr->next;
	  tempPtr->back->next = tempPtr->next;
	  tempPtr->next->back = tempPtr->back;
	}
      //delete the tempPtr
      delete tempPtr;
    }
  else
    throw (std::string("Invalid number"));
}

//Find
bool Document::Find (std::string target)
{
  bool moreToSearch = true;
  bool found;

  //creation of the pointer from where the scna will begin
  NodeType<std::string>* location = headPtr->next;
  
  found = false;
  while (moreToSearch && !found)
    {
      //if it is found
      if ((location->info).find(target) != std::string::npos)
	{
	  found = true;
	  //update the currentPtr
	  currentPtr = location;
	  //retur true
	  return found;
	}
      //if it is not found
      else
	{
	  //go to the next node
	  location = location->next;
	  //contnue searching till we havenot reached the headernode
	  moreToSearch = (location != headPtr);  // stop at the header node
	}   
    }
  return found;
}

//SetCurrent
void Document::SetCurrent (int n)
{

  int maxLength = 0;

  NodeType<std::string>* maxL = headPtr->next;
  //finding the max length
  while (maxL != headPtr)
    {
      //counter to count till it reached the header node back
      maxLength++;
      maxL = maxL->next;
    } 

  //conditional statement
  if (n >= 0 && n < maxLength)
    {

      //a scanning pointer
      NodeType<std::string>* current = currentPtr;

      //reset the currentPtr
      currentPtr = headPtr->next;
      
      for (int i = 0; i < n; i++)
	{
	  //keep of going till it has reached the destination node
	  currentPtr = currentPtr->next;
	  //if the destination node is headPtr then it has over run and throw an error
	  if (currentPtr == headPtr->next)
	    {
	      currentPtr = current;
	      throw (std::string("Invalid number"));
	    }
	}
    }
  else
     throw (std::string("Invalid number"));
}

//MoveCurrent
void Document::MoveCurrent (int n)
{
  if (!IsEmpty())
    {  
      //scanning pointer
      NodeType<std::string>* current = currentPtr;
      
      int length = 0;

      bool moreToSearch = true;
      bool found;     

      NodeType<std::string>* location = headPtr->next;
      
      found = false;

      // find the node where it is currentPtr is pointing to
      while (moreToSearch && !found)
	{
	  if ((location->info).find(currentPtr->info) != std::string::npos)
	    {
	      found = true;
	      currentPtr = location;
	     
	    }
	  else
	    {
	      length++;
	      location = location->next;
	      moreToSearch = (location != headPtr);  // stop at the header node
	    }   
	}

      int maxLength = 0;      

      //findig the max length
      NodeType<std::string>* maxL = headPtr->next;
       
      while (maxL != headPtr)
	{
	  maxLength++;
	  maxL = maxL->next;
	}

      //used these two values to make sure the bounds are placed right
      if ( length + n >= maxLength || length + n < 0)
	throw (std::string("Invalid number"));    
      
     
      try
	{	      
	  //set the current node up or down that many placed depending on the user input
	  SetCurrent (length + n);
	}
      catch (const std::string exception)
	{
	  currentPtr = current;
	  throw (std::string( exception));
	}	    
  
    }
  else
    throw std::string("Document is Empty");
  
}

//Write Line
void Document::WriteLine (std::ostream & out) const
{
  if (!IsEmpty() && currentPtr != headPtr)
    out << currentPtr->info << std::endl; // write line to output stream
}

//Write All
void Document::WriteAll (std::ostream & out) const
{
  // the scanning pointer pointing to the first node
  NodeType<std::string> *temp = headPtr->next;
  // keeps on printing till the document is empty
  if (!IsEmpty())
    {
      while (temp != headPtr)
	{
	  out << temp->info << std::endl;
	  temp = temp->next;	 
	}
    }
 
}


  

 






