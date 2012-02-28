/** 
* @file 2.c
* @brief 用位运算实现对一个无符号数的二进制打印，八进制打印，十六进制打印；（实现三个函数）
* @author GaoJinlong
* @version 0.1
* @date 2011-09-09
*/
#include <stdio.h>
#include <string.h>

void print_binary(unsigned int x, char *buf)
{
        int i;

        for(i = 31; i >= 0; i--)
                buf[31 - i] = ((x >> i) & 0x01) + '0';

        printf("%s\n", strstr(buf, "1"));
}

void print_oct(unsigned int x, char *buf)
{
        int i = 0;

        do{
                buf[i++] = (x & 0x7) + '0';
        }while(x >>= 3);

        while(i--)
                putchar(buf[i]);
        putchar('\n');
}

void print_hex(unsigned int x, char *buf)
{
        int i = 0;
        char *s = "0123456789ABCDEF";

        do{
                buf[i++] = s[x & 0xf];
        }while(x >>= 4);

        while(i--)
                putchar(buf[i]);
        putchar('\n');
}

int main(int argc, const char *argv[])
{
        char buf[32];        
        unsigned int x, i;

        scanf("%u", &x);
        print_binary(x, buf);
        print_oct(x, buf);
        print_hex(x, buf);

        return 0;
}
