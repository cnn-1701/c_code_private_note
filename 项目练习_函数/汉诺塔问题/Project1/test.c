#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int count = 0;
void move(int n,char* scr, char* tmp, char* tgt)
{
	if(n == 1)
	{
		printf("%c ----> %c\n", *scr, *tgt);
		count++;
	}
	else
	{
		move(n - 1, scr, tgt, tmp);
		printf("%c ----> %c\n", *scr, *tgt);
		count++;
		move(n - 1, tmp, scr, tgt);
	}
}

int main()
{
	int n = 0;
	char a = 'a', b = 'b', c = 'c';
	scanf("%d", &n);
	move(n, &a, &b, &c);
	printf("%d\n", count);

	return 0;
}
