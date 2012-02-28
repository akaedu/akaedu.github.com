/** 
* @file 2.c
* @brief strstr函数的测试及实现
* @author GuoPengyu
* @version 0.1
* @date 2011-09-09
*/
#include <stdio.h>
#include <string.h>

char * mystrstr(char *str, char *substr)
{
    while(*str)
    {
        if(strncmp(str, substr, strlen(substr)) == 0)
            return str;
        str++;
    }
    return NULL;
}

int main(int argc, const char *argv[])
{
    char *str = "hello world!";
    char *substr = "or";

    printf("%s\n", mystrstr(str, substr));

    return 0;
}
