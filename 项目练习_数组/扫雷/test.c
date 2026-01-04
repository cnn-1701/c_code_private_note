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
	Putboom();
	
}

int main()
{
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
	} while (input);
	// 使用do...while来构建主函数
	return 0;
}

