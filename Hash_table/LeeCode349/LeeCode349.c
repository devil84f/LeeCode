/*
 * @Author: LiNing
 * @Date: 2025-01-27 01:01:20
 * @LastEditors: LiNing
 * @LastEditTime: 2025-01-27 01:01:22
 * @FilePath: \LeeCode_Modularization\Hash_table\LeeCode349\LeeCode349.c
 * @Description: 
 * Copyright (c) 2025 by ${git_name_email}, All Rights Reserved. 
 */

#include <stdio.h>
#include <stdlib.h>

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    // 创建一个大小为1001的数组，用于记录nums1中元素的出现次数
    int nums1Cnt[1001] = {0};
    
    // 确定结果数组的大小，取两个数组中较小的一个
    int lessSize = nums1Size < nums2Size ? nums1Size : nums2Size;
    
    // 动态分配结果数组的内存，初始化为0
    int * result = (int *) calloc(lessSize, sizeof(int));
    
    // 结果数组的索引
    int resultIndex = 0;

    // 遍历nums1数组，记录每个元素的出现次数
    for(int i = 0; i < nums1Size; i ++) {
        nums1Cnt[nums1[i]]++;
    }

    // 遍历nums2数组，检查元素是否在nums1Cnt中出现过
    for(int i = 0; i < nums2Size; i ++) {
        if(nums1Cnt[nums2[i]] > 0) {
            // 如果出现过，则将其加入结果数组
            result[resultIndex++] = nums2[i];
            // 并将该元素在nums1Cnt中的计数置为0，避免重复加入
            nums1Cnt[nums2[i]] = 0;
        }
    }
    
    // 设置返回结果数组的大小
    *returnSize = resultIndex;
    
    // 返回结果数组
    return result;
}

// 测试主函数
int main() {
    int nums1[] = {1, 2, 2, 1, 3};
    int nums2[] = {2, 2, 3};
    int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
    int nums2Size = sizeof(nums2) / sizeof(nums2[0]);
    int returnSize;
    
    int* result = intersection(nums1, nums1Size, nums2, nums2Size, &returnSize);
    
    printf("Intersection: ");
    for(int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    
    // 释放动态分配的内存
    free(result);
    
    return 0;
}