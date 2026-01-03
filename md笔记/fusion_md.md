# C_cod Learn
## 函数
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void swap(int x, int y)
{
	int z = 0;
	z = x;
	x = y;
	y = z;
}
// 其中，xy为形参，可视作实参ab调用函数swap的一份临时拷贝
// 当swap不调用时，形参xy不申请内存空间
// 对形参的修改无法作用到实参的数值
> int main()
 {
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	printf("swap前: %d %d\n", a, b);
	swap;
	printf("swap后: %d %d\n", a, b);
	return 0;
 } 
// 输出结果应为
// 10 20
// 10 20

 **形参标识符与实参可同可不同**

**为何一定要在外函数求元素个数**
函数传递数组时传递的没有拷贝新一份数组，只传递了一个数组的首地址
因此在内函数（子程序）求数值大小时，实际在求指针变量大小

eg:
> void test(arr[])
{
	sizeof(arr) / sizeof(arr[0])
	        ↑这里不是创建的新数组，而是拷贝的实参数组的地址，因此返回值为1
			写法错误，形参arr看似数值，本质上为指针
}

 # 布尔类型
在C99标准引入bool类型
用于表示真假的变量
eg：
>bool flag = true -- 1
				false-- 0

使用bool类型前先引入<stdbool.h>头文件
bool类型为1字节

# <写一个函数,每调用一次这个函数,就会将num的值增加1>
可将**主函数的计数变量地址**传进需要计数的函数
或者使用static

# 函数的嵌套与链式访问
函数可以嵌套调用但不可嵌套**定义**

# 链式访问
依赖于函数的返回值
eg: 
printf("%d",strlen("abcdef"))
     ↑  参数     ↑  返回值
	 一个函数的返回值做另一个函数的参数，我们称__链式访问__
函数printf完成后的返回值为打印**字符长度**

**链式访问前提条件**：函数有返回值，将返回值作为其他函数的参数

函数返回类型一定要事先定义,函数不定义返回类型时，默认返回类型为**int**
(本质上返回的时寄存器内eax值)

eg：
int ADD(int ,int y)
{
	printf("%d", x + y)
}
上述函数（子程序）返回的是**最后一条指令执行的结果**（不建议使用，未定义写法）

void类型函数不需要返回

定义函数时未定义参数时，主程序仍能传参，但是参数不被接受
可以尝试定义void test（void）
                       ↑明确不接收数值

# main函数参数
实际上有三种参数
int main(int argc,char* argv[ ], char *envp[ ] )
{
	return 0;
}

# 函数的声明与定义

**函数声明**：告诉编译器函数类型
在开头进行函数的声明
int ADD(int x, int y );
↑ 函数的返回类型       ↑ 语句结束
     ↑ 函数名
	      ↑ 函数的参数类型

**函数定义**：定义函数交代函数功能实现
int ADD( int x, int y)
{
	return x + y;
}

编译器遍历代码时从上到下逐行扫描
若此函数直接放在主函数后面时
先扫描到主函数内的定义函数，编译器中函数未定义
因此需要在
1.开头定义
2.在开头进行函数的声明
int ADD(int x, int y );
↑ 函数的返回类型       ↑ 语句结束
     ↑ 函数名
	      ↑ 函数的参数类型
**下方定义函数语句需要保持一致**
**函数声明出现在函数使用前，先声明再使用**
**函数的声明一般放在头文件中**

## 将函数定义放在头文件中
eg：
将函数的声明放在<ADD.h>中
将函数的定义放在<ADD.c>中
在主程序<test.c>中加上预处理# include “ADD.h”
即可使用ADD函数功能，我们将 <ADD.h>和<ADD.c>称为加法==模块==  
### 注意：
 - 在使用系统自带的头文件时使用符号    `<函数名.h>`
 - 在使用自己编写的头文件时使用符号   `" 函数名.h "`	
  
  初学时觉得把所有代码写在一个文件方便
  但是在公司中，需要分文件协作写代码
  - 协作编写角度
  - 模块化的角度
  
### 拆分函数为头文件+源文件的好处：
- 包含头文件的基本原理是**拷贝**头文件内容(实现函数效果)
- 代码的隐藏:将`.c`文件编译为静态库`add.lib`,`.h`文件不编译
  可以理解为`.c`文件为函数主要功能，而`.h`文件为函数的声明部分
  这样我们就可以在隐藏函数源代码的前期下实现函数功能
### 静态库的导入:   `#pragma comment(lib, "add.lib") `

### 防止头文件被重复包含 `# pragma once`

***

# 函数的递归
## 什么是递归？
- 程序调用自生的编程技巧
- 通常将大型复杂问题转换为小型问题层层求解  

#### 练习一
eg: `按顺序打印整型值`
> int main() // 正顺序打印
{
	unsigned int num = 0;// 定义一个无符号整形 
	scanf("%u", &num);
	while (num)
	{
		printf("%d ", num % 10);
		num = num / 10;
	}
	return 0;
}

result:
> 123456
> 6 5 4 3 2 1

// 逆顺序打印
> void print(unsigned int num)
{
	`现在需要从第一位打印`
	`print(123)4`
	`print(12)3 4`
	`print(1)2 3 4`
	`print1 2 3 4 开始回归`
	if (num > 9)
	{
		print(num / 10);// 打印123(传递过程 / 递推过程)
	}
	printf("%d",num % 10);// 打印4(回归起点)
	}




>int main()
{
	unsigned int num = 0;
	scanf("%u ", &num);
	print(num);
	return 0;
}

### 要点：
- 第一个if循环向函数内嵌套递推式
- 出if循环后记得写递推的终点，作为回归的起点
- 注意，可以尝试在每层递推写上对于参数（注意每层参数应当不同）
- 如果不限定递归层数，会造成==栈溢出==，报错`Stack overflow`

## 递归书写的两个***必要条件***
- 存在==限制条件==，达到限制条件后递推不再继续
- 函数每次调用需要越来越接近这个限制条件（收敛）

### 什么是栈溢出
#### 内存结构：
- 栈区：存放函数的`形参`，`局部变量`，`函数返回值`
  
  	`每一次函数的调用都会在栈上申请空间，栈区空间有限`
  	[函数栈帧的创建与销毁](https://www.bilibili.com/video/BV1Pz4y1F7bU?vd_source=e28628411d73a1e10bdcfb1410cbccf8)
- 堆区：`存放动态内存分配`
	- malloc
	- free
	- calloc
	- realloc
- 静态区：`静态内存变量`，`全局变量`


### 如何定义打印一个无符号整形：
> unsigned int num = 0;
> scanf("%u", &num);

- 注意，`%u`用于打印==无符号整形==，而`%d`用于打印==有符号整形==

#### 练习二
`编写函数不允许创建临时变量,求字符串的长度。`
> int my_strlen(char* str)// 此处传递为地址，赋变量值为str
{
	int count = 0;
	while (1)
	{
		if (*str != '\0')
		{
			count++;
			str++;
		}
		else
		{
			break;
		}		
	}
	return count;
}

> int main()
{
	char arr[] = "abc";
	int len = my_strlen(arr);
	printf("%d", len);
	return 0;
}

这段代码本质上通过取地址再判断字符是否相等来测量字符串长度
其中函数`my_strlen`传参部分既可以写为==字符类指针==`char* `也可以写为==数组类型==`str[]`

eg: 	指针类型`int my_strlen(char* str)`
        数组类型`int my_strlen(char str[])`
- ==本质上都在传递地址==
- 由于定义了`char* `类型的指针，使用`str++`语法是指针会增加1个字节
  当我使用`int* `类型指针来定义时，使用`str++`语法会让指针增加4个字节
  指针自加后指向字节的大小与指针类型有关

#### 没有临时变量的写法
> int my_strlen(char* str)
{
	if (*str != '\0')
	{
		return 1 + my_strlen(str + 1);   `此处可以用++str但是不建议每次都用`
	}										
	else
		return 0;
}
 >int main()
{
	char arr[] = "abc";
	int len = my_strlen(arr);
	printf("%d", len);
	return 0;
}

#### 此递归中`str+1`与`++str`区别
- `str+1`不改变str自身内存值
- `++str`将会改变str内存值
- 此函数中两种写法均不影响，但是实例中尽量少用`++str`语法
- 注意理解这里的`str`为每次函数调用时栈创建的新`str`值，不同层数str指向不同字符

## 函数的递归与迭代
- 什么是迭代？
  
  循环是一种迭代，迭代不仅仅是循环
  写代码时可以写为==递归方式==，也可以替换为为==迭代方式==

eg：求阶乘公式

- 递归写法：
> int fac(int num)
{
	if (num)
	{
		n * fac(num - 1);
	}
	else
		return 1;
}  

- 迭代写法
  
> int fac(int num)
{
	int ret = 1
	for (int i = 1,i <= num ,i++);
	{
		ret *= i;
	}
	return ret;
}

#### 练习三
`求第n个斐波那契数`

> int fei(int num)
{
	if ()
	if (num == 1 || num == 2)
		return 1;
	else
		return fei(num - 1) + fei(num - 2);
}
> int main()
{
	int num = 0;
	scanf("%d", &num);
	printf("%d", fei(num));
	return 0;
}

但是此方法用于计算较大`num`时效率较低，我们会大量重复计算同一种函数参数的返回值
当我们计算第40个斐波那契数时，会求3kw次函数分支

**在这种情况时，我们考虑通过循环(迭代)来优化算法效率**
> int fib(int num)
{
	if (num <= 2)
	{
		return 1;
	}
	int a = 1;// a为n-2
	int b = 1;// b为n-1
	int c = a + b;
	for (int i = 3; i < num; i++)
	{
		a = b;
		b = c;
		c = a + b;
	}
	return c;
}
int main()
{
	int num = 0;
	scanf("%d", &num);
	printf("%d", fib(num));
	return 0;
}

或者优化写法
> int Fib(int num)
{
	int a = 1;
	int b = 1;
	int c = 2;
	while(n > 3)
	{
		a = b;
		b = c;
		c = a + b;
		n--;
	}
	return c;
}

### 如何抉择递归写法/迭代写法？
- 如果递归写法简洁且高效，直接使用递归
- 如果遇到例如`斐波那契数列`这种递归效率低下的算法，则考虑迭代
- 即使递归方法简单高效，仍然可能出现栈溢出的现象，因为每次调用新一层函数都会创建新占用栈

#### 如何解决递归栈溢出？
   1. 将递归改写为==迭代法==
   2. 使用静态`static`对象代替`nonstatic`局部对象，即栈对象
   3. 及时释放`nonstatic`局部变量

## 函数递归经典问题
  - `汉诺塔问题`
  - `青蛙跳台问题`
*这些事实上就是我们高中所接触的**马尔科夫链**问题，可自行研究

### [汉诺塔问题](https://www.bilibili.com/video/BV1SP4y137E9?vd_source=e28628411d73a1e10bdcfb1410cbccf8)

问题分析：
- 要将`n`个圆盘从A柱`scr`移动到C柱子`tgt`的过程为：
  将前`n-1`个圆盘从A柱`scr`移动到B柱`tmp`
  将第n个圆盘移动到C柱`target`
  将前`n-1`个圆盘从B`tmp`移动到C柱`tgt`

- 我们通过定义move函数来实现柱子的移动
  move函数应当接受三个参量，即将要移动的盘子数目`n`，源柱`scr`，间柱`tmp`与靶柱`tgt`
  再次分析，我们会将`n-1`个柱子由`scr`柱移动到`tmp`柱
  使第n柱移动到`tgt`柱后
  再将`n-1`从`tmp`柱移动到`tgt`柱，构成递归

> #define _CRT_SECURE_NO_WARNINGS
> #include<stdio.h>

> int count = 0;
> void move(int n,char* scr, char* tmp, char* tgt)
{
	if(n == 1)
	{
		printf("%c ----> %c\n", *scr, *tgt);
		count++;
	}
	else
	{
		move(n - 1, scr, tgt, tmp);
		printf("%c ----> %c\n", *scr, *tgt);
		count++;
		move(n - 1, tmp, scr, tgt);
	}
}
> int main()
{
	int n = 0;
	char scr = 'a', tmp = 'b', tgt = 'c';
	scanf("%d", &n);
	move(n, &scr, &tmp, &tgt);
	printf("%d\n", count);
	return 0;
}

输出结果：
>4
a ----> b
a ----> c
b ----> c
a ----> b
c ----> a
c ----> b
a ----> b
a ----> c
b ----> c
b ----> a
c ----> a
b ----> c
a ----> b
a ----> c
b ----> c
15
C:\Users\Misono Mika\OneDrive\C语言学习\汉诺塔问题\Project1\x64\Debug\Project1.exe (进程 275008)已退出，代码为 0 (0x0)。
按任意键关闭此窗口. . .    

可见我们通过简单的递归调用轻松实现了汉诺塔问题的步骤分析与计数

常见的递归相关题：
- `if`语句中`0`表示假，==非零==表示真而不是`1`表示真
  
- `else`语句总是与==最近的==`if`进行匹配而不是与对齐的`if`进行匹配
  
- `switch`语句中`default`可以放在==任意位置==
  
- `switch`语句中case后表达式只能是==整型常量==表达式
  
  char也是整形家族的，因为字符存储时以`ascii`码进行存储，因此char类型也可在case语句表达式中

- `switch`语句的结果判断/选择题一定要看是否有`break`，否则程序的顺序执行无法被打断，最后输出最后一段语句的值

- 函数的设计应当遵循[高内聚低耦合](https://baike.baidu.com/item/%E9%AB%98%E5%86%85%E8%81%9A%E4%BD%8E%E8%80%A6%E5%90%88/5227009)

- 尽量做到谁申请的资源由谁来释放`动态内存管理`

- 在不同的函数中可以使用`同名变量`
  
- 函数的形参保存在栈上

- 复合语句内定义的变量只在打括号内有效

- [函数栈相关知识](https://www.bilibili.com/video/BV1By4y1x7Yh/?spm_id_from=333.337.search-card.all.click&vd_source=d43d37dc4055f11d65e38cc11ce56540)

- 求字符型数组长度时要减去`\0`
  
  不管是使用`sizeof` 还是 `strlen` 都要减去 `\0`


- 
  eg：
  > switch(1)
  {
	case 1: b = 30;
	case 2: b = 15;
	case 3: b = 5;
	default: b = 0;
  }
  
  最后结果为 b = 0

一些有趣思路：
- 最大公约数找法：
  取两数中较小一数开始自减，若同时满足`(max{a,b} % i == 0) && (min{a,b} % i == 0)`，那我们就找到了最大公约数
  或者我们有`辗转相除法`
  
  首先我们来分析，两数的最大公约数最大的能使两数被整除的数
  则两数的余数一定是最大公约数的倍数，同理递归
  我们只需要重复拿最大的数对最小的数取模，再将最大数淘汰，递归一次使最大数为①中输入的最小数，最小数为取模值即可，重复执行到取模为0时，最小数为原对数的最大公约数
  >void Compare(int* a, int* b)
{
	if (*a <= *b)
	{
		int temp = *b;
		*b = *a;
		*a = temp;
	}
}
int gcd(int a, int b)// a > b
{
	while (a % b)
	{
		int temp = a % b;
			a = b;
			b = temp;
	}
	return b;
}
int main()
{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	Compare(&a, &b);
	printf("%d", gcd(a, b));
	return 0;																								
}

	其中比较大小部分我们还可以用`三目运算符`来实现对`min`与`max`的定位
***
> 使用递归完成数组元素倒置


















