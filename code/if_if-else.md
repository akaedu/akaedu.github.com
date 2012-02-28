---
layout: post
title: 分支，循环控制结构
---

###if/else分支结构
####1.
使用分支结构判断数值非零及奇偶


        /*
         * filename: if.c
         * 
         * function: if/if-else
         *
         * data: 2011-10-26 by YourName
         *
         */

        #include <stdio.h>


        int main(int argc, const char *argv[])
        {
                int x;
                printf("enter a number:");
                scanf("%d", &x);

                //if
                if (x != 0)
                {
                        printf("x is nonzero.\n");
                }

                //judge a num is even or odd
                if (x % 2 == 0)
                {
                        printf("x is even.\n");
                }
                else
                {
                        printf("x is odd.\n");	
                }

                return 0;
        }

####2.
基本的if/else分支结构

        /*
         * filename: if_else.c
         *
         * function: if...else
         *
         * date: 2011-10-26
         *
         */


        #include <stdio.h>


        int main(int argc, char *argv[])
        {
                if (15%4 == 15/4)
                        printf("equal!\n");
                else
                        printf("Not equal!\n");
        

                return 0;
        }

####3.
判断从键盘输入的3个数哪个最大


        /*
         * filename: max_3.c
         *
         * function: max of 3 num
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
                
                int max, a, b, c;

                printf("Please input 3 num:");
                scanf("%d %d %d", &a, &b, &c);

                max = a;

                if (max < b)
                        max = b;
                if (max < c)
                        max = c;

                printf("max of 3 num is : %d\n", max);

                return 0;
        }

####4.
从键盘输入3个整数，判断他们是否能够构成三角形

        
        /*
         * filename: triangle.c
         *
         * function: find a triangle
         *
         * date: 2011-10-26
         *
         */

        #include <stdio.h>

        int main(int argc, const char *argv[])
        {
                int a, b, c;


                printf("Please inout 3 num:");
                scanf("%d %d %d", &a, &b, &c);

                if ((a < 0) || (b < 0) || (c < 0))
                {
                        printf("Invariable input!\n");
                }
                else
                {
                        if (((a + b) > c) && ((a + c) > b) && ((b + c) > c))
                        {
                                printf("a = %d, b = %d, c = %d can found a triangle\n", a, b, c);
                        }
                        else
                        {
                                printf("a = %d, b = %d, c = %d can not found a triangle\n", a, b, c);
                        }
                }


                return 0;
        }

###switch/case分支结构
####1.
按照如下结构输入数据并根据输入的运算符完成四则运算，比如有如下输入：<br>
3 + 5   程序执行完后输出8<br>
3 * 7   程序执行完后输出21<br>


        /*
         * filename: switch-case.c
         *
         * function: switch-case complete + - * / %
         *
         * author: Yourname
         *
         * version: 0.1
         *
         * date: 2011-10-26
         *
         */


        #include <stdio.h>


        int main(int argc, char *argv[])
        {
                int a, b;
                char c;


                printf("please input(num1 + num2):");
                scanf("%d %c %d", &a, &c, &b);
                switch (c)
                {
                        case '+': 
                                printf("%d %c %d = %d\n", a, c, b, a + b);
                                break;
                        case '-': 
                                printf("%d %c %d = %d\n", a, c, b, a - b);
                                break;
                        case '*': 
                                printf("%d %c %d = %d\n", a, c, b, a * b);
                                break;
                        case '/': 
                                printf("%d %c %d = %d\n", a, c, b, a / b);
                                break;
                        case '%': 
                                printf("%d %c %d = %d\n", a, c, b, a % b);
                                break;
                        default: 
                                printf("Invalid input!\n");
                                break;
                }


                return 0;
        }

####2.
输入数字通过switch/case分支转换为成绩级别的描述


        /*
         * filename: switch_grade.c
         *
         * function: enter a grade and print a description
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
                int grade;


                while (1)
                {
                        printf("Please enter grade(0-4): ");
                        scanf("%d", &grade);

                        switch (grade)
                        {
                                case 4:
                                        printf("Excellent\n");
                                        break;
                                case 3:
                                        printf("Good\n");
                                        break;
                                case 2:
                                        printf("Averge\n");
                                        break;
                                case 1:
                                        printf("Poor\n");
                                        break;
                                case 0:
                                        printf("Failing\n");
                                        break;
                                default:
                                        printf("Illegal grade\n");
                                        break;
                        }

                        if ((grade < 0) || (grade > 4))
                                break;
                }

                return 0;
        }

