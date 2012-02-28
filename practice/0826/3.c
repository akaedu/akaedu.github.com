/** 
* @file 3.c
* @brief 编写程序计算一个英文句子中最长单词的长度（字母个数）max，
* 假设该英文句子中只含有字母和空格，空格之间连续的字母称为单词
* @author GaoJinlong
* @version 0.1
* @date 2011-09-09
*/
#include <stdio.h>

int calc(char *str)
{
        int max = 0, tmp = 0;

        while(*str)
        {
                if(*str == ' ')
                {
                        if(tmp > max)
                                max = tmp;
                        tmp = 0;
                }
                else
                        tmp++;
                str++;
        }
        if(tmp > max)
                max = tmp;

        return max;
}

int main(int argc, const char *argv[])
{
        printf("%d\n", calc("hello everyone"));

        return 0;
}
