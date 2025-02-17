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
    // ����һ������Ϊ26�����飬������¼�ַ����ֵ�Ƶ��
    int hasmap[26] = {0}; 

    // ���� ransomNote �ַ��������ٶ�Ӧ��ĸ��Ƶ��
    for (int i = 0; i < strlen(ransomNote); i++) {
        hasmap[ransomNote[i] - 'a'] -= 1;  // ��Ӧ��ĸ��Ƶ�μ�1
    }

    // ���� magazine �ַ��������Ӷ�Ӧ��ĸ��Ƶ��
    for (int i = 0; i < strlen(magazine); i++) {
        hasmap[magazine[i] - 'a'] += 1;  // ��Ӧ��ĸ��Ƶ�μ�1
    }

    // ����� hasmap ��ÿ��λ�õ�ֵ��ȷ��û�и�ֵ
    for (int i = 0; i < 26; i++) {
        if (hasmap[i] < 0) return false;  // ���ĳ����ĸ��Ƶ��С��0������false
    }
    
    return true;  // ���м��ͨ��������true
}

int main() {
    char ransomNote[] = "aabb";
    char magazine[] = "abbbcca";
    
    if (canConstruct(ransomNote, magazine)) {
        printf("���Թ���\n");
    } else {
        printf("�޷�����\n");
    }

    return 0;
}
