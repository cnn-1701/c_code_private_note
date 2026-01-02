#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <math.h>
int Long(int num)
{	
	int i = 0;
	while (1)
	{
		num /= 10;
		if ( num == 0)
		{
			i++;
			return i;
			break;
		}
		else
		{
			i++;
			continue;
		}

	}
	
}

void Print(int num, int len)
{
	for (int i = 0; i <= len; i++)
	{
		printf("%d ",(num / (int)pow(10, (len - i - 1))) % (int)pow(10, (len - i + 1)));
	}
	
}

int main()
{
	int num = 0;
	scanf("%d", &num);

	int len = Long(num);
	
	Print(num, len);

	return 0;
	

}