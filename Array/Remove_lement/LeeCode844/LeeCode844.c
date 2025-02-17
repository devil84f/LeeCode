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
    int i = strlen(s) - 1; // ָ���ַ��� s ��ĩβ
    int j = strlen(t) - 1; // ָ���ַ��� t ��ĩβ
    int skipS = 0; // ��¼ s ����Ҫ�������ַ���
    int skipT = 0; // ��¼ t ����Ҫ�������ַ���

    while (i >= 0 || j >= 0) {
        // ���� s ���˸��߼�
        while (i >= 0) {
            if (s[i] == '#') {
                skipS++; // ���� '#'������һ����Ч�ַ�
                i--;
            } else if (skipS > 0) {
                skipS--; // ������ǰ��Ч�ַ�
                i--;
            } else {
                break; // �ҵ���Ч�ַ����˳�ѭ��
            }
        }

        // ���� t ���˸��߼�
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

        // �Ƚϵ�ǰ�ַ�
        if (i >= 0 && j >= 0 && s[i] != t[j]) {
            return false; // ��ǰ�ַ���ͬ������ false
        }

        // ���һ���ַ����ѱ����꣬����һ��δ�����꣬���� false
        if ((i >= 0) != (j >= 0)) {
            return false;
        }

        // �ƶ�ָ�뵽��һ���ַ�
        i--;
        j--;
    }

    return true;
}
