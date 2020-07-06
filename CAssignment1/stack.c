/*
  Name: Marcus Robertson-Jones
  Matric No: 150010807
  Module No: AC21008
*/

#include <assert.h>
#include <stdlib.h>
#include "stack.h"

//creates a stack using malloc returns a pointer to it
Stack* createStack()
{
	Stack *myStack = malloc(sizeof(Stack));
	assert(myStack != NULL);
	return myStack;
}

bool isEmpty(Stack* stk)
{	
	//check if head is null to see if the stack is empty(you could check if size = 0)
	if (stk->head == NULL) 
	{
		return true;
	}
	else
	{
		return false;
	}
}

// adds a new frame to the top of a stack with value x as data
void push(Stack* stk, int x)
{
	Frame* frm1 = getFrame();	//create a frame to add to the stack
	frm1->data = x;
	frm1->next = stk->head;
	stk->head = frm1;
	stk->size = stk->size + 1 ;	//increment size
}

// removes the frame at the top of the stack return data value from frame deleted
int pop(Stack* stk)
{
	int r;
	// checks if the stack is empty
	if (isEmpty(stk) == true)
	{
		return 0;
	}
	//temporarily store the data from the frame being deleted
	r = stk->head->data;
	
	Frame* tmp = stk->head->next;
	releaseFrame(stk->head);	//release the frame thats is no longer needed
	stk->head = tmp;
	

	stk->size = stk->size - 1;	//decrement size
	
	return r;

}

// freeing a stack
void releaseStack(Stack* stk)
{
	if (stk->size != 0)
	{
		while(stk->size != 0)
		{
			pop(stk);
		} 
		stk->head = NULL;
		stk->size = 0;	
		free(stk);

	}
	else
	{
		stk->head = NULL;
		stk->size = 0;	
		free(stk);
	}
}
