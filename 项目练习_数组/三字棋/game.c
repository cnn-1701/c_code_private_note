#define _CRT_SECURE_NO_WARNINGS

#include "game.h"
// 包含头文件使能够使用宏定义ROW与COL

// 棋盘初始化函数
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			board[i][j] = ' ';
		}
	}
}// 使用双重for循环来打印数组

void DisplayBoard(char board[ROW][COL], int row, int col)
{
	// 如何打印棋盘？
	// ‘ ’+ 数组元素 + ‘ ’
	// 将每行视为一组
	int i = 0;
	for (i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
			else
			{
				printf("\n");
			}
		}
		// 打印数据
		if (i < col - 1)
		{
			for (int j = 0; j < col; j++)
			{
				printf("---", board[i][j]);
				if (j < col - 1)
				{
					printf("|");
				}
				else
				{
					printf("\n");
				}
			}
		}
		// 打印分割行
	}
}

void PlayerMove(char board[ROW][COL], int row, int col)
{			
	while(1)
	{
		int x = 0;
		int y = 0;
		printf("玩家下棋\n");

		printf("请输入坐标：>\n");
		scanf("%d %d", &x, &y);

		// 判断x与y是否合理？
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] = ' ')
			{
				board[x - 1][y - 1] = '*';
				// 玩家下棋放‘*’占用
				return;
			}
			else
			{
				printf("坐标被占用，请选择其他位置\n");
			}
		}
		else
		{
			printf("输入不合法，请重新输入\n");
		}
	}

}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	// 找没下棋的坐标随机下棋
	printf("电脑下棋：\n");
	int x = 0;
	int y = 0;

	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		// 生成rand()范围为0~row/col
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

char IsWin(char board[ROW][COL], int row, int col)
{
	// 先判断行
	for (int i = 0; i < row; i++)
	{
		// 判断每一行
		for (int j = 0; j < col - 2; j++)
		{
			if (board[i][j] != ' ')
			{
				if ((board[i][j] == board[i][j + 1]) && (board[i][j] == board[i][j + 2]))
				{
					if (board[i][j] == '*')
					{
						return '*';
					}
					else
					{
						return '#';
					}
				}
			}
		}
	}

	for (int i = 0; i < row - 2; i++)
	{
		// 判断每一列
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] != ' ')
			{
				if ((board[i][j] == board[i + 1][j]) && (board[i][j] == board[i + 2][j]))
				{
					if (board[i][j] == '*')
					{
						return '*';
					}
					else
					{
						return '#';
					}
				}
			}
		}
	}
	// 正对角线判断
	// i为行数
	// j为列数
	for (int i = 0; i <= row - 3; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] != ' ')
			{
				if ((board[i][j] == board[i + 1][j + 1]) && (board[i][j] == board[i + 2][j + 2]))
				{
					if (board[i][j] == '*')
					{
						return '*';
					}
					if (board[i][j] == '#')
					{
						return '#';
					}
				}
			}
		}
	}
	for (int i = 2; i <= row; i++)
	{
		for (int j = 0; j < col - 2; j++)
		{
			if (board[i][j] != ' ')
			{
				if ((board[i][j] == board[i + 1][j - 1]) && (board[i][j] == board[i + 2][j - 2]))
				{
					if (board[i][j] == '*')
					{
						return '*';
					}
					if (board[i][j] == '#')
					{
						return '#';
					}

				}
			}
		}
	}
	return 'C';
}
