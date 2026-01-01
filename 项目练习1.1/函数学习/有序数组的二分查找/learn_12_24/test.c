#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int search(int arr[],int size, int target)		
{
	int L = 0;
	int R = size - 1;
	int mid = L + (R - L);
	
	while (L <= R)
	{
		mid = L + (R - L);
		if (arr[mid] > target)
		{
			R = mid - 1;
		}
		else if (arr[mid] < target)
		{
			L = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

int menu()
{
	printf("**********************\n");
	printf("*******1.继续 ********\n");
	printf("*******2.结束 ********\n");
	printf("**********************\n");
	int input = 0;
	scanf("%d", &input);
	if (input == 1)
		return 1;
	else if (input == 2)
		return 0;
	else
		printf("输入无效，请重新输入\n");
		return 2;
}

int main()
{
	int arr[10] = { 11,12,13,14,15,16,17,18,19,20 };
	int target = 0;
	int size = sizeof(arr) / sizeof(arr[0]);
	
	while(1)
	{
		scanf("%d", &target);

		if (target == -1)
		{
			goto end;
		}
		while(1)
		{ 
		if (search(arr, size, target) == -1)
		{
			printf("未找到相关元素索引，请重新输入\n");
			goto end;
		}
		else
		{
			printf("您所要查找的元素%d索引为%d\n", target, search(arr, size, target));
			int temp = menu();
			if (temp == 0)
			{
				goto end;
			}
			else if (temp == 1);
				break;
		}
		
		}
	}

end:
	return 0;
}