#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int x : nums) {
            cnt[x]++;
        }

        int ans = 0;
        for (auto& [x, c] : cnt) {
            if (cnt.count(x + 1)) {
                ans = max(ans, c + cnt[x + 1]);
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    
    // 测试用例1: 普通情况
    vector<int> nums1 = {1, 3, 2, 2, 5, 2, 3, 7};
    cout << "Test Case 1: [1,3,2,2,5,2,3,7]" << endl;
    cout << "Expected: 5" << endl;
    cout << "Actual: " << solution.findLHS(nums1) << endl << endl;

    // 测试用例2: 无和谐子序列
    vector<int> nums2 = {1, 1, 1, 1};
    cout << "Test Case 2: [1,1,1,1]" << endl;
    cout << "Expected: 0" << endl;
    cout << "Actual: " << solution.findLHS(nums2) << endl << endl;

    // 测试用例3: 多个候选和谐子序列
    vector<int> nums3 = {1, 2, 3, 4, 5, 6, 7, 8};
    cout << "Test Case 3: [1,2,3,4,5,6,7,8]" << endl;
    cout << "Expected: 2" << endl;
    cout << "Actual: " << solution.findLHS(nums3) << endl << endl;

    // 测试用例4: 包含负数
    vector<int> nums4 = {-1, -2, -2, -3, 0, 0, 0};
    cout << "Test Case 4: [-1,-2,-2,-3,0,0,0]" << endl;
    cout << "Expected: 4" << endl;
    cout << "Actual: " << solution.findLHS(nums4) << endl << endl;

    // 测试用例5: 空数组
    vector<int> nums5 = {};
    cout << "Test Case 5: []" << endl;
    cout << "Expected: 0" << endl;
    cout << "Actual: " << solution.findLHS(nums5) << endl << endl;

    return 0;
}