/** 
* @file 2.c
* @brief 从键盘接收一个字符串，然后按照字符顺序从小到大进行排序并删除重复字符；
* 如从键盘输入的内容为”agehiagehp”,执行完程序之后变成:”aeghip”
* @author GuoPengyu
* @version 0.1
* @date 2011-09-09
*/
#include <stdio.h>
#include <string.h>

#define N 32

void sort(char *str)
{
	int i, j, pos, len;
	char tmp;

	len = strlen(str);
	for(i = 0; i < len - 1; i++)
	{
		pos = i;
		for(j = i+1; j < len; j++)
		{
			if(str[pos] > str[j])
				pos = j;
		}
		if(pos != i)
		{
			tmp = str[i];
			str[i] = str[pos];
			str[pos] = tmp;
		}

	}
}

void del(char *str)
{
	int i, j, k;

	for(i=1, k=1; str[i] != '\0'; i++)
	{
		for(j = k-1; j >= 0; j--)
		{
			if(str[i] == str[j])
				break;
		}
		if(j < 0)
			str[k++] = str[i];
	}
	str[k] = '\0';
}

int main(int argc, char *argv[])
{
	char str[N] = "jsajglksdfl";

	printf("str = %s\n", str);
	sort(str);
	printf("after sort\nstr = %s\n", str);
	del(str);
	printf("after del\nstr = %s\n", str);

	return 0;
}
