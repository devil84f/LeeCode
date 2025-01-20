/*
 * @Author: LiNing
 * @Date: 2025-01-09 00:10:37
 * @LastEditors: LiNing
 * @LastEditTime: 2025-01-09 00:13:46
 * @FilePath: \LeeCode_Arrays\LeeCode_Arrays\LeeCode34\LeeCode34.c
 * @Description: 
 * Copyright (c) 2025 by ${git_name_email}, All Rights Reserved. 
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * searchRange 函数用于在已排序的数组中找到目标值的起始和结束位置。
 * 如果目标值不存在，则返回 [-1, -1]。
 * 
 * @param nums: 排序后的整数数组。
 * @param numsSize: 数组的大小。
 * @param target: 要查找的目标值。
 * @param returnSize: 返回数组的大小，固定为2，表示包含目标值的范围。
 * @return: 一个包含目标值范围的数组，范围为 [left, right]，如果目标值不存在返回 [-1, -1]。
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    // 设置返回数组的大小为2，表示结果为目标值的起始和结束位置
    *returnSize = 2;

    // 动态分配结果数组，用于存储目标值的起始和结束位置
    int* result = (int*)malloc(sizeof(int) * 2);
    
    // 检查内存分配是否成功
    if (result == NULL) {
        *returnSize = 0;  // 如果内存分配失败，返回0大小的数组
        return NULL;
    }

    // 初始化结果数组，默认值为 [-1, -1]
    result[0] = -1;
    result[1] = -1;

    // 如果数组为空或目标值不在数组的范围内，直接返回 [-1, -1]
    if (numsSize == 0 || nums[0] > target || nums[numsSize - 1] < target) {
        return result;
    }

    int left = 0;            // 左指针
    int right = numsSize - 1;  // 右指针
    int middle = 0;          // 中间指针

    // 二分查找目标值的位置
    while (left <= right) {
        middle = left + (right - left) / 2;  // 计算中间位置，避免溢出
        if (nums[middle] == target) {  // 找到目标值
            // 找到目标值后，向左和向右扩展，找到最左和最右的目标值
            int m_left = middle;
            int m_right = middle;

            // 向右扩展，直到不再等于目标值
            while ((m_right + 1) < numsSize && nums[m_right + 1] == target) {
                m_right += 1;
            }

            // 向左扩展，直到不再等于目标值
            while ((m_left - 1) >= 0 && nums[m_left - 1] == target) {
                m_left -= 1;
            }

            // 设置结果数组，返回最左和最右位置
            result[0] = m_left;
            result[1] = m_right;
            return result;
        }

        // 根据中间值与目标值的大小关系调整左右指针
        if (nums[middle] > target) {
            right = middle - 1;  // 如果目标值小于中间值，右指针左移
        } else {
            left = middle + 1;  // 如果目标值大于中间值，左指针右移
        }
    }

    // 如果没有找到目标值，返回 [-1, -1]
    return result;
}

int main() {
    // 示例数组和目标值
    int nums[] = {5, 7, 7, 8, 8, 10};
    int target = 8;
    int returnSize;
    
    // 调用 searchRange 函数
    int* result = searchRange(nums, sizeof(nums) / sizeof(nums[0]), target, &returnSize);

    // 输出结果
    if (result != NULL) {
        printf("Range: [%d, %d]\n", result[0], result[1]);
        free(result);  // 记得释放动态分配的内存
    } else {
        printf("Target not found.\n");
    }

    return 0;
}
