/*
 * @Author: LiNing
 * @Date: 2025-03-31
 * ��ĸ���ַ����еİٷֱ�
*/
#include <stdio.h>
#include <string.h>

int percentageLetter(char* s, char letter) {
    int sSize = strlen(s);
    int num = 0;
    for (int i = 0; i < sSize; i++) {
        if (s[i] == letter) {
            num++;
        }
    }
    
    return num * 100 / sSize;
}

int main () {
    char s[] = "foobar";
    char letter = 'o';
    int result = percentageLetter(s, letter);
    printf("%d\n", result);

    return 0;
}