/*
 * @Author: LiNing
 * @Date: 2025-04-11
 * 统计对称整数的数目
*/
#include <stdio.h>

int countSymmetricIntegers(int low, int high) {
    int res = 0;
    for (int i = low; i <= high; i++) {
        if (i < 100 && i % 11 == 0) {
            res++;
        } else if (i >= 1000 && i <= 10000) {
            int left = i / 1000 + (i % 1000) / 100;
            int right = i % 100 / 10 + i % 10;
            if (right == left) res++;
        }
    }
    return res;
}

int main () {
    printf("%d\n", countSymmetricIntegers(1, 100));
    printf("%d\n", countSymmetricIntegers(1200, 1230));

    return 0;
}