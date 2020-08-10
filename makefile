# Program name: makefile
# Author: Louis Adams
# Date: 2019-04-21
# Description: This is the makefile for Project 2.
# Adapted from: Week 1 Module, Lecture: Makefiles

CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
LDFLAGS = -lboost_date_time

EXECUTABLES = main

OBJECTS = ${SOURCES:.cpp=.o} 

SOURCES = main.cpp Zoo.cpp Animal.cpp Tiger.cpp Penguin.cpp Turtle.cpp NewAnimal.cpp menu.cpp getInteger.cpp getString.cpp outputMessage.cpp inputMessage.cpp

HEADERS = Zoo.hpp Animal.hpp Tiger.hpp Penguin.hpp Turtle.hpp NewAnimal.hpp menu.hpp getInteger.hpp getString.hpp outputMessage.hpp inputMessage.hpp

${EXECUTABLES}: ${OBJECTS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJECTS} -o ${EXECUTABLES}

${OBJECTS}: ${SOURCES}
	${CXX} ${CXXFLAGS} -c ${SOURCES}

clean:
	rm *.o ${EXECUTABLES} file.txt

zip:
	zip -D Project2_Adams_Louis.zip *.cpp *.hpp *.pdf makefile *.txt

val:
	valgrind ${EXECUTABLES} --leak-check=full./${EXECUTABLES}
