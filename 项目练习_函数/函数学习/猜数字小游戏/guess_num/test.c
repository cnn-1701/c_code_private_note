#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <time.h>
#include <stdlib.h>

void menu()
{
	printf("******************\n");
	printf("***   1.play   ***\n");
	printf("***   2.exit   ***\n");
	printf("******************\n");
}

void game()
{	
	int guess = 0;
	int ret = rand() % 100 +1;
	//限定范围为1-100
	//此为随机数生成模块

	printf("请猜数字:>\n");
	
	while (1)
	//重复循环写法
	//while（1），到内部break打破循环
	{
		scanf("%d", &guess);
		if (guess < ret)
			printf("猜小了");
		else if (guess > ret)
			printf("猜大了");
		else
		{
			printf("恭喜你猜对了");
			break;
		}
	}
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	//基于时间戳的伪随机生成
	//时间戳只在主函数开始时定义一次
	//time传参类型为空指针
	//time函数使用前需要预处理头文件<time.h><stdlib.h>
	//time函数返回值为int类型
	//time函数使用前需要使用srand类型设置
	//srand 传参类型需要为无符号整形，因此需要进行强制类型转换
	//随机数种子
	//time函数参数为指针类型，不需要传参时键入NULL即可

	do
	{
		menu();
		printf("请选择:>");

		scanf("%d", &input);
		switch (input)
		{
		case 1://猜数字
			game();//猜数字函数
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input);

	return 0;

}