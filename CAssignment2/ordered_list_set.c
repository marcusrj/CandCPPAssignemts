/*
  Name: Marcus Robertson-Jones
  Matric No: 150010807
  Module No: AC21008
*/

#include <assert.h>
#include <stdlib.h>
#include "ordered_list_set.h"

/* Creates an Ols , initialises its values and also returns a pointer to it */
OrderedListSet* createOLS()
{
	//Assigns memory for ols
	OrderedListSet *myOLS = malloc(sizeof(OrderedListSet));

	//Checks malloc worked
	assert(myOLS != NULL);

	//Sets values of ols to null or 0
	myOLS->size = 0;
	myOLS->head = NULL;
	myOLS->tail = NULL;

	//Return pointer to ols
	return myOLS;
}


/* Adds a value v to an ols so that items in ols are in order, item can only be in ols once */
void insertOLS(OrderedListSet* ols, int v)
{
	//Creates new node to put in list
	OLSNode *newNode = malloc(sizeof(OLSNode));
	//Checks creating node works
	assert(newNode != NULL);
	//Assigns v to be new nodes data
	newNode->data = v;

	
	//Checks if value v is in the ols, if yes then exit
	if (containsOLS(ols, v) == true)
	{
		return;
	}
	
	//Increment ols size by 1
	ols->size = ols->size + 1;

	//If head is null list is empty so new node is the head and the tail
	if (ols->head == NULL)
	{
		ols->head = newNode;
		ols->tail = newNode;
	}
	//If v is less than head's data then new node is the new head
	else if (newNode->data < ols->head->data)
	{
		newNode->next = ols->head;
		ols->head->prev = newNode;
		ols->head = newNode;
		
	}
	//If v is greater than tail's data then new node is the new tail
	else if (newNode->data > ols->tail->data)
	{
		newNode->prev = ols->tail;
		ols->tail->next = newNode;
		ols->tail = newNode;

	}
	else
	{
		OLSNode *prev = ols->head;
		OLSNode *current = ols->head->next;
		//While not at the end of the list
		while (current != NULL)
		{
			//if v is greater than prev data and less than current data 
			//put new node between them
			if (prev->data < v && v < current->data)
			{
				prev->next = newNode;
				newNode->prev = prev;
				newNode->next = current;
				current->prev = newNode;
				return;
				
			}
			//Increment prev and current
			prev=current;
			current=current->next;
		}
		//prev->next = newNode;
		//newNode->prev = prev;
		
	}

	

}

/* return true if value v is already in list return false if not in list */
bool containsOLS(OrderedListSet* ols, int v)
{
	//Temp store current node
	OLSNode *current = ols->head;

	//If not at end of the list
	while (current != NULL)
	{
		//If v is found in node return true
		if (v == current->data)
		{
			return true;
		}
		else 
		{
			//Cycle through list
			current = current->next;
		}
	}
	return false;
}

/* Removes value v from the ols if it is there */
void removeOLS(OrderedListSet* ols, int v)
{
	//Stores current node
	OLSNode *current = ols->head;
	
	//If v not in ols then return
	if (containsOLS(ols, v) == false)
	{
		return;
	}
	
	//Loop until current contains value v
	while (current->data != v)
	{
		current = current->next;
	}
	//if only one node, delete it
	if (ols->tail->data == ols->head->data)
	{
		ols->tail = NULL;
		ols->head = NULL;
	}
	//If value if head delete it, and set head to heads next
	else if (current->data == ols->head->data)
	{
		ols->head = current->next;
		ols->head->prev = NULL;
	}
	//If value is tail delete it, and set tail to tails previous
	else if (current->data == ols->tail->data)
	{
		ols->tail = current->prev;
		ols->tail->next = NULL;	
	}
	//link currents previous and next together in the list
	else
	{
		current->prev->next = current->next;
		current->next->prev = current->prev;
	}
	
	//Decrement size
	ols->size = ols->size -1;

	OLSNode *toDelete = current;
	
	//Clear values in node and free it
	toDelete->next = NULL;
	toDelete->prev = NULL;
	toDelete->data = 0;
	free(toDelete);
	
	

}

/* Free the contents of ols and then ols itself */
void deleteOLS(OrderedListSet* ols)
{
	//If ols isn't empty
	if (ols->size > 0)
	{
		OLSNode *toDelete = ols->head;
		OLSNode *next = ols->head->next;

		//Cycle through all nodes reset the values, then free the each
		while (ols->size > 0)
		{
			//Clears the values in the node
			toDelete->data = 0;
			toDelete->next = NULL;
			toDelete->prev = NULL;
			//Free the node
			free(toDelete);

			//Decrement size
			ols->size = ols->size - 1;

			//Go to next
			toDelete = next;
			next = next->next;
		}

	}
	//Clears the values in the ols
	ols->head = NULL;
	ols->tail = NULL;
	ols->size = 0;
	//Free the ols
	free(ols);
}


