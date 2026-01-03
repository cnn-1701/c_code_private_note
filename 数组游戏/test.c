#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//随机产生 20 个互不相同的[1，100]之间的 整数，
// 存在一维数组 s 中，找出所有 s[i] < s[i + 1]的数组元素。
int main()
{
	srand((unsigned)time(NULL));
	
	int arr_1[20] = { 0 };
	for (int i = 0; i < 20; i++)
	{
		arr_1[i] = (rand() % 100) + 1;
		for (int j = 0; j < i; j++)
		{
			if (arr_1[j] == arr_1[i])
			{
				arr_1[i] = 0;
				i--;
			}
		}
	}
	printf("随机生成数组为:\n");
	for (int i = 0; i < 20; i++)
	{
		printf("%d ", arr_1[i]);
	}
	printf("\n");
	int count = 0;
	for (int i = 0; i < 19; i++)
	{
		if (arr_1[i] < arr_1[i + 1])
		{
			printf("找到一组满足表达式，索引为: %d %d\n", i, i + 1);
			count++;
		}
	}
	printf("共找到 %d 对满足条件的元素\n", count);
	return 0;



}
