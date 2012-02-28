---
layout: post
title: for循环结构
---
###for循环结构
####1.
使用for循环结构求1-100之间的和值


        /*
         * filename: add.c
         *
         * function: 1+2+3+...+100 = ?
         *
         * author: YourName
         *
         * version: 0.1
         *
         * date: 2011-10-26
         *
         */


        #include <stdio.h>

        int main(int argc, const char *argv[])
        {
                int i, sum = 0;

                for (i = 1; i <= 100; i++)
                {
                        sum += i;
                }

                printf("1+2+3+...+100 = %d\n", sum);

                return 0;
        }

####2.
将指定字符串中的大写字母转小写，小写字母转大写

        
        /*
         * filename: convert.c
         *
         * function: convert A to a and convert b to B in a string
         *
         * date: 2011-10-26
         */


        #include <stdio.h>
        #include <string.h>

        #define N 1024

        char convert(char ch)
        {
                if ((ch >= 'a') && (ch <= 'z'))
                        return ch - 32;
                else if ((ch >= 'A') && (ch <= 'Z'))
                        return ch + 32;
                else
                        return ch;
        }

        int main(int argc, const char *argv[])
        {
                char arr[N] = "AKAedu 123 heLLO!";
                int i, len = strlen(arr);

                printf("%s\n\n", arr);
                for (i = 0; i < len; i++)
                {
                        arr[i] = convert(arr[i]);
                }

                printf("After convert...\n\n");
                printf("%s\n", arr);
                
                return 0;
        }

####3.
使用for循环求取10个数中的最大值


        /*
         * filename: max.c
         *
         * function: find max in num[N]
         *
         * author: Yourname
         *
         * version: 0.1
         *
         * date: 2011-10-26
         *
         */

        #include <stdio.h>

        #define N 10

        int main(int argc, const char *argv[])
        {
                int num[N] = {12,6,34,65,67,87,89,100,1,66};
                int i, max = 0;

                for (i = 0; i < 10; i++)
                {
                        if (max < num[i])
                        {
                                max = num[i];
                        }
                }

                printf("max is %d\n", max);

                return 0;
        }

####4.
打印一个简单的两列的平方表


        /*
         * filename: suare,c
         *
         * function: ptint a table of square using a for statement
         *
         * author: YourName
         *
         * version: 0.1
         *
         * date: 2011-10-27
         *
         */

        #include <stdio.h>

        int main(int argc, const char *argv[])
        {
                int i, n;

                printf("this program print a table of square\n");
                printf("Enter number of entries in table: ");
                scanf("%d", &n);

                for (i = 1; i <= n; i++)
                {
                        printf("%10d%10d\n", i, i*i);
                }


                return 0;
        
        }

####5.
输出半个菱形


        #include <stdio.h>

        int main(int argc, const char *argv[])
        {
                int i, j, k;
                int n;

                while (scanf("%d", &n))
                {
                        if (n & 1)
                                break;
                        k = n / 2;

                        for (i = -k; i <= k; i++)
                        {
                                if (i < 0)
                                {
                                        for (j = 0; j < i+k+1; j++)
                                                printf("*");
                                }
                                else
                                {
                                        for (j = 0; j < -i+k+1; j++)
                                                printf("*");
                                }
                                printf("\n");
                        }
                        

                }

                return 0;
        }


