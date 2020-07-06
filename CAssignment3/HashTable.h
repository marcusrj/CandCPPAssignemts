#include <iostream>

#ifndef _HASHTABLE_H
#define _HASHTABLE_H

#include "ListNode.h"
#include "LinkedList.h"

using namespace std;

class HashTable{
	private:
		//stores an array or linked lists
		LinkedList* HashArray[20];
	public:
		//constructor
		HashTable();
		//destructor
		~HashTable();
		//hashes the string input and returns an int
		int hash(string input); 
		//adds a person to the table
		void addToTable(string key, Person* value);
		//returns a person from the table (returns null if not found)
		Person* getFromTable(string key);
		//remove a person whos name matches the one passed in, if they are in the table
		void removeFromTable(string name);
		//display all people stored in the table
		void displayAll();
		//display the sizes of all 20 linked lists
		void displayListSizes();
};
#endif
