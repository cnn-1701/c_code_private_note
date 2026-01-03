
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define ROWS 5     
#define COLS 5     
#define MIN 10    
#define MAX 99    

void generateArray(int arr[ROWS][COLS]) 
{
    for (int i = 0; i < ROWS; i++) 
    {
        for (int j = 0; j < COLS; j++) 
        {
            arr[i][j] = rand() % (MAX - MIN + 1) + MIN;
        }
    }
}
void printArray(int arr[ROWS][COLS]) 
{
    printf("生成的二维数组：\n");
    printf("    ");
    for (int j = 0; j < COLS; j++) 
    {
        printf("列%02d ", j + 1);
    }
    printf("\n");
    printf("   +");
    for (int j = 0; j < COLS; j++) 
    {
        printf("-----");
    }
    printf("\n");

    for (int i = 0; i < ROWS; i++) 
    {
        printf("行%02d|", i + 1);
        for (int j = 0; j < COLS; j++) 
        {
            printf("%4d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void findSaddlePoints(int arr[ROWS][COLS]) 
{
    bool hasSaddlePoint = false;
    int saddlePoints[ROWS * COLS][3]; 
    int pointCount = 0;
;
;

    for (int i = 0; i < ROWS; i++) 
    {
        for (int j = 0; j < COLS; j++) 
        {
            bool isRowMax = true;
            bool isColMin = true;

            for (int k = 0; k < COLS; k++) 
            {
                if (arr[i][k] > arr[i][j]) 
                {
                    isRowMax = false;
                    break;
                }
            }

            if (isRowMax) {
                for (int k = 0; k < ROWS; k++) 
                {
                    if (arr[k][j] < arr[i][j]) 
                    {
                        isColMin = false;
                        break;
                    }
                }
                if (isColMin) 
                {
                    saddlePoints[pointCount][0] = i;
                    saddlePoints[pointCount][1] = j;
                    saddlePoints[pointCount][2] = arr[i][j];
                    pointCount++;
                    hasSaddlePoint = true;
                }
            }
        }
    }
    if (hasSaddlePoint) {
        printf("找到 %d 个鞍点：\n", pointCount);
        printf("编号 | 位置  | 值  | 所在行最大值检查 | 所在列最小值检查\n");
        printf("-----|-------|-----|-----------------|-----------------\n");

        for (int p = 0; p < pointCount; p++) 
        {
            int row = saddlePoints[p][0];
            int col = saddlePoints[p][1];
            int value = saddlePoints[p][2];

            printf(" %2d  | (%d,%d) |%4d | 行元素: ",
                p + 1, row + 1, col + 1, value);
            for (int k = 0; k < COLS; k++) 
            {
                if (k == col) {
                    printf("[%d] ", arr[row][k]);
                }
                else {
                    printf("%d ", arr[row][k]);
                }
            }

            printf("| 列元素: ");
            for (int k = 0; k < ROWS; k++) 
            {
                if (k == row) {
                    printf("[%d] ", arr[k][col]);
                }
                else {
                    printf("%d ", arr[k][col]);
                }
            }
            printf("\n");
        }
    }
    else 
    {
        printf("该二维数组没有鞍点\n");
    }
}
void findSaddlePointsAlternative(int arr[ROWS][COLS]) 
{
    printf("\n使用另一种方法查找鞍点...\n");

    bool hasSaddlePoint = false;
    int count = 0;

    for (int i = 0; i < ROWS; i++) 
    {
        int rowMax = arr[i][0];
        int maxCol = 0;
        for (int j = 1; j < COLS; j++) 
        {
            if (arr[i][j] > rowMax) 
            {

                rowMax = arr[i][j];
                maxCol = j;
            }
        }
        bool isColMin = true;
        for (int k = 0; k < ROWS; k++) 
        {
            if (arr[k][maxCol] < rowMax) 
            {
                isColMin = false;
                break;
            }
        }

        if (isColMin) 
        {
            printf("发现鞍点：位置(%d,%d)，值=%d\n",
                i + 1, maxCol + 1, rowMax);
            hasSaddlePoint = true;
            count++;
        }
    }

    if (!hasSaddlePoint) 
    {
        printf("未找到鞍点\n");
    }
    else 
    {
        printf("总共找到 %d 个鞍点\n", count);
    }
}

void displaySaddlePoints(int arr[ROWS][COLS]) 
{
    printf("\n数组鞍点位置图示：\n");
    printf("    ");
    for (int j = 0; j < COLS; j++) 
    {
        printf("  %02d ", j + 1);
    }
    printf("\n   +");
    for (int j = 0; j < COLS; j++) 
    {
        printf("-----");
    }
    printf("\n");

    for (int i = 0; i < ROWS; i++) 
    {
        printf(" %02d|", i + 1);
        for (int j = 0; j < COLS; j++) 
        {
            bool isRowMax = true;
            bool isColMin = true;


            for (int k = 0; k < COLS; k++) 
            {
                if (arr[i][k] > arr[i][j]) 
                {
                    isRowMax = false;
                    break;
                }
            }
            if (isRowMax) 
            {
                for (int k = 0; k < ROWS; k++) 
                {
                    if (arr[k][j] < arr[i][j]) 
                    {
                        isColMin = false;
                        break;
                    }
                }
            }
            else 
            {
                isColMin = false;
            }

            if (isRowMax && isColMin) 
            {
                printf(" *%2d*", arr[i][j]);
            }
            else {
                printf("%5d", arr[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    srand((unsigned)time(NULL));
    int array[ROWS][COLS];

    printf("数组大小: %d行 × %d列\n", ROWS, COLS);
    printf("数值范围: %d ~ %d\n\n", MIN, MAX);
    generateArray(array);

    printArray(array);

    findSaddlePoints(array);

    displaySaddlePoints(array);


    printf("\n====== 程序说明 ======\n");
    printf("鞍点定义：该位置上的元素既是所在行的最大值，又是所在列的最小值\n");
    printf("注意：一个二维数组可能有0个、1个或多个鞍点\n");

    return 0;
}
