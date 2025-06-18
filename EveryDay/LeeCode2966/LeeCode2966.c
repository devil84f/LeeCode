#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// �ȽϺ�������qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int partitionArray(int* nums, int numsSize, int k) {
    if (numsSize == 0) return 0;
    
    // �ȶ������������
    qsort(nums, numsSize, sizeof(int), compare);
    
    int count = 1;
    int min = nums[0];
    
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] - min > k) {
            count++;
            min = nums[i];
        }
    }
    
    return count;
}

// ����������
int main() {
    int nums1[] = {3, 6, 1, 2, 5};
    int k1 = 2;
    int result1 = partitionArray(nums1, 5, k1);
    printf("Test Case 1: %d\n", result1); // Ԥ�����: 2
    
    int nums2[] = {1, 2, 3, 4, 5};
    int k2 = 0;
    int result2 = partitionArray(nums2, 5, k2);
    printf("Test Case 2: %d\n", result2); // Ԥ�����: 5
    
    int nums3[] = {4,2,9,8,2,12,7,12,10,5,8,5,5,7,9,2,5,11};
    int k3 = 14;
    int result3 = partitionArray(nums3, 4, k3);
    printf("Test Case 3: %d\n", result3); // Ԥ�����: 3
    
    return 0;
}