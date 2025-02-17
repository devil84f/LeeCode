/*
 * @Author: LiNing
 * @Date: 2025-01-13 22:45:19
 * @LastEditors: LiNing
 * @LastEditTime: 2025-01-13 22:45:21
 * @FilePath: \LeeCode_Arrays\Remove_lement\LeeCode977\LeeCode977.c
 * @Description: 
 * Copyright (c) 2025 by ${git_name_email}, All Rights Reserved. 
 */
#include <stdio.h>
#include <stdlib.h>

int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int left = 0, right = numsSize - 1;
    *returnSize = numsSize;
    int* result = (int*)malloc(sizeof(int) * numsSize);

    int index = numsSize - 1; // 结果数组的指针从末尾开始
    while (left <= right) {
        if (abs(nums[left]) > abs(nums[right])) {
            result[index--] = nums[left] * nums[left];
            left++;
        } else {
            result[index--] = nums[right] * nums[right];
            right--;
        }
    }

    return result;
}

int main() {
    int nums[] = {-4, -1, 0, 3, 10};
    int returnSize;
    int* result = sortedSquares(nums, 5, &returnSize);

    printf("Result: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result); // 释放内存
    return 0;
}
