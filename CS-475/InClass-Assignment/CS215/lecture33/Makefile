# File: Makefile
# Makefile for SortedType class test program
# Class: CS 215

listdriver: listdriver.o itemtype.o
	clang++ -g -Wall -o listdriver listdriver.o itemtype.o

listdriver.o: listdriver.cpp sorted.h itemtype.h
	clang++ -g -Wall -c listdriver.cpp

itemtype.o: itemtype.cpp itemtype.h
	clang++ -g -Wall -c itemtype.cpp

clean:
	rm -f *.o listdriver *~
