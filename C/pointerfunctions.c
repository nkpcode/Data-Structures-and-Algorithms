#include <stdio.h>
#include <stdlib.h>

void initializearray(int* x, int length)
{
	for(int i = 0; i < length; i++)
	{
		x[i] = i; 
	}
}

void createarray(int **x, int length)
{
	/* dynamically allocate array */
	*x = (int*)malloc(length * sizeof(int));
}


void arrayofpointers(int* x, int length)
{

	int *x_ptr[length];/* Initializing the length of array of pointers */
	//int x[2];	

	for(int i = 0; i < length; i++)
	{
		/* Assign the addresses of the input array x */
		x_ptr[i] = (x + i);
	}

	printf("Array values using array of pointers:\n");
	for(int i = 0; i < length; i++)
	{	/* print all the elements */
		printf("%d\n",*x_ptr[i]);	
	}	
	
}

int main()
{
	//printf("Hello world\n");
	int length = 6;
	int *inputarray = NULL;
	createarray(&inputarray, length);
	initializearray(inputarray, length);/* try including this in the createarray function */
	arrayofpointers(inputarray, length);
	return 0;
}
