---
layout: post
title: Linux基本命令练习题
---
###1.
试用帮助系统，查看printf函数的使用方法。
###2.
建立如下的目录结构：
. <br>
|-- a <br>
|   \`-- c <br>
|-- b <br>
|   \`-- d <br>
|-- e <br>
\`-- o <br>
###3.
用touch命令在上题的基础上建立如下结构：
. <br>
|-- 1.c <br>
|-- a <br>
|   |-- 2.c <br>
|   \`-- c <br>
|       \`-- 3.c <br>
|-- b <br>
|   \`-- d <br>
|-- e <br>
    |-- f <br>
\`-- o <br>
建立完成后删除文件和目录恢复为2题的结构。
###4.
新建三个文件，main.c，Makefile，add.c，完成后用tar打包并用gzip压缩名为add.tar.gz的压缩包，然后删除这三个文件，将压缩包解压。
###5.
建立如下文件结构，o为指向e/main.c的符号连接。
. <br>
|-- 1 <br>
|-- 1.c <br>
|-- a <br>
|   |-- 2.c <br>
|   \`-- c <br>
|       \`-- 3.c <br>
|-- b <br>
|   \`-- d <br>
|-- e <br>
|   |-- add.c <br>
|   |-- main.c <br>
|   \`-- Makefile <br>
\`-- o -> e/main.c <br>
###6.
查找/usr/src下所有以f开头的c文件。
###7.
查找/usr/src下所有文件含有'scanf'字符串的文件，并打印所在行的内容。
###8.
插入U盘，U盘会自动挂载，先卸载，然后再将其装载到~/mydisk/下。
###9.
在终端下输入vim打开一个vim进程，再打开一个终端，在新开的终端中杀死vim进程。
