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

// 判断字符串是否由子串重复构成
bool repeatedSubstringPattern(char *s) {
    int len = strlen(s);
    char s_new[2 * len + 1]; // 用于存储拼接后的字符串
    
    // 拼接 s + s
    strcpy(s_new, s);
    strcat(s_new, s);
    
    // 去掉首尾字符
    s_new[2 * len - 1] = '\0'; // 去掉最后一个字符
    char *s_new_start = s_new + 1; // 去掉第一个字符
    
    // 判断 s 是否是 s_new_start 的子串
    if (strstr(s_new_start, s) != NULL) {
        return true;
    }
    return false;
}

// 测试主函数
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