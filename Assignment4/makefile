#
# PROGRAM:    Assignment 4   
# PROGRAMMER: Carlton Hunt 
# LOGON ID:   Z1772974
# DATE DUE:   02/22/18 
#
# Compiler variables
CCFLAGS = -ansi -Wall -std=c++11

# Rule to link object code files to create executable file
assignment4: assignment4.o
	g++ $(CCFLAGS) -o assignment4.exe assignment4.o

# Rule to compile source code file to object code
assignment4.o: assignment4.cc	assignment4.h
	g++ $(CCFLAGS) -c assignment4.cc

# Pseudo-target to remove object code and executable files
clean:
	-rm -f *.o assignment4.exe
