/** 
* @file 1.c
* @brief 编写程序实现以下功能，在字符串str中找出最大的字符并放在第一个位置上，
* 并将该字符前的原字符往后顺序移动;
* 如str字符串内容为”chyab”,程序执行完毕，str中的内容将成为”ychab”;
* @author GaoJinlong
* @version 0.1
* @date 2011-09-09
*/
#include <stdio.h>

char *find_max(char *str)
{
        char *max = str;

        while(*str)
        {
                if(*max < *str)
                        max = str;
                str++;
        }

        return max;
}

char *parse(char *str)
{
        char *max_p = find_max(str);
        char max = *max_p;
        char *tmp;

        for(tmp = max_p; tmp >= str; tmp--)
                *tmp = *(tmp - 1);
        *str = max;

        return str;
}

int main(int argc, const char *argv[])
{
        char buf[100] = "chyab";

        printf("%s\n", parse(buf));

        return 0;
}
