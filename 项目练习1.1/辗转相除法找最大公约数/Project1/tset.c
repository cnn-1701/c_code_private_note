#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void Compare(int* a, int* b)
{
	if (*a <= *b)
	{
		int temp = *b;
		*b = *a;
		*a = temp;
	}
}

int gcd(int a, int b)// a > b
{
	while (a % b)
	{
		int temp = a % b;
			a = b;
			b = temp;
	}
	return b;
}

int main()
{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	Compare(&a, &b);
	printf("%d", gcd(a, b));
	return 0;

}