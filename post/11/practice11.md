---
layout: post
title: 练习题
---
##练习题
####1.
看下面的程序：<br>

        #include <stdio.h>

        int main(void)
        {
                int i;
                char str[6] = "hello";
                char reverse_str[6] = "";

                printf("%s\n", str);
                for (i = 0; i < 5; i++)
                        reverse_str[5-i] = str[i];
                printf("%s\n", reverse_str);

                return 0;
        } 

首先用字符串"hello"初始化一个字符数组str（算上'\0'共6个字符）。然后用空字符串""初始化一个同样长
的字符数组reverse_str，相当于所有元素用'\0'初始化。然后打印str，把str倒序存入reverse_str，再打印
reverse_str。然而结果并不正确：

<pre class='terminal bootcamp'>
<span class='codeline'>$ ./main</span>
<span class='bash-output'>hello</span>
</pre>

我们本来希望reverse_str打印出来是olleh，结果什么都没有。重点怀疑对象肯定是循环，那么简单验算一下
，i = 0时，reverse_str[5]i = str[0]，也就是'h'，i = 1时，reverse_str[4] = str[1]，也就是'e'，依
此类推，i = 0,1,2,3,4，共5次循环，正好把h,e,l,l,o五个字母给倒过来了，哪里不对了？用gdb跟踪循环，
找出错误原因
并改正。
