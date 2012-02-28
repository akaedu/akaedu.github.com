---
layout: post
title: 20111120答案
---

<li> <a href="./test.doc">题目下载</a> </li>

###一、选择题
1.C  标识符不能为关键字、数字开头、运算符开头<br>
2.D  转义字符：\\"、\\xdd十六进制、\\xxx八进制<br>
3.A  'A'＋32 ＝'a'<br>
4.C  k = 0，表达式的值为0<br>
5.A  类型自动提升<br>
6.B <br>
7.C 逻辑运算符<br>
8.D 定义函数时为形参，调用函数时为实参<br>
9.B \+\+、\-\-<br>
10.C 指针指向地址<br>
11.C break只用在循环体和switch语句中<br>
12.C 转义字符<br>
13.D 可以在主函数之后，但调用时需要声明<br>
14.A 指针自加，地址后移<br>
15.B 指针数组，数组内为指针，应为地址<br>
16.D 若省略返回值，默认为int<br>
17.D strcmp以第一个不相同的字符判断大小<br>
18.D 数组传参，传地址<br>
19.D 数组指针<br>
20.C 数组指针<br>

###二、填空、简答
1.数据定义

	int a;
	int *a;
	int a[10]; 
	int *a[10]; //指针数组
	int (*a)[10];//数组指针
	void (*p)(int, int);//函数指针，注意加()

2.6 数组<br>
  4 指针的大小都为4<br>
  4 指针的大小都为4<br>
  4 指针的大小都为4<br>
  4 指针的大小都为4<br>

3.1 转义字符<br>
  138 <br>
  12 <br>
  1\.500000,00002 <br>
  地址  值 <br>
  good  ood 字符串以'\\0'结束<br>
  a\[5\] <br>
  28 <br>

###三、编程题
####1.求一个拥有10个元素的整型数组中第二大的数。 例如：数组int a[] = { 7, 63, 54, -78, 31, 42, 83, 142, 57, -20},执行完程序后输出数组中第二大的数83。

	#include <stdio.h>
	
	int main(int argc, const char *argv[])
	{
		int a[] = {7, 63, 54, -78, 31, 42, 152, 152, 17, -20};
		int max = 0;
		int second = 0x80000000;
		int i;
		for(i = 0; i < sizeof(a)/sizeof(a[0]); i++)
		{
			if(a[i] > max)
			{
				second = max;
				max = a[i];
			}
			else if(a[i] > second && a[i] < max)
				second = a[i];
		}
		printf("%d\n", second);
		return 0;
	}
	

####2.用位运算实现对一个无符号数的二进制打印，八进制打印，十六进制打印；(实现3个函数).

	#include <stdio.h>
	
	void print_binary(unsigned int num)
	{
		int i;
		for(i = 31; i >= 0; i--)
		{
			if(num&(1<<i))
				printf("1");
			else
				printf("0");
		}
		printf("\n");
	}
	
	void print_oct(unsigned int num)
	{
		int i;
		char *oct = "01234567";
		for(i = 30; i >= 0; i-=3)
		{
			putchar(oct[num>>i & 0x7]);
		}
		printf("\n");
	}
	
	void print_hex(unsigned int num)
	{
		int i;
		char *hex = "0123456789abcdef";
		for(i = 28; i >= 0; i-=4)
			putchar(hex[num>>i & 0xf]);
		printf("\n");
	}
	
	int main(int argc, const char *argv[])
	{
		int num;
		scanf("%d", &num);
		print_binary(num);
		print_oct(num);
		print_hex(num);
		return 0;
	}
	

####3.约瑟夫问题，设有编号1，2，3……n的n个人围成一个圈，从第一人开始报数，报到m时停止报数，报m的人出圈，……如此下去，直到只剩下一个人为止，当任意给定m和n时，求n个人的出圈顺序。

	#include <stdio.h>
	#define M 10
	#define N 3
	
	int main(int argc, const char *argv[])
	{
	        int arr[M];
	        int i;
	        int counter = 0;
	        int out_cnt = 0;
	        int step = 0;
	        for (i = 0; i < M; i++) 
	                arr[i] = i + 1;
	        while(counter != M)
	        {
	               if(arr[step]) 
	               {
	                        out_cnt++;
	                        if(out_cnt == N)
	                        {
	                                counter++;
	                                out_cnt = 0;
	                                arr[step] = 0;
	                                printf("%d out!\n", step + 1);
	                        }
	               }
	               step++;
	               step = step % M;
	        }
	        return 0;
	}
	

####4.编写一个shell解析器，如将”  cp      1.c       2.c ”解析为三个字符串，”cp”、”1.c”、“2.c”，要求不受多个空格干扰。(提示：将字符串的地址存放在指针数组里)

	#include <stdio.h>
	
	int shell_parse(char *s, int *parc, char *parv[])
	{
		int stat = 0;
		*parc = 0;
		while(*s)
		{
			if(*s != ' ' && stat == 0)
			{
				parv[(*parc)++] = s;
				stat = 1;
			}
			
			if(*s == ' ' && stat == 1)
			{
				*s = '\0';
				stat = 0;
			}
			s++;
		}
		return *parc;
	}
	
	int main(int argc, const char *argv[])
	{
		char *parv[10];
		int parc = 0;
		char s[100];
		int i;
	
		gets(s);
		shell_parse(s, &parc, parv);
	
		for(i = 0; i < parc; i++)
		{
			printf("%s\n", parv[i]);
		}
		return 0;
	}
	


