# File: Makefile
# Makefile for TreeType class test program
# Class: CS 215

treedriver: treedriver.o tree.o
	clang++ -g -Wall -o treedriver treedriver.o tree.o

treedriver.o: treedriver.cpp tree.h
	clang++ -g -Wall -std=c++11 -c treedriver.cpp

tree.o: tree.cpp tree.h
	clang++ -g -Wall -c tree.cpp

clean:
	rm -f *.o treedriver *~
