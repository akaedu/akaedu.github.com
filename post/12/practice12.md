---
layout: post
title: 练习题
---
##练习题
####1.
果调用时的参数类型不对或者参数个数不对会怎么样呢？比如把12.3节的例子改成这样：<br>

        #include <stdio.h>

        int foo();
        int bar();

        int main(void)
        {
                foo(2, 3, 4);

                return 0;
        }

        int foo(int a, int b)
        {
                return bar(a);
        }

        int bar(int c, int d)
        {
                int e = c + d;

                return e;
        }

main函数调用foo时多传了一个参数，那么参数a和b分别取什么值？多的参数怎么办？foo调用bar时少传了一
个参数，那么参数d的值从哪里取得？请读者利用反汇编和gdb自己分析一下。
