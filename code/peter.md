---
layout: post
title: 数组
---
####1.
初始化一个整形数组并遍历打印


        #include <stdio.h>

        int main(int argc, char *argv[])
        {
                int count[4] = {4, 3, 2, 1}, i;

                for (i = 0; i < 4; i++)
                        printf("count[%d] = %d\n", i, count[i]);

                return 0;
        }

####2.
计算整形数组中奇数偶数的个数分别是多少


        /*
         * filename: even_odd.c
         *
         * function: get the number of even and the number of odd
         *
         * author: YourName
         *
         * version: 0.1
         *
         * date: 2011-10-26
         *
         * */

        #include <stdio.h>

        #define N 10

        int main(int argc, const char *argv[])
        {
                int num[N] = {1,2,3,4,5,6,7,8,9,11};
                int num_even = 0, num_odd = 0;
                int i;

                for (i = 0; i < N; i++)
                {
                        if ((num[i] % 2) == 0)
                                num_even++;
                        if ((num[i] % 2) == 1)
                                num_odd++;
                }

                printf("num of even is: %d\n", num_even);
                printf("num of odd is: %d\n", num_odd);

                return 0;
        }

####3.
初始化一个字符数组并打印输出然后从键盘输入一个字符串并打印


        #include <stdio.h>
        #include <string.h>

        #define N 1024

        int main(int argc, const char *argv[])
        {
                char arr[N] = "hello akaedu!";

                printf("old = %s\n", arr);
                printf("sizeof(arr) = %d\n", sizeof(arr));
                printf("strlen(arr) = %d\n\n", strlen(arr));

                printf("Please input a string:");
                scanf("%s", arr);
                printf("new = %s\n", arr);

                return 0;
        }

####4.
统计一下某字符串中指定字符出现的次数


        /*
         * filename: ch_in_str.c
         *
         * function: find hwo many the character in string
         *
         * author: YourName
         *
         * version: 0.1
         *
         * date: 2011-10-27
         *
         *
         */


        #include <stdio.h>

        #define LEN 20

        int main(int argc, char *argv[])
        {
                char str[LEN], c;
                int i, count = 0;

                scanf("%s %c", str, &c);

                for(i = 0; str[i]; i++)
                        if(str[i] == c)
                                count++;

                printf("find %d %c in %s\n", count, c, str);

                return 0;
        }

####5.
删除字符串中出现的特定字符


        #include <stdio.h>

        #define N 1024

        void del_ch(char s[], char ch)
        {
                int i, j;

                for (i = j = 0; s[i]; i++)
                {
                        if (s[i] != ch)
                                s[j++] = s[i];
                }

                s[j] = '\0';

        }

        int main(int argc, const char *argv[])
        {
                char str[] = "hello akaedu!";
                char s[N];
                char ch;
                        
                del_ch(str, 'a');
                printf("After delete 'a', str = %s\n", str);

                printf("Please input string and character:");
                scanf("%s %c", s, &ch);
                printf("you have inputed s = %s, ch = %c\n", s, ch);
                del_ch(s, ch);
                printf("After delete '%c', s = %s\n", ch, s);

                return 0;
        }

####6.
初始化一个二维数组并打印


        /*
         * filename: two_dimension.c
         *
         * function: initialize a two-dimension array and traverse it
         *
         * author: YourName
         *
         * version: 0.1
         *
         * date: 2011-10-27
         *
         */


        #include <stdio.h>

        #define N 5

        int main(int argc, const char *argv[])
        {
                int i, j;
                int arr[N][N] = 
                                {{1 ,2 ,3 ,4 ,5},
                                 {6 ,7 ,8 ,9 ,10},
                                 {11,12,13,14,15},
                                 {16,17,18,19,20},
                                 {21,22,23,24,25},};

                for (i = 0; i < N; i++)
                {
                        for (j = 0; j < N; j++)
                        {
                                printf("%3d", arr[i][j]);
                        }
                        printf("\n");
                }

                return 0;
        }

