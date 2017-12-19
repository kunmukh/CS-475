main: main.o Markup.o
	g++ -Wall main.o Markup.o -o main

markup.o: Markup.cpp Markup.h
	g++ -Wall -c Markup.cpp

main.o: main.cpp Markup.h
	g++ -Wall -c main.cpp

