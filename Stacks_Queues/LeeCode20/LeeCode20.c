/*
 * @Author: LiNing
 * @Date: 2025-02-17 23:31:37
 * @LastEditors: LiNing
 * @LastEditTime: 2025-02-17 23:37:11
 * @FilePath: \LeeCode_Modularization\Stacks_Queues\LeeCode20\LeeCode20.c
 * @Description: 
 * Copyright (c) 2025 by ${git_name_email}, All Rights Reserved. 
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isValid (char* s) {
    int p = -1;
    int len = strlen(s);
    char* stack = (char*)malloc(len * sizeof(char));

    for (int i = 0; i < len; i++){
        if (s[i] == '(') stack[++p] = ')';
        else if (s[i] == '[') stack[++p] = ']';
        else if (s[i] == '{') stack[++p] = '}';
        else if (p == -1 || stack[p] != s[i]) {
            free(stack);  // 释放内存
            return false;
        }
        else p--;
    }
    free(stack);  // 释放内存
    return p == -1;
}

int main () {
    char s[] = "({[]}})";
    bool result = isValid(s);
    if (result) printf("%s 是有效的括号\n", s);
    else printf("%s 不是有效的括号\n", s);
    return 0;
}