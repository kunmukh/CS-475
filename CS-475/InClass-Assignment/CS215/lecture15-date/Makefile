# File: Makefile
# Makefile for UnsortedType class test program
# Class: CS 215

listdriver: listdriver.o unsorted.o date.o
	clang++ -g -Wall -o listdriver listdriver.o unsorted.o date.o

listdriver.o: listdriver.cpp unsorted.h date.h
	clang++ -g -Wall -c listdriver.cpp

unsorted.o: unsorted.cpp unsorted.h date.h
	clang++ -g -Wall -c unsorted.cpp

date.o: date.cpp date.h
	clang++ -g -Wall -c date.cpp

clean:
	rm -f *.o listdriver *~
