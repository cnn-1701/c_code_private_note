#include"game.h"

int menu()
{
	printf("*************************");
	printf("***** 1.play 0.exit *****");
	printf("*************************");
	int ret = 0;
	scanf("%d", &ret);
	if (ret == 0)
	{
		return 0;
	}
	else if (ret == 1)
	{
		return 1;
	}
	else
	{
		return 2;
	}
}

void game()
{
	return;
}
 