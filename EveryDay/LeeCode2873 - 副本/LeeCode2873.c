/*
 * @Author: LiNing
 * @Date: 2025-04-1
 * 最长回文子串
*/
#include <stdio.h>
#include <math.h>

long long maximumTripletValue(int* nums, int numsSize) {
    long long res = 0, imax = 0, dmax = 0;
    for (int k = 0; k < numsSize; k++) {
        res = fmax(res, dmax * nums[k]);
        dmax = fmax(dmax, imax - nums[k]);
        imax = fmax(imax, nums[k]);
    }
    return res;
}

int main () {
    int nums[] = {12, 6, 1, 2, 7};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    long long result = maximumTripletValue(nums, numsSize);
    printf("%d\n", result);

    return 0;
}
