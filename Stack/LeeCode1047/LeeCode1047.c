/*
 * @Author: LiNing
 * @Date: 2025-03-05
 * 堆栈实战
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* removeDuplicates(char* s) {
    int len = strlen(s);
    if (len == 1) return s;
    int p = 0;
    char* result = (char*)malloc(sizeof(char) * (len + 1));
    result[p++] = s[0];
    for (int i = 1; i < len; i++) {
        if (p > 0 && s[i] == result[p-1]) {
            p--;
        } else result[p++] = s[i];
    }
    //存放字符串结束标志'\0'
    result[p] = '\0';
    //返回栈本身作为字符串
    return result;
}

int main () {
    char s[] = "abbacdde";
    char *result = removeDuplicates(s);

    printf("%s\n", result);
    return 0;
}