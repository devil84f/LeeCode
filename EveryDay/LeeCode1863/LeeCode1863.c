/*
 * @Author: LiNing
 * @Date: 2025-04-05
 * �ҳ������Ӽ�������ܺ������
*/
#include <stdio.h>

int dfs(int val, int idx, int* nums, int numsSize) {
    if (idx == numsSize) {
        // ��ֹ�ݹ�
        return val;
    }
    // ����ѡ��ǰ����, ���ǲ�ѡ��ǰ����
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