//File: huffman.h
// HUffman class creates a huffman tree and allows the code
// to be represented using a binary tree with certain properties
//-----------------------------------------------------------------
// Class: CS 215                     Instructor: Dr. Deborah Hwang
// Assignment:    Project 7          Date assigned:  4/19/2017
// Programmer:    Kunal Mukherjee    Date completed: 4/26/2017

#include <string>
#include <fstream>


#ifndef HUFFMAN_H_
#define HUFFMAN_H_


struct TreeNode;

class HuffmanTree
{
 public:

  //Default Constructor
  HuffmanTree();

  //Load
  void Load (std::istream& codefile);

  //Copy Constructor
  HuffmanTree(const HuffmanTree & source);  

  //Destructor
  ~HuffmanTree();  

  //MakeEmpty
  void MakeEmpty();

  //Assignment operator
  HuffmanTree & operator = (const HuffmanTree & source);

  //Write
  void Write (std::ostream & out) const;  

  //Encode
  void Encode (std::istream & messageFile, std::ostream & out) const;  

  //Decode
  void Decode (std::istream & messageFile, std::ostream & out) const;

 private:
  TreeNode* root; //pointer to the root of the tree

};

#endif //HUFFMAN_H_
  

