---
layout: post
title: 简单函数  
---
####1.
自定义加减乘除取模函数并调用


        #include <stdio.h>

        // add
        int add(int a, int b)
        {
                int c = a + b;

                return c;
        }

        // subtract
        int sub(int a, int b)
        {
                int c = a - b;

                return c;
        }

        // multiply
        int mul(int a, int b)
        {
                int c = a * b;

                return c;
        }

        // divide
        int div(int a, int b)
        {
                int c;

                if (b != 0)
                        c = a / b;
                else
                        printf("b can't be 0!\n");

                return c;
        }

        // mode
        int mod(int a, int b)
        {
                int c;

                if (b != 0)
                        c = a % b;
                else
                        printf("b can't be 0!\n");

                return c;

        }


        int main(int argc, const char *argv[])
        {
                int a, b;

                printf("Please input 2 number:");
                scanf("%d%d", &a, &b);

                printf("a + b = %d\n", add(a, b));
                printf("a - b = %d\n", sub(a, b));
                printf("a * b = %d\n", mul(a, b));
                printf("a / b = %d\n", div(a, b));
                printf("a %% b = %d\n", mod(a, b));
                
                return 0;
        
        
        }

####2.
实现数组的连加连减


        #include <stdio.h>

        #define N 10

        int arr_add(int num[], int len)
        {
                int i, sum = 0;

                for (i = 0; i < len; i++)
                        sum += num[i];

                return sum;
        }

        int arr_sub(int num[], int len)
        {
                int i, sub = num[0];

                for (i = 1; i < len; i++)
                        sub -= num[i];

                return sub;
        }

        int main(int argc, const char *argv[])
        {
                int a[N] = {0}, i = 0;
                int sum, sub;

                for (i = 0; i < N; i++)
                {
                        a[i] = i + 10;
                        printf("a[%d] = %d\n", i, a[i]);
                }

                printf("Reverse output:\n");
                // reverse output
                for (i = N - 1; i >= 0; i--)
                        printf("a[%d] = %d\n", i, a[i]);

                sum = arr_add(a, N);
                sub = arr_sub(a, N);

                printf("arr sum: %d, arr sub:%d\n", sum, sub);

                
                return 0;
        }

####3.
编程判断3人中谁的年龄最大，并打印最大者的年龄


        #include <stdio.h>

        int age_cmp(int a, int b)
        {
                if (a > b)
                        return a;
                else
                        return b;
        }

        int main(int argc, const char *argv[])
        {
                int Tom, Bob, Mike;

                printf("Please input 3 ages:");
                scanf("%d %d %d", &Tom, &Bob, &Mike);

                printf("the oldest is %d\n", age_cmp(age_cmp(Tom, Bob), Mike));
                
                return 0;
        }

####4.
求数值的绝对值


        #include <stdio.h>

        extern int myabs(int num);

        int main(int argc, const char *argv[])
        {
                int a = 10;
                int b = -5;

                printf("%d abs is %d\n", a, myabs(a));
                printf("%d abs is %d\n", b, myabs(b));
                
                return 0;
        }

        int myabs(int x)
        {
                if (x >= 0)
                {
                        return x;
                }
                else
                {
                        return -x;
                }
        }

####5.
判断3个数能否组成一个三角形，将其实现为一个函数，并调用


        #include <stdio.h>

        int is_triangle(int a, int b, int c)
        {
                if ((a <= 0) || (b <= 0) || (c <= 0))
                {
                        printf("Usage: a:%d, b:%d, c:%d\n", a, b ,c);
                        return(-1);
                }

                if (((a + b) > c) && ((a + c) > b) && ((b + c) > a))
                        return 1;
                else
                        return 0;
        }

        int main(int argc, const char *argv[])
        {
                int a, b, c;
                int result;

                printf("Please input 3 number as triangle:");
                scanf("%d %d %d", &a, &b, &c);

                result = is_triangle(a, b, c);
                if (result == 1)
                        printf("a = %d, b = %d, c = %d can found a triangle!\n", a, b, c);
                else if (result == 0)
                {
                        printf("a = %d, b = %d, c = %d can not found a triangle!\n", a, b, c);
                }
                else
                        printf("Invariable input!\n");
                
                return 0;
        }

####6.
求1-100之间的素数，将其实现为函数，并调用


        #include <stdio.h>

        int is_prime(int n)
        {
                int i;

                for (i = 2; i < n; i++)
                {
                        if ((n % i) == 0)
                                break;
                }

                if (i == n)
                        return 1;
                else
                        return 0;

        }

        int main(int argc, const char *argv[])
        {
                int i;

                for (i = 1; i <= 100; i++)
                {
                        if (!is_prime(i))
                                continue;
                        printf("%d\n", i);
                }

                return 0;
        }

####7.
使用递归函数求和


        /*
         * filename: add_recursion.c
         *
         * function: add form 1 to n with recursion
         *
         * author: YourName
         *
         * version: 0.1
         *
         * date: 2011-10-27
         *
         */


        #include <stdio.h>

        int sum(int n)
        {
                if (0 == n)
                        return 0;
                else
                        return n + sum(n-1);
        }

        int main(int argc, const char *argv[])
        {
                int n;

                printf("Please input a number:");
                scanf("%d", &n);
                printf("1+2+...+%d = %d\n", n, sum(n));
                
                return 0;
        }
