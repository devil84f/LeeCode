/*
 * @Author: LiNing
 * @Date: 2025-04-13
 * 统计好数字的数目
*/

#include <stdio.h>
#include <math.h>

// 快速幂算法，用于计算(base^power) % mod
long long fastPow(long long base, long long power, long long mod) {
    long long result = 1;
    while (power > 0) {
        if (power % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        power = power / 2;
    }
    return result;
}

// 主解法函数
int countGoodNumbers(long long n) {
    const long long MOD = 1e9 + 7;
    long long evenPositions = (n + 1) / 2; // 奇数位（从1开始计数）
    long long oddPositions = n / 2;        // 偶数位
    
    long long evenChoices = fastPow(5, evenPositions, MOD); // 偶数位有5种选择(0,2,4,6,8)
    long long oddChoices = fastPow(4, oddPositions, MOD);    // 奇数位有4种选择(2,3,5,7)
    
    return (evenChoices * oddChoices) % MOD;
}

// 测试主函数
int main() {
    // 测试用例
    long long testCases[] = {1, 4, 50, 100000000000000};
    int expected[] = {5, 400, 564908303, 643535977};
    int numTests = sizeof(testCases) / sizeof(testCases[0]);
    
    for (int i = 0; i < numTests; i++) {
        long long n = testCases[i];
        int result = countGoodNumbers(n);
        printf("n = %lld\n", n);
        printf("Expected: %d, Result: %d\n", expected[i], result);
        printf(result == expected[i] ? "Test Passed!\n" : "Test Failed!\n");
        printf("-------------------\n");
    }
    
    return 0;
}