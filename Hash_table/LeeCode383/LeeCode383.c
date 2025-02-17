/*
 * @Author: LiNing
 * @Date: 2025-01-31 21:45:22
 * @LastEditors: LiNing
 * @LastEditTime: 2025-01-31 21:51:16
 * @FilePath: \LeeCode_Modularization\Hash_table\LeeCode383\LeeCode383.c
 * @Description: 
 * Copyright (c) 2025 by ${git_name_email}, All Rights Reserved. 
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool canConstruct(char* ransomNote, char* magazine) {
    // 定义一个长度为26的数组，用来记录字符出现的频次
    int hasmap[26] = {0}; 

    // 遍历 ransomNote 字符串，减少对应字母的频次
    for (int i = 0; i < strlen(ransomNote); i++) {
        hasmap[ransomNote[i] - 'a'] -= 1;  // 对应字母的频次减1
    }

    // 遍历 magazine 字符串，增加对应字母的频次
    for (int i = 0; i < strlen(magazine); i++) {
        hasmap[magazine[i] - 'a'] += 1;  // 对应字母的频次加1
    }

    // 最后检查 hasmap 中每个位置的值，确保没有负值
    for (int i = 0; i < 26; i++) {
        if (hasmap[i] < 0) return false;  // 如果某个字母的频次小于0，返回false
    }
    
    return true;  // 所有检查通过，返回true
}

int main() {
    char ransomNote[] = "aabb";
    char magazine[] = "abbbcca";
    
    if (canConstruct(ransomNote, magazine)) {
        printf("可以构成\n");
    } else {
        printf("无法构成\n");
    }

    return 0;
}
