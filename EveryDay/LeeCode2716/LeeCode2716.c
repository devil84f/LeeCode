/*
 * @Author: LiNing
 * @Date: 2025-03-28
 * 最小化字符串长度
*/
#include <stdio.h>
#include <string.h>

int minimizedStringLength(char* s) {
    int mask = 0;
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        mask |= 1 << (s[i] - 'a');
    }
    return __builtin_popcount(mask);
}

int main () {
    char s[] = "aaabbbcccd";
    int result = minimizedStringLength(s);
    printf("%d\n", result);

    return 0;
}