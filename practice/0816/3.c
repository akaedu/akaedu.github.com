/** 
* @file 3.c
* @brief calc the GCD of two numbers
* @author Gaojinlong
* @version 0.1
* @date 2011-09-09
*/

#include <stdio.h>

/** 
* @brief
* 此函数用遍历法求最大公约数，最大公约数只能小于或等于两个数中最小的那个，
* 由此遍历至1，在这中间，若首次遇到既能整除a,又能整除b的数，则该数为最大公约数。
* @param a
* @param b
* 
* @return 
*/
int gcd(int a, int b)
{
	int i;

	for (i = a < b ? a : b; i > 0; i--) 
	{
		if (a % i == 0 && b % i == 0) 
			return i;
	}
}

int main(int argc, const char *argv[])
{
        int i, j;

        printf("Please enter two integer: ");
        scanf("%d %d", &i, &j);
        printf("The gcd of %d and %d is %d\n", i, j, gcd(i, j));

        return 0;
}
