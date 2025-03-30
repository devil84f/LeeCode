/*
 * @Author: LiNing
 * @Date: 2025-03-30
 * ���ַ�����ӿո�
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* addSpaces(char* s, int* spaces, int spacesSize) {
    int sSize = strlen(s);
    // �����㹻�ռ䣺ԭ�ַ������� + �ո��� + ��ֹ��
    char *result = (char*)malloc(sSize + spacesSize + 1);
    if (!result) return NULL;  // ���malloc�Ƿ�ɹ�

    int slow = 0, quick = 0;
    for (int i = 0; i < spacesSize; i++) {
        // ���spaces[i]�Ƿ�Ϸ�
        if (spaces[i] < 0 || spaces[i] > sSize) {
            free(result);
            return NULL;
        }
        // �������ո�λ��ǰ���ַ�
        while (slow < spaces[i]) {
            result[quick++] = s[slow++];
        }
        // ����ո�
        result[quick++] = ' ';
    }
    // ����ʣ���ַ�
    while (slow < sSize) {
        result[quick++] = s[slow++];
    }
    // ��ֹ�ַ���
    result[quick] = '\0';
    return result;
}

// ����������
int main() {
    // ��������1���������
    char s1[] = "Leetcode";
    int spaces1[] = {2, 5};
    char *res1 = addSpaces(s1, spaces1, 2);
    printf("Test 1: %s\n", res1);  // Ԥ����� "Le e t code"
    free(res1);

    // ��������2���ո���뵽��ͷ
    char s2[] = "Hello";
    int spaces2[] = {0};
    char *res2 = addSpaces(s2, spaces2, 1);
    printf("Test 2: %s\n", res2);  // Ԥ����� " Hello"
    free(res2);

    // ��������3���ո���뵽ĩβ
    char s3[] = "World";
    int spaces3[] = {5};
    char *res3 = addSpaces(s3, spaces3, 1);
    printf("Test 3: %s\n", res3);  // Ԥ����� "World "
    free(res3);

    // ��������4�����ַ�������ȷ��spacesΪ�գ�
    char s4[] = "";
    int spaces4[] = {};
    char *res4 = addSpaces(s4, spaces4, 0);
    printf("Test 4: %s\n", res4);  // Ԥ����� ""
    free(res4);

    return 0;
}