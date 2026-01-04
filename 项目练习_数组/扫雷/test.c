#include"game.h"

void menu()
{
	printf("******************************\n");
	printf("*********  1. game  **********\n");
	printf("*********  0. exit  **********\n");
	printf("******************************\n");
	printf("请输入：>");
}



void game()
{
	char mine[ROWS][COLS] = { 0 }; 
	// mine数组用于存放布置好的雷的信息
	char show[ROWS][COLS] = { 0 };
	// show 数组用于存放排查出雷的信息

	// 初始化数组为指定内容
	// mine数组在无雷时都为`0`
	// show数组在未排差时都为*，表示神秘

	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');

	int num = 0;
	printf("请输入埋雷个数: >");
	
	scanf("%d", &num);
	printf("\n");

	SetMine(mine, ROWS, COLS, num);

	DisplayBoard(show, ROWS, COLS);
	
	PrivesBoard(show, mine, ROWS, COLS);




}

int main()
{
	srand((unsigned)time(NULL));
	int input = 0;
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
		{
			printf("开始游戏\n");
			game();
			break;
		}
		case 0:
		{
			break;
		}
		default:
		{
			printf("输入错误，请重新输入：\n");
			break;
		}
		}
		// switch语句中的break只能跳出switch而不是循环
	} while (input);
	// 使用do...while来构建主函数
	return 0;
}

