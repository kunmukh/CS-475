# File: Makefile
# Makefile for UnsortedType class test program
# Class: CS 215

listdriver: listdriver.o unsorted.o itemtype.o
	clang++ -g -Wall -o listdriver listdriver.o unsorted.o itemtype.o

listdriver.o: listdriver.cpp unsorted.h itemtype.h
	clang++ -g -Wall -c listdriver.cpp

unsorted.o: unsorted.cpp unsorted.h itemtype.h
	clang++ -g -Wall -c unsorted.cpp

itemtype.o: itemtype.cpp itemtype.h
	clang++ -g -Wall -c itemtype.cpp

clean:
	rm -f *.o listdriver *~
