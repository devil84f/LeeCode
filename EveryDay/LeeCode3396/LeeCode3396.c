/*
 * @Author: LiNing
 * @Date: 2025-04-08
 * 使数组元素互不相同所需的最少操作次数
*/
#include <stdio.h>
#include <stdbool.h>

int minimumOperations(int* nums, int numsSize) {
    int seen[128] = {0};
    for (int i = numsSize - 1; i >= 0; i--) {
        if (seen[nums[i]]) {
            return i / 3 + 1;
        }
        seen[nums[i]] = true;
    }
    return 0;
}

int main() {
    int nums1[] = {1,2,3,4,5};
    printf("%d\n", minimumOperations(nums1, 5)); // 输出0（无需操作）
    
    int nums2[] = {1,2,3,1,2,3};
    printf("%d\n", minimumOperations(nums2, 6)); // 输出1（移除前3个）
    
    int nums3[] = {1,1,1,2,2,2,3,3,3};
    printf("%d\n", minimumOperations(nums3, 9)); // 输出3（每次移除3个）
    
    int nums4[] = {1,1,1,1};
    printf("%d\n", minimumOperations(nums4, 4)); // 输出2（移除前3个和剩下的1个）
    
    return 0;
}