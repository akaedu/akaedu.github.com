/** 
* @file 3.c
* @brief 找出形参s所指字符串中出现频率最高的字母，不区分大小写，并统计其出现的次数，例如，形参s所指的字符串为:abcAbsmaxless，程序执行后的输出结果为：letter * ‘a’:3 times letter ‘s’ 3 times
* @author GaoJinlong
* @version 0.1
* @date 2011-09-09
*/
#include <stdio.h>

int main(int argc, const char *argv[])
{
	char str[100];
	char *p = str;
	char letter[26] = {0};
	char c;
	int i;
	int pos = 0, max = 0;

	printf("please enter a string: ");
	scanf("%s", str);

	while(*p)
	{
		c = toupper(*p);
		letter[c - 65]++;
		p++;
	}

	for (i = 0; i < 26; i++)
	{
		if(letter[i] > max)
		{
			pos = i;
			max = letter[i];
		}
	}

	for(i = 0; i < 26; i++)
	{
		if(max == letter[i])
			printf("%c appears %d times!\n", i + 65, max);
	}

	return 0;
}
