#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define ROW 9
#define COL 9

#define ROWS ROW + 2
#define COLS COL + 2
// 将二维数组外扩一圈来节省边界的逻辑判断开销

void InitBoard(char arr[ROWS][COLS], int rows, int cols, char tgt);

void DisplayBoard(char arr[ROWS][COLS], int rows, int cols);

void SetMine(char arr[ROWS][COLS], int row, int col, int num);

void PrivesBoard(char show[ROWS][COLS], char mine[ROWS][COLS], int row, int col);