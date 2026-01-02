#define _CRT_SECURE_NO_WARNINGS
// 可以将<stdio.h>头文件封装进<game.h>
#include "game.h"
// 包含game.h头文件



void game()
{
	// 使用3 * 3的二维数组存放下棋位置
	// 功能包含：
	// 玩家下棋，
	// 电脑下棋逻辑，
	// 输赢判断

	char board[ROW][COL] = { 0 };
	// 定义数组时可以使用宏定义来操作
	// 游戏开始前需先初始化棋盘为“ ”
	// 写一个初始化棋盘函数
	InitBoard(board, ROW, COL);
	// 写一个打印棋盘的函数
	DisplayBoard(board, ROW, COL);
	// 开始下棋
	char ret = 0;
	// 使用ret接受IsWin函数
	while (1)// 死循环
	{
		PlayerMove(board, ROW, COL);
		// 判断输赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
			// 如果返回结果不等于C，跳出循环
		}
		DisplayBoard(board, ROW, COL);
		

		ComputerMove(board, ROW, COL);
		// 判断输赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
			// 如果返回结果不等于C，跳出循环
		}
		DisplayBoard(board, ROW, COL);	
	}
	if (ret == '*')
	{
		printf("玩家获胜\n");
		DisplayBoard(board, ROW, COL);
	}
	else if (ret == '#')
	{
		printf("电脑获胜\n");
		DisplayBoard(board, ROW, COL);
	}
	else
	{
		printf("平局\n");
		DisplayBoard(board, ROW, COL);
	}
}


void menu()
{
	printf("********************************\n");
	printf("******   1.play   0.exit   *****\n");
	printf("********************************\n");

}

int main()
{
	srand((unsigned int)time(NULL));
	// srand需要在mian中配置来生成起点
	int input = 0;
	do
	{
		menu();// 打印菜单
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case 1 :
		{
			printf("三子棋\n");
			game();// 使用game函数封装
			break;
		}
		case 0 :
		{
			printf("退出游戏\n");
			break;
		}
		default:
		{
			printf("选择错误，请重新选择!\n");
			continue;
		}
		}
	} while (input);
	// 使用do...while;打印一个至少执行一次的菜单
}