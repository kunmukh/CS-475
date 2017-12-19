# File: Makefile
# Class: CS 215                    # Instructor: Dr. Deborah Hwang
# Assignment:         Poject 7     # Date assigned: 4/19/2017
# Programmer: Kunal Mukherjee      # Date completed: 4/26/2017

coder: coder.o huffman.o
	clang++ -g -Wall -o coder coder.o huffman.o

coder.o: coder.cpp huffman.h
	clang++ -g -Wall -std=c++11 -c coder.cpp

huffman.o: huffman.cpp huffman.h
	clang++ -g -Wall -c huffman.cpp

submit.tar: Makefile huffman.h huffman.cpp coder.cpp
	tar -cvf submit.tar Makefile huffman.h huffman.cpp coder.cpp
