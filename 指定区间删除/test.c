#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//在一个递增有序的数组中，删除元素值在 x~y 之间的所有元素，
// x、y 的值均 从键盘中输入，而且 x < y。

//int main()
//{
//	srand((unsigned)time(NULL));
//	int arr[100];
//	for (int i = 0; i < 100; i++)
//	{
//		arr[i] = rand() % 1000 + 1;
//		while ((i > 0) && (i <= 99))
//		{
//
//			if (arr[i] <= arr[i - 1])
//			{
//				arr[i] = 0;
//				i--;
//			}
//		}
//	}
//	printf("随机生成的有序数组为:");
//	
//	for (int i = 0; i < 100; i++)
//	{
//		printf("%d ", arr[i]);
//		if (i % 5 == 0)
//		{
//			printf("\n");
//		}
//	}
//	int x = 0;
//	int y = 0;
//	printf("请输入对应x、y值");
//	scanf("%d %d", x, y);
//	int Max = (x > y ? x : y);
//	int Min = (x > y ? y : x);
//	int range_max = arr[99];
//	int range_min = arr[0];
//	int maxxxx = arr[99];
//
//	if (Max < range_min || Min > range_max)
//	{
//		printf("输入无效，请重新输入");
//		return 0;
//	}
//	else if (Max < arr[99])
//	{
//		range_max = Max;
//	}
//	else
//	{
//		range_max = arr[99];
//	}
//	if (Min < arr[0])
//	{
//		range_min = arr[0];
//	}
//	else
//	{
//		range_min = Min;
//	}
//	int edge1 = 0;
//	for (int i = 0; i < 100; i++)
//	{
//		if (arr[i] >= range_min)
//		{
//			edge1 = i;
//			break;
//		}
//	}
//	int edge2 = 0;
//	for (int i = 0; i < 100; i++)
//	{
//		if (arr[i] > range_max)
//		{
//			edge2 = i;
//			break;
//		}
//	}
//	int len = edge2 - edge1 + 1;
//	for (int i = edge1; i <= edge2; i++)
//	{
//		arr[i] = 0;
//	}
//	for (int i = edge2 + 1; i < 100; i++)
//	{
//		arr[i - len] = arr[i];
//	}
//	for (int i = edge2; i < 100; i++)
//	{
//		arr[i] = "\0";
//	}
//	printf("删去后的数组为：\n");
//	for (int i = 0; i < 99 - len - 1; i++)
//	{
//		printf("%d", arr[i]);
//	}
//	return 0;
//
//
//
//	
//
//}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() 
{
    srand((unsigned)time(NULL));
    int arr[100];

    for (int i = 0; i < 100; i++) 
    {
        arr[i] = rand() % 1000 + 1;
    }

    bubbleSort(arr, 100);

    printf("随机生成的有序数组为:\n");
    for (int i = 0; i < 100; i++) 
    {
        printf("%4d ", arr[i]);
        if ((i + 1) % 10 == 0) 
        {
            printf("\n");
        }
    }
    printf("\n");

    int x = 0;
    int y = 0;
    printf("请输入x和y的值（x < y）: ");
    scanf("%d %d", &x, &y); 

    if (x >= y) {
        printf("输入无效：x必须小于y\n");
        return 0;
    }

    int start = -1;
    int end = -1;

    for (int i = 0; i < 100; i++) 
    {
        if (arr[i] >= x) 
        {
            start = i;
            break;
        }
    }
    for (int i = 0; i < 100; i++)
    {
        if (arr[i] > y) 
        {
            end = i - 1;
            break;
        }
    }
    if (end == -1 && arr[99] <= y) 
    {
        end = 99;
    }

    if (start == -1 || end == -1 || start > end) 
    {
        printf("没有元素需要删除\n");
        printf("删除后的数组保持不变:\n");
        for (int i = 0; i < 100; i++) 
        {
            printf("%4d ", arr[i]);
            if ((i + 1) % 10 == 0) 
            {
                printf("\n");
            }
        }
        return 0;
    }

    int deleteCount = end - start + 1;

    for (int i = end + 1; i < 100; i++) 
    {
        arr[i - deleteCount] = arr[i];
    }

    for (int i = 100 - deleteCount; i < 100; i++) 
    {
        arr[i] = 0;
    }

    printf("删除了从 %d 到 %d 之间的元素后，数组为:\n", x, y);
    int newSize = 100 - deleteCount;
    for (int i = 0; i < newSize; i++) 
    {
        printf("%4d ", arr[i]);
        if ((i + 1) % 10 == 0) 
        {
            printf("\n");
        }
    }

    if (newSize < 100) 
    {
        for (int i = newSize; i < 100; i++) 
        {
            printf("%4d ", arr[i]);
            if ((i + 1) % 10 == 0) 
            {
                printf("\n");
            }
        }
    }

    printf("\n总共删除了 %d 个元素\n", deleteCount);

    return 0;
}