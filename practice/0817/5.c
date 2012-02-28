/** 
* @file 5.c
* @brief 自己编写程序实现itoa()(提示：将数字x转换为字符串并保存到p中)；
* @author Gaojinlong
* @version 0.1
* @date 2011-09-09
*/

#include <stdio.h>
#include <string.h>

/** 
* @brief itoa
* 
* @param x number to convert
* @param p store to p
*/
void myitoa(int x, char *p)
{
	int i = 0, j = 0;
	int tmp;

	while(x)
	{
		p[i++] = x % 10 + '0';
		x /= 10;
	}
	p[i] = '\0'; // add a '\0' to the end of string

	for (i = 0, j = strlen(p) - 1; i <= j; i++, j--) //revert
	{
		tmp = p[i];
		p[i] = p[j];
		p[j] = tmp;
	}
}

int main(int argc, const char *argv[])
{
	int x;
	char str[100];

	printf("Please input an integer: ");	
	scanf("%d", &x);
	myitoa(x, str);
	printf("After convert, array str is %s\n", str);

	return 0;
}
