#include <stdio.h>
#include <stdlib.h>
//#define testing

typedef struct linky
{
	int value;
	struct linky* next; 
}node_struct;

void printlist(node_struct* head)
{
	node_struct* current = head;
	
	while(current != NULL)
	{
		printf("%d\t",current->value);
		current = current->next;
	}	
	printf("\n");
}

int pushtolist(node_struct* head, int value)
{
	node_struct* current = head;
	if(current == NULL)
	{		
		return 2220;
	}

	/* traverse to the end of the list */

	while(current->next != NULL)
	{
		current = current->next;
	}	
	
	current->next = (node_struct*)malloc(sizeof(node_struct));
	if(current == NULL)
	{
		return 2221;
	}
	
	current->next->value = value;
	current->next->next = NULL;
	
	return 0;
}

int pushtolisttop(node_struct** head, int value)
{
	node_struct* new_head;
	new_head = (node_struct*)malloc(sizeof(node_struct));
	if(new_head == NULL)
	{
		return 333;
	}	
	
	if(*head != NULL)
	{
		new_head->value = value;
		new_head->next = *head;
		*head = new_head;
	}
	else
	{
		return 444;
	}
	return 0;
}

int popfirstitem(node_struct** head)
{

	node_struct* temp = *head;
	*head = temp->next;
	free(temp);	
	return 0;
}	


int	poplastitem(node_struct* head)	
{
	node_struct* current = head;

	/* Remove the array if it has only one element */	

	if(head == NULL)
	{/* Check for empty list */
		printf("what!!");
		free(head);
		head = NULL;
		return 0;
	}


	else if(head->next == NULL)
	{
		printf("what!\t");
		free(head);
		head = NULL;
		return 0;
	}
	

	while(current != NULL)
	{/* peek into the next member in list */
		if(current->next->next == NULL)
		{
			free(current->next);
			current->next = NULL;
			break; 
		}
		current	= current->next;	
	}
}

void delelement(node_struct** head, int value)
{
	node_struct* before = *head;	
	node_struct* temp = *head;
	
	while(temp->next != NULL)
	{
		if(temp->value == value)
		{		
			break;
		}
		before = temp;
		temp = temp->next;
	} 
	
	if(before == *head)
	{/* if the element to remove is the first then */
		popfirstitem(head);		
	}
	else if((before != *head) && (temp->next != NULL))
	{/* other elements after */
		before->next = temp->next;
		free(temp);
	}
	else
	{/* if it the last element in the array */
		before->next = NULL;
		free(temp);
	}	
	
}


int main()
{
	node_struct* head = NULL;
	head = (node_struct*)malloc(sizeof(node_struct));
	if(head == NULL)
	{
		return 111;
	}	
#ifdef testing
	head->value = 1;
	head->next = (node_struct*)malloc(sizeof(node_struct));
	
	head->next->value = 2;
	head->next->next = NULL;
	
	node_struct* dum_head = NULL;

	//Testing 
	pushtolist(head, 3);
	pushtolist(head, 4);
	pushtolisttop(&head, 69);	
	printlist(head); //{69,1,2,3,4}
	/*
	popfirstitem(&head);	
	printlist(head);
	popfirstitem(&head);
	printlist(head);

	poplastitem(head);	
	printlist(head);
	poplastitem(head);
	printlist(head);
	poplastitem(head);
	head = NULL;
	printlist(head);
	poplastitem(head);
	printlist(head);
	*/

	delelement(&head,3);
	printlist(head);
	//delelement(head,69);
	//popfirstitem(&head);
	printlist(head);
	delelement(&head,4);
	printlist(head);
	delelement(&head,69);
	printlist(head);
	delelement(&head,1);
	printlist(head);
	delelement(&head,2);
	printlist(head);
#endif
	return 0;
}




