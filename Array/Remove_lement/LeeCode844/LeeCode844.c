/*
 * @Author: LiNing
 * @Date: 2025-01-11 16:10:56
 * @LastEditors: LiNing
 * @LastEditTime: 2025-01-11 16:11:41
 * @FilePath: \LeeCode_Arrays\Remove_lement\LeeCode844\LeeCode844.c
 * @Description: 
 * Copyright (c) 2025 by ${git_name_email}, All Rights Reserved. 
 */
#include <stdbool.h>

bool backspaceCompare(char * s, char * t) {
    int i = strlen(s) - 1; // 指向字符串 s 的末尾
    int j = strlen(t) - 1; // 指向字符串 t 的末尾
    int skipS = 0; // 记录 s 中需要跳过的字符数
    int skipT = 0; // 记录 t 中需要跳过的字符数

    while (i >= 0 || j >= 0) {
        // 处理 s 的退格逻辑
        while (i >= 0) {
            if (s[i] == '#') {
                skipS++; // 遇到 '#'，跳过一个有效字符
                i--;
            } else if (skipS > 0) {
                skipS--; // 跳过当前有效字符
                i--;
            } else {
                break; // 找到有效字符，退出循环
            }
        }

        // 处理 t 的退格逻辑
        while (j >= 0) {
            if (t[j] == '#') {
                skipT++;
                j--;
            } else if (skipT > 0) {
                skipT--;
                j--;
            } else {
                break;
            }
        }

        // 比较当前字符
        if (i >= 0 && j >= 0 && s[i] != t[j]) {
            return false; // 当前字符不同，返回 false
        }

        // 如果一个字符串已遍历完，但另一个未遍历完，返回 false
        if ((i >= 0) != (j >= 0)) {
            return false;
        }

        // 移动指针到下一个字符
        i--;
        j--;
    }

    return true;
}
