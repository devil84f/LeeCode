/*
 * @Author: LiNing
 * @Date: 2025-03-22
 * 一最多的行
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* rowAndMaximumOnes(int** mat, int matSize, int* matColSize, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * 2);
    int num = 0;
    int col = 0;
    for (int i = 0; i < matSize; i++) {
        int temp = 0;
        for (int j = 0; j < matColSize[i]; j++) {
            if (mat[i][j] == 1) temp++;
        }
        if (temp > num) {
            num = temp;
            col = i;
        }
    }
    * returnSize = 2;
    result[0] = col;
    result[1] = num;
    return result;
}

int main () {
    // 定义一个二维数组矩阵
    int matSize = 3; // 矩阵的行数
    int matColSize[3] = {5, 5, 5}; // 每行的列数
    int** mat = (int**)malloc(matSize * sizeof(int*)); // 动态分配矩阵的行指针

    // 初始化矩阵
    mat[0] = (int*)malloc(matColSize[0] * sizeof(int));
    mat[1] = (int*)malloc(matColSize[1] * sizeof(int));
    mat[2] = (int*)malloc(matColSize[2] * sizeof(int));

    // 填充矩阵
    mat[0][0] = 0; mat[0][1] = 1; mat[0][2] = 1; mat[0][3] = 0; mat[0][4] = 0;
    mat[1][0] = 1; mat[1][1] = 0; mat[1][2] = 0; mat[1][3] = 1; mat[1][4] = 1;
    mat[2][0] = 1; mat[2][1] = 1; mat[2][2] = 1; mat[2][3] = 1; mat[2][4] = 0;

    // 打印矩阵
    printf("Matrix:\n");
    for (int i = 0; i < matSize; i++) {
        for (int j = 0; j < matColSize[i]; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    // 调用函数
    int returnSize;
    int* result = rowAndMaximumOnes(mat, matSize, matColSize, &returnSize);

    // 打印结果
    printf("Result:\n");
    printf("Row with maximum ones: %d\n", result[0]);
    printf("Number of ones in that row: %d\n", result[1]);

    // 释放内存
    for (int i = 0; i < matSize; i++) {
        free(mat[i]);
    }
    free(mat);
    free(result);

    return 0;
}