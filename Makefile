# Makefile for CS 24 Project 2
#     Done: you do not need to change or submit it

# Usage:
#     Either "make" - compile/link listtester
#     Or "make clean" - remove all .o and executable

listtester: listtester.o dlist.o
	g++ -Wall -o listtester listtester.o dlist.o

listtester.o: listtester.cpp
	g++ -Wall -c listtester.cpp

dlist.o: dlist.cpp
	g++ -Wall -c dlist.cpp

clean:
	rm -f listtester.o dlist.o
	rm -f listtester
