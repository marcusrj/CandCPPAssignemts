/*
  Name: Marcus Robertson-Jones
  Matric No: 150010807
  Module No: AC21008
*/

#ifndef H_FRAME_MANAGER_HEADER
#define H_FRAME_MANAGER_HEADER


#include <stdio.h>						
#include "frame.h"	//Include frame.h that i made (uses "" because user defined)

// Creates a frame using malloc and returns a pointer to it
Frame* getFrame();

// Resets the values of oldFrame and frees the memory
void releaseFrame(Frame* oldFrame);

#endif
