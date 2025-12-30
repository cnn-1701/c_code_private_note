#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <string.h>

// 在win中使用CMD命令
// shutdown -s -t 60   表示电脑在60s后关机
// shutdown -a         表示电脑取消关机计划

// 如何通过c程序调用CMD指令？
// 使用库函数system，语法为system("命令")

int main()
{
	char input[20] = { 0 };
	// 初始化存储字符串的数组
	// 类型char，大小为20，全为0
	system("shutdown -s -t 60");
again:
	printf("您的电脑将在60s后关机，若要取消关机，请输入 我是猪:>");
	scanf("%s", &input);
	// %s类型为字符串输入，%s可用于输入char[]或者char*
	

	// 确定字符串输入不能直接==0，需要使用strcmp函数对值进行比较

	// strcmp 是 C 语言标准库中的 字符串比较函数
	// #include <string.h>  // 需要包含头文件
	// int strcmp(const char* str1, const char* str2);
	//
	/*返回值	含义
		< 0	str1 < str2（str1 在字典中排在 str2 前面）
		= 0	str1 == str2（两个字符串完全相同）
		> 0	str1 > str2（str1 在字典中排在 str2 后面）*/

	/*string函数	功能	示例
		strcpy(dest, src)	复制字符串	    strcpy(str, "hello")
		strcat(dest, src)	连接字符串	    strcat(str, " world")
		strlen(str) 	    获取字符串长度	strlen("abc") 返回 3
		strcmp(s1, s2)	    比较字符串	    strcmp("a", "b") 返回负数
		strchr(str, ch)	    查找字符	    strchr("hello", 'e')*/
	if (strcmp(input, "我是猪") == 0)
	{
		system("shutdown -a");
	}
	else
	{
		goto again;
		// goto语句可以实现程序跳转，但是为程序的顺序与可读性，不建议大量使用
		// goto一般可用于大规模嵌套函数中，区别于多层break直接跳出循环嵌套
	}



	return 0;
}
