/** 
* @file 1.c
* @brief 将一个数组用100以内的整数填充，然后将其进行排序，将奇数放在数组的前半部分，偶数放在数组的后半部分
* @author GaoJinlong
* @version 0.1
* @date 2011-09-09
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 10

void init(int *num, int len)
{
	int i;

	srand(time(NULL));
	for (i = 0; i < len; i++) 
		num[i] = rand() % 100;
}

void print(int *num, int len)
{
	int i;

	for (i = 0; i < len; i++) 
		printf("%d ", num[i]);
	printf("\n");
}

void sort(int *num, int len)
{
	int i, j, tmp;

	for (i = 0,j= len - 1;i <= j; i++) 
	{
		if(num[i] % 2 == 0)
		{
			tmp = num[i];
			num[i] = num[j];
			num[j] = tmp;
			i--;
			j--;
		}
		print(num, 5);
	}
}

int main(int argc, const char *argv[])
{
	int num[5];

	init(num, 5);
	print(num, 5);
	sort(num, 5);
	print(num, 5);

	return 0;
}
