/******************************************************************
 CSCI 340 - Assignment 8 - Spring 2018

 Progammer: Carlton Hunt
 Z-ID: Z1772974
 Section: 1
 TA: Saurabh Chitre
 Date Due: 04/16/2018
 Purpose: This program will create, search, print, and manage an
	  item inventory.
 *****************************************************************/

#ifndef ASSIGNMENT8_H
#define ASSIGNMENT8_H
#include <vector>
#include <string>

struct Entry
{
	std::string key;
	std::string description;
	Entry() { key = "---"; }
};

class HT
{
private:
	std::vector<Entry>* hTable;
	int table_size;
	int item_count;
	int hashing(const std::string&);
public:
	HT(int size);
	~HT();
	bool insert(const Entry&);
	int search(const std::string&);
	bool remove(const std::string&);
	void print();
};

#endif
