#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
 
void reverse(char* str, int sz)
{
	// 使用字符地址指针来接受数组
	// 递推式：逆序整个字符串 = 交换首末元素 + 逆序去除首末元素的数组
	// 将末元素交换前后先不将首元素交换后，而是替换为/0来封闭数组，
	// 最后回归时使\0替换为首元素
	if (sz > 1)
	{
		char temp = *str;
		*str = *(str + sz - 1);
		reverse(str + 1, sz - 2);
		// 注意此处为sz - 2，因为我剔除了首尾两个元素
		*(str + sz - 1) = temp;
	}
	else
		return;
	// 达到终止需要设置return
}
int main()
{
	char arr[] = "abcdef";
	int sz = sizeof(arr) - 1;
	reverse(arr, sz);
	printf("%s", arr);
}

// 或者尝试使用双指针迭代法来写此函数
// 所以我们在使用递归法时，最关键的是找到包含函数的递推关系式
// 如f(x) = f(x - 1) + “操作”
// 同时要切记设置函数返回即递归终点 - 回归起点

