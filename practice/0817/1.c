/** 
* @file 1.c
* @brief convert upper to lower
* @author GuoPengyu
* @version 0.1
* @date 2011-09-09
*/

#include <stdio.h>
#include <string.h>

/** 
* @brief upper to lower
* 
* @param a upper
* 
* @return result
*/
char A_to_a(char a)
{
	if (a >= 'A' && a <= 'Z') 
		return a + 32;
	else  
		return a;
}

int main(int argc, const char *argv[])
{
	printf("%c\n", A_to_a('D'));

	return 0;
}
