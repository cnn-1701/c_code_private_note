#include"contact.h"

// 人的信息：名字、年龄、性别、电话、地址
// 功能：
// 存放100人信息
// 增加联系人
// 删除指定联系人
// 查找联系人
// 修改联系人
// 排序
// 显示联系人

// test.c		测试功能
// contact.c	通讯录的实现
// contact.h	通讯录的声明

void menu()
{
	printf("****************************************\n");
	printf("***** 1. add          2.del       ******\n");
	printf("***** 3. search       4.modify    ******\n");
	printf("***** 5. show         6.short     ******\n");
	printf("***** 0.exit                      ******\n");
	printf("****************************************\n");
	return;
}

int main()
{
	int input = 0;
	// PeoInfo data[100];// 存放100人信息
	// int count = 0; // 记录通讯录人数
	// 此处在声明中定义

	Contact con;// 创建结构体变量con
	// 通讯通讯录初始化
	InitContact(&con);
	// 结构体传参尽量传地址
	// 初始化通讯录/
	// 现在还需要加载文件的信息到通讯录之中


	do
	{
		menu(); 
		printf("请选择：>");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
		{
			ADDContact(&con);
			break;
		}
		case 2:
		{
			DelContact(&con);
			break;
		}
		case 3:
		{
			SearchContact(&con);
			break;
		}
		case 4:
		{
			ModifyContact(&con);
			break;
		}
		case 5:
		{
			ShowContact(&con);
			break;
		}
		case 6:
		{
			SortContact(&con);
			break;
		}
		case 0:
		{
			SaveContact(&con);
			// 再程序退出前以文件形式保存通讯录
			printf("退出程序\n");
			break;
		}
		default:
			printf("输入无效，请重新输入\n");
			break;
		}
	} while (input);

	return 0;
}
