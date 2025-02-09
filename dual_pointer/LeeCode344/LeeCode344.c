/*
 * @Author: LiNing
 * @Date: 2025-02-09 22:27:28
 * @LastEditors: LiNing
 * @LastEditTime: 2025-02-09 22:30:44
 * @FilePath: \LeeCode_Modularization\dual_pointer\LeeCode344\LeeCode344.c
 * @Description: 
 * Copyright (c) 2025 by ${git_name_email}, All Rights Reserved. 
 */

#include <stdio.h>
#include <string.h>

void reverseString(char* s, int sSize) {
    int left = 0, right = sSize - 1;
    while (left < right) {
        char temp = s[right];
        s[right--] = s[left];
        s[left++] = temp;
    }
}

int main () {
    char s[] = "hello";
    int sLen = strlen(s);
    printf("原字符串：%s\n", s);

    reverseString(s, sLen);

    printf("反转后字符串：%s\n", s);
}