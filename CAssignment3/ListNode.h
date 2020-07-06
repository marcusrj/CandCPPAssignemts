#include <iostream>

#ifndef _LISTNODE_H
#define _LISTNODE_H

#include "Person.h" 

using namespace std;

//Defines a listnode class
class ListNode{
	private:
		//Stores a person
		Person* data;
		//Stores a pointer to the next node
		ListNode* next;
	public:
		//Default Constructor
		ListNode();
		//Constructor with a person passed in to be stored in node
		ListNode(Person* p);
		//Deconstructor
		~ListNode();

		//Returns pointer to next node
		ListNode* getNext();
		//sets the next node to be the node passed in
		void setNext(ListNode* n);
		//returns pointer to person stored in node
		Person* getData();
		//sets the data to be the person that was passed in
		void setData(Person* p);

		//Calls to string method on the person stored in data
		string toString();
};
#endif
