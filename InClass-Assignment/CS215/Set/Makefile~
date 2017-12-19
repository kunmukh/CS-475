# File: Makefile
# Class: CS 215                    # Instructor: Dr. Deborah Hwang
# Assignment:         SetCard      # Date assigned: 2/3/2017
# Programmer: Kunal Mukherjee      # Date completed: 2/8/2017

settester: setcard.o settester.o #links the objects files into executable
	clang++ -Wall setcard.o settester.o -o settester

setcard.o: setcard.cpp setcard.h
	clang++ -Wall -c setcard.cpp

settester.o: settester.cpp setcard.h
	clang++ -Wall -c settester.cpp

submit.tar: Makefile setcard.h setcard.cpp settester.cpp
	tar -cvf submit.tar Makefile setcard.h setcard.cpp settester.cpp




