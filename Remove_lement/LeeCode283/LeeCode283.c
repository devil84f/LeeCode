/*
 * @Author: LiNing
 * @Date: 2025-01-11 15:17:21
 * @LastEditors: LiNing
 * @LastEditTime: 2025-01-11 15:52:28
 * @FilePath: \LeeCode_Arrays\Remove_lement\LeeCode283\LeeCode283.c
 * @Description: 
 * Copyright (c) 2025 by ${git_name_email}, All Rights Reserved. 
 */
#include <stdio.h>

/**
 * 移动零
 * @param nums: 输入数组
 * @param numsSize: 数组的大小
 */
void moveZeroes(int* nums, int numsSize) {
    int i = 0; // i 指向非零元素要存储的位置
    for (int j = 0; j < numsSize; j++) {
        if (nums[j] != 0) {  // 如果找到非零元素
            nums[i] = nums[j]; // 将非零元素移动到索引 i 的位置
            i++;               // 更新 i 的位置
        }
    }
    for (; i < numsSize; i++) {
        nums[i] = 0; // 将剩余的位置填充为 0
    }
}

int main() {
    int nums1[] = {0, 1, 0, 3, 12};
    int nums2[] = {0, 0, 1};

    moveZeroes(nums1, 5);
    moveZeroes(nums2, 3);

    printf("Test Case 1: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", nums1[i]);
    }
    printf("\n");

    printf("Test Case 2: ");
    for (int i = 0; i < 3; i++) {
        printf("%d ", nums2[i]);
    }
    printf("\n");

    return 0;
}
