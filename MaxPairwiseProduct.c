#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>

int main()
{
	long n;

	long result = 0;/* long to accommodate big numbers */
	long max1 = 0;/* To store the maximum number */
	long max2 = 0;/* To store the next maximum number */

  scanf("%d",&n); /* Size of array */
	long *numbers = (long *)malloc(n * sizeof(long));

  /* Get the numbers */
	for(long i = 0; i < n; i++)
	{
		scanf("%lu", (numbers + i));
    /* Filter out the max1 and max2 as and when they arrive in the stream */
		if (max1 < numbers[i])
		{
			max2 = max1;
			max1 = numbers[i];
		} 
		else if (max2 < numbers[i])
		{
			max2 = numbers[i];
		}
	}
	result = max2 * max1;/* Short time calculation */
	printf("%lu", result);
}

