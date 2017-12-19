# this is a comment
# Makefilel for the Date class and driver program

#Makefile entry:target is the thing to be created
#		dependencies are the files that are used to create it
#		command that creates the thing
# <target>: <dependencies>
# <TAB> <command>
datedriver: date.o datedriver.o # links the objects files into executable
	clang++ -Wall date.o datedriver.o -o datedriver

date.o: date.cpp date.h # -c compiles source file into object file
	clang++ -Wall -c date.cpp

datedriver.o: datedriver.cpp date.h
	clang++ -Wall -c datedriver.cpp

submit.tar: Makefile date.h date.cpp datedriver.cpp
	tar -cvf submit.tar Makefile date.h date.cpp datedriver.cpp

clean: #dummy target
	rm -f datedriver *.o *~
