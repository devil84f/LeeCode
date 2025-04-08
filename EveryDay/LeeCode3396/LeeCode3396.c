/*
 * @Author: LiNing
 * @Date: 2025-04-08
 * ʹ����Ԫ�ػ�����ͬ��������ٲ�������
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
    printf("%d\n", minimumOperations(nums1, 5)); // ���0�����������
    
    int nums2[] = {1,2,3,1,2,3};
    printf("%d\n", minimumOperations(nums2, 6)); // ���1���Ƴ�ǰ3����
    
    int nums3[] = {1,1,1,2,2,2,3,3,3};
    printf("%d\n", minimumOperations(nums3, 9)); // ���3��ÿ���Ƴ�3����
    
    int nums4[] = {1,1,1,1};
    printf("%d\n", minimumOperations(nums4, 4)); // ���2���Ƴ�ǰ3����ʣ�µ�1����
    
    return 0;
}