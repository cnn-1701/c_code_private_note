#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//void swap(int x, int y)
//{
//	int z = 0;
//	z = x;
//	x = y;
//	y = z;
//}
//// 其中，xy为形参，可视作实参ab调用函数swap的一份临时拷贝
//// 当swap不调用时，形参xy不申请内存空间
//// 对形参的修改无法作用到实参的数值
//int main()
//{
//	int a = 0;
//	int b = 0;
//
//	scanf("%d %d", &a, &b);
//	printf("swap前: %d %d\n", a, b);
//	swap(a, b);
//	printf("swap后: %d %d\n", a, b);
//
//	
//	return 0;
//}
//// 输出结果应为
//// 10 20
//// 10 20


// 以上我们称**传值调用**

// 尝试采用指针传址 **传址调用**
// 传址调用是把函数外部创建变量的内存地址传递给函数参数的一种调用函数的方式。
// 这种传参方式可以让函数和函数外边的变量建立起真正的联系, 也就是函数内部可以直接操
// 作函数外部的变量
void swap(int* px, int* py)// 输入形参类型应为地址/指针类型
{
	int z = 0;// 中间变量z可以不是指针，只取指针值
	z = *px;// *为解引用，即将指针对于地址内存中存储的数拉出
	*px = *py;
	*py = z;
}

int main()
{
	int a = 0;
	int b = 0;

	scanf("%d %d", &a, &b);
	printf("swap前: %d %d\n", a, b);
	swap(&a, &b);// 输入为对ab取地址
	printf("swap后: %d %d\n", a, b);


	return 0;
}
// 输出结果应为
// 10 20
// 10 20
