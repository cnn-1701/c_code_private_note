#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
// 递归法求法
//int count = 0;
//int fei(int num)
//{
//	if (num == 3)
//		count++;
//	if (num == 1 || num == 2)
//		return 1;
//	else
//		return fei(num - 1) + fei(num - 2);
//}
//
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	printf("%d , %d", fei(num),count);
//	return 0;
//}

// 迭代法求值
int fib(int num)
{
	if (num <= 2)
	{
		return 1;
	}
	int a = 1;// a为n-2
	int b = 1;// b为n-1
	int c = a + b;
	for (int i = 3; i < num; i++)
	{
		a = b;
		b = c;
		c = a + b;
	}
	return c;
}
int main()
{
	int num = 0;
	scanf("%d", &num);
	printf("%d", fib(num));
	return 0;
}