#include "frame_manager.h"
#include <stdio.h>

/* Iterate from 'f' printing datas as we go. */
void printList(Frame *f)
{
	while(f != NULL) {
		printf(" %d ->", f->data);
		f = f->next;
	}
	printf(" %p\n", (void*)f);
}

/* Print out all details for 'f'. */
void printFrame(Frame *f)
{
	printf(" Address:%p  Data:%d  NextAddress:%p\n", (void*)f, f->data, (void*)f->next);
}

/* Basic testing for Frame. */
int main()
{
	// create five Frames
	printf("Creating five frames...\n");
	Frame *f1 = getFrame();
	Frame *f2 = getFrame();
	Frame *f3 = getFrame();
	Frame *f4 = getFrame();
	Frame *f5 = getFrame();
	
	// print the default frame datas
	printf("Printing frame default datas...\n");
	printFrame(f1);
	printFrame(f2);
	printFrame(f3);
	printFrame(f4);
	printFrame(f5);

	// populate the Frames
	// insert some datas
	printf("Inserting new datas...\n");
	f1->data = 10;
	f2->data = 20;
	f3->data = 30;
	f4->data = 40;
	f5->data = 50;
	// create a Linked List
	printf("Creating a linked list...\n");
	f1->next = f2;
	f2->next = f3;
	f3->next = f4;
	f4->next = f5; 
	f5->next = NULL;

	// print the assigned frame datas
	printf("Printing new frame datas...\n");
	printFrame(f1);
	printFrame(f2);
	printFrame(f3);
	printFrame(f4);
	printFrame(f5);

	// print the list (f1->f5)
	printf("List printing...\n");
	printList(f1);

	// release all frames
	printf("Releasing all frames...\n");
	releaseFrame(f1); 

	releaseFrame(f2);
	releaseFrame(f3);
	releaseFrame(f4);
	releaseFrame(f5);
	printf("...all frames released!\n");
	
	// print the reset frame datas (illegal access to memory)
	printf("Printing released frame datas...\n");
	printFrame(f1);
	printFrame(f2);
	printFrame(f3);
	printFrame(f4);
	printFrame(f5);

	printf("Finished test.\n");

	return 0;
}

