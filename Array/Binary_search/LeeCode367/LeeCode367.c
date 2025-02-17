/*
 * @Author: LiNing
 * @Date: 2025-01-10 00:06:14
 * @LastEditors: LiNing
 * @LastEditTime: 2025-01-10 00:06:15
 * @FilePath: \LeeCode_Arrays\LeeCode_Arrays\LeeCode367\LeeCode367.c
 * @Description: 
 * Copyright (c) 2025 by ${git_name_email}, All Rights Reserved. 
 */
#include <stdio.h>
#include <stdbool.h>

/**
 * 判断一个数是否是完全平方数
 * @param num: 要判断的整数
 * @return: 如果 num 是完全平方数，则返回 true，否则返回 false
 */
bool isPerfectSquare(int num) {
    // 特殊情况：0 和 1 是完全平方数
    if (num == 0 || num == 1) {
        return true;
    }

    // 设置二分查找的左右边界
    int left = 1, right = num / 2;
    
    // 使用二分查找
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int mid_square = mid * mid;

        // 判断 mid 的平方是否等于 num
        if (mid_square == num) {
            return true;  // 如果找到了完全平方数，返回 true
        } 
        // 如果 mid 的平方小于 num，说明平方根在右半部分
        else if (mid_square < num) {
            left = mid + 1;
        } 
        // 如果 mid 的平方大于 num，说明平方根在左半部分
        else {
            right = mid - 1;
        }
    }

    // 如果没有找到完全平方数，返回 false
    return false;
}

int main() {
    // 测试用例
    int test_cases[] = {16, 14, 25, 30, 1, 0, 144};
    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

    for (int i = 0; i < num_tests; i++) {
        int num = test_cases[i];
        if (isPerfectSquare(num)) {
            printf("%d is a perfect square.\n", num);
        } else {
            printf("%d is not a perfect square.\n", num);
        }
    }

    return 0;
}
