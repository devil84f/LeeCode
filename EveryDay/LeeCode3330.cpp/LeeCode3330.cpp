#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int countPossibleOriginalStrings(string word) {
        int n = word.size();
        if (n == 0) return 0;
        
        int res = 1; // 至少包含原始字符串本身
        
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

// 测试函数
void test(string word, int expected) {
    Solution sol;
    int result = sol.countPossibleOriginalStrings(word);
    cout << "Input: \"" << word << "\"\n";
    cout << "Expected: " << expected << ", Got: " << result;
    cout << (result == expected ? " (PASS)" : " (FAIL)") << "\n\n";
}

int main() {
    // 测试用例
    test("a", 1);       // 单个字符，无重复
    test("aa", 2);      // 两个相同字符
    test("ab", 1);      // 无连续重复字符
    test("aab", 2);     // 一个重复块
    test("aabb", 3);    // 两个重复块
    test("aaa", 3);     // 三个相同字符
    test("", 0);        // 空字符串
    test("abcabc", 1);  // 无任何连续重复
    test("aaabbb", 5);  // 两个重复块，长度分别为3和3
    
    return 0;
}