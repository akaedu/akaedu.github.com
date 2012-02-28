/** 
* @file 3.c
* @brief
* 输入字符串，同时输入帧头和帧尾（可多个字符），将该字符串中合法的帧识别出来。
* 示例：帧头：1a2b 帧尾：3c4d
* 输入字串：001a2bssddef3c4d4asf1a2bddaaee343c4d1a2bttt1a2bddd 3c4d3c4d
* @author GaoJinlong
* @version 0.1
* @date 2011-09-09
*/
#include <stdio.h>
#include <string.h>

int find_str(char *base, char *head, char *tail, char *str[])
{
	int i = 0;
	char *tmp;

	while(*base)
	{
		if(tmp = strstr(base, head))
			str[i++] = tmp + strlen(head);
		else
			return i;

		if(tmp = strstr(base, tail))
		{
			base = tmp + strlen(tail);
			*tmp = '\0';
		}
		else
			return i - 2;
	}

	return i;
}

int main(int argc, const char *argv[])
{
	int num, i;
	char base[200] = "001a2bssddef3c4d4asf1a2bddaaee343c4d1a2bttt1a2bddd3c4d3c4d";
	char *head = "1a2b";
	char *tail = "3c4d";
	char *str[10];

	num = find_str(base, head, tail, str);
	for(i = 0; i < num; i++)
		puts(str[i]);

	return 0;
}
