#include "LinkedList.h"


//Default Constructor
LinkedList::LinkedList()
{
	size = 0;
	head =NULL;
}
//Constructor that aloows you to set the head of the linked list on creation (never actually used)
LinkedList::LinkedList(ListNode* newHead)
{
	head = newHead;
	size = 1;
}
//Destructor
LinkedList::~LinkedList()
{
	//deletes the head
	delete head;
}
//Returns the size of the linked list
int LinkedList::getSize()
{
	return size;
}
//sets the size of the linked list
void LinkedList::setSize(int newSize)
{
	size = newSize;
}
//returns a pointer to the listnode at the head of the list
ListNode* LinkedList::getHead()
{
	return head;
}
//sets the head of list to be the node passed in
void LinkedList::setHead(ListNode* newHead)
{
	head = newHead;
}
//add a list node to the end of the list
void LinkedList::addToEnd(ListNode* newNode)
{
	ListNode* current = NULL;

	//if the head is null new node is the head
	if (head == NULL)
	{
		head = newNode;
	}
	else
	{
		//set current to be the head
		current = head;
		//loop until at the end of the list
		while (current->getNext() != NULL)
		{
			//set current to be its next node
			current = current->getNext();
		}
		//store new node in currents next
		current->setNext(newNode);
	}
	//increment size
	size++;
}
//delete a list node if it matches the data of the on that was passed in
void LinkedList::deleteByName(ListNode* toDelete)
{
	ListNode* temp = head;
	if (head->getData() == toDelete->getData())
	{
		cout<< "delete1"<<endl;
		delete head;
		head = toDelete->getNext();
		return;	
	}
	else
	{
		cout<< "delete2"<<endl;
		while (temp->getNext() != NULL)
		{
			if(temp->getNext()->getData() == toDelete->getData())
			{
				break;
			}
			temp = temp->getNext();
		}
	}
	temp->setNext(toDelete->getNext());
	delete toDelete;
	size--;
}
//check if a person is in the list
Person* LinkedList::contains(string name)
{
	//pointer toa list node and set to head
	ListNode* temp = head;
	//if head is null return null
	if (head == NULL)
	{
		return NULL;
	}
	//if name of person stored in head matxhes the one passed in
	if (head->getData()->getName() == name)
	{
		//return person stored in head
		return head->getData();
	}
	else
	{
		//if next isnt null
		while(temp->getNext() != NULL)
		{
			//if nexts name is key
			if(temp->getNext()->getData()->getName() == name)
			{
				//return person
				return temp->getNext()->getData();
			}
			//set temp to temp next
			temp = temp->getNext();
		}
	}
	//else return null
	return NULL;
}
