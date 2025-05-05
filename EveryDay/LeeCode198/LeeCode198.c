/*
 * @Author: LiNing
 * @Date: 2025-05-05
 * 打家劫舍
*/

#include <stdio.h>

// 求最大值函数
int max(int a, int b) {
    return (a > b) ? a : b;
}

int rob(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    if (numsSize == 1) return nums[0];
    
    int dp[numsSize];
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    
    for (int i = 2; i < numsSize; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }
    
    return dp[numsSize - 1];
}

// 示例测试
int main() {
    int nums[] = {2, 7, 9, 3, 1};
    int size = sizeof(nums) / sizeof(nums[0]);
    int result = rob(nums, size);
    printf("最大可偷金额为：%d\n", result);
    return 0;
}
