# File: Makefile
# Class: CS 215                    # Instructor: Dr. Deborah Hwang
# Assignment:         Editor       # Date assigned: 2/23/2017
# Programmer: Kunal Mukherjee      # Date completed: 2/28/2017

editor: document.o editor.o
	clang++ -Wall document.o editor.o -o editor

document.o: document.cpp document.h
	clang++ -Wall -c document.cpp

editor.o: editor.cpp document.h
	clang++ -Wall -c editor.cpp

submit.tar: Makefile document.h document.cpp editor.cpp
	tar -cvf submit.tar Makefile document.h document.cpp editor.cpp





