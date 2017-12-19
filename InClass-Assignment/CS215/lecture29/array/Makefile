# File: Makefile
# Makefile for StackType class test program
# Class: CS 215

stackdriver: stackdriver.o stack.o
	clang++ -g -Wall -o stackdriver stackdriver.o stack.o

stackdriver.o: stackdriver.cpp stack.h itemtype.h
	clang++ -g -Wall -c stackdriver.cpp

stack.o: stack.cpp stack.h itemtype.h
	clang++ -g -Wall -c stack.cpp

clean:
	rm -f *.o stackdriver *~
