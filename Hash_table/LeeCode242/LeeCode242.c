/*
 * @Author: LiNing
 * @Date: 2025-01-26 00:32:16
 * @LastEditors: LiNing
 * @LastEditTime: 2025-01-26 00:32:45
 * @FilePath: \LeeCode_Modularization\Hash_table\LeeCode242\LeeCode242.c
 * @Description: 
 * Copyright (c) 2025 by ${git_name_email}, All Rights Reserved. 
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isAnagram(char* s, char* t) {
    int len1 = strlen(s), len2 = strlen(t);
    if (len1 != len2) {
        return false;
    }

    int map[26] = {0};
    for (int i = 0; i < len1; i++) {
        map[s[i] - 'a'] += 1;
    }
    
    for (int i = 0; i < len2; i++) {
        map[t[i] - 'a'] -= 1;
    }

    for (int i = 0; i < 26; i++) {
        if (map[i] != 0) {
            return false;
        }
    }
    
    return true;
}

int main() {
    char s1[] = "anagram";
    char t1[] = "nagaram";

    char s2[] = "rat";
    char t2[] = "car";

    if (isAnagram(s1, t1)) {
        printf("\"%s\" and \"%s\" are anagrams.\n", s1, t1);
    } else {
        printf("\"%s\" and \"%s\" are not anagrams.\n", s1, t1);
    }

    if (isAnagram(s2, t2)) {
        printf("\"%s\" and \"%s\" are anagrams.\n", s2, t2);
    } else {
        printf("\"%s\" and \"%s\" are not anagrams.\n", s2, t2);
    }

    return 0;
}
