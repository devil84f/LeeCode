/*
 * @Author: LiNing
 * @Date: 2025-02-03 00:26:09
 * @LastEditors: LiNing
 * @LastEditTime: 2025-02-03 00:26:11
 * @FilePath: \LeeCode_Modularization\String\LeeCode541\LeeCode541.c
 * @Description: 
 * Copyright (c) 2025 by ${git_name_email}, All Rights Reserved. 
 */

#include <stdio.h>
#include <string.h>

// ��ת�ַ�������
char* reverseStr(char* s, int k) {
    int len = strlen(s); // ��ȡ�ַ�������

    for (int i = 0; i < len; i += (2 * k)) { // ÿ 2k ���ַ�Ϊһ��
        // �ж�ʣ���ַ��Ƿ����� k ��
        k = i + k > len ? len - i : k;

        int left = i;       // ��ָ��
        int right = i + k - 1; // ��ָ��

        // ��תǰ k ���ַ�
        while (left < right) {
            char temp = s[left];
            s[left++] = s[right];
            s[right--] = temp;
        }
    }

    return s; // ���ط�ת����ַ���
}

// ����������
int main() {
    char s[] = "abcdefg"; // �����ַ���
    int k = 2;            // ��ת���

    printf("ԭʼ�ַ���: %s\n", s);
    char* result = reverseStr(s, k);
    printf("��ת���ַ���: %s\n", result);

    return 0;
}