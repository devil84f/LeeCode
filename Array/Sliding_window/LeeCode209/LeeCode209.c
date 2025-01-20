/*
 * @Author: LiNing
 * @Date: 2025-01-13 22:51:32
 * @LastEditors: LiNing
 * @LastEditTime: 2025-01-13 23:03:30
 * @FilePath: \LeeCode_Arrays\Sliding_window\LeeCode209\LeeCode209.c
 * @Description: 
 * Copyright (c) 2025 by ${git_name_email}, All Rights Reserved. 
 */
#include <stdio.h>
#include <stdlib.h>

int minSubArrayLen(int target, int* nums, int numsSize) {
    int left = 0, sum = 0, minLength = numsSize + 1;

    for (int right = 0; right < numsSize; right++) {
        sum += nums[right];

        // 当窗口和大于等于 target 时，尝试缩小窗口
        while (sum >= target) {
            minLength = (right - left + 1) < minLength ? (right - left + 1) : minLength;
            sum -= nums[left++];
        }
    }

    // 如果找到的最小长度大于数组长度，说明没有符合条件的子数组
    return minLength == numsSize + 1 ? 0 : minLength;
}

int main() {
    int nums[] = {2, 3, 1, 2, 4, 3};
    int target = 7;
    int result = minSubArrayLen(target, nums, 6);
    printf("最小长度为：%d\n", result);  // 输出：2

    return 0;
}
