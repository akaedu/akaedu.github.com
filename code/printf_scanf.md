---
layout: post
title: 输入输出函数 printf/scanf
---
####1.
字符串，整数，浮点数的打印

        
        /*
         * print.c
         *
         * function: generate some simple output
         *
         * 2011-10-26 by YourName
         *
         */


        #include <stdio.h>

        int main(int argc, char *argv[])
        {
                int i = 10;
                float num = 3.14;

                //print string
                printf("Hello world!\n");

                //print a integer
                printf("i = %d\n", i);

                //print a hexadecimal number
                printf("i = 0x%x\n", i);

                //floating point numbers
                printf("num = %f\n", num);

                return 0;
        }

####2.
printf()中格式控制符的使用

        /*
         * filename: printf_advan.c
         *
         * function: printf()
         *
         * author: YourName
         *
         * version: 0.1
         *
         * data: 2011-10-26
         *
         *
         * */


        #include <stdio.h>


        int main(int argc, char *argv[])
        {

                printf("%d, 0x%x, %f\n", 100, 100, (double)100);
                printf("%%, ', \"\n");
                printf("sizeof(char) = %d\n", sizeof(char));
                printf("sizeof(int) = %d\n", sizeof(int));

                return 0;
        }

####3.
数据读取，scanf()的使用


        /*
         * scanf.c
         *
         * function: scanf()
         *
         * 2011-10-26 by YourName
         *
         */


        #include <stdio.h>

        int main(int argc, const char *argv[])
        {
                int i, j, k;
                char str[100];

                //input a integer
                printf("Please input a integer:");
                scanf("%d", &i);
                printf("%d\n", i); 

                //input some integers
                printf("Please input 3 integers:");
                scanf("%d %d %d", &i, &j, &k);
                printf("i = %d, j = %d, k = %d\n", i, j, k);

                //input a string 
                printf("Please input a string:");
                scanf("%s", str);
                printf("%s\n", str);

                return 0;
        }

####4.
使用scanf()接收不含空格的字符串

        #include <stdio.h>

        #define N 1024

        int main(int argc, const char *argv[])
        {
                char str[N];

                printf("Please enter <hello world>: ");
                scanf("%s", str);
                printf("%s\n", str);

                return 0;
        }

####5.
gets函数接收含有空格的字符串


        #include <stdio.h>

        #define N 1024

        int main(int argc, const char *argv[])
        {
                char str[N];

                printf("Please enter <hello world>: ");
                gets(str);
                printf("%s\n", str);

                return 0;
        }

####6.
格式匹配输入数据

                
        /*
         * filename: y_m_d.c
         *  
         * function: input mm/dd/yy,output yy/mm/dd
         *
         * author: YourName
         *
         * version: 0.1
         *
         * data: 2011-10-26
         */

        #include <stdio.h>


        int main(int argc, char *argv[])
        {
                int year, month, day;

                printf("Enter a date(mm/dd/yyyy):");
                scanf("%d/%d/%d", &month, &day, &year);
                printf("You enterd the date:%4d/%02d/%02d\n", year, month, day);

                return 0;
        }
