#include <stdio.h>
#include <string.h>

/* 两数相加 */
int add(int a, int b) {
    return a + b;
}

int main () {
    char buf[] = {"12345678"};
    printf("%s\n", (buf+3));
    printf("%d\n", strlen(buf));
    return 0;
}

