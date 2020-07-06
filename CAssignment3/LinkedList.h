#include <iostream>
#include <string>

#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#include "ListNode.h" //also includes Person.h

using namespace std;
//Defines a linked list
class LinkedList{
	private:
		//Stores how many nodes are in the linked list
		int size;
		//Stores the head of the list
		ListNode* head;
	public:
		//Destructor
		~LinkedList();
		//Default Constructor
		LinkedList();
		//Constructor that aloows you to set the head of the linked list on creation (never actually used)
		LinkedList(ListNode* newHead);
		//Returns the size of the linked list
		int getSize();
		//sets the size of the linked list
		void setSize(int newSize);
		//returns a pointer to the listnode at the head of the list
		ListNode* getHead();
		//sets the head of list to be the node passed in
		void setHead(ListNode* newHead);
		//add a list node to the end of the list
		void addToEnd(ListNode* newNode);
		//delete a list node if it matches the data of the on that was passed in
		void deleteByName(ListNode* toDelete);
		//check if a person is in the list
		Person* contains(string name);
};
#endif