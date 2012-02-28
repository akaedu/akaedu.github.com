/** 
* @file 1.c
* @brief 给定某年某月某日，将其转换为这一年的第几天并输出
* @author Gaojinlong
* @version 0.1
* @date 2011-09-09
*/
#include <stdio.h>

int day_per_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/** 
* @brief judge whether the year is a leap year
* 
* @param year the year
* 
* @return 1 for yes, 0 for no
*/
int is_leap(int year)
{
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) 
		return 1;
	else
		return 0;
}

/** 
* @brief Calc the totol day of 1-x month
* 
* @param month the last month
* 
* @return the total days
*/
int total_month(int month)
{
	int i, count = 0;

	for (i = 0; i < month; i++) 
		count += day_per_month[i];

	return count;
}

/** 
* @brief Calc the total days
* 
* @param year year
* @param month month
* @param day day
* 
* @return total days
*/
int calc(int year, int month, int day)
{
	int count = 0;

	count = total_month(month) + day;
	if (is_leap(year) && month > 2) //如果是闰年并且月份大于2，就在总数上加一天。
		count++;

	return count;
}

int main(int argc, const char *argv[])
{
	int year, month, day;

	printf("Please enter date like this xxxx:xx:xx: ");
	scanf("%4d:%2d:%2d", &year, &month, &day);
	printf("Total %d days\n", calc(year, month, day));

	return 0;
}
