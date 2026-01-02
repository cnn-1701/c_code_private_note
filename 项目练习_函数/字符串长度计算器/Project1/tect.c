#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

//编写函数不允许创建临时变量, 求字符串的长度。

//int main()
//{
//	int len = strlen("abc");
//	printf("%d", len);
//	return 0;
//}

//int my_strlen(char* str)// 此处传递为地址，赋变量值为str
//{
//	int count = 0;
//	while (1)
//	{
//		if (*str != '\0')
//		{
//			count++;
//			str++;
//		}
//		else
//		{
//			break;
//		}		
//	}
//	return count;
//}
//
//int main()
//{
//	char arr[] = "abc";
//	int len = my_strlen(arr);
//	printf("%d", len);
//	return 0;
//}

// 不创建临时变量
// 递归求解
//拆分步骤：
//my_strlen 为整型类型
//逻辑：判断是否为\0
//如果是，求1+my_strlen("bc")

int my_strlen(char* str)
{
	if (*str != '\0')
	{
		return 1 + my_strlen(str + 1);
	}
	else
		return 0;
}


int main()
{
	char arr[] = "abcdef";
	int len = my_strlen(arr);
	printf("%d", len);
	return 0;
}