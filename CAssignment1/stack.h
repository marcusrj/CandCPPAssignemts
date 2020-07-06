/*
  Name: Marcus Robertson-Jones
  Matric No: 150010807
  Module No: AC21008
*/

#ifndef H_STACK_HEADER
#define H_STACK_HEADER

#include <stdio.h>
#include "frame.h"
#include <stdbool.h>
#include "frame_manager.h"

typedef struct Stack {
	int size;
	Frame* head;
}Stack;

Stack* createStack();
bool isEmpty(Stack* stk);
void push(Stack* stk, int x);
int pop(Stack* stk);
void releaseStack(Stack* stk);

#endif
