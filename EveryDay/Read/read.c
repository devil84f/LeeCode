#include <stdio.h>
#include <string.h>

/* ������� */
int add(int a, int b) {
    return a + b;
}

int main () {
    char buf[] = {"12345678"};
    printf("%s\n", (buf+3));
    printf("%d\n", strlen(buf));
    return 0;
}

