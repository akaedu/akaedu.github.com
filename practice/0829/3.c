/** 
* @file 3.c
* @brief 删除字符串中的子字符串
* @author Gaojinlong
* @version 0.1
* @date 2011-09-09
*/
#include <stdio.h>
#include <string.h>

#define N 128

void del(char *str, char *substr)
{
        char *p;

        int len_sub = strlen(substr);
        while(p = strstr(str, substr))
        {
                *p = '\0';
                strcat(str, p + len_sub);
        }
}

int main(int argc, char *argv[])
{
	char str[N] = "helllo akaedullo";
	char sub[N] = "llo";

	printf("str = %s\n", str);
	del(str, sub);
	printf("After...\nstr = %s\n", str);

	return 0;
}
