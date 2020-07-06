#include "stack.h"

void printEmpty(Stack* stk)
{
	printf("Checking if stack is empty... ");
	if (isEmpty(stk) == true)
	{
		printf("Stack is empty\n");
	}
	else
	{
		printf("Stack is not empty\n");
	}
}

void pushAndPrint(Stack* myStack, int x)
{
	push(myStack,x);
	printf("\t Pushed: %d New Head: %d Size: %d\n", x,myStack->head->data,myStack->size);
	
}

//void popAndPrint(Stack* myStack)
//{
	//int x = pop(myStack);
	
	//printf("%d\n",myStack->size);


//}


int main(int argc, char* argv[])
{
	printf("\n");
	printf("Creating Stack...\n");
	Stack* myStack = createStack();	
	
	printEmpty(myStack);

	printf("Pushing five numbers...\n");
	pushAndPrint(myStack,10);
	pushAndPrint(myStack,20);
	pushAndPrint(myStack,30);
	pushAndPrint(myStack,40);
	pushAndPrint(myStack,50);

	
	printEmpty(myStack);

	
	//printf("%d\n",myStack->size);
	//printf("\t Popped: New Head: %d\n",myStack->head->data);
	
	int x = pop(myStack);
	printf("\t Popped: %d New Head: %d Stack Size: %d\n", x,myStack->head->data,myStack->size);
	x = pop(myStack);
	printf("\t Popped: %d New Head: %d Stack Size: %d\n", x,myStack->head->data,myStack->size);
	x = pop(myStack);
	printf("\t Popped: %d New Head: %d Stack Size: %d\n", x,myStack->head->data,myStack->size);
	x = pop(myStack);
	printf("\t Popped: %d New Head: %d Stack Size: %d\n", x,myStack->head->data,myStack->size);
	x = pop(myStack);
	printf("\t Popped: %d New Head: NULL Stack Size: %d\n", x,myStack->size);
	//printf("%d\n",myStack->size);

	
}


