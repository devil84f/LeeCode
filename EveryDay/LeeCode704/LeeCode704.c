/*
 * @Author: LiNing
 * @Date: 2025-04-22
 * 二分查找
*/
#include <stdio.h>

int search(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;
        if (nums[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int main() {
    // 测试用例1
    int nums1[] = {-1, 0, 3, 5, 9, 12};
    int target1 = 9;
    int expected1 = 4;
    int result1 = search(nums1, sizeof(nums1)/sizeof(nums1[0]), target1);
    printf("Test case 1: %s\n", result1 == expected1 ? "Passed" : "Failed");
    printf("Expected: %d, Result: %d\n\n", expected1, result1);

    // 测试用例2
    int nums2[] = {-1, 0, 3, 5, 9, 12};
    int target2 = 2;
    int expected2 = -1;
    int result2 = search(nums2, sizeof(nums2)/sizeof(nums2[0]), target2);
    printf("Test case 2: %s\n", result2 == expected2 ? "Passed" : "Failed");
    printf("Expected: %d, Result: %d\n\n", expected2, result2);

    // 测试用例3 (空数组)
    int nums3[] = {};
    int target3 = 0;
    int expected3 = -1;
    int result3 = search(nums3, sizeof(nums3)/sizeof(nums3[0]), target3);
    printf("Test case 3: %s\n", result3 == expected3 ? "Passed" : "Failed");
    printf("Expected: %d, Result: %d\n\n", expected3, result3);

    // 测试用例4 (单元素数组)
    int nums4[] = {5};
    int target4 = 5;
    int expected4 = 0;
    int result4 = search(nums4, sizeof(nums4)/sizeof(nums4[0]), target4);
    printf("Test case 4: %s\n", result4 == expected4 ? "Passed" : "Failed");
    printf("Expected: %d, Result: %d\n\n", expected4, result4);

    return 0;
}