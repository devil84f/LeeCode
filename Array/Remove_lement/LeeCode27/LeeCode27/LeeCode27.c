/*
 * @Author: LiNing
 * @Date: 2025-01-09 00:10:37
 * @LastEditors: LiNing
 * @LastEditTime: 2025-01-10 00:38:39
 * @FilePath: \LeeCode_Arrays\Remove_lement\LeeCode27\LeeCode27.c
 * @Description: 
 * Copyright (c) 2025 by ${git_name_email}, All Rights Reserved. 
 */

#include <stdio.h>

/**
 * 移除元素
 * @param nums: 输入的数组
 * @param numsSize: 数组的大小
 * @param val: 要移除的目标元素
 * @return: 移除元素后的新数组长度
 */
int removeElement(int* nums, int numsSize, int val) {
    int slow = 0; // j 是新数组的指针，记录移除元素后的数组长度
    for (int fast = 0; fast < numsSize; fast++) {
        if (nums[fast] != val) {  // 如果当前元素不是目标元素 val
            nums[slow] = nums[fast];  // 将当前元素移到数组前面
            slow++;                // 新数组的长度加一
        }
    }
    return slow;  // 返回新数组的长度
}

int main() {
    // 测试用例
    int nums1[] = {3, 2, 2, 3};
    int nums2[] = {0, 1, 2, 2, 3, 0, 4, 2};
    int val1 = 3;
    int val2 = 2;
    
    int len1 = removeElement(nums1, sizeof(nums1) / sizeof(nums1[0]), val1);
    int len2 = removeElement(nums2, sizeof(nums2) / sizeof(nums2[0]), val2);
    
    // 输出测试结果
    printf("New length of nums1: %d\n", len1);
    printf("Modified nums1: ");
    for (int i = 0; i < len1; i++) {
        printf("%d ", nums1[i]);
    }
    printf("\n");

    printf("New length of nums2: %d\n", len2);
    printf("Modified nums2: ");
    for (int i = 0; i < len2; i++) {
        printf("%d ", nums2[i]);
    }
    printf("\n");

    return 0;
}
