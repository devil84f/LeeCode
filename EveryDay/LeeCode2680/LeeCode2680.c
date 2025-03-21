/*
 * @Author: LiNing
 * @Date: 2025-03-21
 * 最大或值
 * 前缀和  后缀和
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long maximumOr(int *nums, int numsSize, int k) {
    long long *suf = (long long *)malloc((numsSize + 1) * sizeof(long long));
    suf[numsSize] = 0;

    for (int i = numsSize - 1; i >= 0; i--) {
        suf[i] = suf[i + 1] | nums[i];
    }

    long long res = 0;
    long long pre = 0;
    for (int i = 0; i < numsSize; i++) {
        res = fmax(res, pre | ((long long)nums[i] << k) | suf[i + 1]);
        pre |= nums[i];
    }
    free(suf);
    return res;
}

int main () {
    int nums[] = {8, 1, 2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 2;

    long long result = maximumOr(nums, numsSize, k);
    printf("%d\n", result);
    return 0;
}