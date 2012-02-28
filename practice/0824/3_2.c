/** 
* @file 3_2.c
* @brief
* 输入字符串，同时输入帧头和帧尾（可多个字符），将该字符串中合法的帧识别出来。
* 示例：帧头：1a2b 帧尾：3c4d
* 输入字串：001a2bssddef3c4d4asf1a2bddaaee343c4d1a2bttt1a2bddd 3c4d3c4d
* @author GuoPengyu
* @version 0.1
* @date 2011-09-09
*/
#include <stdio.h>
#include <string.h>

#define LEN 128

int main(void)
{
	char *str1 = "1a2b";
	char *str2 = "3c4d";
	char str[LEN];
	char *start, *end, *p;

	fgets(str, LEN, stdin);
	start = end = str;

	do
	{
		start = strstr(start, str1);
		end = strstr(end, str2);

		if (!start || !end)
			break;
		if (end < start)
		{
			end = start + 1;
			continue;
		}
		for(p = start + 4; p < end; p++)
			printf("%c", *p);
		printf("\n");

		start = end = end + 1;
	} while(start < str + strlen(str));

	return 0;
}
