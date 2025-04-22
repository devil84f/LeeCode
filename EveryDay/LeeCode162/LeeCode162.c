/*
 * @Author: LiNing
 * @Date: 2025-04-22
 * 寻找峰值
*/
#include <stdio.h>

int findPeakElement(int* nums, int numsSize) {
    int left = 0;
    int right = numsSize - 1;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] > nums[mid + 1]) {
            // 峰值在左侧或mid本身就是峰值
            right = mid;
        } else {
            // 峰值在右侧
            left = mid + 1;
        }
    }
    
    return left;
}

int main() {
    // 测试用例1
    int nums1[] = {1,2,3,1};
    int expected1 = 2;
    int result1 = findPeakElement(nums1, sizeof(nums1)/sizeof(nums1[0]));
    printf("Test case 1: %s\n", result1 == expected1 ? "Passed" : "Failed");
    printf("Expected: %d, Result: %d\n\n", expected1, result1);

    // 测试用例2
    int nums2[] = {1,2,1,3,5,6,4};
    int expected2 = 1; // 可以返回1或5
    int result2 = findPeakElement(nums2, sizeof(nums2)/sizeof(nums2[0]));
    printf("Test case 2: %s\n", (result2 == 1 || result2 == 5) ? "Passed" : "Failed");
    printf("Expected: 1 or 5, Result: %d\n\n", result2);

    // 测试用例3 (单元素数组)
    int nums3[] = {5};
    int expected3 = 0;
    int result3 = findPeakElement(nums3, sizeof(nums3)/sizeof(nums3[0]));
    printf("Test case 3: %s\n", result3 == expected3 ? "Passed" : "Failed");
    printf("Expected: %d, Result: %d\n\n", expected3, result3);

    // 测试用例4 (严格递增数组)
    int nums4[] = {1,2,3,4,5};
    int expected4 = 4;
    int result4 = findPeakElement(nums4, sizeof(nums4)/sizeof(nums4[0]));
    printf("Test case 4: %s\n", result4 == expected4 ? "Passed" : "Failed");
    printf("Expected: %d, Result: %d\n\n", expected4, result4);

    // 测试用例5 (严格递减数组)
    int nums5[] = {5,4,3,2,1};
    int expected5 = 0;
    int result5 = findPeakElement(nums5, sizeof(nums5)/sizeof(nums5[0]));
    printf("Test case 5: %s\n", result5 == expected5 ? "Passed" : "Failed");
    printf("Expected: %d, Result: %d\n\n", expected5, result5);

    return 0;
}