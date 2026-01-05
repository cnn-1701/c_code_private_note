#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

struct Product
{
	char name[20];
	double price;
};

void view(struct Product* ps)
{
	printf("商品名：%s\n商品价格:%.1f\n", (*ps).name, (*ps).price);
	printf("商品名：%s\n商品价格:%.1f\n", ps->name, ps->price);
	return;
}

int main()
{
	struct Product a = {
	"安徽理工校园周边", 20.0
	};
	view(&a);


	return 0;
}