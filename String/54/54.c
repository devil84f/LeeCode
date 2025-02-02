/*
 * @Author: LiNing
 * @Date: 2025-02-03 00:28:30
 * @LastEditors: LiNing
 * @LastEditTime: 2025-02-03 00:40:41
 * @FilePath: \LeeCode_Modularization\String\54\54.c
 * @Description: 
 * Copyright (c) 2025 by ${git_name_email}, All Rights Reserved. 
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void replaceDigitsWithNumber(char* s) {
    int len = strlen(s);
    char result[1000];  // 用来存储结果
    int j = 0;  // 结果数组的索引
    
    for (int i = 0; i < len; i++) {
        if (isdigit(s[i])) {
            // 如果字符是数字，添加 "number"
            strcpy(&result[j], "number");
            j += 6;  // "number" 长度为 6
        } else {
            // 如果字符是字母，保持不变
            result[j++] = s[i];
        }
    }
    
    result[j] = '\0';  // 结束字符串
    strcpy(s, result);  // 将结果复制回原字符串
}

int main() {
    char s[] = "a1b2c3";
    replaceDigitsWithNumber(s);
    printf("转换后的字符串是：%s\n", s);
    return 0;
}
