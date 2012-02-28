/** 
* @file 3.c
* @brief 编写程序检查某一个整数中是否有重复的数字，如检查2823中存在重复数字2
* @author GuoPengyu
* @version 0.1
* @date 2011-09-09
*/
#include <stdio.h>

int main(int argc, const char *argv[])
{
	int n, digit[10] = {0};

	printf("Input a number: ");
	scanf("%d", &n);

	while(n)
	{
		if (digit[n % 10] == 1) 
			break;
		else
			digit[n % 10] = 1;
		n /= 10;
	}

	if (n) 
		printf("Yes!\n");
	else
		printf("No!\n");

	return 0;
}
