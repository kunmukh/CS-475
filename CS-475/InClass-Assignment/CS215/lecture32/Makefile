# File: Makefile
# Makefile for StackType<ItemType> class template test program
# Class: CS 215

stackdriver: stackdriver.o #stack.o
	clang++ -g -Wall -o stackdriver stackdriver.o #stack.o

stackdriver.o: stackdriver.cpp stack.h #itemtype.h
	clang++ -g -Wall -c stackdriver.cpp

#stack.o: stack.cpp stack.h itemtype.h
#	clang++ -g -Wall -c stack.cpp

date.o: date.cpp date.h
	clang++ -g -Wall -c date.cpp

clean:
	rm -f *.o stackdriver *~
