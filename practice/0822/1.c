/** 
* @file 1.c
* @brief 有两个字符串（有效字符不超过9个）str1，str2，将str1，str2的对应字符按从小到大的顺序存放在一个数组的对应位置上，
* 如：str1 = “hello”；str2 = “akaedu”；
* 完成组合后，新的字符串为：“ahekaedllou”；
* @author GuoPengyu
* @version 0.1
* @date 2011-09-09
*/
#include <stdio.h>

int main(int argc, char *argv[])
{
	char str1[] = "hello";
	char str2[] = "akaedu";
	char str[32] = {0};
	int i=0, j=0, k=0;

	while(str1[i] && str2[j])
	{
		if(str1[i] < str2[j])
			str[k++] = str1[i++];
		else
			str[k++] = str2[j++];
	}

	while(str1[i])
		str[k++] = str1[i++];
	while(str2[j])
		str[k++] = str2[j++];

	str[k] = '\0';
	
	printf("str1 = %s\nstr2 = %s\nafter...\nstr = %s\n", str1, str2, str);

	return 0;
}
