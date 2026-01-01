#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void count()
{
	static time = 0;
	time++;
	printf("%d", time);
}

int main()
{	
	while (1)
	{
		if (getchar())
			count();
		else
			break;
	}
}
