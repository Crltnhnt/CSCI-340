/******************************************************************
 CSCI 340 - Assignment 8 - Spring 2018

 Progammer: Carlton Hunt
 Z-ID: Z1772974
 Section: 1
 TA: Saurabh Chitre
 Date Due: 04/16/2018
 Purpose: This program will create, searc, print, and manage an
	   item inventory.
 *****************************************************************/

#include "assignment8.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

/***************************get_entry*************************************
Use: This method takes a line of input and parses it to make a new Entry.
Returns: Returns a new Entry that holds the 'key'.
*************************************************************************/
Entry* get_entry(const string& line)
{
	Entry* parsed_line = new Entry;

	parsed_line->key = line.substr(2, 3);
	parsed_line->description = line.substr(6, line.length() - 6);

	return parsed_line;
}

/******************************get_key**************************************
Use: This method takes a line of input and parses it to return the item-key.
Returns: Returns the parsed string which contains the key.
***************************************************************************/
string get_key(const string& line)
{
	string gKey = line.substr(2, 3);

	return gKey;
}

/******************************HT******************************************
Use: This is the default constructor.
Returns: No Returns.
*************************************************************************/
HT::HT(int s = 11)
{
	hTable = new vector<Entry>(s);

	table_size = s;
	item_count = 0;
}

/*****************************~HT****************************************
Use: This is the destructor for HT.
Returns: No Returns.
************************************************************************/
HT::~HT()
{
	delete hTable;
}

/*******************************************search***************************************
Use: This public member function searches the hash table for a record with a given 'key'.
Returns: The position of the found item.
*****************************************************************************************/
int HT::search (const string& key)
{
	int keyIndex = hashing(key);

	for(int i = 0; i < table_size; i++)
	{
		if ((*hTable)[keyIndex].key == key)
			return keyIndex;

		keyIndex = (keyIndex + 1) % table_size;
	}
	return -1;
}

/***************************insert************************************
Use: This public member function inserts item 'e' in the hash table.
Returns: True/False checkpoint.
*********************************************************************/
bool HT::insert(const Entry& e)
{
	int keyIndex = hashing(e.key);
	string sKey = e.key;

	if (search(sKey) != -1)
	{
		cerr << "Unable to insert...identical key found" << endl;
		return false;
	}
	else if (item_count == table_size)
	{
		cerr << "Unable to insert...the table is full." << endl;
		return false;
	}

	else
	{
		int i;

		for (i = 0; i < table_size; i++)
		{
			if ((*hTable)[keyIndex].key == "---" || (*hTable)[keyIndex].key == "+++")
			{
				(*hTable)[keyIndex] = e;
				item_count++;

				return true;
			}
			keyIndex = keyIndex + 1 % table_size;
		}
	}

	return false;
}

/*********************************remove******************************
Use: This public member function removes an item with given key 's'.
Returns: True/False checkpoint
*********************************************************************/
bool HT::remove(const string& s)
{
	if (search(s) == -1)
	{
		return false;
	}

	else
	{
		int keyIndex = search(s);

		(*hTable)[keyIndex].key = "+++";
		item_count--;
		return true;
	}
}

/****************************print***********************************************
Use: This public member function prints the existing entries in the hash table.
Returns: No Returns.
********************************************************************************/
void HT::print ()
{
	cout << endl << "----Hash Table-----" << endl;

	for (int i = 0; i < table_size; i++)
	{
		if ((*hTable)[i].key != "---" && (*hTable)[i].key != "+++")
		{
			cout << right << setw(2) << i << ": ";
			cout << (*hTable)[i].key << " ";
			cout << (*hTable)[i].description << endl;
		}
	}

	cout << "-------------------" << endl << endl;
}


// key is in form of letter-letter-digit
// compute sum <-- ascii(pos1)+ascii(pos2)+ascii(pos3)
// compute sum%htable_size
int HT::hashing(const string& key) {
	return ((int)key[0] + (int)key[1] + (int)key[2]) % table_size;
}

int main(int argc, char** argv) {
	if (argc < 2) {
		cerr << "argument: file-name\n";
		return 1;
	}

	HT ht;
	ifstream infile(argv[1], ios::in);
	string line;
	infile >> line;
	while (!infile.eof()) {
		if (line[0] == 'A') {
			Entry* e = get_entry(line);
			ht.insert(*e);
			delete e;
		}
		else {
			string key = get_key(line);
			if (line[0] == 'D') {
				cout << "Removing " << key << "...\n";
				bool removed = ht.remove(key);
				if (removed)
					cout << key << " is removed successfully...\n\n";
				else
					cout << key << " does not exist, no key is removed...\n\n";
			}
			else if (line[0] == 'S') {
				int found = ht.search(key);
				if (found < 0)
					cout << key << " does not exit in the hash table ..." << endl << endl;
				else
					cout << key << " is found at table position " << found << endl << endl;
			}
			else if (line[0] == 'P') {
				cout << "\nDisplaying the table: " << endl;
				ht.print();
			}
			else
				cerr << "wrong input: " << line << endl;
		}
		infile >> line;

	}

	infile.close();
	return 0;
}
