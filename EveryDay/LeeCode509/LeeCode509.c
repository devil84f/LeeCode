/*
 * @Author: LiNing
 * @Date: 2025-04-3
 * ì³²¨ÄÇÆõÊý
*/
#include <stdio.h>

int fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    int a = 0, b = 1;
    int ret = 0;
    for (int i = 2; i <= n; i++) {
        ret = a + b;
        a = b;
        b = ret;
    }
    return ret;
}

int main () {
    int n = 4;
    int ret = fib(n);
    printf("%d\n", ret);

    return 0;
}