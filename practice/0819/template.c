#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
	int i, num[10] = {0}; //给srand函数一个种子;

	srand(time(NULL));
	for(i = 0; i < 10; i++)
	{
		num[i] = rand() % 10; //产生随机数
	}

	for(i = 0; i < 10; i++)
	{
		printf("%d, ", num[i]);
	}
	printf("\n");
	 
	return 0;
}

