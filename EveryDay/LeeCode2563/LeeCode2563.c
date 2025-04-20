/*
 * @Author: LiNing
 * @Date: 2025-04-20
 * 统计公平数对的数目
*/
#include <stdio.h>
#include <stdlib.h>

// 比较函数（用于排序）
int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

long long countFairPairs(int* nums, int numsSize, int lower, int upper) {
    qsort(nums, numsSize, sizeof(int), cmp); // 排序
    long long count = 0;

    for (int i = 0; i < numsSize; i++) {
        // 二分查找左边界：nums[i] + nums[j] >= lower
        int left = i + 1, right = numsSize - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[i] + nums[mid] >= lower) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        int lower_bound = left;

        // 二分查找右边界：nums[i] + nums[j] <= upper
        left = i + 1, right = numsSize - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[i] + nums[mid] <= upper) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        int upper_bound = right;

        // 统计有效数对
        if (lower_bound <= upper_bound) {
            count += (upper_bound - lower_bound + 1);
        }
    }

    return count;
}

// 测试主函数
int main() {
    int nums1[] = {0, 1, 7, 4, 4, 5};
    int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
    int lower1 = 3, upper1 = 6;
    printf("Test Case 1: %lld\n", countFairPairs(nums1, numsSize1, lower1, upper1)); // 输出 6

    int nums2[] = {1, 7, 9, 2, 5};
    int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);
    int lower2 = 11, upper2 = 11;
    printf("Test Case 2: %lld\n", countFairPairs(nums2, numsSize2, lower2, upper2)); // 输出 1

    return 0;
}