#include <stdio.h>
#include <string.h>

int possibleStringCount(char* word) {
    int len = strlen(word);
    int ret = 1;
    int temp = 0;

    for (int i = 0; i < len; i++) {
        while (word[i] == word[i + 1]) {
            temp++;
            i++;
        }
        ret += temp;
        temp = 0;
    }

    return ret;
}

int test (char* word, int expected) {
    int ret = possibleStringCount(word);
    printf("Input: %s \n", word);
    printf("Expected: %d, Got: %d", expected, ret);
    printf(ret == expected ? " (PASS)\n\n" : " (FAIL)\n\n");

    return 0;
}

int main () {
    // ��������
    test("a", 1);       // �����ַ������ظ�
    test("aa", 2);      // ������ͬ�ַ�
    test("ab", 1);      // �������ظ��ַ�
    test("aab", 2);     // һ���ظ���
    test("aabb", 3);    // �����ظ���
    test("aaa", 3);     // ������ͬ�ַ�
    test("", 0);        // ���ַ���
    test("abcabc", 1);  // ���κ������ظ�
    test("aaabbb", 5);  // �����ظ��飬���ȷֱ�Ϊ3��3

    return 0;
}