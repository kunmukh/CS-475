///File: huffman.cpp
// Implementtaion of the huffman class that allauws code to be
// displayed in binary tree  with certain properties
//-----------------------------------------------------------------
// Class: CS 215                     Instructor: Dr. Deborah Hwang
// Assignment:    Project 7          Date assigned:  4/19/2017
// Programmer:    Kunal Mukherjee    Date completed: 4/26/2017


#include "huffman.h"

struct TreeNode
{
  char info;
  TreeNode* left;
  TreeNode* right;
};

//Prototype of helper function
//CopyTree
void  CopyTree (TreeNode* & copyRoot, const TreeNode* localRoot);

//Destroy
void Destroy (TreeNode* & localRoot);

//WriteTree
void WriteTree (std::ostream & out, TreeNode* localRoot, int level);

//CharToCode
std::string CharToCode (char ch, TreeNode* localRoot, std::string pathSoFar);

//Default Constructor
HuffmanTree::HuffmanTree()
{
  //the intial pointer points to nothing
  root = NULL;
}

//Load
void HuffmanTree::Load (std::istream& codefile)
{
  int num = 0;
  int numSpace = 0;
  
  char code;
  char numCode;
  
  std::string line;
  
  TreeNode * temp = root;
  
  codefile >> num;  
  while (num > 0)
    {
      while(std::getline(codefile, line))
	{
	  code = line[0];
	  
	  while (!line [2 + numSpace] != std::string::npos)
	    {
	      TreeNode* newNode;
	      numCode = line [2 + numSpace];
	  
	      if (numCode == '0')
		{
		  if (temp->left != NULL)
		    {
		      temp = temp->left;
		    }
		  else
		    {
		      TreeNode* parentPtr = temp;
		      TreeNode* newNode = new TreeNode;
		      parentPtr->left = newNode;
		      newNode->info = '*';
		      newNode->left = NULL;
		      newNode->right = NULL;		      
		    }		  
		}	      
	      if (numCode == '1')
		{
		  if (temp->right != NULL)
		    {
		      temp = temp->right;
		    }
		  else
		    {
		      TreeNode* parentPtr = temp;
		      TreeNode* newNode = new TreeNode;
		      parentPtr->right = newNode;
		      newNode->info = '*';
		      newNode->left = NULL;
		      newNode->right = NULL;
		    }
		}	    	     
	      numSpace++;
	    };
	  temp->info = code;
	};
      num--;
    };  
}

//Copy Constructor
HuffmanTree::HuffmanTree (const HuffmanTree & source)
{
  // Calls recursive function CopyTree to copy the source
  CopyTree (root, source.root);
}

//CopyTree
void CopyTree (TreeNode*& copyRoot, const TreeNode* localRoot)
{
  if (localRoot == NULL) // the localroot is empty
    copyRoot = NULL;// copy is the empty tree
  else
    {
      // Make copy of the root node
      copyRoot = new TreeNode;
      copyRoot->info = localRoot->info;
      //Make copy of the left sub-tree
      CopyTree (copyRoot->left, localRoot->left);
      //Make copy of the right sub-tree
      CopyTree (copyRoot->right, localRoot->right);
    }
}

//Destructor
HuffmanTree::~HuffmanTree()
{
  // Calls recursively function Destroy to destroy the tree
  Destroy (root);
}

//Destroy
void Destroy(TreeNode*& localRoot)
// Post: tree is empty; nodes have been deallocated.
{
  if (localRoot != NULL) //not empty
    {
      // Destroy the left child
      Destroy (localRoot->left);
      //Destroy the right child
      Destroy (localRoot->right);
      // Delete the root node
      delete localRoot;
    }
}

//Make Empty
void HuffmanTree::MakeEmpty()
{
   Destroy(root);
   root = NULL;
}

//Assignment Operator
HuffmanTree & HuffmanTree::operator = (const HuffmanTree & source)
{
     // Use the swap technique
   HuffmanTree theCopy (source);
   // Swap contents
   std::swap (root, theCopy.root);  
   // Return self object, destructor automatically called on theCopy
   //    to delete the old data nodes
   return *this;   // 'this' is a pointer, so need to dereference
}

//Write
void HuffmanTree::Write (std::ostream & out) const
{
  WriteTree(out, root, 0);
}

//WriteTree
void WriteTree (std::ostream & out, TreeNode* localRoot, int level)
{
  if (localRoot != NULL)
    {
      WriteTree(out, localRoot->right, level +1);
      
      std::string spaces;
      std::string newLine;

      for (int i = 0; i < 8 * level; i++)
	std::string spaces = spaces + '%';
      
      out << newLine << spaces << localRoot->info;
      
      WriteTree(out, localRoot->left, level +1);
    }
}
    
// Encode
 void HuffmanTree::Encode (std::istream & messageFile, std::ostream & out) const
 {
   std::string output;
   std::string path;
   char ch;
   while (messageFile.get(ch))
     {
       path = output;
       output = CharToCode (ch, root, path);
       out << output << std::endl;
     }
 }

//CharToCode
std::string CharToCode (char ch, TreeNode* localRoot, std::string pathSoFar)
{
  if (localRoot->info == ch)
    return pathSoFar;
  else
    return CharToCode (ch, localRoot->right, pathSoFar + '1') +
      CharToCode (ch, localRoot->left, pathSoFar + '0');  
}

 //Decode
 void HuffmanTree::Decode (std::istream & messageFile, std::ostream & out) const
 {
   char ch;
   TreeNode * temp;
   temp = root;
   while (messageFile.get(ch))
     {
       if (ch == '0')
	 {
	   if (temp->left->info != NULL)
	     out << root->left->info << std::endl;
	   else
	     temp = temp->left;
	 }
       if (ch == '1')
	 {
	   if (root->right->info != NULL)
	     out << root->right->info << std::endl;
	   else
	     temp = temp->right;
	 }
     };
	  

 }
