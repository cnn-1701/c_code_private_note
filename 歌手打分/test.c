#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#define SINGERS 10 
#define JUDGES 7

float generateScore() 
{
   
    return (rand() % 51 + 50) / 10.0f;
}

float calculateScore(float scores[]) 
{
    float sum = 0;
    float max = scores[0];
    float min = scores[0];

    for (int i = 0; i < JUDGES; i++) 
    {
        sum += scores[i];
        if (scores[i] > max) max = scores[i];
        if (scores[i] < min) min = scores[i];
    }

    return (sum - max - min) / (JUDGES - 2);
}

void sortScores(float scores[], int ids[]) 
{
    for (int i = 0; i < SINGERS - 1; i++) 
    {
        for (int j = 0; j < SINGERS - i - 1; j++) 
        {
            if (scores[j] < scores[j + 1]) 
            {
                
                float tempScore = scores[j];
                scores[j] = scores[j + 1];
                scores[j + 1] = tempScore;

                int tempId = ids[j];
                ids[j] = ids[j + 1];
                ids[j + 1] = tempId;
            }
        }
    }
}

int main() 
{
    srand((unsigned)time(NULL));

    float singerScores[SINGERS];     
    int singerIds[SINGERS];           
    float judgeScores[JUDGES];       

    printf("====== 歌手评分系统 ======\n\n");
    printf("评委打分情况：\n");
    printf("歌手编号 | 评委打分（7位评委） | 最终得分\n");
    printf("---------|-------------------|----------\n");

    for (int i = 0; i < SINGERS; i++) 
    {
        singerIds[i] = i + 1;
        for (int j = 0; j < JUDGES; j++) 
        {
            judgeScores[j] = generateScore();
        }

        singerScores[i] = calculateScore(judgeScores);

        printf("歌手%2d  | ", i + 1);
        for (int j = 0; j < JUDGES; j++) 
        {
            printf("%.1f ", judgeScores[j]);
        }
        printf("| %.2f\n", singerScores[i]);
    }
    sortScores(singerScores, singerIds);
    printf("\n====== 歌手得分排名（从高到低） ======\n");
    printf("名次 | 歌手编号 | 最终得分\n");
    printf("-----|----------|----------\n");

    for (int i = 0; i < SINGERS; i++)
    {
        printf(" %2d  | 歌手%2d   | %.2f\n",
            i + 1, singerIds[i], singerScores[i]);
    }
    float total = 0;
    float highest = singerScores[0];
    float lowest = singerScores[SINGERS - 1];

    for (int i = 0; i < SINGERS; i++) 
    {
        total += singerScores[i];
    }

    printf("\n====== 统计信息 ======\n");
    printf("平均得分: %.2f\n", total / SINGERS);
    printf("最高得分: %.2f (歌手%d)\n", highest, singerIds[0]);
    printf("最低得分: %.2f (歌手%d)\n", lowest, singerIds[SINGERS - 1]);

    return 0;
}