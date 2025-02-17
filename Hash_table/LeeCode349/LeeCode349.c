/*
 * @Author: LiNing
 * @Date: 2025-01-27 01:01:20
 * @LastEditors: LiNing
 * @LastEditTime: 2025-01-27 01:01:22
 * @FilePath: \LeeCode_Modularization\Hash_table\LeeCode349\LeeCode349.c
 * @Description: 
 * Copyright (c) 2025 by ${git_name_email}, All Rights Reserved. 
 */

#include <stdio.h>
#include <stdlib.h>

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    // ����һ����СΪ1001�����飬���ڼ�¼nums1��Ԫ�صĳ��ִ���
    int nums1Cnt[1001] = {0};
    
    // ȷ���������Ĵ�С��ȡ���������н�С��һ��
    int lessSize = nums1Size < nums2Size ? nums1Size : nums2Size;
    
    // ��̬������������ڴ棬��ʼ��Ϊ0
    int * result = (int *) calloc(lessSize, sizeof(int));
    
    // ������������
    int resultIndex = 0;

    // ����nums1���飬��¼ÿ��Ԫ�صĳ��ִ���
    for(int i = 0; i < nums1Size; i ++) {
        nums1Cnt[nums1[i]]++;
    }

    // ����nums2���飬���Ԫ���Ƿ���nums1Cnt�г��ֹ�
    for(int i = 0; i < nums2Size; i ++) {
        if(nums1Cnt[nums2[i]] > 0) {
            // ������ֹ����������������
            result[resultIndex++] = nums2[i];
            // ������Ԫ����nums1Cnt�еļ�����Ϊ0�������ظ�����
            nums1Cnt[nums2[i]] = 0;
        }
    }
    
    // ���÷��ؽ������Ĵ�С
    *returnSize = resultIndex;
    
    // ���ؽ������
    return result;
}

// ����������
int main() {
    int nums1[] = {1, 2, 2, 1, 3};
    int nums2[] = {2, 2, 3};
    int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
    int nums2Size = sizeof(nums2) / sizeof(nums2[0]);
    int returnSize;
    
    int* result = intersection(nums1, nums1Size, nums2, nums2Size, &returnSize);
    
    printf("Intersection: ");
    for(int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    
    // �ͷŶ�̬������ڴ�
    free(result);
    
    return 0;
}