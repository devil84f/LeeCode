/*
 * @Author: LiNing
 * @Date: 2025-03-25
 * 对角线上不同值的数量差
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int** differenceOfDistinctValues(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes) {
    int m = gridSize, n = *gridColSize;
    int** res = (int**)malloc(m * sizeof(int*));
    *returnColumnSizes = (int*)malloc(m * sizeof(int));
    *returnSize = m;
    for (int i = 0; i < m; ++i) {
        res[i] = (int*)malloc(n * sizeof(int));
        (*returnColumnSizes)[i] = n;
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            bool s1[51] = {false};
            int count1 = 0;
            int x = i + 1, y = j + 1;
            while (x < m && y < n) {
                if (!s1[grid[x][y]]) {
                    s1[grid[x][y]] = true;
                    count1++;
                }
                x += 1;
                y += 1;
            }
            bool s2[51] = {false};
            int count2 = 0;
            x = i - 1, y = j - 1;
            while (x >= 0 && y >= 0) {
                if (!s2[grid[x][y]]) {
                    s2[grid[x][y]] = true;
                    count2++;
                }
                x -= 1;
                y -= 1;
            }
            res[i][j] = abs(count1 - count2);
        }
    }
    return res;
}

// 打印二维数组的函数
void printMatrix(int** matrix, int rows, int* cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols[i]; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // 定义测试用例的矩阵
    int gridSize = 3;
    int gridColSize[] = {3, 3, 3};
    int grid[3][3] = {
        {1, 2, 3},
        {3, 1, 5},
        {3, 2, 1}
    };

    // 将二维数组转换为指针数组
    int* gridPtr[3];
    for (int i = 0; i < gridSize; i++) {
        gridPtr[i] = grid[i];
    }

    // 调用函数
    int returnSize;
    int* returnColumnSizes;
    int** result = differenceOfDistinctValues(gridPtr, gridSize, gridColSize, &returnSize, &returnColumnSizes);

    // 打印结果
    printf("Result:\n");
    printMatrix(result, returnSize, returnColumnSizes);

    // 释放内存
    for (int i = 0; i < returnSize; i++) {
        free(result[i]);
    }
    free(result);
    free(returnColumnSizes);

    return 0;
}