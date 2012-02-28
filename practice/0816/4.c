/** 
* @file 4.c
* @brief Display a virtual clock in terminal
* @author Gaojinlong
* @version 0.1
* @date 2011-09-09
*/
#include <stdio.h>

/** 
* @brief
* 在一个死循环中令second一直自加，然后进行判断，当second加到60后，将其清零，minute进行自加，minute加到60后，将其清零，hour自加，hour加到24后，将其清零。
* 在输出时，定义好格式‘b’为退格，%02d意为输出整数，不足两位以0补齐。
* fflush(stdout)为清楚缓冲区，由于printf函数以行为缓冲，当不想输出换行符时可这样输出。
* @return 
*/
int main(int argc, const char *argv[])
{
        int hour = 23, minute = 59, second = 50;

        while(1)
        {
		second++;
		if (second == 60) 
		{
			second = 0;
			minute++;
			if (minute == 60) 
			{
				minute = 0;
				hour++;
				if (hour == 24) 
					hour = 0;
			}
		}
		printf("\b\b\b\b\b\b\b\b%02d:%02d:%02d", hour, minute, second);
		fflush(stdout);
		sleep(1);
        }

        return 0;
}
