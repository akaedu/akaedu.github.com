/** 
* @file five-chess.c
* @brief five-chess
* @author liming
* @version 0.1
* @date 2011-09-09
*/
#include <stdio.h>
#define COL 8
#define ROW 8

#define N 5

int chessboard[ROW][COL];

/** 
* @brief print the chessboard with printf
*/
void print_chessboard(void)
{
	int i, j;

	printf("\n");
	printf("  ");
	for (j = 0; j < COL; j++)
		printf(" %d", j);
	printf("\n");

	printf(" -");
	for (j = 0; j < COL; j++)
		printf(" -");
	printf("\n");

	for (i = 0; i < ROW; i++) {
		printf("%d| ", i);
		for (j = 0; j < COL; j++) {
			printf("%d ", chessboard[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

/** 
* @brief check whether the position is occupied
* 
* @param x column
* @param y row
* 
* @return 1 for empty, 0 for occupied
*/
int is_empty(int x, int y)
{
        return !chessboard[x][y];
}

/** 
* @brief test whether the position is available
* 
* @param x column
* @param y row
* 
* @return 1 for yes, 0 for no
*/
int test(int x, int y)
{
        if(x >= COL || x < 0)
                return 0;
        if(y >= ROW || y < 0)
                return 0;
        if(is_empty(x, y))
                return 1;
        return 0;
}

/** 
* @brief Put a chess to a position
* 
* @param x column
* @param y row
* @param who player
* 
* @return 1 for success, 0 for fail
*/
int put_chess(int x, int y, int who)
{
        if(test(x, y))
        {
                chessboard[x][y] = who;
                return 1;
        }
        else
                return 0;
}

/** 
* @brief Check whether game is over
* 
* @param x start column
* @param y start row
* 
* @return  1 for yes, 0 for no
*/
int check(int x, int y)
{
        int i, j;
        int counter = 1;
        int who;
        int nx, ny;

        int dirx[4] = {0, 1, 1, 1};
        int diry[4] = {1, 0, 1, -1};
        who = chessboard[x][y];
        if(who == 0)
                return 0;
        for (i = 0; i < 4; i++) 
        {
                nx = x;
                ny = y;
                counter = 1;
                for (j = 0; j < N; j++) 
                {
                        nx += dirx[i];
                        ny += diry[i];
                        if(chessboard[nx][ny] == who)
                                counter++;
                        else
                                break;
                }
                if(counter == N)
                {
                        printf("check OK!  %d %d -> dir(%d)", x, y, i);
                        return 1;
                }
        }
        return 0;
}

/** 
* @brief travel all the position
* 
* @return 
*/
int find(void)
{
        int i, j;
        for(i = 0; i < ROW; i++)
        {
                for(j = 0; j < COL; j++)
                {
                        if(check(i, j))
                                return 1;
                }
        }
        return 0;
}


int main(int argc, const char *argv[])
{
        int x, y, step = 0, who;
        printf("Welcome to five-chess, Let's go!\n");
        print_chessboard();
        while(1)
        {
                who = step % 2 + 1;
                printf("you can input 4 4 to put a chess on board\n");
                printf("player %d: ", who);
                scanf("%d %d", &x, &y);
                if(put_chess(x, y, who))
                {
                        step++;
                        print_chessboard();
                        if(find())
                        {
                                printf("Congratulations! Player %d win!\n", who);
                                return 0;
                        }
                }
                else
                        printf("[%d %d] is occupied\n", x, y);
        }
        return 0;
}
