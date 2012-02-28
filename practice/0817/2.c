/** 
* @file 2.c
* @brief simple calculator
* @author GuoPengyu
* @version 0.1
* @date 2011-09-09
*/

#include <stdio.h>

/** 
* @brief simple calculator with switch
* 
* @param x integer
* @param y integer
* @param symbol like '+' '-' '*' '/'
* 
* @return result
*/
int calc(int x, int y, char symbol)
{
	switch(symbol)
	{
		case '+' : return x + y; break;
		case '-' : return x - y; break;
		case '*' : return x * y; break;
		case '/' : return x / y; break;
		case '%' : return x % y; break;
		default : printf("symbol error!\n"); return -1; break;
	}
}

int main(int argc, const char *argv[])
{
	int x, y;
	char symbol;
	printf("Please input like this 3 + 4: ");
	scanf("%d %c %d", &x, &symbol, &y);
	printf("%d %c %d = %d\n", x, symbol, y, calc(x, y, symbol));
	return 0;
}
