/*
 * @Author: LiNing
 * @Date: 2025-02-23 23:22:57
 * @LastEditors: LiNing
 * @LastEditTime: 2025-02-23 23:28:11
 * @FilePath: \LeeCode_Modularization\Stacks_Queues\LeeCode347\LeeCode347.c
 * @Description: 
 * Copyright (c) 2025 by ${git_name_email}, All Rights Reserved. 
 */

#include <stdio.h>
#include <stdlib.h>

// 定义结构体，用于存储元素及其频率
typedef struct {
    int num;
    int freq;
} NumFreq;

// 比较函数，用于排序
int compare(const void *a, const void *b) {
    return ((NumFreq *)b)->freq - ((NumFreq *)a)->freq;
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    // 假设数组中的元素范围在 -10000 到 10000 之间
    int hash[20001] = {0}; // 哈希表，用于统计频率
    int i, j;

    // 统计频率
    for (i = 0; i < numsSize; i++) {
        hash[nums[i] + 10000]++;
    }

    // 将哈希表中的元素和频率提取到结构体数组中
    NumFreq *numFreqArray = (NumFreq *)malloc(numsSize * sizeof(NumFreq));
    int count = 0;
    for (i = 0; i < 20001; i++) {
        if (hash[i] > 0) {
            numFreqArray[count].num = i - 10000;
            numFreqArray[count].freq = hash[i];
            count++;
        }
    }

    // 对结构体数组按照频率进行排序
    qsort(numFreqArray, count, sizeof(NumFreq), compare);

    // 提取前 k 个元素
    int *result = (int *)malloc(k * sizeof(int));
    for (i = 0; i < k; i++) {
        result[i] = numFreqArray[i].num;
    }

    *returnSize = k;
    free(numFreqArray);
    return result;
}

int main() {
    int nums[] = {1, 1, 1, 2, 2, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 2;
    int returnSize;
    int *result = topKFrequent(nums, numsSize, k, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}