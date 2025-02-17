/*
 * @Author: LiNing
 * @Date: 2025-01-11 15:17:21
 * @LastEditors: LiNing
 * @LastEditTime: 2025-01-11 15:52:28
 * @FilePath: \LeeCode_Arrays\Remove_lement\LeeCode283\LeeCode283.c
 * @Description: 
 * Copyright (c) 2025 by ${git_name_email}, All Rights Reserved. 
 */
#include <stdio.h>

/**
 * �ƶ���
 * @param nums: ��������
 * @param numsSize: ����Ĵ�С
 */
void moveZeroes(int* nums, int numsSize) {
    int i = 0; // i ָ�����Ԫ��Ҫ�洢��λ��
    for (int j = 0; j < numsSize; j++) {
        if (nums[j] != 0) {  // ����ҵ�����Ԫ��
            nums[i] = nums[j]; // ������Ԫ���ƶ������� i ��λ��
            i++;               // ���� i ��λ��
        }
    }
    for (; i < numsSize; i++) {
        nums[i] = 0; // ��ʣ���λ�����Ϊ 0
    }
}

int main() {
    int nums1[] = {0, 1, 0, 3, 12};
    int nums2[] = {0, 0, 1};

    moveZeroes(nums1, 5);
    moveZeroes(nums2, 3);

    printf("Test Case 1: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", nums1[i]);
    }
    printf("\n");

    printf("Test Case 2: ");
    for (int i = 0; i < 3; i++) {
        printf("%d ", nums2[i]);
    }
    printf("\n");

    return 0;
}
