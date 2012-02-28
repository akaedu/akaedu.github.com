---
layout: post
title: continue/break/goto关键字
---
####1.
统计1-100内偶数的个数


        /*
         * filename continue.c
         *
         * function: number of even from 1 to 100
         *
         */


        #include <stdio.h>

        int main(int argc, const char *argv[])
        {
                int count = 0, i;

                for (i = 1; i <= 100; i++)
                {
                        if ((i % 2) == 0)
                                count++;
                        else
                                continue;
                }	

                printf("count = %d\n", count);

                return 0;
        }

####2.
输入一个数求它的3次方，输入0结束程序


        #include <stdio.h>

        int main(int argc, const char *argv[])
        {
                int n;

                while (1)
                {
                        printf("Enter a number(enter 0 to stop): ");
                        scanf("%d",&n);
                        if (0 == n)
                                break;
                        printf("%d cubed is %d\n", n, n*n*n);

                }

                return 0;
        }

####3.
输出1-100之间的素数


        #include <stdio.h>

        int main(int argc, const char *argv[])
        {
                int i, j;


                for (i = 1; i <= 100; i++)
                {
                        for (j = 2; j < i; j++)
                        {
                                if (i % j == 0)
                                        break;
                        }

                        if (i == j)
                                printf("%d\n", i);
                        else
                                continue;
                
                }


                return 0;
        }

####4.
使用goto语句实现跳转


        #include <stdio.h>

        int main(int argc, char *argv[])
        {
                int i, j;
                
                for (i = 0; i < 4; i++)
                {
                        for (j = 0; j < 10; j++)
                        {
                                printf("(i, j) = (%d, %d)\n", i, j);
                                if (2 == j)
                                      //break;
                                        goto out;

                        }
                }

        out:
                return 0;
                
        }
