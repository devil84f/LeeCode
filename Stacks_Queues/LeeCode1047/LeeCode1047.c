/*
 * @Author: LiNing
 * @Date: 2025-02-20 23:20:57
 * @LastEditors: LiNing
 * @LastEditTime: 2025-02-20 23:26:15
 * @FilePath: \LeeCode_Modularization\Stacks_Queues\LeeCode1047\LeeCode1047.c
 * @Description: 
 * Copyright (c) 2025 by ${git_name_email}, All Rights Reserved. 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* removeDuplicates(char* s) {
    int len = strlen(s);
    if (len == 1) return s;
    int p = 0;
    char* result = (char*)malloc(sizeof(char) * (len + 1));
    result[p++] = s[0];
    for (int i = 1; i < len; i++) {
        if (p > 0 && s[i] == result[p-1]) {
            p--;
        } else result[p++] = s[i];
    }
    //存放字符串结束标志'\0'
    result[p] = '\0';
    //返回栈本身作为字符串
    return result;
}

int main () {
    char s[] = "abbaca";

    char* result = removeDuplicates(s);
    printf("处理后字符串为：%s\n", result);

    return 0;
}