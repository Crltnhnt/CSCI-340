#
# PROGRAM: Assignment 1
# PROGRAMMER: Carlton Hunt 
# LOGON ID: Z1772974
# DATE DUE: jan 29 2018
#
# Compiler variables
CCFLAGS = -ansi -Wall -std=c++11

# Rule to link object code files to create executable file
assignment1: assignment1.o
	g++ $(CCFLAGS) -o assignment1 assignment1.o

# Rule to compile source code file to object code
assignment1.o: assignment1.cc
	g++ $(CCFLAGS) -c assignment1.cc

# Rule to compile source code file and create executable file
	g++ -Wall assignment1.cc -o assignment1.exe

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assignment1
