---
layout: post
title: 练习题
---
##练习题
####1.
自己实现函数，用位运算实现对一个无符号整型的二进制打印，八进制打印，十六进制打印；

####2.
用位运算实现字符的大小写转换，要求：输入大写的字符转为小写，输入小写的字符转为大写；

####3.
取出一个整型数中的指定的位，比如取出100的4～7位；

####4.
用位运算实现随机生成无重复的26个字母，要求不允许使用数组，结构体；（提示：用一个整型数记录产生的字母）


####5.
计算一个整数a中有多少个1；（提示：a & a-1 可以把最右边的1变成0）

####附加题
给定任意一个数字a，如果a中含有k个1，请用位运算生成下一个含有k个1的二进制数 <br>
参考阅读 http://www.matrix67.com/blog/archives/813

### 课后阅读
漫谈字符集和编码 <br>
http://wenku.baidu.com/view/cb9fe505cc17552707220865.html

编码,charset,乱码,unicode,utf-8与net简单释义 <br>
http://tsoukw.cnblogs.com/archive/2006/07/13/449588.html

有兴趣的同学可以尝试在终端 Console 下显示 ”汉“ 字 <br>
http://wenku.baidu.com/view/395f895d312b3169a451a489.html

参考代码

	#include <stdio.h>
		
	char buf[32] = { 	
				0x40, 0x08,
				0x37, 0xfc,
				0x10, 0x08,
				0x82, 0x08,
				0x62, 0x08,
				0x22, 0x10,
				0x09, 0x10,
				0x11, 0x20,
				0x20, 0xa0,
				0xe0, 0x40,
				0x20, 0xc0,
				0x21, 0x10,
				0x22, 0x08,
				0x24, 0x0e,
				0x08, 0x04,
				0x00, 0x00
			};
	
	char sub = 'a';
	
	int main(void)
	{
		int i = 0, j;
	
		printf("hello, font demo \n");
		//scanf("%c", &sub);
	
		while (i < 32)
		{
			for (j = 7; j >= 0; j--)
			{
				char c = buf[i];
	
				if (c & (1<<j))
					printf("%c", sub);
				else
					printf(" ");
			}	
			i++;
	
			for (j = 7; j >= 0; j--)
			{
				char c = buf[i];
	
				if (c & (1<<j))
					printf("%c", sub);
				else
					printf(" ");
			}	
			i++;
	
			printf("\n");
		}
		
		return 0;
	}
