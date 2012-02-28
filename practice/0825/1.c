/** 
* @file 1.c
* @brief 练习使用strcmp, strncmp函数并自己编程实现strcmp, strncmp函数
* @author GuoPengyu
* @version 0.1
* @date 2011-09-09
*/
#include <stdio.h>
#include <string.h>

int my_strcmp(char *s1, char *s2)
{
	while(*s1 == *s2)
	{
		if(*s1 == '\0')
			return 0;
		s1++;
		s2++;
	}

	return (*s1 > *s2 ? 1 : -1); 
}

int my_strncmp(char *s1, char *s2, int n)
{
	if(!n)
		   return 0;
	while(*s1 == *s2)
	{
		if(*s1 == '\0' || !(--n))
			return 0;
		s1++;
		s2++;
	}

	return (*s1 > *s2 ? 1 : -1); 
}
int main(int argc, const char *argv[])
{
	char *p = "akaedu1", *q = "akadeu", *str = "helaka";

	printf("%d\n", strcmp(p, q));
	printf("%d\n", my_strcmp(p, q));
	printf("strncmp = %d\n", strncmp(p, str,3));
	printf("my_strncmp = %d\n", my_strncmp(p, str, 3));

	return 0;
}
