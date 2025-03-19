/*
 * @Author: LiNing
 * @Date: 2025-03-19
 * 转换二维数组
*/

#include <stdio.h>
#include <stdlib.h>

int** findMatrix(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int** result = (int**)malloc(sizeof(int*) * 201);
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(201 * sizeof(int));
    for (int i = 0; i < 201; i++) {
        result[i] = (int*)malloc(numsSize * sizeof(int));
        (*returnColumnSizes)[i] = 0;
    }
    int* hashTable = (int*)calloc(201, sizeof(int)); // 初始化为0
    for (int i = 0; i < numsSize; i++) {
        int j = hashTable[nums[i]]++;
        result[j][(*returnColumnSizes)[j]++] = nums[i]; // 放置数字
        * returnSize = j + 1 > * returnSize ? j + 1 : * returnSize;
    }
     // 释放多余的内存
    for (int i = 0; i < *returnSize; i++) {
        result[i] = (int*)realloc(result[i], (*returnColumnSizes)[i] * sizeof(int));
    }

    free(hashTable); // 释放哈希表
    return result;
}

int main () {
    int nums[] = {1, 3, 4, 1, 2, 3, 1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize = 0;
    int* returnColumnSizes;
    int** result = findMatrix(nums, numsSize, &returnSize, &returnColumnSizes);
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
        free(result[i]); // 释放每一行的内存
    }
    free(result);
    free(returnColumnSizes);

    return 0;
}