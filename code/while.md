---
layout: post
title: while/do...while循环结构
---
####1.
使用while循环结构求1-100的和


        /*
         * filename: while_add.c
         *
         * function: get result of 1+2+...+100 in while
         *
         * date: 2011-10-26
         *
         */


        #include <stdio.h>

        int main(int argc, const char *argv[])
        {
                int i = 1, sum = 0;

                while (i <= 100)
                {
                        sum += i;
                        i++;
                }

                printf("1+2+3+...+100 = %d\n", sum);

                return 0;
        }

####2.
使用while循环结构求10个数中的最大值


        /*
         * filename: while_max.c
         *
         * fuction: find the max number in number array
         *
         * date: 2011-10-26
         */

        #include <stdio.h>

        #define N 10

        int main(int argc, const char *argv[])
        {
                
                int num[N] = {12,6,34,65,67,87,89,100,1,66};
                int i = 0, max = 0;

                while (i++ < N)
                {
                        if (max < num[i])
                        {
                                max = num[i];
                        }

                }

                printf("max is %d\n", max);
                return 0;
        }

####3.
使用do/while循环结构求n！（n从键盘输入）


        /*
         * filename: do-while.c 
         *
         * function: get the result of n!
         *
         * date: 2011-10-26
         *
         */

        #include <stdio.h>

        int main(int argc, const char *argv[])
        {

                int result = 1;
                int i = 1, n;

                printf("Please input a number:");
                scanf("%d", &n);

                do 
                {
                        result = result * i;
                        i = i + 1;

                } while (i <= n);
         
                printf("n! = %d\n", result);

                return 0;
        }

####4.
从键盘输入一个整数， 判断该整数有几位


        /*
         * filename: num_digit.c
         *
         * function: calculates the number of digits in an integer
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
                int digits = 0, n;

                printf("Enter a nonnegative integer: ");
                scanf("%d", &n);

                do
                {
                        n /= 10;
                        digits++;
                
                } while (n > 0);

                printf("the number has %d digits\n", digits);

                return 0;
        }
