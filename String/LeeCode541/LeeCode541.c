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

// 反转字符串函数
char* reverseStr(char* s, int k) {
    int len = strlen(s); // 获取字符串长度

    for (int i = 0; i < len; i += (2 * k)) { // 每 2k 个字符为一段
        // 判断剩余字符是否少于 k 个
        k = i + k > len ? len - i : k;

        int left = i;       // 左指针
        int right = i + k - 1; // 右指针

        // 反转前 k 个字符
        while (left < right) {
            char temp = s[left];
            s[left++] = s[right];
            s[right--] = temp;
        }
    }

    return s; // 返回反转后的字符串
}

// 测试主函数
int main() {
    char s[] = "abcdefg"; // 测试字符串
    int k = 2;            // 反转间隔

    printf("原始字符串: %s\n", s);
    char* result = reverseStr(s, k);
    printf("反转后字符串: %s\n", result);

    return 0;
}