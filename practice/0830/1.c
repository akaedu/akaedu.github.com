/** 
* @file 1.c
* @brief 求一个拥有10个元素的整形数组的第二大的数。
* 例如：数组int a = {7, 63, 54, -78, 31, 42, 83, 142, 57,
* -20}，执行完程序后输出数组中第二大的数83
* @author GaoJinlong
* @version 0.1
* @date 2011-09-09
*/
#include <stdio.h>

int find_second(int *a, int size)
{
        int max = 0, second = 0, i;

        for(i = 0; i < size; i++)
        {
                if(a[i] > max)
                {
                        max = a[i];
                }
                else if(a[i] > second)
                        second = a[i];
        }

        return second;
}

int main(int argc, const char *argv[])
{
        int a[] = {143, 42, 54, -78, 31, 42, 83, 122, 57, -20};

        printf("%d\n", find_second(a, sizeof(a) / sizeof(int)));

        return 0;
}
