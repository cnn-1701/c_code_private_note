
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
struct Student 
{
    char name[20];
};
// 结构体第一层 -- 学生
struct Class 
{
    struct Student stu;
    char classId[20];
};

// 结构体第二层，班级，包含学生成员

struct School 
{
    struct Class cls;
    // 创建cls类型结构体变量，在School中定义
    char schoolName[20];
};

int main() 
{
    struct School sch = 
    //创建sch结构体变量
    {
        .cls = {.stu = {" 程柄淋"}, .classId = {"软工25-2"}},
        .schoolName = "AUST"
    };
    // 在School对成员进行初始化

    struct School* p = &sch;
    // 定义结构体指针指向结构体变量sch

    printf("School: %s, Class: %s, Student: %s\n",
        p->schoolName,
        p->cls.classId,
        p->cls.stu.name);
    // 在嵌套访问时为一级成员.二级成员.三级成员

    printf("School: %s, Class: %s, Student: %s\n",
        (*p).schoolName,
        (*p).cls.classId,
        (*p).cls.stu.name);

    return 0;
}


