/*
 * @Author: LiNing
 * @Date: 2025-01-10 00:58:35
 * @LastEditors: LiNing
 * @LastEditTime: 2025-01-10 01:00:03
 * @FilePath: \LeeCode_Arrays\Remove_lement\LeeCode27\LeeCode26\LeeCode26.c
 * @Description: 
 * Copyright (c) 2025 by ${git_name_email}, All Rights Reserved. 
 */
#include <stdio.h>

/**
 * 删除排序数组中的重复项
 * @param nums: 输入的数组
 * @param numsSize: 数组的大小
 * @return: 去重后的数组长度
 */
int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) {
        return 0;  // 如果数组为空，返回长度 0
    }

    int j = 1;  // j 用于记录去重后数组的位置
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[i - 1]) {  // 如果当前元素与前一个元素不同
            nums[j] = nums[i];          // 将当前元素移到新数组的位置
            j++;                        // 新数组的长度加一
        }
    }

    return j;  // 返回去重后数组的长度
}

int main() {
    // 测试用例
    int nums1[] = {1, 1, 2};
    int nums2[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    
    int len1 = removeDuplicates(nums1, sizeof(nums1) / sizeof(nums1[0]));
    int len2 = removeDuplicates(nums2, sizeof(nums2) / sizeof(nums2[0]));
    
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
