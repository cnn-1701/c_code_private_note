#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void bubble(int* p,int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (*(p + j) > *(p + j + 1))
			{
				int temp = *(p + 1 + j);
				*(p + 1 + j) = *(p + j);
				*(p + j) = temp;
			}
		}
	}
}
int main()
{
	srand((unsigned)time(NULL));
	int arr[100];
	printf("≈≈–Ú«∞£∫\n");
	for (int i = 0; i < 100; i++)
	{
		arr[i] = (rand() % 1000 + 1);
		if (i % 10 == 0)
		{
			printf("\n");
		}
		printf("%d\t|", arr[i]);
		
	}
	int len = sizeof(arr) / sizeof(arr[0]);
	bubble(arr,len);
	printf("\n≈≈–Ú∫Û:\n");
	for (int i = 0; i < 100; i++)
	{
		if (i % 10 == 0)
		{
			printf("\n");
		}
		printf("%d\t|", arr[i]);
	}

	return 0;
}