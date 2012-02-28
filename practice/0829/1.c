/** 
* @file 1.c
* @brief 找9问题：从1到100中找出有多少个9；
* 要求：设计函数实现；函数不仅可以找9，还可以找8，找7…
* @author Gaojinlong
* @version 0.1
* @date 2011-09-09
*/

#include <stdio.h>

int find_x(int num, int x)
{
        int count = 0;

        do{
                if(num % 10 == x)
                        count++;
        }while(num /= 10);

        return count;
}

int main(int argc, const char *argv[])
{
        int count = 0, i;
        int x;

        printf("num to find: ");
        scanf("%d", &x);
        for(i = 1; i <= 100; i++)
        {
                count += find_x(i, x);
        }
        printf("%d\n", count);

        return 0;
}
