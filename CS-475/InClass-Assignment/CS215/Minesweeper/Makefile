# File: Makefile
# Class: CS 215                    # Instructor: Dr. Deborah Hwang
# Assignment:         Minesweepr   # Date assigned: 3/17/2017
# Programmer: Kunal Mukherjee      # Date completed: 3/24/2017

sweeper: sweeper.o sweepergrid.o sweepercell.o
	clang++ -g -Wall -o sweeper sweeper.o sweepergrid.o sweepercell.o

sweeper.o: sweeper.cpp sweepergrid.h sweepercell.h
	clang++ -g -Wall -c sweeper.cpp

sweepergrid.o: sweepergrid.cpp sweepergrid.h sweepercell.h
	clang++ -g -Wall -c sweepergrid.cpp

sweepercell.o: sweepercell.cpp sweepercell.h
	clang++ -g -Wall -c sweepercell.cpp

submit.tar: Makefile sweepergrid.h sweepergrid.cpp sweeper.cpp
	tar -cvf submit.tar Makefile sweepergrid.h sweepergrid.cpp sweeper.cpp

clean:
	rm -f *.o listdriver *~
