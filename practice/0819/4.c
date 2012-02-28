/** 
* @file 4.c
* @brief 将下列二位数组转置；(提示：行变列，列变行)
* @author GuoPengyu
* @version 0.1
* @date 2011-09-09
*/
#include <stdio.h>

int main(int argc, const char *argv[])
{
	int num[5][5] = {{1, 6, 2, 3, 7},
			 {2, 7, 3, 2, 2},
			 {3, 2, 5, 2, 6},
			 {3, 2, 6, 4, 2},
			 {4, 3, 7, 4, 8}};
	int i, j, tmp;
	for(i = 0; i < 4; i++){
		for(j = i + 1; j < 5; j++)
		{
			tmp = num[i][j];
			num[i][j] = num[j][i];
			num[j][i] = tmp;
		}
	}

	for(i = 0; i < 5; i++)
	{
		for(j = 0; j < 5; j++)
			printf("%2d ", num[i][j]);

		printf("\n");
	}

	return 0;
}
