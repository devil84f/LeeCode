/*
 * @Author: LiNing
 * @Date: 2025-01-08 00:03:12
 * @LastEditors: LiNing
 * @LastEditTime: 2025-01-08 23:35:42
 * @FilePath: \LeeCode_Arrays\LeeCode_Arrays\LeeCode704\LeeCode704.c
 * @Description: 
 * Copyright (c) 2025 by ${git_name_email}, All Rights Reserved. 
 */

#include <stdio.h>

int search(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    int middle = left + (right - left) / 2;

    while (left <= right) {  
        // ���middle�Ƿ�ΪĿ��ֵ
        if (nums[middle] == target) return middle;

        // middleС��target ˵��target��middle�ұ� �ƶ�left��middle�ұ�һλ
        // middle����target ˵��target��middle��� �ƶ�right��middle���һλ
        if (nums[middle] < target) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }

        // ����middleλ��
        middle = left + (right - left) / 2;
    }
    return -1;
}

int main () {
    int nums[] = {-1, 0, 3, 5, 9, 12};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 9;

    int result = search(nums, numsSize, target);

    if (result != -1) {
        printf("Target %d found at index %d\n", target, result);
    } else {
        printf("Target %d not found in the array.\n", target);
    }
    
    return 0;
}