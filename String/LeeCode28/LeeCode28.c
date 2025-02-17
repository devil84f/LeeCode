/*
 * @Author: LiNing
 * @Date: 2025-02-06 00:38:08
 * @LastEditors: LiNing
 * @LastEditTime: 2025-02-06 00:40:44
 * @FilePath: \LeeCode_Modularization\String\LeeCode28\LeeCode28.c
 * @Description: 
 * Copyright (c) 2025 by ${git_name_email}, All Rights Reserved. 
 */
#include <stdio.h>
#include <string.h>

// ʵ�� strStr() ����
int strStr(char *haystack, char *needle) {
    int len_haystack = strlen(haystack);
    int len_needle = strlen(needle);
    
    // ��� needle �ǿ��ַ��������� 0
    if (len_needle == 0) {
        return 0;
    }
    
    // ��� haystack �ĳ���С�� needle �ĳ��ȣ����� -1
    if (len_haystack < len_needle) {
        return -1;
    }
    
    // ���� haystack
    for (int i = 0; i <= len_haystack - len_needle; i++) {
        int j;
        // ����ƥ�� needle
        for (j = 0; j < len_needle; j++) {
            if (haystack[i + j] != needle[j]) {
                break;
            }
        }
        // ���ƥ��ɹ������ص�ǰλ��
        if (j == len_needle) {
            return i;
        }
    }
    
    // δ�ҵ�ƥ�䣬���� -1
    return -1;
}

// ����������
int main() {
    char haystack[] = "hello";
    char needle[] = "ll";
    
    int result = strStr(haystack, needle);
    
    printf("Input: haystack = \"%s\", needle = \"%s\"\n", haystack, needle);
    printf("Output: %d\n", result);
    
    return 0;
}