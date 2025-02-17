/*
 * @Author: LiNing
 * @Date: 2025-01-10 00:58:35
 * @LastEditors: LiNing
 * @LastEditTime: 2025-01-10 01:00:03
 * @FilePath: \LeeCode_Arrays\Remove_lement\LeeCode27\LeeCode26\LeeCode26.c
 * @Description: 
 * Copyright (c) 2025 by ${git_name_email}, All Rights Reserved. 
 */
#include <stdio.h>

/**
 * ɾ�����������е��ظ���
 * @param nums: ���������
 * @param numsSize: ����Ĵ�С
 * @return: ȥ�غ�����鳤��
 */
int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) {
        return 0;  // �������Ϊ�գ����س��� 0
    }

    int j = 1;  // j ���ڼ�¼ȥ�غ������λ��
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[i - 1]) {  // �����ǰԪ����ǰһ��Ԫ�ز�ͬ
            nums[j] = nums[i];          // ����ǰԪ���Ƶ��������λ��
            j++;                        // ������ĳ��ȼ�һ
        }
    }

    return j;  // ����ȥ�غ�����ĳ���
}

int main() {
    // ��������
    int nums1[] = {1, 1, 2};
    int nums2[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    
    int len1 = removeDuplicates(nums1, sizeof(nums1) / sizeof(nums1[0]));
    int len2 = removeDuplicates(nums2, sizeof(nums2) / sizeof(nums2[0]));
    
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
