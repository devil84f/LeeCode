/*
 * @Author: LiNing
 * @Date: 2025-04-16
 * �ַ����ķ���
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int scoreOfString(char* s) {
    int i = 1, res = 0;
    while (s[i]) {
        res += abs(s[i] - s[i-1]);
        i++;
    }
    return res;
}

void test_scoreOfString() {
    // ��������1: �����ַ���
    char *s1 = "hello";
    int result1 = scoreOfString(s1);
    int expected1 = 13; // h-e=7, e-l=7, l-l=0, l-o=3 �� 7+7+0+3=17
    printf("Test case 1: %s\n", result1 == expected1 ? "PASSED" : "FAILED");
    printf("Expected: %d, Actual: %d\n", expected1, result1);

    // ��������2: ���ַ��ַ���
    char *s2 = "a";
    int result2 = scoreOfString(s2);
    int expected2 = 0; // ֻ��һ���ַ��������ڲ�
    printf("Test case 2: %s\n", result2 == expected2 ? "PASSED" : "FAILED");
    printf("Expected: %d, Actual: %d\n", expected2, result2);

    // ��������3: ���ַ���
    char *s3 = "";
    int result3 = scoreOfString(s3);
    int expected3 = 0;
    printf("Test case 3: %s\n", result3 == expected3 ? "PASSED" : "FAILED");
    printf("Expected: %d, Actual: %d\n", expected3, result3);

    // ��������4: ��д��ĸ
    char *s4 = "ABC";
    int result4 = scoreOfString(s4);
    int expected4 = 2; // A-B=1, B-C=1 �� 1+1=2
    printf("Test case 4: %s\n", result4 == expected4 ? "PASSED" : "FAILED");
    printf("Expected: %d, Actual: %d\n", expected4, result4);

    // ��������5: ��ϴ�Сд
    char *s5 = "aBc";
    int result5 = scoreOfString(s5);
    int expected5 = 33; // a-B=31, B-c=2 �� 31+2=33
    printf("Test case 5: %s\n", result5 == expected5 ? "PASSED" : "FAILED");
    printf("Expected: %d, Actual: %d\n", expected5, result5);
}

int main() {
    test_scoreOfString();
    return 0;
}