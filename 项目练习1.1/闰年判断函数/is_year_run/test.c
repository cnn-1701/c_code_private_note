#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int is_year_run(int year)
{
	if ((year % 4 == 0 && year % 100 != 0 )|| year % 400 == 0)
	{
		return 1;
	}
	else
		return 0;
}


int main()
{	
	int year = 0;
	do {
		printf("请输入年份:>");
		scanf("%d", &year);
		if (year == 0)
		{
			break;
		}
		else
		{
			if (is_year_run(year))
			{
				printf("是闰年");
			}
			else
				printf("不是闰年");

		}
	} while (year);
	return 0;
}