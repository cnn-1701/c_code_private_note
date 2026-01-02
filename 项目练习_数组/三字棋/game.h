#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 10
#define COL 10

// 开头使用宏定义来明确行列数，提前规划

// 初始化棋盘的声明
void InitBoard(char board[ROW][COL], int row, int col);

// 打印棋盘的声明
void DisplayBoard(char board[ROW][COL], int row, int col);

// 玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col);

// 电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col);

//
// 判断输赢的几种情况
// 1 玩家获胜	- '*'
// 2 电脑获胜	- '#'
// 3 平局		- 'Q'
// 4 继续		- 'C'
//   

char IsWin(char board[ROW][COL], int row, int col);