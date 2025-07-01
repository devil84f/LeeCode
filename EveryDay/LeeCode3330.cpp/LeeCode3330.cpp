#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int countPossibleOriginalStrings(string word) {
        int n = word.size();
        if (n == 0) return 0;
        
        int res = 1; // ���ٰ���ԭʼ�ַ�������
        
        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && word[j] == word[i]) {
                j++;
            }
            int len = j - i;
            if (len >= 2) {
                res += len - 1;
            }
            i = j;
        }
        
        return res;
    }
};

// ���Ժ���
void test(string word, int expected) {
    Solution sol;
    int result = sol.countPossibleOriginalStrings(word);
    cout << "Input: \"" << word << "\"\n";
    cout << "Expected: " << expected << ", Got: " << result;
    cout << (result == expected ? " (PASS)" : " (FAIL)") << "\n\n";
}

int main() {
    // ��������
    test("a", 1);       // �����ַ������ظ�
    test("aa", 2);      // ������ͬ�ַ�
    test("ab", 1);      // �������ظ��ַ�
    test("aab", 2);     // һ���ظ���
    test("aabb", 3);    // �����ظ���
    test("aaa", 3);     // ������ͬ�ַ�
    test("", 0);        // ���ַ���
    test("abcabc", 1);  // ���κ������ظ�
    test("aaabbb", 5);  // �����ظ��飬���ȷֱ�Ϊ3��3
    
    return 0;
}