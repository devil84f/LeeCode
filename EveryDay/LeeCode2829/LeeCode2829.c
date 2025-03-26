/*
 * @Author: LiNing
 * @Date: 2025-03-26
 * k-avoiding 数组的最小总和
*/
#include <stdio.h>

int minimumSum(int n, int k) {
    int result = 0;
    int num = 1;
    for (int i = 1; i <= n; i++) {
        if (i <= k/2) {
            result += i;
        } else {
            result += (i + k / 2 - !(k%2));
        }
    }

    return result;
}

int main () {
    int n = 5, k = 4;
    int result = minimumSum(n, k);
    printf("%d\n", result);

    return 0;
}