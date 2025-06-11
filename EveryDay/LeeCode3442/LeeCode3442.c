#include <stdio.h>
#include <string.h>
#include <limits.h>

int maxFrequencyDifference(char* s) {
    int freq[26] = {0}; // �洢ÿ����ĸ�ĳ���Ƶ��
    int len = strlen(s);
    
    // ͳ��ÿ���ַ��ĳ���Ƶ��
    for (int i = 0; i < len; i++) {
        freq[s[i] - 'a']++;
    }
    
    int maxOdd = -1;  // ����������Ƶ��
    int minEven = INT_MAX; // ��С��ż����Ƶ�ʣ�������0��
    int hasEven = 0;  // �Ƿ��з����ż����Ƶ��
    
    // ����������ĸ��Ƶ��
    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 == 1) { // ������
            if (freq[i] > maxOdd) {
                maxOdd = freq[i];
            }
        } else { // ż����
            if (freq[i] > 0) { // ֻ���Ƿ����ż����
                hasEven = 1;
                if (freq[i] < minEven) {
                    minEven = freq[i];
                }
            }
        }
    }
    
    // �����������
    if (maxOdd == -1) { // û���������ַ�
        return 0;
    }
    if (!hasEven) { // û�з����ż�����ַ�
        minEven = 0;
    }
    
    return maxOdd - minEven;
}

// ����������
int main() {
    // ��������1
    char s1[] = "aaaaabbc";
    printf("��������1: \"aaaaabbc\"\n");
    printf("Ԥ�ڽ��: 3\n");
    printf("ʵ�ʽ��: %d\n\n", maxFrequencyDifference(s1));
    
    // ��������2
    char s2[] = "abcabcab";
    printf("��������2: \"abcabcab\"\n");
    printf("Ԥ�ڽ��: 1\n");
    printf("ʵ�ʽ��: %d\n\n", maxFrequencyDifference(s2));
    
    // ��������3
    char s3[] = "aabbcc";
    printf("��������3: \"aabbcc\"\n");
    printf("Ԥ�ڽ��: 0\n");
    printf("ʵ�ʽ��: %d\n\n", maxFrequencyDifference(s3));
    
    // ��������4
    char s4[] = "zzzzzz";
    printf("��������4: \"zzzzzz\"\n");
    printf("Ԥ�ڽ��: 6\n");
    printf("ʵ�ʽ��: %d\n\n", maxFrequencyDifference(s4));
    
    // ��������5
    char s5[] = "a";
    printf("��������5: \"a\"\n");
    printf("Ԥ�ڽ��: 1\n");
    printf("ʵ�ʽ��: %d\n\n", maxFrequencyDifference(s5));
    
    return 0;
}