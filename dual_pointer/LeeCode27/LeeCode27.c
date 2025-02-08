/*
 * @Author: LiNing
 * @Date: 2025-02-06 00:38:08
 * @LastEditors: LiNing
 * @LastEditTime: 2025-02-08 16:07:21
 * @FilePath: \LeeCode_Modularization\dual_pointer\LeeCode27\LeeCode27.c
 * @Description: 
 * Copyright (c) 2025 by ${git_name_email}, All Rights Reserved. 
 */
#include <stdio.h>
#include <string.h>

int removeElement(int* nums, int numsSize, int val) {
    int slow = 0, fast = 0;
    int result = numsSize;

    for (int i = 0; i < numsSize; i++) {
        if (nums[fast] == val) {
            fast++;
            result--;
            continue;
        }
        nums[slow++] = nums[fast++];
    }
    return result;
}

// ²âÊÔÖ÷º¯Êý
int main() {
    int nums[] = {3, 2, 2, 3};
    int val = 2;
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    
    int result = removeElement(nums, numsSize, val);
    printf("%d\n", numsSize);
    
    for (int i = 0; i < result; i++) {
        printf("%d ", nums[i]);
    }
    return 0;
}