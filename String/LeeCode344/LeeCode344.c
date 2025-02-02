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
    int left = 0, right = sSize - 1;  // 定义左右指针
    while (left < right) {  // 当左指针小于右指针时
        char temp = s[right];  // 临时保存右指针处的字符
        s[right--] = s[left];  // 将左指针处的字符放到右指针位置，并右指针向左移动
        s[left++] = temp;  // 将临时保存的字符放到左指针位置，并左指针向右移动
    }
}

int main() {
    char s[] = "hello";  // 测试字符串
    int sSize = 5;  // 字符串的长度
    reverseString(s, sSize);  // 调用反转函数

    printf("Reversed string: %s\n", s);  // 输出反转后的字符串
    return 0;
}
