/*
 * @Author: LiNing
 * @Date: 2025-04-05
 * 找出所有子集的异或总和再求和
*/
#include <stdio.h>

int dfs(int val, int idx, int* nums, int numsSize) {
    if (idx == numsSize) {
        // 终止递归
        return val;
    }
    // 考虑选择当前数字, 考虑不选择当前数字
    return dfs(val ^ nums[idx], idx + 1, nums, numsSize) + dfs(val, idx + 1, nums, numsSize);
}

int subsetXORSum(int* nums, int numsSize) {
    return dfs(0, 0, nums, numsSize);
}

int main () {
    int nums[] = {3, 4, 5, 6, 7, 8};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int ret = subsetXORSum(nums, numsSize);
    printf("%d\n", ret);

    return 0;
}