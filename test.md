1
#1 硬件原理图 (Schematic)
##1.1 核心板
	SoC: 	S5PV210 -> 584pin	(S5PV210_UM_REV1.1.pdf)
	Mem:	K4T1G -> 1Gb=128MB (K4T1G164QE_rev11.pdf)
	Flash: 	K9F2G08 -> 256M*8bit=256MB (K9F2G08.pdf)
	Reset:	Max811
	Jtag:	TCK/TDI/TDO/TMS/TRST
	CLOCK:	24Mhz (X1) XXTI/XXTO
	LED:	LED1-4
	HDMI:	mini HDMI(CON8)

##1.2 底板
	CONN-AB:	30*2 * 2个 = 120pin 引出 (例如串口TxD/RxD)
	CONN-C:		15*2 = 30pin 引出 (例如I2C, CAM)
	Power-On/Off: 	S1
	NET：		DM9000AEP (Ethernet) HR91105A
	Audio:		WM8960 (DA/AD convert)
	Buzzer:		PWM beep
	RTC:		Real-Time Clock
	I2C-Eeprom:	MAC address (6 bytes)
	Buttons:	K1-K8 (XEINT16-27)
	SD-CARD:	Data(4pin) + (4pin)
	UART:		串口(通用异步收发器)
	LCD：		40pin / 45pin (DATA-24pin)

	课堂练习：找一下 LED1-4, RxD0/TxD0 这些pin在210上的位置

#2 芯片手册导读 (DataSheet)
	S5PV210_UM_REV1.1.pdf (2095页)
		作用：内部结构和设计<->584Pin 之间的关系
##2.1 目录结构图
			PRODUCT OVERVIEW
			Block Diagram
				CPU (运算) (控制)
				BUS
				Controllers (特殊功能寄存器)
			Pin Assignment Diagram
			SIGNAL DESCRIPTIONS
			SPECIAL REGISTERS (SFRs)
			SYSTEM MANAGER
				System Memory Map (系统内存映射)
					0x4000000 = 0x40M = 64M
				System Manager Registers (10+)
			SFR
				Name + Address + R/W + desc. + Reset Value
				Bit-Field
			Timing 时序图
			Controller
				OVERVIEW
				Diagram
				SPECIAL REGISTERS
				Timing

	课堂作业： 请自己阅读 210.pdf 手册，找出手册之间的异同

##2.2 S5PV210_UM_REV1.1.pdf 手册分析
	Section 节
		Chapter 章
			subitem 子项

	一、Overview
		1. overview
			block diagram
		2. memory map
			System Memory Map
			SFRs (Special Function Register)
				0xE0000000 - 0xFB6FFFFF (max-512M)
				真实的存储容量：寄存器的个数 * 4bytes
				以串口为例： 15个 * 4组 = 60个 * 50 = 3K * 4 = 12K
		3. ball map
			pin assignment
			signal description
				UART-RxD0/TxD0 CTS0/RTS0
	二、System
		1. GPIO
		2. Clock
		3. Power
		4. boot sequence
	三、Bus
		1. AXI/AHB
	四、Interrupt
		1. Vectored Interrupt Controller
	五、Memory
		1. DRAM => DDR memeory
		2. SROM => SRAM + ROM(Nor Flash)
		3. OneNand
		4. Nand
		5. Compact Flash
	六、DMA
		1. DMA Controller
	七、Timer
		1. PWM Timer
		2. System Timer
		3. Watchdog Timer
		4. RTC
	八、Connectivity
		1. UART
		2. IIC-bus
		3. SPI (serial peripheral interface)
		4. USB Host
		5. USB OTG
		6. SD/MMC
	九、Multimedia
		1. LCD
		2. CAM
		3. G3D
		4. CODEC
		5. TVOUT
		6. VIDEO
		7. MIXER
		8. IMAGE ROTATOR
		9. JPEG
		10. G2D
	十、AUDIO
		1. IIS
		2. AC97
		3. PCM
		4. ADC (TS)
		5. KeyPad
	十一、Security

#3 关于内核，控制器，总线和外设之间的关系
	内核：Cortex-A8 (CORE)
		寄存器 Regs (R0-R15, CPSR)
		指令集 Ins (add/sub, ldr/str)
		总线 (访存指令)
	地址概念：
		cpu：32bit	ldr r0, [r1] 	(r1:addr)
			1)SRAM:
			2)SFR:
			--------------------------
			3)DDR:
			4)Device internal memory:
	总线概念：
		片内总线
			地址线-32bit	由 地址寄存器的字节数 决定
		片外总线
			地址线-29bit	由 设计cpu时，外接的单个存储器件的最大容量 决定
		内存控制器
			通过把 32bit 的最大访存范围，分割为若干个 bank 来进行统一访问
	外设控制器概念：
		外设 = 可见(接插件/关联芯片/连接线) + 不可见(外设控制器)
		外设控制器 = 寄存器接口 <---- 黑匣子(类似函数库.o) ---> 外设工作的时序图
	总结关系：
		都是涉及到裸板驱动 (无操作系统/无MMU参与)
		本质上除了运算之外，都是变成为对地址的读写
		C语言的指针，在本阶段，占一个很重要的角色。

#4 开发工具链
##4.1 工具位置
	C:\Program Files\ARM\ADSv1_2\Bin
	IDE.exe 	ADS IDE
	axd.exe		AXD debugger

##4.2 命令行开发工具链 (GNU tools-chain)
	armcc.exe	C compiler	(armcpp.exe) /gcc
	armasm.exe	ASM Assembler /as
	armlink.exe	Linker	/ld (collect2)
	fromelf.exe	Bin-Utils (objdump/objcopy)

##4.3 C 编译器
	armcc
		-c 只编译，不连接
		-D (定义)条件编译 (-DDEBUG)
		-U (不定义)条件编译 (-DDEBUG)
		-g 增加调试信息
		-I 指定 include 路径(自己的)
		-On 编译优化级别
		-S 生成汇编
		-o 指定生成文件名
	arm-linux-gcc 交叉编译器的库 和 armcc 链接的库是否一样？

	armcc hello.c
		默认会生成  __image.axf (a.out)

	如果C程序，没有 main 函数，有警告，无error，能生成可执行文件

	fromelf -bin hello.axf -o hello.bin

	fromelf -c hello.axf -o hello.txt

	armcc -c hello.c
	armlink hello.o -o hello.axf
	fromelf -bin hello.axf -o hello2.bin

	armlink -entry test hello.o -o hello3.axf
	fromelf -c hello3.axf -o hello3.txt

	armlink -ro-base 0x0 -entry test hello.o -o hello4.axf
	fromelf -c hello4.axf -o hello4.txt

	armasm start.s -o start.o
	armlink start.o main.o -o demo.axf

day 2:
课堂提问：
=========
#1 你用过哪种嵌入式开发板？
	ARM Cortex-A8
	Samsung S5PV210 (1G)
	底板 + 核心板结构
	核心板上有最小系统(时钟，cpu，ddr sdram, nandflash)
	底板上有串口，网口，音频，usb，SD

#2 你用的板子上面有哪些芯片？
	核心板上有S5PV210, K4T1G164, K9F2G08, Max811, 24MHz
	底板上有DM9000, WM8960, Max3232, Eeprom,

#3 你用过的主芯片里面有什么？
	CORE - Cortex-A8
		MMU
		CACHE
		Regs (通用寄存器)
		ALU (运算器)
	BUS
		片内 - 地址线32bit
		片外 - 地址线取决于BANK的大小
	iRAM (SRAM)
	iROM
	Peripheral Controllers
		Memory cont.
		GPIO cont.
		UART cont.
		USB cont.
		IIC cont.
		SD cont.
		SPI cont.
		DMA cont.
		Interrupt cont.
		G3D, G2D
		HDMI
		CAMERA
		TVOUT
		IMAGE ROTATOR
		JPEG

#4 通过原理图能够知道哪些信息？
	有哪些芯片
	芯片有哪些管脚
	芯片之间的连接关系
	芯片与外设本身之间的连接关系
	得到有些芯片管脚的默认连接（接地/接电源）
	NC (No Connection) 不连接的管脚
	电阻电容等分立元件（模拟电路）

#5 数据手册应该怎样阅读？
	Overview
		CHIP Block Diagram, MemoryMap,
		Pin Assignment, Signal Description
		SFRs (how many, address range)
		Controllers (how many)
	System
		Clock (BUS), Power
		Boot Sequence (启动/引导流程)
		GPIO
	Device
		UART
		NandFlash
		Memory (DDR)
		DMA
		Interrupt
		PWM Timer
			-> mini OS porting
		LCD + TS
		AUDIO
		DM9000
		SD
		Security

#6 你用过的开发工具是如何使用的？
		armcc main.c -> .axf
		armasm start.s -> .o
		armlink -ro-base 0x?? -entry xxx -> .axf
		fromelf -bin -> .bin
		fromelf -c -> .txt (反汇编)

#1 GPIO 驱动工作原理
##1.1 read_CHIP_ID
	/*
	PRO_ID	0xE0000000
		Product ID  [31:12]  Product ID
		The product ID allocated to S5PV210 is “0x43110”
	*/

##1.2 GPIO 数据手册导读
	General Purpose Input/Output (p92-p352)
	（看完 GPIO 章节，要解决哪些问题？）
	1) 237 multi-functional input/output port pins
		34 general port groups
	2) GPIO <---> peripheral controller (signal mux)
	3) GPIO Block Diagram
		APB bus (addr + data) *(int *)0xE0000000 = 0x1234;
		Register File (GPIO SFRs)
		Mux Control (functional)
		Interrupt Control (Interrupt cont.)
	4) Pin Mux Description
		pin name -> GPIO name
		default function
	5) GPIO REGISTER DESCRIPTION
		addr range: 0xE020_0000 - 0xE020_0F80
		Reg1: GPA0CON: GPA0 + CON (control)
			bit-field name: GPA0CON[7] -> GPA0_7
			field width: [31:28]
			GPA0_7 pin setting:
				input: 0000
				output: 0001
				UART_1: 0010
				INT: 1111

		Reg2: GPA0DAT
			bit-field: [7:0]
			when input:	the pin state(high-level:1 low-level:0)
			when output: set bit 1, output high-level
			when functional: leave this pin to peripheral controller

		Reg3: GPA0PUD
			Pull-up
			Pull-down
				00 = Pull-up/down disabled
				01 = Pull-down enabled
				10 = Pull-up enabled
				11 = Reserved

		Reg4: GPA0_INT_CON
			Sets the signaling method
				000 = Low level
				001 = High level
				010 = Falling edge triggered
				011 = Rising edge triggered
				100 = Both edge triggered
				101 ~ 111 = Reserved

		Reg5: GPA0_INT_MASK
			Enables Interrupt / Masked
				0 = Enables Interrupt
				1 = Masked

		Reg6: GPA0_INT_PEND
			Interrupt occur status
				0 = Not occur
				1 = Occur interrupt

##1.3 硬件连接情况：
		LED1: 	GPJ2_0	output	GPJ2CON	0xE020_0280
		K1: 	GPH2_0	input	GPH2CON	0xE020_0C40
		Buzzer:	GPD0_0	output	GPD0CON	0xE020_00A0

#2 GPIO 驱动编码实现
##2.1 汇编程序
	TAB
	AREA led
	CODE, DATA
	READONLY
	label
	instruction...
	END

##2.2 立即数的表示
	mov 操作，#后面跟着的数字是立即数，会写入指令中
	有效位不超过8位，同时通过循环右移偶数位得到
	1 0000 0010 = 0x102
	10 0000 0100 = 0x204

连接开发板
	启动超级终端 hypertrm	(.exe)
	选择 COM1 (pc)
	修改波特率为 115200
	修改流控制为 无 (none) （影响输入）
	连接之后，输入 help
	如果发现有输出但无法输入，留意 Scroll Lock 是否被误按

	# loadb 输入命令
	超级终端菜单 -> 传送 -> 发送文件
	-> 选择文件 + Kermit协议 -> 点击发送
	# go 0x21000000
	之后观察 LED1 灯亮啦

##2.2 C程序

day 3:
课堂提问：
=========
#1 你写过GPIO的驱动，请简单说明GPIO的工作原理
	GPIO Controller
		how many pin
		pin number, pin name, pin mux functional
		device <-> GPIO (LED1 -> GPJ2_0) 原理图
	GPIO SFRs
		Set mux function
			控制寄存器 GPXCON
		Set pin value
			数据寄存器 GPXDAT
		Set interrupt function
			中断寄存器 ...

#2 ARM汇编实现 GPIO 的驱动，有哪些注意要点？
	AREA name, CODE, DATA, READONLY, ENTRY
	entry name, instructions, END

	mov 立即数, 有效位<=8bit，通过循环移动偶数位可以得到
	LED 灯，写0点亮，查看原理图可得
	LED 灯闪，需要延时，不延时虚亮，延时时间：0x10000000
	CPU 速率 1G = (0x后6-7个0)
	CPU 速率 200M = (0x后4-5个0)
	CPU 速率 24M = (0x后3-4个0)

#3 请写一段ARM汇编的延时函数，并说明之。

	主程序中
	bl delay
	...

delay
	ldr r0, =0x10000000
go_on
	sub r0, r0, #1
	cmp r0, #0
	bne go_on

	mov pc, lr

#1 UART
##1.1 串口驱动工作原理
###1 串口的硬件连接 (硬件原理图)
	COM0 接口 DB9 九针公头
	pin2: RSRXD0
	pin3: RSTXD0
	pin5: GND
	通过 TxD 发送字符（以字节为单位 5-8bits）
	通过 RxD 接收字符（以字节为单位 5-8bits）

	RS232 电平：-15v->+15v (+15v-逻辑0, -15v-逻辑1)
	TTL 电平： 0->+5v (0-逻辑0, 5v-逻辑1)
	逻辑电平的转换： MAX3232 (美信芯片)

	查看 MAX3232 芯片+核心板原理图可得
		RSTXD0 <- XuTxD0 -- TINY1B B7 -- XuTXD0/GPA0_1
		RSRXD0 -> XuRxD0 -- TINY1B B8 -- XuRXD0/GPA0_0

	结论： GPA0 管理了 UART 的 Txd/Rxd 两个引脚

###2 串口的管脚功能复用 (210芯片手册)
	GPA0 Mux Function
	查看 GPA0[0] GPA0[1]，确认了 UART 的复用功能
	查看 GPA0CON 寄存器，了解如何设置 (0010)
	GPA0CON : 地址 0xe0200000
	[FriendlyLEG-TINY210]# md 0xe0200000
	e0200000: 22222222 000000ab 00005555 00000000    """"....UU......
	e0200010: 00000000 00000000 00005555 00000000    ........UU......

	[FriendlyLEG-TINY210]# mw 0xe0200000 0x22222202

	结论：RXD 影响接收， TXD 影响发送
		RTS和CTS对发送和接收暂时无影响（无流控制）

###3 串口的控制器 (210芯片手册)
	UART Controller (p853-p882)
	类似是一个函数，需要了解它的->输入，输出，如何实现
		1. 输出：Timing (串行通信实现时序图)
			Serial I/O Frame Timing Diagram (Normal UART)  ->p860
		2. 输入：SFR (串口控制器的寄存器)
			REGISTER DESCRIPTION  ->p864
		3. 实现：Block Diagram (结构框图)
			Block Diagram of UART  ->p854

	1. Timing:
		空闲状态 high-level
		起始位 start bit - 1 bit
		数据位 data bit - 8bit
			奇偶校验 odd/even Parity (无)
		停止位 stop bit - 1 bit

	2. SFR:
		15 Regs	Register  Address
		控制类	6个
			ULCON0  0xE290_0000
			UCON0  0xE290_0004
			UFCON0  0xE290_0008
			UMCON0  0xE290_000C
			UBRDIV0  0xE290_0028
			UDIVSLOT0  0xE290_002C

		状态类	4个
			UTRSTAT0  0xE290_0010
			UERSTAT0  0xE290_0014
			UFSTAT0  0xE290_0018
			UMSTAT0  0xE290_001C

		数据类	2个
			UTXH0  0xE290_0020
			URXH0  0xE290_0024

		中断类	3个
			UINTP0  0xE290_0030
			UINTSP0  0xE290_0034
			UINTM0  0xE290_0038

	3. Block Diagram:
		Peripheral Bus 外设总线
			*(int *)SFR_ADDR = value;
		Controll Unit 控制单元
			Control Regs
		Baud-Rate Gengenrator 波特率发生器
			Clock Source 时钟源 (66M)
		Transmitter 发送器
			Transmit shift 发送移位器
			Transmit buffer 发送队列FIFO缓冲器
		Receiver 接收器
			Receiver shift 接收移位器

###4 串口的寄存器 (210芯片手册)
	查看 uboot 对串口的设置

	[FriendlyLEG-TINY210]# md 0xe2900000
	e2900000: 00000003 00000245 00000000 00000000    ....E...........
	e2900010: 00000000 00000000 00010000 00000010    ................
	e2900020: 00000000 0000000d 00000023 00000808    ........#.......
	e2900030: 00000005 00000005 00000000 00000000    ................
	e2900040: 00000000 00000000 00000000 00000000    ................
	e2900050: 00000000 00000000 00000000 00000000    ................
	e2900060: 00000000 00000000 00000000 00000000    ................
	e2900070: 00000000 00000000 00000000 00000000    ................
	e2900080: 00000000 00000000 00000000 00000000    ................
	e2900090: 00000000 00000000 00000000 00000000    ................

	ULCON0  	0xE290_0000 	00000003
	UCON0  		0xE290_0004 	00000245
	UFCON0  	0xE290_0008 	0
	UMCON0  	0xE290_000C 	0
	UBRDIV0  	0xE290_0028 	00000023
	UDIVSLOT0  	0xE290_002C 	00000808

	其中 FIFO control & Modem control 可以不用设置
	Timing setting
		ULCON0	0x3
			data bit: 8bit
			stop bit: 1bit
			parity: none
		UCON0	0x245
			enable Transmit & Receive MODE: 01 01	(INT&Polling)
			interrupt: disable
			dma: disable

	CLOCK setting
		UCON0	00:  PCLK (66M)
			--> 115200 bps (bit/second)
			--> 波特率并不是串口控制器的工作频率，串口控制器在接收采样时，是波特率的16倍

		66Mhz = 66000000hz

		分频因子 = 66000000 / (115200*16) - 1
		(分频因子 + 1) = PCLK/(bps*16)

		UBRDIV0:  0x23 = (66000000)/(115200*16)-1= 35
		UDIVSLOT0:

#2 CLOCK
#2.1 时钟源
###1 时钟和周期的换算关系
		24Mhz 输入时钟
		10^(-3)	毫秒	10^(-6)	微秒	10^(-9)	纳秒
		1Khz 10^3		1Mhz 10^6		1Ghz 10^9
		1Ghz -> 1纳秒
		100Mhz -> 10纳秒

###2 Clock Controller 时钟控制器 (p353-p417)
	CMU: Clock Management Unit
		总线频率
		MSYS: Main  (200Mhz-100Mhz)
			Cortex A8 Core
			DRAM controller
		DSYS: Display (166Mhz-83Mhz)
			JPEG
		PSYS: Peripheral (133Mhz-66Mhz)
			UART
			AC97
			PWM Timer
			GPIO

	Clock Generator 时钟发生器
		S5PV210 Top-Level Clocks
			XXTI - 24Mhz --> (4 PLLS's input)
			XrtcXTI - 32.768Khz
		4 PLLs (APLL, MPLL, VPLL, EPLL)
			Phase Locked Loop 锁相环 (倍频)

	MSYS clock domain (H->HighPerformance P->Peripheral)
		AHB / APB
		freq(ARMCLK)  = 1000Mhz		1000M/1
		freq(HCLK_MSYS) = 200Mhz	ARMCLK/5
		freq(PCLK_MSYS) = 100Mhz	HCLK_M/2
		freq(HCLK_IMEM) = 100Mhz	HCLK_M/2

	DSYS clock domain
		freq(HCLK_DSYS) = 166Mhz
		freq(PCLK_DSYS) = 83Mhz		HCLK_D/2

	PSYS clock domain
		freq(HCLK_PSYS) = 133Mhz
		freq(PCLK_PSYS) = 66Mhz		HCKL_P/2
		freq(SCLK_ONENAND) = 133M/166Mhz

	PLL PMS setting

###3 Clock Generator 时钟发生器
	PLL: Fin -> Fout 倍频		XPLL_CON
	MUX: 0/1 选择器 SRC选择源	CLK_SRC
	DIV: /2-16 分频器 DIV		CLK_DIV

	REGISTER DESCRIPTION
	OM[0]: cpu pin OM[0]=0, XXTI=24M
	Fin_PLL: 24Mhz
	APLL: APLL_CON: e0100100: 0xa07d0301 => 1000Mhz
	Mux_APLL: CLK_SRC0, 0xe0100200: 10001111 [0]=> 1
	Mux_MSYS: CLK_SRC0, 0xe0100200: 10001111 [16]=> 0
	DIV_APLL: CLK_DIV0, 0xE0100300: 14131440 [2:0]=> 0 = /1
= 	DIV_APLL: CLK_DIV0, 0xE0100300: 14131440 [10:8]=> 100 = /5

	UART 串口时钟 PCLK_PSYS 的生成过程
	Mux_PSYS: CLK_SRC0, 0xe0100200: 10001111 [24]=>0  Fout_mpll

	MPLL: MPLL_CON: 0xa29b0c01 => 667Mhz (p358)
		Equation to calculate the output frequency:
		FOUT = MDIV X FIN / (PDIV X 2^SDIV)
		Fout = (0x29b)*24M/(12 * 2^1) = 667Mhz
	Mux_MPLL: CLK_SRC0, 0xe0100200: 10001111 [4]=> 1  Fout_mpll

	DIV_HCLKP: CLK_DIV0, 0xE0100300: 14131440 [27:24]=> 0100 = /5
	DIV_PCLKP: CLK_DIV0, 0xE0100300: 14131440 [30:28]=> 001 = /2

#3 CLOCK & UART 编程实现
##3.1 C语言

#课后作业
从键盘输入一个数字，用LED灯显示它的二进制
例如，输入'9', 显示 1001 (1-亮,0-灭)

day4:
课堂提问：
=========
#1 请简单说明UART Controller的工作原理
	Signal 信号线
		TxD/RxD
			RSTXD/RSRXD (MAX3232)
	Timing 串行通信的时序图
		空闲状态：高电平
		起始位：1bit = 0
		数据位：8bit
			奇偶校验位：1bit （可无）
		停止位：1bit
	SFR 特殊功能寄存器
		控制类，数据类，状态类，中断类
	Block Diagram 结构框图
		Peripheral Bus
		Control unit
		Baud rate generator
		transmitter & receiver
			shifter
			buffer (FIFO)

#2 请解释一下串口的波特率计算公式
	buadrate divisor = PCLK/(bps*16) - 1
	PCLK: UART Controller 的输入时钟
	bps: 数据输出/输入的位时钟
	bps*16: UART Controller 的工作时钟
	分频值： 输入时钟/工作时钟
	减1： 分频值 - 1

#3 请说明一下 S5PV210 芯片的串口寄存器情况
	控制类6个
		ULCON0: 数据位，停止位，奇偶校验位
		UCON0: tran&recv mode(polling/int/dma)
				clock source (PCLK)
		UFCON0: FIFO disable
		UMCON0: Modem disable
		UBRDIV0: buadrate divisor
		UDIVSLOT0: divisor's left
	状态类4个：
		UTRSTAT0: Trans&Recv status
		...
	数据类2个：
		UTXH0: trans (char)
		URXH0: recv (char)
	中断类：
		INTP
		INTSP
		INTM

#4 请解释以下名词 PLL, MUX, DIV 在时钟管理中的作用
	PLL: 锁相环
		作用： 倍频
		配置： P，M，S
			Fout = Fin * M / (P*2^(s-1))
			PLL_CON (P,M,S)
	MUX: 多路复用选择器
		作用： 选择输入时钟源（来自哪个输出）
		配置： CLK_SRC (1 bit)
	DIV: 分频器
		作用： 降低输出频率
		配置： CLK_DIV (n bit) 8(3bit) 16(4bit)


#5 请说明一下 S5PV210 芯片的时钟输出情况
	3个 domain 域
	MSYS: main
		ARMCLK: 1G
		HCLK_MSYS: 200Mhz
		PCLK_MSYS: 100Mhz

	DSYS: display
		HCLK_DSYS: 166Mhz
		PCLK_DSYS: 83Mhz

	PSYS: peripheral
		HCLK_PSYS: 133Mhz
		PCLK_PSYS: 66Mhz

存储管理
#1 Memory Map 存储映射
	地址的划分
		*(int *)0x21000000 : DRAM
		*(int *)0xE0200280 : GPIO SFR
		*(int *)0xE2900000 : UART SFR
	DRAM0: 	0x20000000 - 0x3FFFFFFF: 2^29 = 512M
	DRAM1:  0x40000000 - 0x7FFFFFFF: =1G
	SFR:	0xE0000000 - 0xFFFFFFFF: =512M
	iROM:	0xD0000000 - 0xD0010000: =64K
	iRAM: 	0xD0020000 - 0xD0038000: =96K (0x18=24*0x1000) 
	Boot Area: 0x0 - 0x20000000 =512M
		Mirrored region depending on boot mode
	
Section 5: Memory	
==================
#1 DDR SDRAM 硬件连接情况 (原理图)
	Memory Summary (p4)
	DDR SDRAM (p8)
		行地址：14
		列地址: ?
	
	DDR DRAM 的内部结构（容量）
		数据线 8bit * 4chip = 32bit data bus
		地址线 14根
			内部分 8 bank，每个bank=64M
			0-64M:		0x4000000
					100 000...000 (24-0)
			64M-128M:
					200 000...000 (24-0)
			128-192M:
					300 000...000 (24-0)
					
				  000
				  111
				  bank0,bank1,bank2
			
			26根-64M/bank
			行地址：14根
			列地址：10根
			--------------
					24根 + (A0,A1 -- GND)
					
		CPU:
			512M = 2^29
			29根地址线 (A0-A28)
				A28,A27,A26 : BA2,BA1,BA0
				A25-A12: 行地址 14根
				A11-A2: 列地址 10根
				A1, A0, - GND

#2 DDR 寄存器配置
	[FriendlyLEG-TINY210]# md 0xF0000000
	f0000000: 0ff02330 00202400 20e00323 00e00323    0#...$ .#.. #...
	f0000010: 00110400 ff000000 79101003 00000086    ...........y....
	f0000020: 00000000 00000000 ffff00ff 00000000    ................
	f0000030: 00000618 2b34438a 24240000 0bdc0343    .....C4+..$$C...
	f0000040: 00001db7 00000000 60000000 00000000    ...........`....
	f0000050: 000005b2 00000000 00000000 00000000    ................
	f0000060: 00000000 00000000 00000000 00000000    ................
	f0000070: 00000000 00000000 00000000 00000000    ................
	f0000080: 00000000 00000000 00000000 00000000    ................
	f0000090: 00000000 00000000 00000000 00000000    ................
	f00000a0: 00000000 00000000 00000000 00000000    ................
	f00000b0: 00000000 00000000 00000000 00000000    ................				
				
	DDR 寄存器配置参数
		data width: 32bit
		row address bit: 14bit
		col address bit: 10bit
		memory type: DDR2
		number of banks: 8banks (DDR chip)
		Average Periodic Refresh Interval: 0x618
			7.8us * 200Mhz = 1560 = 0x618
			7.8us : 刷新周期
		Timing 时间参数
			...
			
#2 GPIO & UART 编程模块化实现
	1-GPIO-demo
	2-UART-demo
	
#3 课后作业：
	1) 修改 uart_init, 把波特率改为 19200
	2) 修改 时钟发生器，把 PCLK 输出改为 33M, 波特率重新计算 115200
	3) 实现 puts("hello, world");  输出 "hello, world" 
		实现 实现 putchar_hex('a') 十六进制, 输出 0x61
	目的：了解 \n换行  \r回车  之间的差别
		
	4) 修改 DRAM Controller，
		把 col address 的宽度改为 9bit
		把 data bit 的32bit 改为 8bit
		用上述 putchar_hex 输出接口，观察读取DDR内存单元的数值变化

day5:
NandFlash 驱动
==============
#1 NandFlash 硬件连接情况 (原理图)
##1.1 K9F2G08 芯片 
	48-pin TSOP1 封装
	NC - No Connect 不连接，留待扩展 (25pin NC)
	Signal Desc.
		IO[7:0]: 无地址线，也无数据线，只有IO线 (IO0-IO7)
		CLE: 命令锁存使能
		ALE: 地址锁存使能
		nCE: 芯片使能（片选）
		nRE: 读使能
		nWE: 写使能
		nWP: 写保护
		R/nB: 就绪/忙 信号
		
	Nand Flash 存储特点：
		1 page = 2048 bytes = 2K
		1 block = 64 pages = 128K
		1 device = 2048 blocks = 2K * 128K = 256M bytes
		
	对比 DDR Sdram ：	
		1 device = 8 banks * 16M/bank = 128M
		1 banks = 16M = 16M_A * 8bit
		16M_A = 14行地址 * 10列地址 = 2^24 = 16M
		16M_A * 8bit = 16M
	
	Operation 几种典型的操作
		Read ID 读ID			90h
		Read Page (读)			00h -> 30h
		Program Page 编程(写) 	80h -> 10h	
		Erase Block 块擦除		60h -> D0h

#2 Nand Flash Controller 控制器
	SFR 特殊功能寄存器 (部分)
	控制类
		NFCONF  0xB0E00000 
		NFCONT  0xB0E00004 	
		NFCMMD  0xB0E00008 	[7:0] 命令
		NFADDR  0xB0E0000C 	[7:0] 地址
	数据类	
		NFDATA  0xB0E00010 	[31:0] 数据
	状态类
		NFSTAT  0xB0E00028

#3 Nand Flash Timing 时序
	READ ID Timing (p31)
		CLE 命令周期 写1次 90h		
		ALE 地址周期 写1次 00h
		DAT 数据周期 读5次 id = 0x EC DA 10 95 44 

	READ page Timing (p23)
		CLE 命令周期 写1次 00h
		ALE 地址周期 写5次 
		CLE 命令周期 写1次 30h
		忙等待周期 R/nB 高有效
		数据周期 读2048次data + 64次ECC

#4 要能够读出 ID ，还需要哪些操作？
	初始化配置
		mw 0xe0200320 0x22222222
		mw 0xb0e00000 0x00006552
		mw 0xb0e00004 0x00c100c5
		mw 0xb0e00008 0x90
		mw 0xb0e0000c 0x00
		md 0xb0e00010
		
		GPIO 功能复用设置为 NF signal 						
			ALE: MP0_3[1]
			CLE: MP0_3[0]
			MP0_3CON 	Address = 0xE020_0320
			mw 0xe0200320 0x22222222
			
		NFCONF	0x00001000	-> 0x00006552
			NAND clock = 133M (p363-NFCON) -> 7.5ns (1 clock)
			Nand Timing (k9f2g08.pdf - p13)
			
			mw 0xb0e00000 0x00006552
			
		NFCONT 	0x00c100c6  -> 0x00c100c5
			mw 0xb0e00004 0x00c100c5
			
		NFCMMD:
			mw 0xb0e00008 0x90

		NFADDR:		
			mw 0xb0e0000c 0x00
		
		NFDATA:
			md 0xb0e00010
			
#5 NandFlash 驱动编程实现
	0x1000 = 4K
	0x800 = 2K
	0x400 = 1K

#理论总结
1) GPIO 驱动 和 UART 驱动有何异同？
	引脚：		237pin	vs	14pin(RxD/TxD CTS/RTS)
	功能复用：	input/output/EINT	vs 		RxD/TxD CTS/RTS
	SFR寄存器:	CON/DAT/PUP/INT		vs 		CON/STAT/DAT/BRDIV/INT
	时序图:		High-Low/Sim anytiming	vs	idle/start/data/parity/stop
	驱动初始化：set direction (CON)		vs	set data bit (8bit)/parity (none)/stop (1bit)
				set value	(DAT)			set polling mode (trans&recv)				
				set pull-up 				set baudrate divisor (PCLK/(bps*16)-1)
	驱动读写：	read DAT			vs		polling status, if not empty, read URXH
				write DAT					polling status, if empty, write UTXH
												
2) DRAM 驱动 和 NandFlash 驱动有何异同？
	硬件连接和管脚接口
		14根地址线(行列复用)	vs		8根IO线(数据和地址复用)
		8根数据线(4个拼成32位)	vs		8根IO线(只能按字节连续访问)
		控制线(nRAS/nCAS)		vs		控制线(CLE/ALE)
		片选信号nCS(Xm1CSn0)	vs		nCE(NFCSn0)
		BA[2:0]/R14/C10			vs		Page(2)/Block(3):5次地址发送
		无写保护/无忙			vs		nWP 写保护/ R_nB 忙信号
	
	芯片内部结构和工作原理
		8 banks * 16M = 128M	vs		1page = 2048bytes = 2K
		1bank = 16M						1block = 64pages = 128K
		16M = 14row * 10col * 8bit		1device = 2048blocks = 2K*128K = 256M
		
	特殊功能寄存器组织
		datasheet p614			vs 		datasheet p706
		CON(10-) + Timing(5+)  service(50+)			vs		CON(2) + Timing(3) + ECC(30+)
	
	读写时序图					vs		读page
		1-RAS(BAn)						1-CLE(00h)
		2-RAS(row)						2-ALE(5 addr=2:page+3:block)
		3-CAS(col)						3-CLE(30h)
		4-data R/W						4-polling R/nB
										5-DATA(2048+64)
										
										擦除erase
										1-CLE(60h)
										2-ALE(3 addr=3:block)
										3-CLE(D0h)
										4-polling R/nB
										5-CLE(70h)
										6-DATA(read IO0)
										
										写page (program)
										1-CLE(80h)
										2-ALE(5 addr=2:page+3:block)
										3-DATA(write 2048)
										4-CLE(10h)
										5-polling R/nB
										6-CLE(70h)
										7-DATA(read IO0)
				
	驱动程序编写
	初始化 (see p598) 非常复杂		vs		初始化 (see p708) 比较简单
	读写数据 非常简单 LDR/STR		vs		读写数据 非常复杂 read_page()/program_page()
											读时序： 2个命令周期 + 5个地址周期 + 等待
	Bank选通+行地址+列地址					写时序： 3个命令周期 + 5个地址周期 + 等待
	上述操作都是DRAM控制器自动完成的		上述操作是我们自己手工实现的
	
3) 访问 DRAM 的 0地址和 访问 Flash 的0 地址，硬件是如何实现的？
	DRAM 0地址
		1. 软件上访问 LDR r0, [0] ;  a = *(int *)0x0;
		2. 此时的0地址是cpu，不是 DRAM 芯片的0地址
			DRAM 芯片的0地址，在CPU看来应该是 0x20000000
		3. ldr r0, [0x20000000] 或者 *(int *)0x20000000 才对！
		4. 硬件：DRAM Controller 它获得了CPU发出的 0x20000000 地址
		0x20000000 = 0b 0010 0000 0000 0000 0000 0000 0000 0000
					  A31									  A0
		其中 A31-A29 (001) 做了片选 -> Xm1CSn0 使能
			A28-A26 (000) 做了BANK -> BA2/BA1/BA0 选通，每个芯片内部的0bank选通
			A25-A12 (...) 做了行地址 ->  nRAS 选通，发出行地址14根
			A11-A2 (...) 做了列地址 ->  nCAS 选通，内部移位，然后发出列地址10根
			A1-A0 (00)	直接接地
			然后数据线 4个chip 各贡献了 8个bit，拼成一个32bit数据返回
			
		拓展思考： 如果 *(char *)0x1 或者 *(int *)0x2 会怎么样？
		
	Flash 0地址
		1. 软件上访问 应该是 计算出 0 地址所在的 page + block
			NFCMMD = 0x00;
			NFADDR = 0x0;	
			NFADDR = 0x0;
			NFADDR = 0x0;
			NFADDR = 0x0;
			NFADDR = 0x0;
			NFCMMD = 0x30;
			wait R/nB;
			read NFDATA 2048;
			
		2. 硬件上
			NFCMMD = 0x00;	-> CLE 使能/ALE 禁止, IO[7:0] = 0x00;
			NFADDR = 0x0;	-> ALE 使能/CLE 禁止, IO[7:0] = 0x00;
			NFADDR = 0x0;	-> ALE 使能/CLE 禁止, IO[7:0] = 0x00;
			NFADDR = 0x0;	-> ALE 使能/CLE 禁止, IO[7:0] = 0x00;
			NFADDR = 0x0;	-> ALE 使能/CLE 禁止, IO[7:0] = 0x00;
			NFCMMD = 0x00;	-> CLE 使能/ALE 禁止, IO[7:0] = 0x30;
			read NFSTAT;	-> R/nB 线会设置 STAT 寄存器 0 位
			read NFDATA;	-> nRE 使能, CLE/ALE 禁止, IO[7:0] => NFDATA 中
		
day6:
printf 实现
===========		
#1 概念复习
	栈帧 stack frame
		函数调用过程中，传入参数和函数的局部变量通常都分配在该函数的栈帧里面。
	参数列表 args
		#include <stdarg.h>
		va_list: 类型声明 typedef 本质是一个指针
		va_start: 宏定义 #define 指针ap指向栈(获得栈帧)
		va_arg: 宏定义 #define 通过ap来获取内容(参数的值)，并且指向下一个
		va_end: 宏定义 #define 指针ap清空
	传入参数(局部变量) 栈空间的分配原则
		1. 栈一般来说，都是递减栈。(先入栈在高地址)
		2. 如果要分配空间，则所有参数应该是连续分配
		3. 后进先出 (最后的参数，先入栈=第1个参数，先出栈)
		结论： 如果我们知道第一个参数的地址 p，
				则通过 p++ 就可以得到第2个参数的地址，以此类推
		
#2 编码实现
	如何声明？
	int printf(const char * format, ...);
	类似地
	int add(...);
	int max(...);
	例如：
	int add(int a);
	int add(int a, int b);
	int add(int a, int b, int c);
	int max(int a, int b);
	int max(int a, int b, int c);

课后作业
	基于 gets/puts/printf 完成一个 shell，能够支持命令解析。
	例如： 	$ load    0x21000000
			$ go 0x21000000
		能够解析出 cmd = load, addr = 0x21000000

#printf 实现的相关知识点
	char * itoa(int n, char * s);
	char * reverse(char * s);	// recursive
	int printf(const char *, ...);
	#include <stdarg.h>
	va_xxx 3个宏定义的实现
	实现 printf 的结构 while + switch case
	复习掌握栈帧的用法 (体现在递归实现中)

#shell 实现的相关知识点
	char * gets(char * s);
		\r - 回车键 Enter
		\n - 换行键 Ctrl + Enter
		\b - 退格键 Backspace
	
	int shell_parse(char * s, char * argv[]);
		"load 100"
			argc = 2
			argv[0] = "load"
			argv[1] = "100"

	int load(int argc, char * argv[]);
		size = atoi(argv[1]);	// 字符串到整型转换
		
	int go(int argc, char * argv[]);
		void (*pf)(void);		// 函数指针

day7:
#Loader 实现
#BOOTING SEQUENCE 
SD 卡启动
	1. 跳线拨到了 SD 卡启动
	2. SD 插在座上
	3. SD 空卡 -> Format FAT32 -> dd u-boot.bin bs=1
	
Nand 启动
	1. 跳线拨到了 Nand 启动
	2. NandFlash 0 地址烧入 superboot.bin
		Nand 2M 地址烧入 u-boot.bin
	3. NandFlash 4M 地址烧入 zImage


day8:	
ARM 异常处理
============
#1 ARM 的工作模式有几种？各是哪些？
	7种
		USR: helloworld (非特权->MSR不允许执行)
		SYS: kernel        (2种非异常模式)
		--------------------
		SVC: reset加电     (5种异常模式)
		IRQ: EINT0 key
		FIQ: EINT0 key + MODE(REG)
		ABT: Memory Fault
		UND: execute undefine ins.
		
#2 ARM 的寄存器有多少？ 各是哪些？
	37个 = 31 通用 + 6 状态
		R0-R7: 未分组 (8个)
		R8-R12: 分组 (10个=5*2组 FIQ/~FIQ)
		R13-R14: 分组 (12个=2*6组 5异常+1非异常)
			R13: SP (stack pointer) 压栈/出栈
			R14: LR (Link Register) BL/异常发生后保存PC
		R15: 程序计数器 (1个)
			R15: PC (Program Counter) 流水线 +8
		-----------------------
		CPSR: 程序状态寄存器  (1个)
		SPSR: 备份的状态寄存器 (5个-5种异常)	
	
#3 ARM 的异常有几种？各是哪些？ 
	7种
		复位异常
		数据访问中止
		快速中断
		快速中断
		普通中断
		指令预取中止
		软件中断： SWI
		未定义指令异常： 什么样的指令是未定义？		
		
#4 ARM 的异常向量表是指什么? 有什么特点？
	异常发生后的入口地址
		从0开始的32字节，7种异常都有入口，0x14保留
		向量一般情况下是指地址，但是异常向量表里面存放是指令
		所有ARM内核的处理器都按上述方式工作
		0x0: reset
		0x8: swi
		0x18: IRQ
		0x1C: FIQ (放在最后，那么好处是可以省一条跳转)
	里面存放的是跳转指令
		跳转指令可以是 B (相对，有限) / BL(不能)
		还可以是 LDR (任意跳转)
			B: 		0xEA000000 + offset
			LDR: 	0xE59ff000 + offset
			
#5 ARM 的软中断异常发生后，硬件做何响应？
	硬件要做6件事情，以发生SWI异常为例：
		1. 保存 PC -> LR_svc
		2. 保存 CPSR -> SPSR_svc
		3. 修改 CPSR -> SVC mode
		4. 修改 CPSR I-bit -> disable IRQ
		5. 映射相应IRQ模式的寄存器
		6. 修改 PC -> 0x8
		
#6 cpu 内核跳转到 0x8 之后，软件需要做哪些工作？
	软件要做以下工作：
		1. 保存现场： r0-r12, r14 压栈
			STMFD r13!, {r0-r12, r14}
		2. 进入异常处理:
			BL	swi_handler
		3. 恢复现场： r0-r12, pc 出栈
			A) LDMFD r13!, {r0-r12, pc}^
			B) LDMFD r13!, {r0-r12, r14}
				movs pc, lr	
			将原来保存的 spsr 恢复给 CPSR
	
#7 软件中断和硬件中断，在进行异常处理时有何异同？
	流程基本一样，向量跳转的入口不同：0x8 vs 0x18
	不同之处在于 IRQ返回之前，需要 sub lr, lr, #4
	除此之外，IRQ中断处理还需要清除中断标志位
	
	
day9:
ARM 中断处理
============
#1 异常和中断的概念区分
	异常指的都是内核里面(Cortex-A8)发生的事情
		例如：执行 swi 指令		
	中断指的都是板子上面(tiny210)发生的事情
		例如：用户按下 K1 按键，
				定时器Timer(不在板子上，但在芯片里)
	联系在于？都有模式的切换，中断处理需要包含异常处理
		异常模式包含(中断)异常模式

#2 中断处理的相关概念
#2.1 中断源
	属于 Controller (Samsung) + Board (tiny210)

#2.2 中断控制器 Interrupt Controller
	属于 Controller (Samsung)

#2.3 中断模式的响应和恢复
	属于 Cortex-A Core (ARM)

	S3C4510 - ARM7TDMI
	S3C2440 - ARM920T
	S3C6410 - ARM1176
	S5PV210 - Cortex A8	
	
#2.4 哪些事情硬件做，哪些事情软件做？
	1. 中断触发 (用户/用户设置/外部数据)	
		中断触发条件的初始化操作--软件有关 
	2. 中断响应 (从当前位置跳转到 0x18)
		保存原来的模式和返回的地址--硬件有关
	3. 中断发生后的(老的)现场保存和恢复
		压栈和出栈--软件有关
	4. 中断返回
		恢复原来的模式和地址--软件有关
	5. 中断标志位 SFR Pending bit
		pending bit 的设置--硬件有关 (控制器寄存器PND)			
		pending bit 的清除--软件有关 (控制器寄存器PND)
		作用：识别中断源/调用相应的handler--软件有关(可以交给VIC实现)		
	6. 中断允许位 CPSR I-bit
		加电之后，I-bit 的初始状态是 关闭/禁止 的 (0xD3->0x53)
		MSR/MRS 可以允许使能--软件有关 (内核寄存器CPSR) 
	7. IRQ发生 -> Pending bit -> I-bit	enable -> 跳转
		(跳转之前，硬件会完成 disable I-bit，
			因此不再响应后继任何中断，直到软件恢复CPSR)
	8. 在软件恢复CPSR(重新允许中断)之前，软件需要清除之前的pending bit(VIC+ADDR寄存器=0)
	
	内核和处理器升级的过程，就是不断把原来软件的工作交给硬件来做。
	中断的优先级
	中断的处理程序 ISR -> 中断的向量表
	
#3 中断相关寄存器 SFR
		如何跳转
---------------------------------------------------------------
		b irq_handler0					VectADDR -> PC
		LDR pc, =irq_handler0			VIC interface(A31-A0)
---------------------------------------------------------------			
		IC				IC				Vectored IC ->
		
		ARM7(4510)		ARM9(2440)		ARM11(6410)		A8(210)		
---------------------------------------------------------------
										CPSR I-bit
内核	CPSR I-bit		CPSR I-bit		VIC Port(Enable)
(A8)									VIC interface(PC)
---------------------------------------------------------------
						INTOFFSET		VectADDRESS(32bit)
						INTPRI			Vectors(handlers)
		INTMOD			INTMOD			Priority
中断	INTPND			INTPND			STATUS(PND) (IRQ/FIQ)
控制器	INTMSK			INTMSK			SELECT(MOD) IRQ/FIQ
(IC)					SRCPND			ENABLE(MSK)
										RAWINTR(SRC)
---------------------------------------------------------------
										INTMSK
										INTPND(clear)
		EINTCON			EINTCON			EINTCON
中断源	(F/R/L)			(F/R/L)			(F/R/L)		
控制器	GPXCON			GPXCON			GPXCON
(GPIO)	(EINT)			(EINT)			(EINT)		
---------------------------------------------------------------
硬件层 Key/UART/USB/Timer 

#4 S5PV210 中断相关寄存器
	中断源 GPIO Controller
		GPH2CON[0]   [3:0]   0000 = Input     
			0001 = Output 
			0010 = Reserved 
			0011 = KP_COL[0] 
			0011 ~ 1110 = Reserved 
		*	1111 = EXT_INT[16] 
		
		EXT_INT_2_CON[0]  [2:0]  Sets the signaling method of EXT_INT[16] 
			000 = Low level     
			001 = High level 
		*	010 = Falling edge triggered 
			011 = Rising edge triggered 
			100 = Both edge triggered 
			101 ~ 111 = Reserved 
				
		EXT_INT_2_MASK[0]  [0]  
		*	0 = Enables Interrupt     
			1 = Masked 
	
		EXT_INT_2_PEND[0]  [0]  (R)
			0 = Not occur     
			1 = Occur interrupt 

	向量中断控制器 Vectored Interrupt Controller
		VIC0RAWINTR  0xF200_0008 R  
			Specifies the Raw Interrupt Status Register 
			RawInterrupt  [31:0]  Shows the status of the FIQ interrupts before masking by the 
				VICINTENABLE and VICINTSELECT Registers: 
				0 = Interrupt is inactive before masking 
				1 = Interrupt is active before masking
				
		VIC0INTENABLE  0xF200_0010 R/W 
			Specifies the Interrupt Enable Register
			IntEnable  [31:0]  Enables the interrupt request lines
				Write: 
				0 = No effect 
				1 = Enables Interrupt. 
		
		VICINTENCLEAR 
			IntEnable Clear 	
				Write: 	
				0 = No effect 
				1 = Disables Interrupt in VICINTENABLE Register. 				
		
		VIC0IRQSTATUS  0xF200_0000 R  
			Specifies the IRQ Status Register 
			IRQStatus  [31:0]  Shows the status of the interrupts after masking by the 
				VICINTENABLE and VICINTSELECT Registers: 
				0 = Interrupt is inactive 
				1 = Interrupt is active. 
		
		VIC0INTSELECT  0xF200_000C R/W 
			Specifies the Interrupt Select Register 
			IntSelect  [31:0]  Selects interrupt type for interrupt request: 
				0 = IRQ interrupt 
				1 = FIQ interrupt 

		VIC0VECTADDR0 0xF200_0100 R/W 
			Specifies the Vector Address 0 Register		
			VICVECTADDR[0-31]  Bit  Description 
				VectorAddr 0-31  [31:0]  Contains ISR vector addresses. 
			
		VIC0VECTPRIORITY0  0xF200_0204 R/W 
			Specifies the Vector Priority 1 Register 
			VectPriority  [3:0]  Selects vectored interrupt priority level. You can select 
				any of the 16 vectored interrupt priority levels by 
				programming the register with the hexadecimal value of 
				the priority level required, from 0-15. 

		VIC0ADDRESS  0xF200_0F00 R/W 
			Specifies the Vector Address Register 
			VectAddr  [31:0]  
			Contains the address of the currently active ISR

	内核 
		CPSR I-bit
		VIC Enable (p15)

#实验验证结论：		
	第一阶段，观察 GPIO 控制器里面的 pending bit 设置情况
	
		VIC0(IRQ/FIQ)STATUS	标识中断是否通过(IRQ/FIQ)
		VIC0INTSELECT		选择IRQ还是FIQ
		VIC0INTENABLE		使能中断通过
		VIC0RAWINTR			通过 EXT_INT_2_MASK 之后的情况
		---------------------
		EXT_INT_2_MASK		中断 Mask bit	
		EXT_INT_2_PEND		中断 Pending bit
		EXT_INT_2_CON		下升沿触发 Falling Edge
		GPH2CON				管脚复用 EXT_INT[16]	
			
	第二阶段，如何清除 pending bit ？
		写1清除 pending bit
		写0无效
	
	第三阶段，观察中断控制器中的使能Enable和状态Status标识寄存器
		使能 Enable 寄存器在 RAW 和 STATUS 之间
		STATUS 寄存器的标识位无需软件清除，只要清除 PENDing 位，该状态位自动清 0
		SELECT 寄存器决定该中断是 IRQ 还是 FIQ，从而硬件会设置不同的 STATUS 寄存器
	
	第四阶段，如何打开 CPSR I-bit ?
		通过 汇编 MSR 	(SVC: 0xD3	1101->0101 0x53->CPSR)
		__asm
		{
			mov r0, #0x53
			msr	cpsr, r0
		}
	
	第五阶段，中断发生了之后怎么办？
		接下来有2种处理办法：
		A) 简单的办法就是使用 VIC 向量中断控制器的功能
			1. 跳转的地址向量要提前设置好
			2. 通知 ARM11 内核，启用 VIC Port 功能
			紧接着的问题是，如何在执行完 beep 之后返回主程序？
				原因： beep 程序不能作为 IRQ_handler
				真正的 IRQ_handler 应该要完成
				1) 保存cpu 现场 STMFD
				2) 清除掉 Pending bit，调用 beep					
				3) 恢复cpu 现场 LDMFD (lr-4)->PC 	SPSR->CPSR
			修改 start.s ，实现 IRQ_handler
				1) IRQ 模式下的 sp 指针需要初始化
				2) 除了清除pending bit 之外，还需要清除 VIC0ADDRESS = 0;
			
		B) 复杂的办法就是不用 VIC ，自己实现全过程
			1. 当 IRQ 异常发生的时候，cpu 跳转到 0x18
			2. 背景知识：reset 0 地址被映射 map 到 iROM
				0 地址 在 iROM 中 (0xD0000000)
					iRAM (0xD0020000) -> 0x20000
				0x18: 0xEA000018
				最终在 iROM 中的程序(不可修改)会加载
				0xD0037400 地址开始的值，作为异常发生后要跳转的地址+offset	
			3. (int)IRQ_handler -> 0xD0037400 + 0x18
				如果是 SWI 软件中断，则在 0xD0037408 处填写swi_handler的地址	

day10:
定时器 Timer
============
#1 工作原理
功能：计时，中断，PWM Timer (驱动PWM信号的设备)
原理：类似于以前的 "沙漏"
	沙漏的计时原理：沙子量，漏沙的速度，到时的反转(连续)
Timer:	
	沙子量： Counter的初值
	漏沙速度：counter-- (自动完成，并且依据Clock=PCLK=66Mhz)
	反转：reload 操作 (InitValue -> Counter)
	装沙子：Manual update
	
真正的硬件设计是怎样的？
	TCNTBn - 用来装沙子的量筒，可以修改
	TCNTn - 真正用来做 counter--, 不可修改，不可见
	TCNTOn - 可以用来观察 TCNTn 的值的变化
		
#2 寄存器
	Register  Address 
	TCFG0 	0xE250_0000 	65
		PCLK = 66M 	66000000 -> 分频
		Timer Input Clock Frequency = PCLK / ( {prescaler value + 1} ) / {divider value} 
			{prescaler value} = 1~255  
			{divider value} = 1, 2, 4, 8, 16, TCLK 
		66M/66(65+1)	= 1M = 1000000
		
	TCFG1  	0xE250_0004 	0100=0x4
		1M/16 = 62500
		
	TCON  	0xE250_0008 
		*[3] Timer 0 Auto Reload on/off  
				0 = One-Shot  
				1 = Interval Mode(Auto-Reload) 
		[2]	Timer 0 Output Inverter on/off    
				0 = Inverter Off  
				1 = TOUT_0 Inverter-On 
		*[1]	Timer 0 Manual Update    
				0 = No Operation    
				1 = Update TCNTB0,TCMPB0 
		*[0] Timer 0 Start/Stop  
				0 = Stop     
				1 = Start Timer 0 
		
	TCNTB0  0xE250_000C 
		val = 62500 (=1s)
		
	TCMPB0  0xE250_0010 
		
	TCNTO0  0xE250_0014 
		read value -> TCNT0's value

	TINT_CSTAT, R/W, Address = 0xE250_0044)
		Interrupt Control and Status Register 
		Timer 0 Interrupt Status  
			[5]  Timer 0 Interrupt Status Bit. 
			Clears by writing ‘1’ on this bit. 	
	
		Timer 0 interrupt Enable  
			[0]   Enables Timer 0 Interrupt. 
				1 = Enables                  
				0 = Disabled 
	
#3 编程实现
	// init Timer
	// step 0: setup clock TCFG0+TCFG1
	// step 1: TCNTBn <- init value
	// setp 2: Set the manual update bit 
	// 		and clear only manual update bit
	//		enable auto-reload bit
	// step 3: Set the start bit 
	// step 4: Enable interrupt
	
	while (1)
	{
		// polling TCNTO0, putint_hex()
		
		// polling TINT_CSTAT bit[5] == 1 ?
			beep();	
	}
	
	// init VIC 
	Timer0 SRC = bit[21] belong to VIC0
	
	Timer0 中断传递相关寄存器
	VIC0(IRQ/FIQ)STATUS	标识中断是否通过(IRQ/FIQ)
	VIC0INTSELECT		选择IRQ还是FIQ: bit21
	VIC0INTENABLE		使能中断通过: bit21
	VIC0RAWINTR			通过Timer0之后的情况 bit21
	---------------------
	TINT_CSTAT			中断(MSK) Enable bit [0]
	TINT_CSTAT			中断(PND) Status bit [5]
	TCNTB0				触发方式 1 sec interrupt
		(TCFG0 + TCFG1) clock init
	-GPD0CON			管脚复用 TOUT0 
		

		
1. 请定义一个函数指针 fp，并指向 add 函数 int add(int, int);

2. 请写出 printf 函数实现中，所需要用到的3个以 va_ 开始的宏定义。

3. 请写出串口的 DB9 接头中，哪几个引脚表示 TxD, RxD, GND。 

4. 请写出 read 和 write 系统调用的函数原型。

5. 请写出 NandFlash K9F2G08 芯片内部的存储结构 (提示 device/block/page)。

6. 请解释什么是 Memory Map？ 可以 S5PV210 芯片为例。

7. 请解释什么是软链接和硬链接？ 请举例创建出 a.txt 的软链接和硬链接。

8. 请写出 ARM 处理器内核的 7 种工作模式，并写出加电启动后的工作模式。

9. 请写出 linux 上编程 helloworld，需要 #include 哪个头文件？ 它存放在什么目录下？

10. 请解释用 static 修饰函数，有什么作用？

11. 请解释 makefile 中对变量定义时， =  :=  +=  ?=  有什么区别？

12. 请解释什么是 GPL ？

13. 请解释什么叫做上拉电阻？ 并画图说明。

14. 请写出中断处理的流程，包括硬件上和软件上分别要做哪些工作。

15. 请写出在ARM处理器中，进行压栈和出栈的两条指令。

16. 请解释什么叫做队列？ 并写出对队列进行操作的两个函数接口名称。

17. 请解释什么叫做 Framebuffer? 并结合 LCD 驱动进行举例说明。

18. 请写出串口控制器的内部组成，并画图示意之。

19. 请定义一个链表的节点 node，并写出创建节点的函数实现 make_node	

20. 请写出你在驱动课程阶段的学习目标。
