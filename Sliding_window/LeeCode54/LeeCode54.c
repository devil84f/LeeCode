/*
 * @Author: LiNing
 * @Date: 2025-01-16 22:49:46
 * @LastEditors: LiNing
 * @LastEditTime: 2025-01-16 22:49:48
 * @FilePath: \LeeCode_Arrays\Sliding_window\LeeCode54\LeeCode54.c
 * @Description: 
 * Copyright (c) 2025 by ${git_name_email}, All Rights Reserved. 
 */

#include <stdio.h>
#include <stdlib.h>

// 螺旋矩阵输出函数
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    if (matrixSize == 0 || matrixColSize[0] == 0) {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = matrixSize * matrixColSize[0];
    int* result = (int*)malloc(sizeof(int) * (*returnSize));
    if (!result) {
        return NULL;  // 内存分配失败
    }

    int left = 0, right = matrixColSize[0] - 1, top = 0, bottom = matrixSize - 1;
    int index = 0;

    while (index < *returnSize) {
        for (int i = left; i <= right && index < *returnSize; i++) {
            result[index++] = matrix[top][i];
        }
        top++;

        for (int i = top; i <= bottom && index < *returnSize; i++) {
            result[index++] = matrix[i][right];
        }
        right--;

        for (int i = right; i >= left && index < *returnSize; i--) {
            result[index++] = matrix[bottom][i];
        }
        bottom--;

        for (int i = bottom; i >= top && index < *returnSize; i--) {
            result[index++] = matrix[i][left];
        }
        left++;
    }

    return result;
}

// 主函数测试
int main() {
    int matrixSize = 3;
    int matrixColSize[] = {4, 4, 4}; // 每一行的列数
    int matrixData[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    int* matrix[3];
    for (int i = 0; i < 3; i++) {
        matrix[i] = matrixData[i];
    }

    int returnSize;
    int* result = spiralOrder(matrix, matrixSize, matrixColSize, &returnSize);

    printf("螺旋矩阵输出结果:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}
