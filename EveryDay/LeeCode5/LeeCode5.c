/*
 * @Author: LiNing
 * @Date: 2025-04-1
 * ������Ӵ�
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
    
    // ������̬�滮��
    bool dp[n][n];
    memset(dp, 0, sizeof(dp));
    
    // ���г���Ϊ1���Ӵ����ǻ���
    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
    }
    
    int maxLen = 1;
    int start = 0;
    
    // ��鳤��Ϊ2���Ӵ�
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            start = i;
            maxLen = 2;
        }
    }
    
    // ��鳤�ȴ���2���Ӵ�
    for (int len = 3; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;  // �Ӵ�����λ��
            
            // ��������ַ���ͬ�����ڲ��Ӵ��ǻ��ģ���ǰ�Ӵ�Ҳ�ǻ���
            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                
                if (len > maxLen) {
                    start = i;
                    maxLen = len;
                }
            }
        }
    }
    
    // �����ڴ沢���ƽ��
    char* result = (char*)malloc((maxLen + 1) * sizeof(char));
    strncpy(result, s + start, maxLen);
    result[maxLen] = '\0';
    
    return result;
}

int main() {
    // ��������
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
        printf("����: \"%s\"\n", testCases[i]);
        printf("������Ӵ�: \"%s\"\n\n", result);
        free(result);  // �ͷ��ڴ�
    }
    
    return 0;
}