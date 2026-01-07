#include"contact.h"

void InitContact(Contact* pc)
{
	assert(pc);
	pc->count = 0;
	memset(pc->data, 0, sizeof(pc->data));
	// 内存设置函数，从data开始将sizeof(pc->data)大小的内存设置为0
	// memset 头文件为<string.h>
	LoadContact(pc);
	// 初始化时使用LoadContact函数加载文件信息
}

void LoadContact(Contact* pc)
{
	assert(pc);

	FILE* pfRead = fopen("contact.txt", "rb");
	if (pfRead == NULL)
	{ 
		perror("LoadContact");
		return;
	}

	pc->count = 0;

	PeoInfo tmp = { 0 };

	while (fread(&tmp, sizeof(PeoInfo), 1, pfRead))
		// fread函数会“自动翻页”
	{
		if (pc->count >= MAX)
		{
			printf("通讯录已满，停止加载\n");
			break;
		}
		pc->data[pc->count] = tmp;
		pc->count++;
	}

	fclose(pfRead);
	pfRead = NULL;

	if (pc->count > 0)
	{
		printf("已从文件加载 %d 个联系人\n", pc->count);
	}
}

void ADDContact(Contact* pc)
{
	assert(pc);
	// assert断言，当条件为假则触发错误
	if (pc->count == MAX)
	{
		// 通讯录满了判断
		printf("通讯录已满，无法添加\n");
		return;
	}
	printf("请输入名字：>");
	scanf("%s", pc->data[pc->count].name);
	// 将个人信息存放入data中下标为conunt的位置
	// name为数组名，不需要取地址
	printf("请输入年龄： >");
	scanf("%d", &(pc->data[pc->count].age));

	printf("请输入性别：>");
	scanf("%s", pc->data[pc->count].sex);

	printf("请输入电话：>");
	scanf("%s", pc->data[pc->count].tele);

	printf("请输入地址：>");
	scanf("%s", pc->data[pc->count].addr);

	pc->count++;
	printf("添加成功\n");
}

void ShowContact(const Contact* pc) 
// 添加const保护指针所选内容不被修改
{
	assert(pc);
	int i = 0;
	// 增加表头
	printf("% 20s\t % 5s\t % 5s\t % 12s\t % 30s\n","姓名", "年龄", "性别", "电话", "住址");
	// 记得大小对齐
	for (i = 0; i < pc->count; i++)
	{
		printf("%20s\t%5d\t%5s\t%12s\t%30s\n", 
			pc->data[i].name, 
			pc->data[i].age, 
			pc->data[i].sex,
			pc->data[i].tele,
			pc->data[i].addr);
		// 长代码使用换行来增加可读性
		// %ns用于打印指定位数的字符串
		// 想要左对齐使用%-ns即可
	}
}

void DelContact(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	assert(pc);
	printf("请输入要删除的联系人：>");
	scanf("%s", name);
	if (pc->count == 0)
	{
		printf("通讯录为空,没有信息删除\n");
		return;
	}
	//1. 先查找
	int pos = FindByName(pc, name);// 查找函数，找到返回下标，找不到返回-1
	if (pos == -1)
	{
		printf("无此联系人\n");
		return;
	}
	//2. 再删除，即将后面元素向前覆盖
	for (int i = pos; i < pc->count - 1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->count--;
	printf("删除成功\n");
}

static int FindByName(Contact* pc, char name[])
// 在.c文件中使用static修饰来保护函数，static在定义时修饰函数后，被修饰的函数只能在.c文件中被看到，其他地方无法看到
// 可以不在头文件中对此函数声明
{
	assert(pc);
	for (int i = 0; i < pc->count; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
			// 遍历比较所要查找姓名与录入信息
			// strcmp返回值为0是表示字符串相同
		{
			return i;
		}
	}
	return -1;
}

void SearchContact(Contact* pc)
{
	assert(pc);
	char name[MAX_NAME] = { 0 };
	printf("请输入要查找人姓名：>");
	scanf("%s", name);
	int pos = FindByName(pc, name);

	if (pos == -1)
	{
		printf("要查找的人不存在\n");
		return;
	}
	else
	{
		printf("% 20s\t % 5s\t % 5s\t % 12s\t % 30s\n", "姓名", "年龄", "性别", "电话", "住址");
		printf("%20s\t%5d\t%5s\t%12s\t%30s\n",
			pc->data[pos].name,
			pc->data[pos].age,
			pc->data[pos].sex,
			pc->data[pos].tele,
			pc->data[pos].addr);
	}
}
void ModifyContact(Contact* pc)
{
	assert(pc);
	char name[MAX_NAME] = { 0 };
	printf("请输入要修改的人物名字：>");
	scanf("%s", &name);
	int pos = FindByName(pc, name);

	if (pos == -1)
	{
		printf("要修改的联系人不存在\n");
		return;
	}
	else
	{
		printf("请输入名字：>");
		scanf("%s", pc->data[pos].name);
		// 将个人信息存放入data中下标为conunt的位置
		// name为数组名，不需要取地址
		printf("请输入年龄： >");
		scanf("%d", &(pc->data[pos].age));

		printf("请输入性别：>");
		scanf("%s", pc->data[pos].sex);

		printf("请输入电话：>");
		scanf("%s", pc->data[pos].tele);

		printf("请输入地址：>");
		scanf("%s", pc->data[pos].addr);

		printf("修改成功\n");
		// 此处直接套用函数，将源输入函数下标修改为pos即可
	}
}

int cmp_peo_by_name(const void* e1, const void* e2)
// 使用qsort函数前必须要定义个排序函数
{
	// e1与e2首先必须被强制类型转换为PeoInfo类型的指针
	// 使用前必须要强制类型转换

	return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);

}

// 按照名字来排序
void SortContact(Contact* pc)
{
	assert(pc);
	qsort(pc->data, pc->count, sizeof(PeoInfo),cmp_peo_by_name);
	// qsort函数输入参数为起始参数，排序元素个数，排序元素大小，比较函数的函数指针（参数为比较两个元素的指针）
	// qsort头文件为<stdlib.h>
}

void SaveContact(const Contact* pc)
{
	assert(pc);
	// 先打开文件
	FILE* pfWrite = fopen("contact.txt", "wb");
	if (pfWrite == NULL)
	{
		perror("SaveContact");
		return;
	}
	// 以二进制文件写count个信息进入文件
	for (int i = 0; i < pc->count; i++)
	{
		fwrite(pc->data + i, sizeof(PeoInfo), 1, pfWrite);
	}


	fclose(pfWrite);
	pfWrite = NULL;
	return;
}
