#include <stdio.h>
#include <string.h>
#include <limits.h>

int maxFrequencyDifference(char* s) {
    int freq[26] = {0}; // 存储每个字母的出现频率
    int len = strlen(s);
    
    // 统计每个字符的出现频率
    for (int i = 0; i < len; i++) {
        freq[s[i] - 'a']++;
    }
    
    int maxOdd = -1;  // 最大的奇数次频率
    int minEven = INT_MAX; // 最小的偶数次频率（不包括0）
    int hasEven = 0;  // 是否有非零的偶数次频率
    
    // 遍历所有字母的频率
    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 == 1) { // 奇数次
            if (freq[i] > maxOdd) {
                maxOdd = freq[i];
            }
        } else { // 偶数次
            if (freq[i] > 0) { // 只考虑非零的偶数次
                hasEven = 1;
                if (freq[i] < minEven) {
                    minEven = freq[i];
                }
            }
        }
    }
    
    // 处理特殊情况
    if (maxOdd == -1) { // 没有奇数次字符
        return 0;
    }
    if (!hasEven) { // 没有非零的偶数次字符
        minEven = 0;
    }
    
    return maxOdd - minEven;
}

// 测试主函数
int main() {
    // 测试用例1
    char s1[] = "aaaaabbc";
    printf("测试用例1: \"aaaaabbc\"\n");
    printf("预期结果: 3\n");
    printf("实际结果: %d\n\n", maxFrequencyDifference(s1));
    
    // 测试用例2
    char s2[] = "abcabcab";
    printf("测试用例2: \"abcabcab\"\n");
    printf("预期结果: 1\n");
    printf("实际结果: %d\n\n", maxFrequencyDifference(s2));
    
    // 测试用例3
    char s3[] = "aabbcc";
    printf("测试用例3: \"aabbcc\"\n");
    printf("预期结果: 0\n");
    printf("实际结果: %d\n\n", maxFrequencyDifference(s3));
    
    // 测试用例4
    char s4[] = "zzzzzz";
    printf("测试用例4: \"zzzzzz\"\n");
    printf("预期结果: 6\n");
    printf("实际结果: %d\n\n", maxFrequencyDifference(s4));
    
    // 测试用例5
    char s5[] = "a";
    printf("测试用例5: \"a\"\n");
    printf("预期结果: 1\n");
    printf("实际结果: %d\n\n", maxFrequencyDifference(s5));
    
    return 0;
}