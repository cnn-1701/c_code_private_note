#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
//assert断言
// 类型的声明可以在头文件进行
#define MAX 100
// 定义最大人数为100
#define MAX_NAME  20
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX_ADDR 30

typedef struct PeoInfo
{
	char name[MAX_NAME];// 姓名
	int age;	 // 年龄
	char sex[MAX_SEX];// 性别
	char tele[MAX_TELE];// 电话
	char addr[MAX_ADDR];// 住址
}PeoInfo;// 对类型重新命名为PeoInfo

typedef struct Contact
{
	PeoInfo data[MAX];//100人
	int count;
}Contact;

// 初始化通讯录
void InitContact(Contact* pc);// 传参类型为Contact类型的指针

// 增加联系人
void ADDContact(Contact* pc);

// 打印通讯录信息
void ShowContact(Contact* pc);

// 删除联系人信息
void DelContact(Contact* pc);

// 查找联系人
void SearchContact(Contact* pc);

// 修改指定联系人
void ModifyContact(Contact* pc);

// 排序通讯录中内容
// 按照年龄，名字来排序
void SortContact(Contact* pc);

// 保存通讯录信息到文本文件
void SaveContact(const Contact* pc);

// 加载文件信息到通讯录
void LoadContact(Contact* pc);
