---
layout: post
title: C Notes
---

2012-2-20 亚嵌教育 46期C语言复习串讲课堂笔记
如有疑问，请加李明老师QQ: 2372614758

day1: section 1
程序概念
	指令 （代码段）
		函数调用 printf()
		运算(加法) a + b
		条件判断 if
		跳转 goto
		循环 while
		函数返回 return
		表达式(赋值) a = 100
	数据 （数据段）
		变量的定义（全局变量)
			指针
			结构体/联合
			数组(一维/二维)

开发环境(Linux 上的 C)
	机器语言/汇编语言/高级语言
	编译器 gcc -s (->.s)
	汇编器 as (->.o)
	链接器 ld (->.elf)
	加载器 loader (disk->mem exec())
	调度器 scheduler (执行)

程序的调试
	编译时错误 compile error
		语法错误 syntax (BNF 范式)
		expression -> while (statement)
				{
					expresstion;
				}
		statement -> variable == statement;
		链接错误
			undefined referrence !
			redefination ...
		
	运行时错误 run-time error
		段错误（非法访问内存）MMU权限设置
		char * p;	// char * p = &c;
		*p = 'a';	// 权限问题 
		
第一个程序 helloworld
int main(void)
{
	return 0;
}
	返回值
	main 名称
		入口
		_start 真正入口
	传入参数 
		void 关键词
	函数体 { }
	return 关键词
		父进程 shell

#include <stdio.h>
/* main function */	
int main(int argc, char * argv[])
{
	// print msg
	printf("hello, world\n");
	return 0;
}
	# 预处理符
	include 关键词 (文件展开)
	stdio.h 文件 (库的头文件)
	库 (标准C库 /lib/libc.a & libc.so)
	链接标准C库 隐含链接规则 -lc (gcc main.c)
	printf (基本的输入输出库) 族
		参数可变长度，第一个参数 const char*
		返回值 int 
		第一个参数里面 % 格式化 (%d, %c, %x, %s, %f, %o, %p, %u, %l, %+/-0Nx) 
		\n (转义字符 \t \r \b \xhh \\ \' \")
	注释 
		// 单行，可以后跟 //
		/* */ 多行，不能嵌套  
	
day1: section 2
数据
	进制 (10-decimal 2-binary 16-hex）
	逻辑运算 (与AND, 或OR, 非NOT)
	算术运算 (加法ADD => 异或XOR)
	MSB/LSB (Most/Least Significant Bit)
	Signed/unsigned (1+1, 1+(-1), (-1)+(-1))
		原码 反码 补码 3个概念
	浮点数
		科学记数法 float pi = 3.1415
		3个部分 符号位 + 幂 + 有效位
		union
		{
			double pi;
			char buf[8];
		}

常量
	字符 char c = 'a';
	数字 int v = 100;	float pi = 3.14;
	枚举 	enum
		{
			Monday = 1,
			Tuesday, Wednesday, ...
		}		
	字符串常量 printf("hello");
		char * p = "hello";
		错误理解 char p[] = "hello";	本质是数组的初始化值，归为数据段（全局变量)

变量 variable
	char, short, int, long
	float, double	
	命名规则：字母和_开头，后面跟字母，数字，下划线
	2个不行：数字开头的不行，关键字的也不行	
	variable ->  [a-z]/_ [a-z]/[0-9]/_+
	int 3 = 4;	
	
关键字 keyword
	auto enum inline register restrict void
	注意 NULL 不是关键字，而是宏定义
	int main(void)
	{
		int NULL＝ 100;
		return NULL;
	}
	结论： #define NULL	((void *)0)
	
赋值语句
	int a = 100;
	看这条语句在函数内，还是函数外
	函数内： 则转为赋值语句，即指令
	函数外： 则转为初始化值，归为数据段
	以下写法为加深理解
	int a : 100;
	char p[] : "abcd";
	int main(void)
	{
		return 0;
	}
	
数字的表示
	0XFULL 是不是一个数字？ 答案是 
	
表达式
	l-value / r-value 左值/右值
	
复杂形式
	+=, -=, *=, /=, %=
	i++, i--
	++i, --i

逻辑运算符
	&&, ||, ~
移位运算符
	>>, <<,
关系运算符
	>, <, ==, >=, <=, !=
位运算符
	＆, |, ~, ^

优先级的问题
	a = 0; b = 1;
	if (a & b == 0)
		c = 0;	
	else
		c = 1;	
	最后打印 c 的值是多少？ 结果是1
结合顺序是 == 先结合，然后才是 &
	加括号才能解决  if ((a & b) == 0)
		
条件运算符
	a > 1? b : c
	value = c > '9'? c-'a'+10 : c-'0'
	
逗号运算符
	b = (t = 3, t + 2) 表达式的值是5 -> b

sizeof 和 typedef
	int a = 100, b[8];
	sizeof a	
	sizeof (a)
	sizeof b/sizeof b[0] --> 8	
	
	int main(void)
	{
		int a = 123456;
	}
	常量 123456 存在哪里？  不同编译器有不同的做法
	方法1：存放到 .rodata 段
	方法2：不单独作为一个段的数据，而是嵌到指令中间
		这种数据，称为 文字池 literal pool
	
	typedef unsigned long size_t;
	#define size_t unsigned long
	
ASCII 码
	CR， LF， DEL
	0－127
	可见部分 0－0x20 空格之后...... 直到 0x7E(126) ~
	'\11' 代表 八进制 ==9
	'\x11' 代表 16进制 ==17
	int a = 011, b = 0x11;
	printf("a = %d\n", a);  打印的是 9
	printf("b = %d\n", b);  打印的是 17
	
day1: section 3
分支结构
	逻辑表达式

if语句
	if/else 语句
		语句块的中间可以出现局部变量
		if/if/else 最后的 else 是就近结合
	
	if 有个特殊性
	if ()
		statement;
	
	if ()		// 对
		statement;
	else
		statement;
		
	if ()		// 对
	{
	
	};
	
	if ()		// 错！
	{
	
	};
	else
	{	
	
	}
	
	if ()		// 对
		do
		{
		
		} while (0);
	else
	{	
	
	}

	if (btn1_is_down())
	{
		a = 1;
		b = 1;
	}
	else
	{
		a = 0;
		b = 0;
	}	
	
	if (btn2_is_down())
	{
		a = 1;
		b = 1;
	}
	else
	{
		a = 0;
		b = 0;
	}	

错误举例： OPEN 后面的分号，语法不能通过
#define OPEN		{ a = 1; b = 1; }
#define CLOSE	{ a = 0; b = 0; }
	if (btn_is_down())
		OPEN;
	else
		CLOSE;
		
正确举例：
#define OPEN	do { a = 1; b = 1; } while (0)

switch 语句
	case 后面能跟 整型常量
	每个 case 后面应该有一个 break; （也可以没有）
	default 是不是必须有？ 不是

break 语句
	退出内层循环
	
循环语句
	while
	do/while
	for
		for (s1; s2; s3) 用分号间隔
		s1 里面可以有 逗号
		for (int i = 0; i < 100; i++)
			注意：这种语法是 C99 的标准
		for (;;)
		{
			
		}
	continue 语句：无法跳出循环，但忽略后面的语句
	label + goto	
	goto 语句：标号 label 后面需要有冒号 label:
	(汇编语法中 .global .globl 都可以 )
	
day1: section 5	
数组：
	数组定义时，下标可以不可以是变量？
	int b = 100;
	int a[b]; 
	结论：局部变量时 可以，编译能够通过
		全局变量时 不可以，编译不通过
		
	数组名：是常量，只有右值，不能放等号左边
		同时，数组名也不能作 ++ 运算
		但可以作加/减运算，不能做乘除（需要强制类型转换）
		
数组初始化
	用 {} 和 , 来表示初始化值
	如果少，则剩余部分用 0 (全局和局部都会清0)
	如果用 int a[] =  来初始化，则长度由后面的元素个数定
		
常量数组
	const int day[] = {31, 28, 31...};

字符串
	本质是一个字符数组，结尾用 '\0'	
	char str[10] = "hello,world"; 	(bad)
	char str[] = "hello,world"; 	(good)
	char *str = "hello,world";
	
综合：
	char * argv[];
	(char*) argv[]; 	(good)
	char **argv;		(ok)
	结论： 当char * argv[] 数组作为参数传递时，
	argv 不是一个数组名，也不是常量，而就是变量
	[] 里面的数组大小，对于参数传递没有效果，无用
	
结构/联合/枚举	struct / union / enumeration
	Tag: 	struct my_tag
		{
			int a;
			int b;
		} zhang;
	zhang: 变量，注意最后要有分号 (可省略）
	. 运算符 zhang.a  zhang.b

题目举例:  写一个宏： 问如何获得成员 b 的偏移量
	int offset_of_b = ???
		
#define  GET_OFFSET(type, member)        \
       (int)&(((type *)0)->member) - (int)&(*(type *)0)
	
	int offset = GET_OFFSET(struct mytag, b);

问题：结构体在函数传参的时候，是传地址，还是传值？
	struct mytag zhang;
	fun(zhang);
		in fun() 对 zhang.b 做了修改
	zhang.b 是修改之后的，还是原始？
	结论： 是传的值，修改之后，不影响原始的值
	struct mytag li;	
	li = zhang; 	结论：是把zhang整体拷贝赋值给li
	
结论： 结构体在传值和赋值这些操作时，就等同于一个整型

题目：用联合union来判断机器是大端存储还是小端存储。

day1: section 6
简单函数
	在汇编语言里面，没有一个非常合适的特性来支持
	在机器上最终C语言的函数，转为汇编的方法不尽相同

严格写出一个函数的 返回值，参数列表，参数类型
	如果不返回值或者没有参数，都用 void 来表示
	main 函数的两种写法
	
int func(void) {
	return 0;	
}

int
func(void)
{
	return 0;
}

	函数原型的声明，不需要说明参数的名字，但需要类型
	但是在实现的地方，必须要名字，无论你用不用它
int func(int, int);

int func(int a, int b)	// a, b 不可省略
{
	return 0;
}

	return 返回： 如果上述函数用 return; 返回，
	是警告 warning 还是错误 error？	
	结论： 是警告，返回一个随机值
	如果是提前 return 后面的代码不执行，无警告
	
问题： 局部变量和全局变量的区别和联系。

增量式开发 incremental development
分层设计 stratify 分解和复用

递归函数 Recursive
	0，Fabonacci 数列
	1，写出10的阶乘
	2，逆序打印 (关键：先递归后打印)
	print_str(char * s)
	{
		if (*s == '\0')
			return;
		
		printf_str(s+1);
		putchar(*s);	
	}	
	3，快速排序
	4，树的遍历（深度，广度有限）
	
位操作
	问题：给定一个数 a ，统计二进制表示中1的个数
		int counter = sum(a);
	int sum(int a)
	{		
		int counter = 0;
		for (; a &= (a-1); counter++)
			;
		return counter;
	}
	
典型操作
	与&，或|，异或^，取反~
	移位 <<, >>
	设1： REG |= 1<<n;
	设0：REG &= ~(1<<n);

异或操作实现两个数的 swap，省略一个中间变量
	
指针
	函数内部的变量地址，不能作为指针类型的返回值
	推论：一个就是 scanf("%d", &a);
		还有一个就是 gets(buf);

指针与数组
	指针和整数的加法 p+1	(int)p+1 不一样
	指针的相减很常用，特别是在字符串处理中
	
字符串
	char ch = "abc"[1];		// 'b'->ch
	char digit2hex(int digit)
	{
		return "0123456789abcdef"[digit];
	}
	
	
	char s[10] = "01234567899" 可以吗？
	
字符串库函数
	char * strcpy(char * s1, const char * s2);
	char * strcat(char * dst, const char * src);
	int strcmp(const char * s1, const char * s2);
	size_t strlen(const char * s);
	char * strchr(const char * s, int c);
	char * strstr(const char * haystack, const char * needle);
	char * strtok(char * s, const char * delim);
	char * strtok_r(char * s, const char * delim, char **saveptr);	
	可重入函数reentrant，不可重入函数
	
函数调用的一种写法	
	(void) printf("hello, world\n");
	
day2：setction 1
x86汇编基础
GCC - AT&T 汇编格式
	.section .globl .data .text
	_start:
	# 注释
	mov, movl, int $0x80
	_exit(0), system call

第二个程序
	增加了x86指令：cmpl, je, incl, jle, jmp
	x86寄存器：%eax, %ebx, %edi
	汇总：%ecx, %edx, %esi, %ebp, %esp, %eip
	
通用： %eax, %ebx, %ecx, %edx (ah, al)
栈：%ebp(底), %esp(顶)
数据：%esi(源), %edi(目的) 

day2：setction 2
ELF 格式
	可执行文件.elf，可链接文件.o，动态库.so
	结构组成：ELF Header, Program/Section Header Table, Segments/Sections
	ELF Header: "ELF", Entry Point, Number of Sections
			Size of Section Header
	xxx Header Table: Section Start addr, Size, Section Name index
	Sections: .text .data .bss
		.symtab .strtab
		.shstrtab .rel.text
	
关于程序的加载	
	.o -> sections 节
	.elf -> N sections -> Segment 段 -> 内存页面（虚拟）0x1000(4K)
	虚拟页面的属性：MMU 的权限保护机制 (可读，可写，可执行)
	
函数调用
	函数栈帧 （栈上面有什么？）
		1. 函数调用时传入的参数
		2. 函数内部使用的局部变量
		3. 被调函数完成之后的返回地址
		4. 上一级主调函数的栈底指针(以便恢复上一级栈帧)
			［当前的栈底就是上一级的栈顶］
			
Calling Convention - ABI (Application Binary Interface) 
结合X86说明：	call 指令完成了什么［调用发生处］
		函数进入时编译器作了什么？ ［调用进入处］
		leave 指令完成了什么? ［调用结束处］
		ret 指令完成了什么? ［调用返回处］
	
main函数调用
	哪些工具和库参与了 main 的链接完成？ (gcc -v)
	工具
		cc1: 编译器 .c -> .s
		as: 汇编器 .s -> .o
		collect2: 链接器 .o -> .elf			
	库
		[libc] libc.a/libc.so + [libgcc]
		crt1.o crti.o crtn.o crtbegin.o crtend.o
		/usr/lib/crt1.o 里面包含了 _start 的符号，才是真正的入口
		/lib/ld-linux.so.2 动态链接器
	
变量的存储布局
	全局变量 global
		有初始化值的
			-> 变量会分配到数据段.data
		未初始化的（包括初始化值为0的）
			-> 变量会分配到.bss段
	局部变量 local
		有初始化值的和未初始化的（包括初始化值为0的）
			-> 变量会分配到栈上
	静态变量 static 
		函数内部和函数外部的，有初始化值的
			-> 变量会分配到数据段.data
		函数内部和函数外部的，未初始化的（包括初始化值为0的）
			-> 变量会分配到.bss段
	只读变量 const 
		函数内部的
			-> 变量会分配到栈上
		函数外部的
			-> 变量会分配到只读数据段.rodata
	寄存器变量 register
		一般都分配到寄存器上
		
day2: section 3
结构体和联合体
	Alignment 对齐
	Padding 填充
	是因为要对齐，所以才有了填充； （为什么要对齐呢？）
	由此引出了一个 GCC 的扩展语法：紧致 packed
	struct { ...
	} __attribute__((packed)) s;
	
位域 bit-field
	struct bit-field-demo {
		int one : 1;
		int tow : 3;
		..
	};
	
	// 冒号的用法还可以用于某些成员变量的初始化
	
volatile 限定符
	用 volatile 修饰变量，有以下作用：
		“防止优化，强制访存”

链接详解
	链接脚本 (ld --verbose) 默认链接脚本，需要得到
		第1个就是 .text 代码段的起始地址： 0x8048xxx
		第2个就是 .data 数据段的起始地址： 0x8049xxx
		第3个就是 读写	RO 页面：.text + .rodata + .plt
				RW 页面：.data + .bss + .got
		第4个就是 合并	.text : { *(.text) }	
				.data : { *(.data) }
		第5个就是 程序的入口是从 _start 开始 ENTRY(_start)

静态库
	文件名	.a
	生成	gcc -c		-> .o
		ar rs (ranlib)	-> .a	
			r：添加或创建
			s：创建索引	
	使用	gcc -lname -Lpath -Idir (-static)
		［库的搜索路径］ gcc -print-search-dir
		gcc -static 静态链接
		好处：如果是.a来参与链接，则只取出需要的部分来链接
共享库	
	文件名	.so
	生成	gcc -c -fPIC	-> .o
		gcc -shared 	-> .so
	使用	gcc -lname -Lpath -Idir
	问题	找不到共享库，怎么办？
	error while loading shared libraries: libstack.so: cannot open shared object file: No such file or directory
	解决：	1. 修改环境变量 export LD_LIBRARY_PATH=
		2. 修改缓存文件(/etc/ld.so.cache) vi /etc/ld.so.conf + sudo ldconfig -v
		3. 拷贝文件法 cp libxxx.so /usr/lib (/lib)
		4. 写死文件法 gcc -o main -Wl,-rpath,/home/akaedu/...
		
动态链接的过程
	.plt 段：Procedure Linkage Table 指令
	.got 段：Global Offset Table 数据
	/lib/ld-linux.so.2 动态加载器 + 链接器

共享库的命名
	real name:	libc-2.5.so (libc-2.8.90.so) 真正库文件
	soname:		libc.so.6 符号链接
	linker name:	libc.so 本质上是一段链接脚本
	
几个重要的工具命令
	readelf -a max.o/max 读ELF文件
	hexdump -C max.o/max 查16进制
	objdump -dS max.o/max 反汇编（加入源码）
	nm max.o/max 查看符号表
	ld --verbose 查看默认链接脚本
	ar rs + ranlib 生成静态库
	ldd main 查看可执行文件的依赖关系 （依靠哪些共享库）
	ldconfig -v 生成 ld.so.cache 文件（from ld.so.conf)
	ln -s old new 建立符号链接
	
day2: section 4
Makefile
	基本内容：目标Target，条件Prerequisite，命令Command
	举例： 	target: prerequisite 
			command1
			command2
			...
	1. 目标必须顶格，条件可以省略
	2. 命令必须用 TAB 开头			
	
	更新规则：目标没有生成，条件需要更新
	嵌套/递归的过程
	
	标准情况是：命令即要执行，命令本身还要显示出来
		如果多条命令，中间某一个出错了，则后面的不再执行下去
	＠ 作用：只执行这条命令，能看到命令执行的结果，但不再显示命令本身
		@echo "here is a help"
	- 作用：即使命令执行出错，也不停下来，而是继续执行后面的命令
	
	.PHONY 作用 －－ 同名的文件，则用 .PHONY: clean
	
	约定俗成的内部名字：all, clean, install, distclean

make 的参数
	make -p: 打印隐含规则
	make -n: 只打印，不执行
	make -C dir: 调用指定目录(dir)下的Makefile
	make CFLAGS=-g: 给Makefile 传递宏变量的值
	
makefile 的符号
	$@: 代表左边的目标
	$<: 代表右边条件列表中的第一个
	$^: 代表右边条件列表中所有
	$?: 代表右边条件列表中的比目标新的
	
makefile 的变量
	=	不立即展开，到最后才替换
	:=	立即展开，立即替换，避免死循环
	?=	如果没定义过，则相当于=;如果定义过了，则什么也不做
	+=	追加到当前变量值的后面，自动添加空格
	
makefile 的函数
	$(wildcard *.c)三连符 'a' 'h' 的处理
	$(subst ee, EE, feet on the street) -> fEEt on the strEEt
	$(patsubst %.c, %.o, 1.c 2.c 3.c) -> 1.o 2.o 3.o
	$(strip " a b c  ") -> "a b c"
	$(findstring a, a b c) -> a	(否则返回空)
	$(filter %.c %.s, $(SRC)) -> 过滤掉不符合.c/.s的文件
	$(filter-out) -> 去除掉符合模式的文件
	$(sort foo bar lose) -> 排序 bar foo lose
	$(dir)	$(notdir)	$(suffix)	$(basename)
	$(addsuffix)	$(addprefix)	$(join)

day2: section 5	
预处理
	基本步骤：	1. 三连符 'a' 'h' 的处理
			2. 解决 \ 多行连接成一行问题
			3. 去注释问题
			4. 识别 token 的过程
			5. 相应的预处理，例如 include 文件的展开
			6. 解决 '\n' '\t' 转义字符
			7. 解决 连接字符串 的问题 "hello" "world"
			8. 去空格问题 int      a;
		
	宏定义 manifest constant
		#define N	100
		#define PI	3.1415
	#define LOOP	for(;;)
	#define BOOL	int
	#define DEBUG	不带任何值
	
	带参数的宏（类似函数）
#define MAX(x, y)	((x) > (y)? (x) : (y))
#define TOUPPER(c)	('a'<=(c) && (c)<='z'? (c)-'a'+'A':(c))
写一个宏 hexchar2int(c)	把"0123..9abcdef" 中的字符转为0-15的数字	
	#define getchar()	getc(stdin)
	
#运算符
	表示转换为字符串	
	#define PRINT_INT(x)	printf(#x "=%d\n", x)
	PRINT_INT(i/j)	->	printf("i/j=%d\n", i/j); 	
	
##运算符	
	表示连接字符串
	#define MK_ID(n)	i##n
	MK_ID(1), MK_ID(2)	i1, i2
	
int div_int(int x, int y)
{
	return x/y;
}

float div_float(float x, float y)
{
	return x/y;
}

#define MAKE_DIV_FUNC(type)	\
		type div_##type(type x, type y)	\
		{				\
			return x/y;		\
		}	

	预处理器只会替换完整的记号，而不会替换记号的片段
	#define SIZE 	256		
	int BUFFER_SIZE = 0;	(其中的SIZE不会替换)
	
#undef 宏
	取消已经定义的宏，和 #define DEBUG 对应

预定义宏 (都是编译的时候进行的替换，而不是执行的时候）
	__LINE__	整型
	__FILE__	字符串
	__DATE__	字符串
	__TIME__	字符串
	__STDC__	整型
		
条件预处理（条件编译）		
	#if
		...
	#endif

	#if defined(DEBUG)	或者 	#if !defined(DEBUG)
		...
	#endif

	#ifdef DEBUG
		...
	#endif 

	#if DEBUG
		...
	#else	或者 	#elif	
		...
	#endif
	
assert 宏的实现
	#define assert(test)	((void)0)
	void _Assert(char *);
	#define _STR(x)		_VAL(x)
	#define _VAL(x)		#x
	#define assert(test)	\
		((test)? (void)0 : _Assert(...))
	_Assert(__FILE__ ":" _STR(__LINE__) " " #test)
	
void _Assert(char * mesg)	
{
	fputs(mesg, stderr);
	fputs("--assertion failed\n", stderr);
	abort();
}
	
__func__	这是一个变量名，不是预处理的宏，它的类型是一个字符串
	
day2: section 6
指向指针的指针
	int* *p;
指针数组	
	int* a[10];	定义了一个数组，有10个元素，每个元素是 int *
	
int main(int argc, char * argv[])
	函数原型中的 argv[] 表示的是指针，而不表示数组，等价于 **argv
	这里面的 argv 能作 argv++ 吗？ 答案是能。

指向数组的指针
	int (*a)[10];	定义了一个指针，指向一个数组，数组有10个元素
		这样理解：  typdef int 	t[10];
				t *a;

	int* a[10];	可以拆开理解：typedef int*    t;
					t a[10];
	
	二维数组作为参数传递时，必须给出一维的下标，否则编译器无法计算地址
	
函数指针
	void f(void);		函数声明
	void (*pf)(void);	函数指针（区别在于一个括号）
	int (*padd)(int a, int b);
	
函数类型定义	
	typedef int F(void);
	F f1, f2;  =>	int f1(void); int f2(void);
		
函数指针类型定义
	typedef int (*F)(void);
	F pf1, pf2;	=> int (*pf1)(void); int (*pf2)(void);

文件操作
	FILE *	<stdio.h>
	stdin stdout stderr
	FILE * fopen(const char * path, const char * mode);
	int fclose(FILE * fp);
	#define EOF	(-1)
	
	void perror(const char * s);
	char * strerror(int err_num);
	
	int fseek(FILE * fp, long offset, int whence);
	long ftell(FILE * stream);
	void rewind(FILE * stream);
	
	int printf(const char * format, ...);
	int fprintf(FILE * fp, const char * format, ...);
	int sprintf(char * buf, const char * format, ...);
	int snprintf(char * buf, size_t size, const char * fmt, ...)
	
	int scanf(const char * format, ...);
	int fscanf(FILE * fp, const char * format, ...);
	int sscanf(char * buf, const char * format, ...);
	
	int fgetc(FILE * fp);
	int getchar(void);
	int fputc(int c, FILE * fp);
	int putchar(int c);
	
	char * fgets(char * s, int size, FILE * fp);
	char * gets(char * s);
	
	int fputs(const char * s, FILE * fp);
	int puts(char * s);
	
	size_t fread(void * ptf, size_t size, size_t nmemb, FILE * fp);
	size_t fwrite(const void * ptf, size_t size, size_t nmemb, FILE * fp);
	
	
day3: section 1
Niklaus Wirth	
	 数据结构 + 算法 = 程序

栈的概念
	LIFO 后进先出（先进后出），不能随机访问
	对于编程者，对于栈的访问接口只有 push, pop, is_empty, (peek)

栈的应用	
编程题：用2个栈来解决表达式求值问题： 5+2*4, 5+2+4, 5+2*4*3-1
	
编程题：用栈来实现逆序打印
	提示：先递归，后打印
	
深度优先搜索
编程题：用栈来解决迷宫问题
	算法要领：把可能的路径都压栈保存，然后出栈1次测试一种可能路径
	用0表示可以走，没走过
	用1表示墙壁，不能走
	用2表示走过了，防止重复走
	所谓测试一种路径，就是把走过的0标记为2，然后再接着压栈（下一个可能的路径），重复算法
	总结：这是一种深度优先搜索（DFS：Depth First Search）
	
	如果一种测试失败，或者一条路径找到，栈里仍有节点（可能性），则可以用回溯法接着寻找下一个正确的路径
	
回溯法：
	典型应用：解决八皇后问题
	回溯法的关键是：当退回到某个可能的节点时，当时的状态应得以恢复

day2: section 2	
广度优先搜索
	引入新的数据结构－－队列：
	特点是：2种基本操作--Enqueue (入队) ＆ Dequeue (出队)
	FIFO （先进先出）
	步步为营的策略，每个方向都探索一步，将前线推进一步，始终保持队列中的元素总是由前线的点组成
	所以广度优先的搜索，导致的结果是可以找到最短路径。
	
环形队列
	因为队列这种数据结构，有一个不足之处：入队出队后的空间不能重复利用，所以组成一个圆，用head表示出队位置，用tail表示入队位置
	判断队列满的条件转变成为了 tail 是否能够追赶上 head
	判断队列空的条件转变成为了 head 是否能够追赶上 tail
	
链表
考核的知识点包含：结构体，指针，内存操作，函数，传参，搜索，排序算法	
单链表的几种操作
	定义节点 struct node, typedef, link next;
	创建节点 make_node, malloc, NULL, <stdlib.h>
	插入节点 insert_node, head
	查找节点 p=search(key), 比较节点传 compare 函数指针 (man qsort)
	删除节点 delete_node(p), head
	遍历链表 traverse, visit 函数指针
	销毁节点 free_node(p), free(p)
	销毁链表 destroy, 

编程题：用链表来实现栈操作 push & pop

双向链表 Doubly Lined List
	特点：引入一个前趋指针
	Sentinel 节点：界定表头和表尾

编程题：用链表来实现队列操作 enqueue & dequeue

推荐参考：可以去查看一下Linux内核中的链表实现，抽象程度更高
	/include/linux/list.h 	900行左右的实现
	其中包括了 inline 内联函数实现的链表操作，以及 常用的宏操作
	
day2: section 3
二叉树 Binary Tree
	节点的定义：link l, r;
	满二叉树：所有子节点都有左右子树，节点总数是 1，3，7 (2^N-1)
	完全二叉树：最后一层可以不满，叶子靠左
	平衡二叉树：层数的差别小于等于1
	排序二叉树：

二叉树的遍历
	后序，前序，中序
	其中 中序 遍历的结果通常和排序二叉树有关
	前序和中序遍历的结果合在一起，就可以唯一确定二叉树的形态(ok)
	后序和中序遍历的结果合在一起，就可以唯一确定二叉树的形态(ok)
	前序和后序遍历的结果合在一起，能否唯一确定二叉树的形态？(NO)	
	
二叉树的几种常用操作
	定义树节点 struct node, typedef, link l, r;
	创建树节点 make_node, malloc, NULL, <stdlib.h>
	初始化树：init, 给定中序和前序(后序)的遍历结果，递归实现
	前序遍历：pre_order, 递归实现, visit 函数指针
	中序遍历：in_order, 递归实现, visit 函数指针
	后序遍历：post_order, 递归实现, visit 函数指针
	统计节点：count(), 计算所有节点总数, 递归实现
	计算深度：depth(), 计算二叉树的深度（最深的子树）, 递归实现
	销毁树节点： free_node(p), free(p)
	销毁整棵树： destroy, 必须用后序遍历实现，Why?
	
排序二叉树 BST: Binary Search Tree
	概念：所有左子树都比根节点小，所有右子树都比根节点大，并且递归
	特点：排序二叉树中序遍历的结果，就是从小到大排列的。
	
排序二叉树的几种常用操作
	插入节点 insert, key, 递归实现, 第一个插入的就是根节点
		比根小，则放左边；比根大或者相等，则放右边
		root = insert(root, key);
		
	查找节点 search(root, key), 递归实现
		if (search(root, key))
			delete(root, key);
		
	删除节点 delete_node(root, key), 递归实现
		比根小，则在左子树里面删除；
		比根大，则在右子树里面删除；
		如果就是根，就需要选举出一个新的根
选举办法：1. 如果没有子节点了，那就直接删除，返回NULL
	2. 如果有左子树，则选用在左子树的最右边的节点(左边最大的)
	3. 如果有右子树，则选用在右子树的最左边的节点(右边最小的)
			
排序和查找
	算法 Algorithm 
排序算法
	1. 冒泡排序：bubble_sort
	算法思想：相邻交换，最大数下沉，然后调整范围，接着找次大数。
	
	2. 归并排序 merge_sort
	算法思想：递归，分而治之，对半划分，然后左右递归，再进行合并排序
	缺点：过多占用存储空间
	
	3. 快速排序 quick_sort
	算法思想：递归，分而治之，现选第一个数，为这个数找到它应该的位置，同时保证左边都比它小，右边都比它大，然后左右递归
	优点：没有过多占用存储空间
	
查找算法
	1. 线性查找
	算法思想：顺序查找
	
	2. 折半查找
	算法思想：Binary Search （二分法）
	算法复杂度：O(lgN)
	
补充内容：
	计算机体系结构基础
		MMU
		虚拟地址和物理地址 VA & PA
		页帧（Page Frame）
		MMU会查找页表来确定一个VA应该映射到什么PA
	编码风格
		缩进和空白, 注释, 标识符命名, 函数, indent工具
	gdb
		相关命令用法
			
