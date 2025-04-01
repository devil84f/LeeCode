/*
 * @Author: LiNing
 * @Date: 2025-04-1
 * 最长回文子串
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char* longestPalindrome(char* s) {
    int n = strlen(s);
    if (n < 2) {
        return s;
    }
    
    // 创建动态规划表
    bool dp[n][n];
    memset(dp, 0, sizeof(dp));
    
    // 所有长度为1的子串都是回文
    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
    }
    
    int maxLen = 1;
    int start = 0;
    
    // 检查长度为2的子串
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            start = i;
            maxLen = 2;
        }
    }
    
    // 检查长度大于2的子串
    for (int len = 3; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;  // 子串结束位置
            
            // 如果两端字符相同，且内部子串是回文，则当前子串也是回文
            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                
                if (len > maxLen) {
                    start = i;
                    maxLen = len;
                }
            }
        }
    }
    
    // 分配内存并复制结果
    char* result = (char*)malloc((maxLen + 1) * sizeof(char));
    strncpy(result, s + start, maxLen);
    result[maxLen] = '\0';
    
    return result;
}

int main() {
    // 测试用例
    char* testCases[] = {
        "babad",
        "cbbd",
        "a",
        "ac",
        "abcba",
        "aaaa",
        "abacdfgdcaba"
    };
    
    int numCases = sizeof(testCases) / sizeof(testCases[0]);
    
    for (int i = 0; i < numCases; i++) {
        char* result = longestPalindrome(testCases[i]);
        printf("输入: \"%s\"\n", testCases[i]);
        printf("最长回文子串: \"%s\"\n\n", result);
        free(result);  // 释放内存
    }
    
    return 0;
}