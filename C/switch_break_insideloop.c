#include <stdio.h>
#include <stdlib.h>

/* Testing how loops react to the break/continue statement in a switch */
void switchwierdcases()
{
	int loop_var = 1;
	//int sw_var;

	while(loop_var <= 10)
	{
		switch(loop_var)
		{
			case 1:
				printf("Value of loop_var is 1 \n");
				loop_var = loop_var + 1;
				continue;/* goes to the top of the while loop */

			case 2:
				printf("Value of loop_var is 2 \n");
				loop_var = loop_var + 1;			
				break;/* also goes to the top of the while loop */

			case 3:
				printf("Value of loop_var is 3 \n");
				loop_var = loop_var + 1;			
				break;

			case 4:
				printf("Value of loop_var is 4 \n");
				loop_var = loop_var + 1;			
				break;		

			default:
				printf("V... Wait... what?? \n");
				loop_var = loop_var + 1;
				return;/* this breaks out of the while loop and exits the function */							
		}

	}	

}

int main()
{
	switchwierdcases();
	return 0;

}