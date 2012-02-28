---
layout: post
title: chess code
---
###code

	#include <stdio.h>
	
	#define COL 8
	#define ROW 8
	
	int chess_board[COL][ROW];
	
	void print_board()
	{
		int i, j;
		printf("  ");
		for(i = 0; i < ROW; i++)
		{
			printf(" %d", i);
		}
		printf("\n");
		for(i = 0; i < ROW + 1; i++)
		{
			printf(" -");
		}
		printf("\n");
		for(i = 0; i < ROW; i++)
		{
			printf("%d|", i);
			for(j = 0; j < COL; j++)
			{
				printf(" %d", chess_board[i][j]);
			}
			printf("\n");
		}
	}
	
	int is_empty(int x, int y)
	{
		if(chess_board[x][y] == 0)
			return 0;
		
		return 1;
	}
	
	int in_board(int x, int y)
	{
		if(x>=0 && x<ROW && y>=0 && y<ROW)
			return 0;
		return 1;
	}
	
	int put_chess(int x, int y, int who)
	{
		chess_board[x][y] = who;
	}
	
	int check_one(int x, int y)
	{
		int dx[4] = {0, 1, 1, -1};
		int dy[4] = {1, 0, 1, 1};
		int i, j;
		int nx, ny;
		int who = chess_board[x][y];
		int cnt;
		if(who == 0)
			return 0;
	
		for(i = 0; i < 4; i++)
		{
			nx = x;
			ny = y;
			cnt = 1;
			for(j = 0; j < 4; j++)
			{
				nx += dx[i];
				ny += dy[i];
				if(chess_board[nx][ny] == who)
				{
					cnt++;
				}
				else
					break;
			}
			if(cnt == 5)
			{
				print_board();
				printf("%d win!\n", who);
				return 1;
			}
		}
	
		return 0;
	}
	
	int travel()
	{
		int i, j;
		for(i = 0; i < ROW; i++)
		{
			for(j = 0; j < COL; j++)
			{
				if(check_one(i, j) == 1)
					return 1;
			}
		}
	
		return 0;
	}
	
	int main(int argc, const char *argv[])
	{
		int x, y;
		int who = 0;
		int step = 0;
		while(1)
		{
			print_board();
			who = step%2 + 1;
			scanf("%d%d", &x, &y);
			if(in_board(x, y) == 0 && is_empty(x, y) == 0)
			{
				put_chess(x, y, who);
				step++;
			}
			else
			{
				printf("Place invalid!\n");
				continue;
			}
			if(travel())
				return 0;
		}
		return 0;
	}
	
	
	static u32_t cursor_pixel[C_H][C_W]=
	{
		{BORD,T___,T___,T___,T___,T___,T___,T___,T___,T___},
		{BORD,BORD,T___,T___,T___,T___,T___,T___,T___,T___},
		{BORD,X___,BORD,T___,T___,T___,T___,T___,T___,T___},
		{BORD,X___,X___,BORD,T___,T___,T___,T___,T___,T___},
		{BORD,X___,X___,X___,BORD,T___,T___,T___,T___,T___},	
		{BORD,X___,X___,X___,X___,BORD,T___,T___,T___,T___},
		{BORD,X___,X___,X___,X___,X___,BORD,T___,T___,T___},
		{BORD,X___,X___,X___,X___,X___,X___,BORD,T___,T___},
		{BORD,X___,X___,X___,X___,X___,X___,X___,BORD,T___},
		{BORD,X___,X___,X___,X___,X___,X___,X___,X___,BORD},
		{BORD,X___,X___,X___,X___,X___,BORD,BORD,BORD,BORD},
		{BORD,X___,X___,BORD,X___,X___,BORD,T___,T___,T___},
		{BORD,X___,BORD,T___,BORD,X___,X___,BORD,T___,T___},
		{BORD,BORD,T___,T___,BORD,X___,X___,BORD,T___,T___},
		{T___,T___,T___,T___,T___,BORD,X___,X___,BORD,T___},
		{T___,T___,T___,T___,T___,BORD,X___,X___,BORD,T___},
		{T___,T___,T___,T___,T___,T___,BORD,BORD,T___,T___}
	};
