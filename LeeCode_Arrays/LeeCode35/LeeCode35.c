/*
 * @Author: LiNing
 * @Date: 2025-01-08 23:13:18
 * @LastEditors: LiNing
 * @LastEditTime: 2025-01-08 23:36:37
 * @FilePath: \LeeCode_Arrays\LeeCode_Arrays\LeeCode35\LeeCode35.c
 * @Description: 
 * Copyright (c) 2025 by ${git_name_email}, All Rights Reserved. 
 */

#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target) {
    if (nums[0] > target) return 0;
    if (nums[numsSize - 1] < target) return numsSize;
    int result = 0;
    int left = 0;
    int right = numsSize - 1;
    int middle = 0;
    while (left <= right) {
        middle = left + (right - left) / 2;
        if (nums[middle] == target) return middle;
        if (nums[middle] > target) {
            right = middle - 1;
        } else if (nums[middle] < target) {
            left = middle + 1;
        }
    }
    // middle = left + (right - left) / 2; 
    // 1 / 2 = 0 所以最后停留在target左一位 
    return right + 1;
}

int main() {
    int nums1[] = {1, 3, 5, 6};
    int target1 = 5;
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Test case 1: %d\n", searchInsert(nums1, size1, target1));  // Expected output: 2

    int nums2[] = {1, 3, 5, 6};
    int target2 = 2;
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Test case 2: %d\n", searchInsert(nums2, size2, target2));  // Expected output: 1

    int nums3[] = {1, 3, 5, 6};
    int target3 = 7;
    int size3 = sizeof(nums3) / sizeof(nums3[0]);
    printf("Test case 3: %d\n", searchInsert(nums3, size3, target3));  // Expected output: 4

    int nums4[] = {1, 3, 5, 6};
    int target4 = 0;
    int size4 = sizeof(nums4) / sizeof(nums4[0]);
    printf("Test case 4: %d\n", searchInsert(nums4, size4, target4));  // Expected output: 0

    int nums5[] = {1};
    int target5 = 0;
    int size5 = sizeof(nums5) / sizeof(nums5[0]);
    printf("Test case 5: %d\n", searchInsert(nums5, size5, target5));  // Expected output: 0

    return 0;
}
