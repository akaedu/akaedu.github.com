/** 
* @file 2.c
* @brief 将两个字符串连接起来，并打印结果； 
* 1）练习使用strcat()函数；（通过man手册或网络自学）
* 2）自己实现my_strcat()
* @author GuoPengyu
* @version 0.1
* @date 2011-09-09
*/
#include <stdio.h>
#include <string.h>

char *my_strcat(char *dest, const char *src)
{
	char *cp = dest;

	while (*cp)
		cp++;
	for (; (*cp = *src); cp++, src++)
		;

	return dest;
}


int main(int argc, char *argv[])
{
	const char src[16] = "akaedu";
	char dest[32] = "hello";

	//printf("after strcat src= %s\n", strcat(dest, src));
	printf("after my_strcat src= %s\n", my_strcat(dest, src));

	return 0;
}
