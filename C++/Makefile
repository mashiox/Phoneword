TORM = phoneword main.o phoneword.o
CC = g++
CCFLAGS = -g -O3 -Wall -std=c++11 -Wpointer-arith -Wcast-qual -Wwrite-strings

all: phoneword main

phoneword: phoneword.cc phoneword.h
	${CC} ${CCFLAGS} -c phoneword.cc

main: main.o
	${CC} ${CCFLAGS} -o phoneword main.o phoneword.o

main.o: main.cpp
	${CC} ${CCFLAGS} -c main.cpp

clean: 
	rm -f ${TORM}
