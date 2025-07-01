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
    // 测试用例
    test("a", 1);       // 单个字符，无重复
    test("aa", 2);      // 两个相同字符
    test("ab", 1);      // 无连续重复字符
    test("aab", 2);     // 一个重复块
    test("aabb", 3);    // 两个重复块
    test("aaa", 3);     // 三个相同字符
    test("", 0);        // 空字符串
    test("abcabc", 1);  // 无任何连续重复
    test("aaabbb", 5);  // 两个重复块，长度分别为3和3

    return 0;
}