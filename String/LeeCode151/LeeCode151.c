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

// 去除多余空格
void removeExtraSpaces(char *s) {
    int len = strlen(s);
    int slow = 0; // 慢指针，用于构建新字符串
    for (int fast = 0; fast < len; fast++) {
        // 跳过空格
        if (s[fast] != ' ') {
            // 在单词之间添加一个空格
            if (slow != 0) {
                s[slow++] = ' ';
            }
            // 复制单词
            while (fast < len && s[fast] != ' ') {
                s[slow++] = s[fast++];
            }
        }
    }
    s[slow] = '\0'; // 添加字符串结束符
}

// 反转字符串
void reverseString(char *s, int start, int end) {
    while (start < end) {
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
}

// 反转字符串中的单词
void reverseWords(char *s) {
    // 1. 去除多余空格
    removeExtraSpaces(s);
    int len = strlen(s);
    
    // 2. 反转整个字符串
    reverseString(s, 0, len - 1);
    
    // 3. 反转每个单词
    int start = 0;
    for (int i = 0; i <= len; i++) {
        if (s[i] == ' ' || s[i] == '\0') {
            reverseString(s, start, i - 1);
            start = i + 1;
        }
    }
}

// 测试主函数
int main() {
    char s[] = "the sky is blue";
    printf("Original: \"%s\"\n", s);
    
    reverseWords(s);
    
    printf("Reversed: \"%s\"\n", s);
    
    return 0;
}