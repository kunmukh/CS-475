# File: Makefile
# Makefile for SortedType class test program
# Class: CS 215

listdriver: listdriver.o itemtype.o
	clang++ -g -Wall -o listdriver listdriver.o itemtype.o

# Note use of -std=c++11 option
listdriver.o: listdriver.cpp sorted.h sortediter.h itemtype.h
	clang++ -g -Wall -std=c++11 -c listdriver.cpp

itemtype.o: itemtype.cpp itemtype.h
	clang++ -g -Wall -c itemtype.cpp

clean:
	rm -f *.o listdriver *~
