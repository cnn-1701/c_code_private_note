#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
//编写一个判断 m 是否为质数的函数，验证歌德巴赫猜想：任何大于 2 的偶数
// 均可表示为两个质数之和。例如：4 = 2 + 2，6 = 3 + 3，8 = 3 + 5, …。
int IsZi(int x)
{
	if (x == 2 || x == 1)
	{
		return 1;
	}
	for (int j = 3; j <= sqrt(x); j++)
	{
		if (x % j == 0)
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	int num = 0;
	scanf("%d", &num);
	int ret = 0;
	for (int i = 1; i <= num; i++)
	{
		if (IsZi(i) && IsZi(num - i))
		{
			ret = i;
			printf("%d + %d = %d\n", ret, (num - ret), num);
			return 0;
		}
	}
	printf("该结论不成立\n");
	return 0;
}