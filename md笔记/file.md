# C_code
files

---
1. 为什么使用文件
2. 什么是文件
3. 文件的打开和关闭
4. 文件的顺序读写
5. 文件的随机读写
6. 文本文件和二进制文件
7. 文件读取结束的判定
8. 文件缓冲区

---

## 一、使用文件的原因：

将数据直接保存在`电脑硬盘`上，实现数据的==持久化==

## 二、什么是文件

`硬盘上的文件`才是文件

程序设计中文件包括`程序文件`与`数据文件`

- 程序文件 ：包括`源程序文件`（如.c文件）、`目标文件`（如.obj文件 ）、`可执行程序文件`（如.exe文件）

- 数据文件：程序运行时读写的数据

- 源程序执行流程：数据文件 --读(输入)--> .c程序 --写(输出)--> 程序文件

- 文件名：文件的唯一文件标识，便于用户识别引用

    由三部分组成：`文件路径` + `文件名主干` + `文件后缀`
    例如 c:\code\test.c

## 三、文件的打开与关闭

文件操作流程：打开文件 --> 操作文件 --> 关闭文件

- `文件指针`
  
  每个被使用的文件都会在内存中开辟一个相应`文件信息区`用于存放文件相关信息
  文件信息包括`文件名`、`文件状态`、`文件路径`
  这些信息将保存在一个`结构体变量`中，该结构体由系统声明，标签为**FILE.**
    
    ![alt text](image-1.png)
    最后使用typedef 重命名为`FILE`.

    使用库函数`fopen`打开文件时会返回FILE类型结构体的起始地址，我们称此地址为文件指针

    FILE* pf //创建一个文件指针变量

     pf指针是一个指向FILE类型数据的指针变量，通过pf指针指向不同文件信息区来访问该文件，也就是**可以实现通过文件指针变量找到与其关联的文件**
    ![alt text](image-3.png)

-  文件的打开与关闭：

    文件打开的同时会返回一个 FILE* 类型的指针变量指向该文件信息区的首地址

    ANSIC规定使用`fopen`来打开文件，`fclose`来关闭文件

    文件打开
    >FILE * fopen( const char * filename, const char * mode)

    文件关闭：
    > int fclose ( FILE * stream )

    - fopen函数：
    FILE * fopen( const char * filename, const char * mode)

    先指定文件名，再指定文件打开形式
        文件的打开形式：

    |文件使用方式|含义|若文件不存在|
    |:----:|:----:|:----:|
    |"r"(只读)|打开一个已经存在的文本|出错|
    |"w"(只写)|为了输出数据，打开一个文本文件|建新文件|
    |"a"(追加)|向文本文件尾添加数据|建立一个新的文件|
    |"rb"(只读)|为了输出数据打开一个二进制文件|出错|
    |"ab"(追加)|向一个二进制文件尾添加数据|出错|
    |"r+"(读写)|为了读和写，打开一个文本文件|出错|
    |"w+"(读写)|为了读写，打开一个新文件|建立一个新的文件|
    |"a+"(读写)|打开一个文件，在文件尾进行读写|建立一个新文件|
    |"rb+"(读写)|为了读和写，打开一个二进制文件|出错|
    |"wb+"|为了读和写，新建一个二进制文件|建立一个新文件|
    |"ab+"(读写)|打开一个二进制文件，在文件尾进行读写|新建一个文件|

    > eg:
    FILE* pf = fopen("test.c", "w")

    如果该文件不存在，即打开失败,fopen函数会返回空指针，建议在打开后判断

    `if (pf == NULL)`

    可以引入头文件`errno.h`+`string.h`来实现对错误信息的打印
    > eg:
    >/* strerror example : error list */
    #include <stdio.h>
    #include <string.h>
    #include <errno.h>

    >int main ()
    {
    FILE * pFile;
    pFile = fopen ("unexist.ent","r");
    if (pFile == NULL)
        printf ("Error opening file unexist.ent: %s\n",strerror(errno));
    fclose(pf)
    return 0;

    }

    若文件不存在，将会打印错误信息：**Error opening file unexist.ent: No such file or directory**
    
    错误信息的打印还可以使用库函数`perror`
    例：当fopen打开失败时
    可以尝试使用语句`perror("fopen")`来实现对fopen返回的错误信息（空指针进行打印）
     - perror函数：C 库函数 void perror(const char *str) 把一个描述性错误消息输出到标准错误 stderr。首先输出字符串 str，后跟一个冒号，然后是一个空格

    > eg:if( fp == NULL ) 
    {
      perror("Error: ");
      return(-1);
    }

    该语句执行结果为
    `Error： ：No such file or directory `

    - fclose函数：
    
    使用例：
    fclose(pf);
    pf = NULL;// 需要初始化创建的指针以释放

    文件默认路径为`项目根目录`，为相对路径

    如果想打开其他位置的路径需要以`绝对路径`形式打开
    eg: "D:\\OneCloud\\test.c"

    注：**此处字符串中反斜杠需要使用转义字符**

## 文件的读写
|功能|函数名|适用范围|
|:----|:---:|:----:|
|字符输入函数   |fgrtc|所有输入流|
|字符输出函数|fputc|所有输出流|
|文本行输入函数|fgets|所有输入流|
|文本行输出函数|fputs|所有输出流|
|格式化输入函数|fscanf|所有输入流|
|格式化输出函数|fprint|所有输出流|
|二进制输入|fread|文件|
|二进制输出|fwrite|文件|

### 格式化输入/输出stdio
> // 写入结构体类型数据
> #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

> struct S
{
	char arr[11];
	int age;
	float score;
};

> int main()
{
    struct S s = { "zhangsan", 25, 50.5f };
    FILE* pf = fopen("test.txt", "w");
    if (pf == NULL)
    {
    perror("fopen");
    return 1;
    }
    // 现在需要以格式化写入数据
    fprintf(pf,"%s %d %f", s.arr, s.age, s.score);
    fclose(pf);
    pf = NULL;
    return 0;
}

- 在实例中，我们使用fprintf来进行格式化写入结构体类型数据，

- fprintf语法为`(FILE* stream， const char * format...)`
  即文件类型指针 + 格式化输入内容

- 编译运行后，发现根目录下的test.txt文本文件被写入了zhangsan 25 50.500000

- fscanf语法为`fscanf(FILE* stream, const char * format)`
  >fscanf(pf, "%s %d %f", &s.arr, &s.age, &s.score)

- 注：此时使用fopen时需要使用`fopen("D:\\Desktop\\Project1\\test.txt","r")`, 中，打开模式为` r `只读

- 此过程将test.txt文件中数据从硬盘中读取到内存中

- 对`fprintf`与`fscanf`可以理解为与外部设备（硬盘、屏幕、网络等等的交互）

- 为了防止编程时外部设备管理混乱，在写入外部设备前程序会将数据过度到中间`流`中，再写入外部设备，降低了编写压力

我们在打开文件时返回FILE*指针的过程可理解为**打开一个文件流**

**任何c程序，只要运行起来就会默认打开三个流**：

1. FILE* stdin  - 标准输入流(键盘)
2. FILE* stdout - 标准输出流(屏幕)
3. FILE* stderr - 标准错误流(屏幕)

 比如说使用fprintf()将数据打印到屏幕上时，地址指针栏可以写为stdout，使其打印到屏幕上,`std`含义为`标准化`
 **fprinf(stdout, "") == printf("")**

### 二进制输入/输出
fread,fwrite

- 只能针对文件流

- 为二进制输入输出模式

打开文件`fopen`时需要以二进制形式打开`wb`

- `fwrite`的语法为
> size_t fwrite(const void* ptr, size_t size, size_t const, FILE * stream)

> 解释：ptr指向目标函数地址，size_t size使用sizeof函数求结构体大小，size_t const为依此写入流次数，pf为指针
>例：fwrite ( &s, sizeof(struct S), 1, pf)

**其中我们在文本中以二进制写入，可能出现乱码，我们可以通过fread来正常读出**

- `fread`的语法为

> size_t fread ( const void* ptr, size_t szie,count, FILE * stream)

>eg:fread ( &s, sizeof (struct S), 1, pf)

- 二进制写入与文本写入区别：
  1. 二进制文件体积可能会更小
  2. 文本写入时生成的txt文件可直接阅读，二进制文件可能会出现乱码








