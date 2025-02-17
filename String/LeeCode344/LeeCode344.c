/*
 * @Author: LiNing
 * @Date: 2025-01-21 23:26:40
 * @LastEditors: LiNing
 * @LastEditTime: 2025-02-02 23:55:36
 * @FilePath: \LeeCode_Modularization\String\LeeCode344\LeeCode344.c
 * @Description: 
 * Copyright (c) 2025 by ${git_name_email}, All Rights Reserved. 
 */

#include <stdio.h>

void reverseString(char* s, int sSize) {
    int left = 0, right = sSize - 1;  // ��������ָ��
    while (left < right) {  // ����ָ��С����ָ��ʱ
        char temp = s[right];  // ��ʱ������ָ�봦���ַ�
        s[right--] = s[left];  // ����ָ�봦���ַ��ŵ���ָ��λ�ã�����ָ�������ƶ�
        s[left++] = temp;  // ����ʱ������ַ��ŵ���ָ��λ�ã�����ָ�������ƶ�
    }
}

int main() {
    char s[] = "hello";  // �����ַ���
    int sSize = 5;  // �ַ����ĳ���
    reverseString(s, sSize);  // ���÷�ת����

    printf("Reversed string: %s\n", s);  // �����ת����ַ���
    return 0;
}
