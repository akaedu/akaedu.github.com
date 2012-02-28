/** 
* @file 2.c
* @brief calc the different nums within 100-999 with 1-4
* @author Gaojinlong
* @version 0.1
* @date 2011-09-09
*/

#include <stdio.h>

int main(int argc, const char *argv[])
{
	int i, j, k;
	int count = 0;

	for (i = 1; i <= 4; i++) 
		for (j = 1; j <= 4; j++) 
			for (k = 1; k <= 4; k++) 
				if (i != j && i != k && j != k) 
				{
				    count++;
				    printf("%d%d%d\n", i, j, k);
				}
	printf("\ncount = %d\n", count);

	return 0;
}
