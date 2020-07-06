/*
  Name: Marcus Robertson-Jones
  Matric No: 150010807
  Module No: AC21008
*/


#include <assert.h>
#include <stdlib.h>
#include "frame_manager.h"

//Creates a frame usisng malloc and returns a pointer to it
Frame* getFrame()
{
	Frame *myFrame = malloc(sizeof(Frame));
	assert(myFrame != NULL);
	return myFrame;
	
}

void releaseFrame(Frame* oldFrame)
{
	
	assert(oldFrame != NULL);
	// reset the values stored in the frame
	oldFrame->data = 0; 
	oldFrame->next = NULL;	
	free(oldFrame->next);	// free the next frame pointer
	free(oldFrame->data);	// free the data int
	free(oldFrame);		// free the frame

} 


