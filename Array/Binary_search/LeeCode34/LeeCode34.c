/*
 * @Author: LiNing
 * @Date: 2025-01-09 00:10:37
 * @LastEditors: LiNing
 * @LastEditTime: 2025-01-09 00:13:46
 * @FilePath: \LeeCode_Arrays\LeeCode_Arrays\LeeCode34\LeeCode34.c
 * @Description: 
 * Copyright (c) 2025 by ${git_name_email}, All Rights Reserved. 
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * searchRange ������������������������ҵ�Ŀ��ֵ����ʼ�ͽ���λ�á�
 * ���Ŀ��ֵ�����ڣ��򷵻� [-1, -1]��
 * 
 * @param nums: �������������顣
 * @param numsSize: ����Ĵ�С��
 * @param target: Ҫ���ҵ�Ŀ��ֵ��
 * @param returnSize: ��������Ĵ�С���̶�Ϊ2����ʾ����Ŀ��ֵ�ķ�Χ��
 * @return: һ������Ŀ��ֵ��Χ�����飬��ΧΪ [left, right]�����Ŀ��ֵ�����ڷ��� [-1, -1]��
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    // ���÷�������Ĵ�СΪ2����ʾ���ΪĿ��ֵ����ʼ�ͽ���λ��
    *returnSize = 2;

    // ��̬���������飬���ڴ洢Ŀ��ֵ����ʼ�ͽ���λ��
    int* result = (int*)malloc(sizeof(int) * 2);
    
    // ����ڴ�����Ƿ�ɹ�
    if (result == NULL) {
        *returnSize = 0;  // ����ڴ����ʧ�ܣ�����0��С������
        return NULL;
    }

    // ��ʼ��������飬Ĭ��ֵΪ [-1, -1]
    result[0] = -1;
    result[1] = -1;

    // �������Ϊ�ջ�Ŀ��ֵ��������ķ�Χ�ڣ�ֱ�ӷ��� [-1, -1]
    if (numsSize == 0 || nums[0] > target || nums[numsSize - 1] < target) {
        return result;
    }

    int left = 0;            // ��ָ��
    int right = numsSize - 1;  // ��ָ��
    int middle = 0;          // �м�ָ��

    // ���ֲ���Ŀ��ֵ��λ��
    while (left <= right) {
        middle = left + (right - left) / 2;  // �����м�λ�ã��������
        if (nums[middle] == target) {  // �ҵ�Ŀ��ֵ
            // �ҵ�Ŀ��ֵ�������������չ���ҵ���������ҵ�Ŀ��ֵ
            int m_left = middle;
            int m_right = middle;

            // ������չ��ֱ�����ٵ���Ŀ��ֵ
            while ((m_right + 1) < numsSize && nums[m_right + 1] == target) {
                m_right += 1;
            }

            // ������չ��ֱ�����ٵ���Ŀ��ֵ
            while ((m_left - 1) >= 0 && nums[m_left - 1] == target) {
                m_left -= 1;
            }

            // ���ý�����飬�������������λ��
            result[0] = m_left;
            result[1] = m_right;
            return result;
        }

        // �����м�ֵ��Ŀ��ֵ�Ĵ�С��ϵ��������ָ��
        if (nums[middle] > target) {
            right = middle - 1;  // ���Ŀ��ֵС���м�ֵ����ָ������
        } else {
            left = middle + 1;  // ���Ŀ��ֵ�����м�ֵ����ָ������
        }
    }

    // ���û���ҵ�Ŀ��ֵ������ [-1, -1]
    return result;
}

int main() {
    // ʾ�������Ŀ��ֵ
    int nums[] = {5, 7, 7, 8, 8, 10};
    int target = 8;
    int returnSize;
    
    // ���� searchRange ����
    int* result = searchRange(nums, sizeof(nums) / sizeof(nums[0]), target, &returnSize);

    // ������
    if (result != NULL) {
        printf("Range: [%d, %d]\n", result[0], result[1]);
        free(result);  // �ǵ��ͷŶ�̬������ڴ�
    } else {
        printf("Target not found.\n");
    }

    return 0;
}
