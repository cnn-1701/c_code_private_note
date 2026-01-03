#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int Exponent(int n, int k)
{
	// 实现逻辑 N ^ k = N * N ^ (k - 1)
	if (k > 1)
	{
		return (n * Exponent(n, k - 1));
	}
	else
		return n;
}

int main()
{
	int n = 0;
	int k = 0;

	printf("请按照格式n k输入一对指数\n");
	scanf("%d %d", &n, &k);

	int ret = Exponent(n, k);

	printf("%d", ret);
}