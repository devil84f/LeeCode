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

// 实现 strStr() 函数
int strStr(char *haystack, char *needle) {
    int len_haystack = strlen(haystack);
    int len_needle = strlen(needle);
    
    // 如果 needle 是空字符串，返回 0
    if (len_needle == 0) {
        return 0;
    }
    
    // 如果 haystack 的长度小于 needle 的长度，返回 -1
    if (len_haystack < len_needle) {
        return -1;
    }
    
    // 遍历 haystack
    for (int i = 0; i <= len_haystack - len_needle; i++) {
        int j;
        // 尝试匹配 needle
        for (j = 0; j < len_needle; j++) {
            if (haystack[i + j] != needle[j]) {
                break;
            }
        }
        // 如果匹配成功，返回当前位置
        if (j == len_needle) {
            return i;
        }
    }
    
    // 未找到匹配，返回 -1
    return -1;
}

// 测试主函数
int main() {
    char haystack[] = "hello";
    char needle[] = "ll";
    
    int result = strStr(haystack, needle);
    
    printf("Input: haystack = \"%s\", needle = \"%s\"\n", haystack, needle);
    printf("Output: %d\n", result);
    
    return 0;
}