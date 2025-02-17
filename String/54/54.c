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
    char result[1000];  // �����洢���
    int j = 0;  // ������������
    
    for (int i = 0; i < len; i++) {
        if (isdigit(s[i])) {
            // ����ַ������֣���� "number"
            strcpy(&result[j], "number");
            j += 6;  // "number" ����Ϊ 6
        } else {
            // ����ַ�����ĸ�����ֲ���
            result[j++] = s[i];
        }
    }
    
    result[j] = '\0';  // �����ַ���
    strcpy(s, result);  // ��������ƻ�ԭ�ַ���
}

int main() {
    char s[] = "a1b2c3";
    replaceDigitsWithNumber(s);
    printf("ת������ַ����ǣ�%s\n", s);
    return 0;
}
