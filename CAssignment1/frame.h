/*
  Name: Marcus Robertson-Jones
  Matric No: 150010807
  Module No: AC21008
*/

#ifndef H_FRAME_HEADER
#define H_FRAME_HEADER

#include <stdio.h>

//defining frame struct, contains an int and a pointer to another frame.
typedef struct Frame {
	
	int data;
	struct Frame* next;

} Frame;

#endif

