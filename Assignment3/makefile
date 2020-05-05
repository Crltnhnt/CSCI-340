#
# PROGRAM:    Assignment 3   
# PROGRAMMER: Carlton Hunt 
# LOGON ID:   Z1772974
# DATE DUE:   February 14th 2018
#
# Compiler variables
CCFLAGS = -ansi -Wall -std=c++11

# Rule to link object code files to create executable file
assignment3: assignment3.o
	g++ $(CCFLAGS) -o assignment3.exe assignment3.o

# Rule to compile source code file to object code
assignment3.o: assignment3.cc
	g++ $(CCFLAGS) -c assignment3.cc

# Pseudo-target to remove object code and executable files
clean:
	-rm -f *.o assignment3.exe

