/** 
* @file 2.c
* @brief  判断输入的字符串是否为回文字符串；（提示：回文顺读倒读都一样，例如：12321，abcba）
* @author Gaojinlong
* @version 0.1
* @date 2011-09-09
*/
#include <stdio.h>

/** 
* @brief 判断输入的字符串是否为回文字符串；（提示：回文顺读倒读都一样，例如：12321，abcba）
* 
* @param str the string
* 
* @return 1 for yes, 0 for no
*/
int loop(char *str)
{
    int i, j;

    for (i = 0, j = strlen(str) - 1; i <= j; i++, j--) 
    {
        if (str[i] != str[j]) 
            return 0;
    }

    return 1;
}

int main(int argc, const char *argv[])
{
    char str[100];

    printf("Please enter a string: ");
    scanf("%s", str);

    if (loop(str))
        printf("Yes!\n");
    else
        printf("No!\n");

    return 0;
}
