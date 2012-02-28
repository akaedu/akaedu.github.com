/** 
* @file 1.c
* @brief mystrcpy
* @author GuoPengyu
* @version 0.1
* @date 2011-09-09
*/
#include <stdio.h>

/** 
* @brief strcpy
* 
* @param dest dest
* @param src source
* 
* @return original address of dest
*/
char *mystrcpy(char *dest, char *src)
{
	char *bak = dest;

	while(*dest++ = *src++);

	return bak;
}

int main(int argc, const char *argv[])
{
	char src[20] = "Hello world!";
	char dest[20];

	printf("%s\n", mystrcpy(dest, src));

	return 0;
}
