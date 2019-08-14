## Makefile
## Kunal Mukherjee

problem2: problem2.o chart.o
	clang++ -g -Wall -o problem2 problem2.o chart.o

problem2.o: problem2.cpp chart.h
	clang++ -g -Wall -c problem2.cpp

chart.o: chart.cpp chart.h
	clang++ -g -Wall -c chart.cpp
