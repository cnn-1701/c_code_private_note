#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int add(int num)
{
	// 功能拆分：最低位数字加上去除这位数字的传入数
	// 当传入数小于等于9时返回

	if (num > 9)
	{
		return ((num % 10) + add(num / 10));
	}
	else
		return num;
}

int main()
{
	int num = 0;
	scanf("%d", &num);
	int sum = add(num);
	printf("%d",sum);
	return 0;


}