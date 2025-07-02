#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000 // 假设数组最大长度

int findMaxK(int* nums, int numsSize) {
    bool hash[2001] = {false}; // -1000到1000映射到0-2000
    int max_k = -1;
    
    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        hash[num + 1000] = true; // 将-1000映射到0，1000映射到2000
        
        // 如果当前数是正数且它的负数存在
        if (num > 0 && hash[-num + 1000]) {
            if (num > max_k) {
                max_k = num;
            }
        }
        // 如果当前数是负数且它的正数存在
        else if (num < 0 && hash[-num + 1000]) {
            int positive = -num;
            if (positive > max_k) {
                max_k = positive;
            }
        }
    }
    
    return max_k;
}

int main() {
    // 测试用例1
    int nums1[] = {-1, 2, -3, 3};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Test case 1: %d\n", findMaxK(nums1, size1)); // 应输出3
    
    // 测试用例2
    int nums2[] = {-1, 10, 6, 7, -7, 1};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Test case 2: %d\n", findMaxK(nums2, size2)); // 应输出7
    
    // 测试用例3
    int nums3[] = {-10, 8, 6, 7, -2, -3};
    int size3 = sizeof(nums3) / sizeof(nums3[0]);
    printf("Test case 3: %d\n", findMaxK(nums3, size3)); // 应输出-1
    
    // 测试用例4
    int nums4[] = {1, -1};
    int size4 = sizeof(nums4) / sizeof(nums4[0]);
    printf("Test case 4: %d\n", findMaxK(nums4, size4)); // 应输出1
    
    // 测试用例5
    int nums5[] = {1000, -1000};
    int size5 = sizeof(nums5) / sizeof(nums5[0]);
    printf("Test case 5: %d\n", findMaxK(nums5, size5)); // 应输出1000
    
    return 0;
}