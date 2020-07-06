#include "ListNode.h"
//Constructor with a person passed in to be stored in node
ListNode::ListNode(Person* p)
{
	data = p;
	next = NULL;
}
//Default Constructor
ListNode::ListNode()
{
	data = NULL;
	next = NULL;
}
//Destructor
ListNode::~ListNode()
{
	delete data;
}
//Returns pointer to next node
ListNode* ListNode::getNext()
{
	return next;
}
//sets the next node to be the node passed in
void ListNode::setNext(ListNode* n)
{
	next = n;
}
//returns pointer to person stored in node
Person* ListNode::getData()
{
	return data;
}
//sets the data to be the person that was passed in
void ListNode::setData(Person* p)
{
	data = p;
}
//Calls to string method on the person stored in data
string ListNode::toString()
{
	return data->toString();
}