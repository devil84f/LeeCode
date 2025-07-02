#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000 // ����������󳤶�

int findMaxK(int* nums, int numsSize) {
    bool hash[2001] = {false}; // -1000��1000ӳ�䵽0-2000
    int max_k = -1;
    
    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        hash[num + 1000] = true; // ��-1000ӳ�䵽0��1000ӳ�䵽2000
        
        // �����ǰ�������������ĸ�������
        if (num > 0 && hash[-num + 1000]) {
            if (num > max_k) {
                max_k = num;
            }
        }
        // �����ǰ���Ǹ�����������������
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
    // ��������1
    int nums1[] = {-1, 2, -3, 3};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Test case 1: %d\n", findMaxK(nums1, size1)); // Ӧ���3
    
    // ��������2
    int nums2[] = {-1, 10, 6, 7, -7, 1};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Test case 2: %d\n", findMaxK(nums2, size2)); // Ӧ���7
    
    // ��������3
    int nums3[] = {-10, 8, 6, 7, -2, -3};
    int size3 = sizeof(nums3) / sizeof(nums3[0]);
    printf("Test case 3: %d\n", findMaxK(nums3, size3)); // Ӧ���-1
    
    // ��������4
    int nums4[] = {1, -1};
    int size4 = sizeof(nums4) / sizeof(nums4[0]);
    printf("Test case 4: %d\n", findMaxK(nums4, size4)); // Ӧ���1
    
    // ��������5
    int nums5[] = {1000, -1000};
    int size5 = sizeof(nums5) / sizeof(nums5[0]);
    printf("Test case 5: %d\n", findMaxK(nums5, size5)); // Ӧ���1000
    
    return 0;
}