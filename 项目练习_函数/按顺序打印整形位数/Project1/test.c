#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//接受一个整型值(无符号),按照顺序打印它的每一位。
//例如:
//输入:1234,输出 1234.

//int main()
//{
//	unsigned int num = 0;// 定义一个无符号整形 
//	scanf("%u", &num);
//	while (num)
//	{
//		printf("%d ", num % 10);
//		num = num / 10;
//	}
//
//	return 0;
//}

void print(unsigned int num)
{
	// 现在需要从第一位打印
	// print(123)4
	// print(12)3 4
	// print(1)2 3 4
	// print1 2 3 4 开始回归

	if (num > 9)
	{
		print(num / 10);// 打印123(传递过程 / 递推过程)
	}
	printf("%d",num % 10);// 打印4(回归起点)
	
}

int main()
{
	unsigned int num = 0;
	scanf("%u ", &num);
	print(num);
	return 0;
}