/*
 * @Author: LiNing
 * @Date: 2025-04-09
 * ʹ�����ֵȫ��Ϊ K �����ٲ�������
*/
#include <stdio.h>
#include <stdlib.h>

int minOperations(int* nums, int numsSize, int k) {
    int* hasTable = (int*)calloc(101, sizeof(int));
    int ret = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < k) return -1;
        if ((nums[i] != k) && (hasTable[nums[i]] == 0)) {
            hasTable[nums[i]]++;
            ret++;
        }
    }
    free(hasTable);
    return ret;
}

int main() {
    int nums[] = {5, 2, 5, 4, 5};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 2;
    int ret = minOperations(nums, numsSize, k);
    printf("%d\n", ret);

    return 0;
}