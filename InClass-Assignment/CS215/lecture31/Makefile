# File: Makefile
# Makefile for QueueType class test program
# Class: CS 215

queuedriver: queuedriver.o queue.o
	clang++ -g -Wall -o queuedriver queuedriver.o queue.o

queuedriver.o: queuedriver.cpp queue.h itemtype.h
	clang++ -g -Wall -c queuedriver.cpp

queue.o: queue.cpp queue.h itemtype.h
	clang++ -g -Wall -c queue.cpp

clean:
	rm -f *.o queuedriver *~
