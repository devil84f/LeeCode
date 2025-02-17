/*
 * @Author: LiNing
 * @Date: 2025-02-07 00:30:42
 * @LastEditors: LiNing
 * @LastEditTime: 2025-02-07 00:30:44
 * @FilePath: \LeeCode_Modularization\String\LeeCode459\LeeCode459.c
 * @Description: 
 * Copyright (c) 2025 by ${git_name_email}, All Rights Reserved. 
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// �ж��ַ����Ƿ����Ӵ��ظ�����
bool repeatedSubstringPattern(char *s) {
    int len = strlen(s);
    char s_new[2 * len + 1]; // ���ڴ洢ƴ�Ӻ���ַ���
    
    // ƴ�� s + s
    strcpy(s_new, s);
    strcat(s_new, s);
    
    // ȥ����β�ַ�
    s_new[2 * len - 1] = '\0'; // ȥ�����һ���ַ�
    char *s_new_start = s_new + 1; // ȥ����һ���ַ�
    
    // �ж� s �Ƿ��� s_new_start ���Ӵ�
    if (strstr(s_new_start, s) != NULL) {
        return true;
    }
    return false;
}

// ����������
int main() {
    char s1[] = "abab";
    char s2[] = "aba";
    char s3[] = "abcabcabcabc";
    
    printf("Input: \"%s\"\n", s1);
    printf("Output: %s\n", repeatedSubstringPattern(s1) ? "true" : "false");
    
    printf("Input: \"%s\"\n", s2);
    printf("Output: %s\n", repeatedSubstringPattern(s2) ? "true" : "false");
    
    printf("Input: \"%s\"\n", s3);
    printf("Output: %s\n", repeatedSubstringPattern(s3) ? "true" : "false");
    
    return 0;
}