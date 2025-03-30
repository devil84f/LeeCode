/*
 * @Author: LiNing
 * @Date: 2025-03-30
 * 向字符串添加空格
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* addSpaces(char* s, int* spaces, int spacesSize) {
    int sSize = strlen(s);
    // 分配足够空间：原字符串长度 + 空格数 + 终止符
    char *result = (char*)malloc(sSize + spacesSize + 1);
    if (!result) return NULL;  // 检查malloc是否成功

    int slow = 0, quick = 0;
    for (int i = 0; i < spacesSize; i++) {
        // 检查spaces[i]是否合法
        if (spaces[i] < 0 || spaces[i] > sSize) {
            free(result);
            return NULL;
        }
        // 拷贝到空格位置前的字符
        while (slow < spaces[i]) {
            result[quick++] = s[slow++];
        }
        // 插入空格
        result[quick++] = ' ';
    }
    // 拷贝剩余字符
    while (slow < sSize) {
        result[quick++] = s[slow++];
    }
    // 终止字符串
    result[quick] = '\0';
    return result;
}

// 测试主函数
int main() {
    // 测试用例1：正常情况
    char s1[] = "Leetcode";
    int spaces1[] = {2, 5};
    char *res1 = addSpaces(s1, spaces1, 2);
    printf("Test 1: %s\n", res1);  // 预期输出 "Le e t code"
    free(res1);

    // 测试用例2：空格插入到开头
    char s2[] = "Hello";
    int spaces2[] = {0};
    char *res2 = addSpaces(s2, spaces2, 1);
    printf("Test 2: %s\n", res2);  // 预期输出 " Hello"
    free(res2);

    // 测试用例3：空格插入到末尾
    char s3[] = "World";
    int spaces3[] = {5};
    char *res3 = addSpaces(s3, spaces3, 1);
    printf("Test 3: %s\n", res3);  // 预期输出 "World "
    free(res3);

    // 测试用例4：空字符串（需确保spaces为空）
    char s4[] = "";
    int spaces4[] = {};
    char *res4 = addSpaces(s4, spaces4, 0);
    printf("Test 4: %s\n", res4);  // 预期输出 ""
    free(res4);

    return 0;
}