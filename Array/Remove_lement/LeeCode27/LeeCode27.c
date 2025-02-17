/*
 * @Author: LiNing
 * @Date: 2025-01-09 00:10:37
 * @LastEditors: LiNing
 * @LastEditTime: 2025-01-10 00:38:39
 * @FilePath: \LeeCode_Arrays\Remove_lement\LeeCode27\LeeCode27.c
 * @Description: 
 * Copyright (c) 2025 by ${git_name_email}, All Rights Reserved. 
 */

#include <stdio.h>

/**
 * �Ƴ�Ԫ��
 * @param nums: ���������
 * @param numsSize: ����Ĵ�С
 * @param val: Ҫ�Ƴ���Ŀ��Ԫ��
 * @return: �Ƴ�Ԫ�غ�������鳤��
 */
int removeElement(int* nums, int numsSize, int val) {
    int slow = 0; // j ���������ָ�룬��¼�Ƴ�Ԫ�غ�����鳤��
    for (int fast = 0; fast < numsSize; fast++) {
        if (nums[fast] != val) {  // �����ǰԪ�ز���Ŀ��Ԫ�� val
            nums[slow] = nums[fast];  // ����ǰԪ���Ƶ�����ǰ��
            slow++;                // ������ĳ��ȼ�һ
        }
    }
    return slow;  // ����������ĳ���
}

int main() {
    // ��������
    int nums1[] = {3, 2, 2, 3};
    int nums2[] = {0, 1, 2, 2, 3, 0, 4, 2};
    int val1 = 3;
    int val2 = 2;
    
    int len1 = removeElement(nums1, sizeof(nums1) / sizeof(nums1[0]), val1);
    int len2 = removeElement(nums2, sizeof(nums2) / sizeof(nums2[0]), val2);
    
    // ������Խ��
    printf("New length of nums1: %d\n", len1);
    printf("Modified nums1: ");
    for (int i = 0; i < len1; i++) {
        printf("%d ", nums1[i]);
    }
    printf("\n");

    printf("New length of nums2: %d\n", len2);
    printf("Modified nums2: ");
    for (int i = 0; i < len2; i++) {
        printf("%d ", nums2[i]);
    }
    printf("\n");

    return 0;
}
