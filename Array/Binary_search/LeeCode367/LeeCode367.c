/*
 * @Author: LiNing
 * @Date: 2025-01-10 00:06:14
 * @LastEditors: LiNing
 * @LastEditTime: 2025-01-10 00:06:15
 * @FilePath: \LeeCode_Arrays\LeeCode_Arrays\LeeCode367\LeeCode367.c
 * @Description: 
 * Copyright (c) 2025 by ${git_name_email}, All Rights Reserved. 
 */
#include <stdio.h>
#include <stdbool.h>

/**
 * �ж�һ�����Ƿ�����ȫƽ����
 * @param num: Ҫ�жϵ�����
 * @return: ��� num ����ȫƽ�������򷵻� true�����򷵻� false
 */
bool isPerfectSquare(int num) {
    // ���������0 �� 1 ����ȫƽ����
    if (num == 0 || num == 1) {
        return true;
    }

    // ���ö��ֲ��ҵ����ұ߽�
    int left = 1, right = num / 2;
    
    // ʹ�ö��ֲ���
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int mid_square = mid * mid;

        // �ж� mid ��ƽ���Ƿ���� num
        if (mid_square == num) {
            return true;  // ����ҵ�����ȫƽ���������� true
        } 
        // ��� mid ��ƽ��С�� num��˵��ƽ�������Ұ벿��
        else if (mid_square < num) {
            left = mid + 1;
        } 
        // ��� mid ��ƽ������ num��˵��ƽ��������벿��
        else {
            right = mid - 1;
        }
    }

    // ���û���ҵ���ȫƽ���������� false
    return false;
}

int main() {
    // ��������
    int test_cases[] = {16, 14, 25, 30, 1, 0, 144};
    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

    for (int i = 0; i < num_tests; i++) {
        int num = test_cases[i];
        if (isPerfectSquare(num)) {
            printf("%d is a perfect square.\n", num);
        } else {
            printf("%d is not a perfect square.\n", num);
        }
    }

    return 0;
}
