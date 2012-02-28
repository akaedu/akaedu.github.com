/** 
* @file 2.c
* @brief 编写函数把任意十进制的正整数转换为二进制，主函数调用该函数完成整数的二进制形式输出，要求不能按逆序输出
* @author GuoPengyu
* @version 0.1
* @date 2011-09-09
*/
#include <stdio.h>

/** 
* @brief convert to binary
* 
* @param buf store in
* @param num number to convert
* 
* @return total place of the number
*/
int convert(int *buf, int num)
{
	int i = 0;

	while(num)
	{
		buf[i++] = num % 2;
		num /= 2;
	}

	return i - 1;
}

int main(int argc, const char *argv[])
{
	int b[32] = {0};
	int num;
	int place;

	printf("Please enter the number to convert: ");
	scanf("%d", &num);
	place = convert(b, num);
	while(place >= 0)
	{
		printf("%d", b[wei--]);
	}

	return 0;
}
