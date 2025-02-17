/*
 * @Author: LiNing
 * @Date: 2025-01-14 23:10:52
 * @LastEditors: LiNing
 * @LastEditTime: 2025-01-14 23:23:22
 * @FilePath: \LeeCode_Arrays\Sliding_window\LeeCode76\LeeCode76.c
 * @Description: 
 * Copyright (c) 2025 by ${git_name_email}, All Rights Reserved. 
 */
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <stdio.h>

bool is_covered(int cnt_s[], int cnt_t[]) {
    for (int i = 'A'; i <= 'Z'; i++) {
        if (cnt_s[i] < cnt_t[i]) {
            return false;
        }
    }
    for (int i = 'a'; i <= 'z'; i++) {
        if (cnt_s[i] < cnt_t[i]) {
            return false;
        }
    }
    return true;
}

char* minWindow(char* s, char* t) {
    int ans_left = -1, ans_right = INT_MAX / 2;
    int cnt_s[128] = {}; // s 子串字母的出现次数
    int cnt_t[128] = {}; // t 中字母的出现次数
    for (int i = 0; t[i]; i++) {
        cnt_t[t[i]]++;
    }

    int left = 0;
    for (int right = 0; s[right]; right++) { // 移动子串右端点
        cnt_s[s[right]]++; // 右端点字母移入子串
        while (is_covered(cnt_s, cnt_t)) { // 涵盖
            if (right - left < ans_right - ans_left) { // 找到更短的子串
                ans_left = left; // 记录此时的左右端点
                ans_right = right;
            }
            cnt_s[s[left]]--; // 左端点字母移出子串
            left++;
        }
    }

    if (ans_left < 0) {
        return "";
    }
    s[ans_right + 1] = '\0';
    return s + ans_left;
}

int main (void) {
    int cnt_t[128] = {}; // t 中字母的出现次数

    printf("%d\n", 'A');
    int i = 'A'; // 对char类型强制类型转换得到int值
    cnt_t[i]++; 

    printf("%d\n", i);
    printf("%d\n", cnt_t[i]);
}
