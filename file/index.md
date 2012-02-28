---
layout: post
title: 文件操作总结
---
###fopen/fclose

	#include <stdio.h>
	FILE *fopen(const char *path, const char *mode);
	int fclose(FILE *fp);

FILE是在头文件中定义的一个结构体类型，这个结构体包含了文件信息，结构体内部有一个内部文件指针用来指向文件中的位置。<br>
mode是一个字符串其中：<br>
“r”     只读，文件必须己存在<br>
“w”    只写，不存在即创建，清空原文件<br>
“a”     只追加，不存在即创建<br>
“r+”    允许读写，文件必须己存在<br>
“w+”   允许读写，不存在即创建，清空原文件<br>
“a+”    充许读和追加，不存在即创建<br>
示例：1.c

	#include <stdio.h>
	
	/** 
	* @brief 创建一个文件，运行之后将创建一个名为file1.txt的文件
	* 
	* 
	* @return 
	*/
	int main(int argc, const char *argv[])
	{
		FILE *fp;
	
		fp = fopen("./file1.txt", "w+");
		if(fp == NULL)
			printf("file open error!\n");
		close(fp);
	
		return 0;
	}
	
###fputc/fgetc

	int fgetc(FILE　*stream);

fgetc()用来从参数stream 所指的文件中读取一个字符， 若读到文件尾而无数据时便返EOF <br>
返回值：fgetc（）会返回读取到的字符，若返回EOF表示读到了文件尾。<br>

	int fputc(int c, FILE *stream);

fputc() 会将参数c转为unsigned char 然后写入参数stream 指定的文件中。<br>
调用fputc/fgetc后文件的内部指针将会向后移。<br>

示例：2.c

	#include <stdio.h>
	
	/** 
	* @brief 观察fgetc的返回值。
	* 
	* 
	* @return 
	*/
	int main(int argc, const char *argv[])
	{
		FILE *fp;
		int i;
		fp = fopen("./file2.txt", "w+");
		for(i = 0; i < 10; i++)
		{
			fputc('a' + i, fp);
		}
		fclose(fp);
	
		fp = fopen("./file2.txt", "r+");
		printf("%c\n", fgetc(fp));
		printf("%c\n", fgetc(fp));
		printf("%c\n", fgetc(fp));
		printf("%c\n", fgetc(fp));
		fclose(fp);
	
		return 0;
	}
	
练习：将a-z26个字母写入文件~/char.txt，写入后从文件中读出并将小写转换成大写打印到屏幕上。<br>3.c

	#include <stdio.h>
	
	int main(int argc, const char *argv[])
	{
		FILE *fp;
		int i;
	
		fp = fopen("./file2.txt", "w+");
		for(i = 0; i < 26; i++)
		{
			fputc('a' + i, fp);
		}
		fclose(fp);
	
		fp = fopen("./file2.txt", "r+");
		for(i = 0; i < 26; i++)
		{
			printf("%c", fgetc(fp) - 32);
		}
		fclose(fp);
	
		return 0;
	}
	

###fseek

	int fseek(FILE *stream, long offset, int fromwhere);

表示将文件内部指针从fromwhere处偏移offset个字节。<br>
fromwhere:<br>
0:文件开头位置<br>
1:文件当前位置<br>
2:文件结尾位置<br>
示例：4.c

	#include <stdio.h>
	
	/** 
	* @brief 体会fseek对文件内部指针的操作
	* 
	* 
	* @return 
	*/
	int main(int argc, const char *argv[])
	{
		FILE *fp = fopen("./char.txt", "w+");
	
		for (i = 0; i < 10; i++) 
		{
			fputc('a' + i, fp);
		}
		fseek(fp, -1, 2);
		printf("%c\n", fgetc(fp));
		fseek(fp, 1, 0);
		printf("%c\n", fgetc(fp));
		fseek(fp, 2, 1);
		printf("%c\n", fgetc(fp));
	
		return 0;
	}
	
###fputs/fgets

	char *fgets(char *buf, int size, FILE *stream);

fgets将从stream所指的文件中读取字符串，遇到'\n'结束。

	int fputs(const char *buf, FILE *stream);

fputs会将字符串buf输出到stream所指定的文件中。
stdin/stdout/stderr是由系统定义的三个文件，分别为标准输入，标准输出，标准错误。
示例：5.c

	#include <stdio.h>
	
	int main(int argc, const char *argv[])
	{
		char buf[100];
		fputs("hello world!", stdout);//put to screen
		fgets(buf, 100, stdin);//get from keyboard
		puts(buf);
	
		FILE *fp = fopen("test.txt", "w+");
		fputs("hi,everyone!", fp);//put to file test.txt
		fgets(buf, 100, fp);//get from file test.txt
		puts(buf);
	
		return 0;
	}
	
###fprintf/fscanf

	int fprintf(FILE *stream, const char *format, ...);
	int scanf(FILE *stream, const char *format, ...);

用法与printf/scanf相同，只是输出/输入的目标改为了从文件。<br>
练习：建立一个结构体student，要求有姓名，语文成绩，数学成绩，英语成绩及平均成绩。建立有5人的结构体数组，从键盘上输入姓名，成绩。输入完毕后计算每个人的平均成绩，将五个人的信息按平均成绩排序输出到文件~/student.txt。<br>6.c

	#include <stdio.h>
	
	typedef struct{
		char name[20];
		int chinese;
		int math;
		int english;
		float average;
	}student_t;
	student_t stu[3];
	
	
	int main(int argc, const char *argv[])
	{
		int i, j;
		student_t tmp;
		FILE *fp = fopen("./student.txt", "w+");
		for (i = 0; i < 3; i++) 
		{
			scanf("%s %d %d %d", stu[i].name, &stu[i].chinese, &stu[i].math, &stu[i].english);
			stu[i].average = (float)(stu[i].chinese + stu[i].math + stu[i].english) / 3;
		}
		for(i = 0; i < 3; i++)
		{
			for(j = 0; j < 3 - i - 1; j++)
			{
				if(stu[j].average > stu[j + 1].average)
				{
					tmp = stu[j + 1];
					stu[j + 1] = stu[j];
					stu[j] = tmp;
				}
			}
		}
		for(i = 0; i < 3; i++)
			fprintf(fp, "%s %d %d %d %.2f\n", stu[i].name, stu[i].chinese, stu[i].math, stu[i].english, stu[i].average);
		return 0;
	}
	

###open/close

	int open(const char *pathname, int flags, int mode);
	int close(int fd);

flags:<br>
O\_RDONLY <br>
O\_WRONLY <br>
O\_RDWR <br>
O\_CREAT <br>
以上几个为宏定义，表示flags的某些位，若要使用多个应使用‘｜’来进行位与操作。<br>
mode用来表示创建文件时的文件读写方式，要用八进制来表示。如0644则表示创建的文件模式为rw-r--r--<br>
返回值为文件描述符，打开文件后系统会开辟一块系统空间来保存文件的信息，通过这个返回值就可找到打开的固定文件。<br>
示例： 7.c

	#include <stdio.h>
	#include <fcntl.h>
	
	int main(int argc, const char *argv[])
	{
		int fd;
		fd = open("./open.txt", O_RDWD | O_CREAT, 0644);
		close(fd);
		fd = open("./open.txt", O_RDONLY);
		close(fd);
		return 0;
	}
	
###read/write

	#include <unistd.h>
	ssize_t read(int fd, void *buf, size_t count);
	ssize_t write(int fd, const char *buf, size_t count);

fd即由open函数返回的文件描述符，buf为存放读取/写入内容的缓冲区，count为要读取多少个字节。<br>
示例：8.c

	#include <stdio.h>
	#include <fcntl.h>
	#include <string.h>
	
	int main(int argc, const char *argv[])
	{
		int fd;
		char buf[100];
	
		buf = "hello world!";
		fd = open("./open.txt", O_RDWD | O_CREAT, 0644);
		wirte(fd, buf, strlen(buf));
		close(fd);
	
		return 0;
	}
	
###fstat
	
	#include <sys/stat.h>
	int fstat(int fd, struct stat *buf);

fstat用来获取文件信息，并将信息存入结构体类型变量buf中。<br>
stat是在头文件中定义的一个结构体：

           struct stat {
               dev_t     st_dev;     /* ID of device containing file */
               ino_t     st_ino;     /* inode number */
               mode_t    st_mode;    /* protection */
               nlink_t   st_nlink;   /* number of hard links */
               uid_t     st_uid;     /* user ID of owner */
               gid_t     st_gid;     /* group ID of owner */
               dev_t     st_rdev;    /* device ID (if special file) */
               off_t     st_size;    /* total size, in bytes */
               blksize_t st_blksize; /* blocksize for file system I/O */
               blkcnt_t  st_blocks;  /* number of 512B blocks allocated */
               time_t    st_atime;   /* time of last access */
               time_t    st_mtime;   /* time of last modification */
               time_t    st_ctime;   /* time of last status change */
           };

结构体的内容不需要记，只要记住其中st\_size是指文件大小就可以了。
示例：9.c

	#include <stdio.h>
	#include <fcntl.h>
	#include <sys/stat.h>
	
	int main(int argc, const char *argv[])
	{
		int fd;
		struct stat buffer;
		fd = open("./main.c", O_RDONLY);
		fstat(fd, &buffer);
	
		printf("filesize = %d\n", buffer.st_size);
		return 0;
	}
	

练习:实现mycp函数。10.c

	#include <stdio.h>
	#include <fcntl.h>
	#include <sys/stat.h>
	
	int main(int argc, const char *argv[])
	{
		int fd1, fd2;
		struct stat buf;
		char cbuf[10000];
		fd1 = open(argv[1], O_RDONLY);
		fd2 = open(argv[2], O_RDWR | O_CREAT, 0644);
		if(fd1 < 0 | fd2 < 0)
		{
			printf("file open error\n");
			return 1;
		}
		fstat(fd1, &buf);
		read(fd1, cbuf, buf.st_size);
		write(fd2, cbuf, buf.st_size);
		return 0;
	}
	
