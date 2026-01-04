#include"game.h"


void InitBoard(char arr[ROWS][COLS], int rows, int cols, char set)
{
	// 设计二维数组函数时可以像这样在头文件对数组大小进行宏定义
	// 再传入行列大小的形参

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = set;
		}
	}
}

void DisplayBoard(char arr[ROWS][COLS], int rows, int cols)
{
	printf("   |");
	for (int j = 1; j < cols -1; j++)
	{	
		if (j < cols - 2)
		{
			printf(" %d |", j);
		}
		else
			printf(" %d \n", j);
	}
	for (int j = 1; j < cols - 1; j++)
	{
		printf("---|");
	}
	printf("---\n");
	// 第一行的输入
	for (int i = 1; i < rows - 1; i++)
	{
		printf(" %d |", i);
		int j = 0;
		for (j = 1; j < cols - 2; j++)
		{
			printf(" %c |", arr[i][j]);
		}
		printf(" %c \n", arr[i][j]);

		if (i < rows - 2)
		{
			for (int j = 1; j < cols - 1; j++)
			{
				printf("---|");
			}
			printf("---\n");
		}
	}
	return;
}

void SetMine(char arr[ROWS][COLS], int row, int col, int num)
{
	for (int i = 0; i < num; i++)
	{	
		int rows = rand() % 9 + 1;
		int cols = rand() % 9 + 1;
		if (arr[rows][cols] == '0')
		{
			arr[rows][cols] = '1';
		}
		else
			i--;
	}
	return;

}

void PrivesBoard(char show[ROWS][COLS], char mine[ROWS][COLS], int row, int col)
{
	int rows = rand() % 9 + 1;
	int cols = rand() % 9 + 1;

	if (mine[rows][cols] == '0')
	{
		show[rows][cols] == ' ';
	}
}



