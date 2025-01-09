/*
 * @Author: LiNing
 * @Date: 2025-01-09 23:40:38
 * @LastEditors: LiNing
 * @LastEditTime: 2025-01-10 00:00:39
 * @FilePath: \LeeCode_Arrays\LeeCode_Arrays\LeeCode69\LeeCode69.cc
 * @Description: 
 * Copyright (c) 2025 by ${git_name_email}, All Rights Reserved. 
 */
#include <stdio.h>

int mySqrt(int x) {
    if (x == 0 || x == 1) {
        return x;
    }

    int left = 0, right = x;
    int mid;
    
    while (left <= right) {
        mid = left + (right - left) / 2;

        // mid * mid == x, return mid
        if (mid * mid == x) {
            return mid;
        }
        // mid * mid < x, we need a larger mid
        else if (mid * mid < x) {
            left = mid + 1;
        }
        // mid * mid > x, we need a smaller mid
        else {
            right = mid - 1;
        }
    }

    // After loop, right is the largest value where right * right <= x
    return right;
}

int main() {
    // ²âÊÔÓÃÀý
    int test_cases[] = {0, 1, 4, 8, 16, 24, 25, 50, 99, 100, 121, 150};
    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

    for (int i = 0; i < num_tests; i++) {
        int x = test_cases[i];
        int result = mySqrt(x);
        printf("x = %d, sqrt(x) = %d\n", x, result);
    }

    return 0;
}
