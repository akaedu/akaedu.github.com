/** 
* @file 3.c
* @brief 定义一个整形数组，用100以内的随机数填充，然后对其进行冒泡排序
* @author GuoPengyu
* @version 0.1
* @date 2011-09-09
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 10

int main(int argc, char *argv[])
{
	int i, j, tmp;	
	int num[LEN] = {0};

	srand(time(NULL));

	for(i = 0; i < LEN; i++)
	{
		num[i] = rand() % 100;	
		printf("%d, ", num[i]);
	}
	printf("\n");

	for(i = 0; i < LEN -1; i++)
	{
		for(j = 0; j < LEN -1 - i; j++)
		{
			if(num[j] > num[j+1])
			{
				tmp = num[j];
				num[j] = num[j+1];
				num[j+1] = tmp;
			}
		}
	}

	printf("after sort...\n");

	for(i = 0; i < LEN; i++)
	{
		printf("%d, ", num[i]);
	}
	printf("\n");

	return 0;
}
