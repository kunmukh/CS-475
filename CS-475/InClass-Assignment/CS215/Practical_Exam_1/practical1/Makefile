##Kunal Mukherjee
##Practical Exam1
##Timer

problem2: timer.o problem2.o
	clang++ -Wall timer.o problem2.o -o problem2

timer.o: timer.cpp timer.h
	clang++ -Wall -c timer.cpp

problem2.o: problem2.cpp timer.h
	clang++ -Wall -c problem2.cpp

submit.tar: Makefile timer.h timer.cpp problem2.cpp
	tar -cvf submit.tar Makefile timer.h timer.cpp problem2.cpp 
