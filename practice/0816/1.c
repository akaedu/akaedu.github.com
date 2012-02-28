/** 
* @file 1.c
* @brief find the max number
* @author Gaojinlong
* @version 0.1
* @date 2011-09-09
*/

#include <stdio.h>

/** 
* @brief find the max number of a,b,c
* 
* @param a number a
* @param b number b
* @param c number c
* 
* @return  max
*/
int get_max(int a, int b, int c)
{
        if (a < b) //a is the biggest in a and b
       		a = b;
        if (a > c) //if a > c  a is the biggest in a, b, c
                return a;
        else
                return c;
}

int main(int argc, const char *argv[])
{
        int a, b, c;

        printf("Enter the age of three people: ");
        scanf("%d %d %d", &a, &b, &c);
        printf("The max is %d\n", get_max(a, b, c));

        return 0;
}
