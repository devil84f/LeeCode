/*
 * @Author: LiNing
 * @Date: 2025-03-24
 * 统计是给定字符串前缀的字符串数目
*/
#include <stdio.h>
#include <string.h>

int countPrefixes(char** words, int wordsSize, char* s) {
    int res = 0;
    for (int i = 0; i < wordsSize; i++) {
        if (strncmp(s, words[i], strlen(words[i])) == 0) {
            res++;
        }
    }
    return res;
}

int main() {
    char* words[] = {"a", "b", "c", "ab", "bc", "abc"};
    char* s = "abc";
    int wordsSize = sizeof(words) / sizeof(words[0]);

    printf("是给定字符串前缀的字符串数目: %d\n", countPrefixes(words, wordsSize, s)); // 0

    return 0;
}