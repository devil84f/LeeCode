/*
 * @Author: LiNing
 * @Date: 2025-02-05 00:24:31
 * @LastEditors: LiNing
 * @LastEditTime: 2025-02-05 00:33:25
 * @FilePath: \LeeCode_Modularization\String\55\55.c
 * @Description: 
 * Copyright (c) 2025 by ${git_name_email}, All Rights Reserved. 
 */

#include <stdio.h>
#include <string.h>

void revers (char* s, int start, int end) {
    for (int i = 0; i < end; i++) {
        char temp = s[start];
        s[start++] = s[end];
        s[end--] = temp;
    }
}

int main () {
    char s[] = "abcdefg";
    int k = 2, len = strlen(s); 
    revers(s, 0, len - 1);
    revers(s, 0, k - 1);
    revers(s, k, len - 1);
    printf("%s", s);
    
    return 0;
}