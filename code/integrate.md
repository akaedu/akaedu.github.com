---
layout: post
title: 综合练习
---
####1.
练习使用strlen函数


        /*
         * filename: use_strlen.c
         *
         * function: learn to use the strlen() and learn more string
         *      end of string is '\0'
         *
         * author: YourName
         *
         * version: 0.1
         *
         * date: 2011-10-27
         *
         */


        #include <stdio.h>
        #include <string.h>

        #define N 32

        int main(int argc, const char *argv[])
        {
                char str[] = "hello world";
                char arr[N] = "hello akaedu";

                printf("strlen(str) = %d\n", strlen(str));
                printf("sizeof(str) = %d\n", sizeof(str));

                printf("strlen(arr) = %d\n", strlen(arr));
                printf("sizeof(arr) = %d\n", sizeof(arr));

                return 0;
        }

####2.
使用数组将一数列反向


        #include <stdio.h>

        #define N 10

        int main(int argc, const char *argv[])
        {
                int a[N], i;

                printf("enter %d number: ", N);
                for (i = 0; i < N; i++)
                        scanf("%d", &a[i]);

                printf("In reverse order: ");
                for (i = N - 1; i >= 0; i--)
                        printf(" %d", a[i]);

                printf("\n");
                
                return 0;
        }

####3.
显示倒计数


        #include <stdio.h>

        void print_count(int n)
        {
                printf("T m inus %d and counting\n", n);
        }

        int main(int argc, const char *argv[])
        {
                int i;


                for (i = 10; i > 0; i--)
                        print_count(i);


                return 0;
        }

####4.
计算指针变量占用的字节数


        #include <stdio.h>
        #include <string.h>


        int main(int argc, const char *argv[])
        {
                char *p = "012345";

                printf("sizeof(p) = %d, strlen(p) = %d\n", sizeof(p), strlen(p));

                printf("sizeof(char *) = %d\n", sizeof(char *));
                printf("sizeof(short *) = %d\n", sizeof(short *));
                printf("sizeof(int *) = %d\n", sizeof(int *));

                return 0;
        }

####5.
使用指针将一数列反向


        #include <stdio.h>

        #define N 10

        int main(int argc, const char *argv[])
        {
                int a[N], *p;

                printf("enter %d number: ", N);
                for (p = a; p < a + N; p++)
                        scanf("%d", p);

                printf("In reverse order: ");
                for (p = a + N - 1; p >= a; p--)
                        printf(" %d", *p);

                printf("\n");
                
                return 0;
        }

####6.
求以数列中的最大值


        #include <stdio.h>

        #define N 10

        int find_max(int a[], int len)
        {
                int max, i;
                max = a[0];

                for (i = 1; i < len; i++)
                        if (a[i] > max)
                                max = a[i];

                return max;
        }


        int main(int argc, const char *argv[])
        {
                
                int num[N] = {23,21,56,43,78,26,98,13,44,6};

                printf("max num is: %d\n", find_max(num, N));

                return 0;
        }

####7.
练习实现strlen函数


        /*
         * filename: achieve_strlen.c
         *
         * function: achieve strlen() by yourself
         *
         * author: YourName
         *
         * version: 0.1
         *
         * date: 2011-10-27
         *
         */


        #include <stdio.h>
        #include <string.h>

        int my_strlen_fir(char s[])
        {
                int i = 0;
                int len = 0;

                //end in '\0'
                while (s[i++])
                        len++;

                return len;
        }

        int my_strlen_sec(char s[])
        {
                int len = 0;

                for ( ; (*s != '\0'); s++)
                        len++;

                return len;
        }

        int my_strlen_thi(char s[])
        {
                int len = 0;

                for ( ; *s; s++)
                        len++;

                return len;
        }

        int my_strlen_for(char s[])
        {

                int len = 0;

                for ( ; *s++; )
                        len++;

                return len;
        }

        int main(int argc, const char *argv[])
        {
                char str[] = "Hello world";

                printf("strlen(str) = %d\n", strlen(str));
                printf("my_strlen_fir(str) = %d\n", my_strlen_fir(str));
                printf("my_strlen_sec(str) = %d\n", my_strlen_sec(str));
                printf("my_strlen_thi(str) = %d\n", my_strlen_thi(str));
                printf("my_strlen_for(str) = %d\n", my_strlen_for(str));

                return 0;
        }

####8.
指针的基本使用--将两个数交换


        #include <stdio.h>

        void swap_fir(int a, int b)
        {
                int tmp;

                tmp = a;
                a = b;
                b = tmp;
        }

        void swap_sec(int *a, int *b)
        {
                int tmp;

                tmp = *a;
                *a = *b;
                *b = tmp;
        }

        int main(int argc, const char *argv[])
        {
                int a = 3, b = 4;

                printf("a = %d, b = %d\n\n", a, b);

                swap_fir(a, b);
                printf("After swap_fir...\n\n");
                printf("a = %d, b = %d\n\n", a, b);
                
                a = 3, b = 4;

                printf("Again: a = %d, b = %d\n\n", a, b);
                swap_sec(&a, &b);
                printf("After swap_sec...\n\n");
                printf("a = %d, b = %d\n\n", a, b);
                
                return 0;
        }
