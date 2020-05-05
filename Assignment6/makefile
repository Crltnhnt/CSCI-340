#
# PROGRAM: Assignment 5   
# PROGRAMMER: Carlton Hunt 
# LOGON ID: Z1772974
# DATE DUE: March 23, 2018 
#
# Compiler variables
CCFLAGS = -ansi -Wall -std=c++11

# Rule to link object code files to create executable file
assignment6.exe: assignment5.o assignment6.o assignment6main.o 
	g++ $(CCFLAGS) -o assignment6.exe assignment5.o assignment6.o assignment6main.o

# Rule to compile source code file to object code
assignment6.o: assignment6.cc
	g++ $(CCFLAGS) -c assignment6.cc

assignment5.o: assignment5.cc
	g++ $(CCFLAGS) -c assignment5.cc

assignment6main.o: assignment6main.cc
	g++ $(CCFLAGS) -c assignment6main.cc

# Pseudo-target to remove object code and executable files
clean:
	rm -f *.o assignment6.exe
