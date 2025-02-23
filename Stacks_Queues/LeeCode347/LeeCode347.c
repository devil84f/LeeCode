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

// ����ṹ�壬���ڴ洢Ԫ�ؼ���Ƶ��
typedef struct {
    int num;
    int freq;
} NumFreq;

// �ȽϺ�������������
int compare(const void *a, const void *b) {
    return ((NumFreq *)b)->freq - ((NumFreq *)a)->freq;
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    // ���������е�Ԫ�ط�Χ�� -10000 �� 10000 ֮��
    int hash[20001] = {0}; // ��ϣ������ͳ��Ƶ��
    int i, j;

    // ͳ��Ƶ��
    for (i = 0; i < numsSize; i++) {
        hash[nums[i] + 10000]++;
    }

    // ����ϣ���е�Ԫ�غ�Ƶ����ȡ���ṹ��������
    NumFreq *numFreqArray = (NumFreq *)malloc(numsSize * sizeof(NumFreq));
    int count = 0;
    for (i = 0; i < 20001; i++) {
        if (hash[i] > 0) {
            numFreqArray[count].num = i - 10000;
            numFreqArray[count].freq = hash[i];
            count++;
        }
    }

    // �Խṹ�����鰴��Ƶ�ʽ�������
    qsort(numFreqArray, count, sizeof(NumFreq), compare);

    // ��ȡǰ k ��Ԫ��
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