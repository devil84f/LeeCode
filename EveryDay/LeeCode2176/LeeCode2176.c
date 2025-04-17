/*
 * @Author: LiNing
 * @Date: 2025-04-17
 * 统计数组中相等且可以被整除的数对
*/
#include <stdio.h>

int countPairs(int* nums, int numsSize, int k) {
    int res = 0;
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] == nums[j] && (i * j) % k == 0) res++;
        }
    }
    return res;
}

int main() {
    // 测试用例1
    int nums1[] = {3, 1, 2, 2, 2, 1, 3};
    int k1 = 2;
    int expected1 = 4;
    int result1 = countPairs(nums1, sizeof(nums1)/sizeof(nums1[0]), k1);
    printf("Test case 1: %s\n", result1 == expected1 ? "Passed" : "Failed");
    printf("Expected: %d, Result: %d\n\n", expected1, result1);

    // 测试用例2
    int nums2[] = {1, 2, 3, 4};
    int k2 = 1;
    int expected2 = 0;
    int result2 = countPairs(nums2, sizeof(nums2)/sizeof(nums2[0]), k2);
    printf("Test case 2: %s\n", result2 == expected2 ? "Passed" : "Failed");
    printf("Expected: %d, Result: %d\n\n", expected2, result2);

    // 测试用例3
    int nums3[] = {5, 5, 5, 5, 5};
    int k3 = 5;
    int expected3 = 4;
    int result3 = countPairs(nums3, sizeof(nums3)/sizeof(nums3[0]), k3);
    printf("Test case 3: %s\n", result3 == expected3 ? "Passed" : "Failed");
    printf("Expected: %d, Result: %d\n\n", expected3, result3);

    // 测试用例4 (边界情况)
    int nums4[] = {1};
    int k4 = 1;
    int expected4 = 0;
    int result4 = countPairs(nums4, sizeof(nums4)/sizeof(nums4[0]), k4);
    printf("Test case 4: %s\n", result4 == expected4 ? "Passed" : "Failed");
    printf("Expected: %d, Result: %d\n\n", expected4, result4);

    return 0;
}