/*
 * @Author: LiNing
 * @Date: 2025-02-04 00:52:47
 * @LastEditors: LiNing
 * @LastEditTime: 2025-02-04 00:54:19
 * @FilePath: \LeeCode_Modularization\String\LeeCode151\LeeCode151.c
 * @Description: 
 * Copyright (c) 2025 by ${git_name_email}, All Rights Reserved. 
 */

#include <stdio.h>
#include <string.h>

// ȥ������ո�
void removeExtraSpaces(char *s) {
    int len = strlen(s);
    int slow = 0; // ��ָ�룬���ڹ������ַ���
    for (int fast = 0; fast < len; fast++) {
        // �����ո�
        if (s[fast] != ' ') {
            // �ڵ���֮�����һ���ո�
            if (slow != 0) {
                s[slow++] = ' ';
            }
            // ���Ƶ���
            while (fast < len && s[fast] != ' ') {
                s[slow++] = s[fast++];
            }
        }
    }
    s[slow] = '\0'; // ����ַ���������
}

// ��ת�ַ���
void reverseString(char *s, int start, int end) {
    while (start < end) {
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
}

// ��ת�ַ����еĵ���
void reverseWords(char *s) {
    // 1. ȥ������ո�
    removeExtraSpaces(s);
    int len = strlen(s);
    
    // 2. ��ת�����ַ���
    reverseString(s, 0, len - 1);
    
    // 3. ��תÿ������
    int start = 0;
    for (int i = 0; i <= len; i++) {
        if (s[i] == ' ' || s[i] == '\0') {
            reverseString(s, start, i - 1);
            start = i + 1;
        }
    }
}

// ����������
int main() {
    char s[] = "the sky is blue";
    printf("Original: \"%s\"\n", s);
    
    reverseWords(s);
    
    printf("Reversed: \"%s\"\n", s);
    
    return 0;
}