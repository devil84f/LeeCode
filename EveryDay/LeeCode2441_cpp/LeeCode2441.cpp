#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int ret = -1;
        unordered_set<int> s;
        for (int x : nums) {
            if (s.count(-x))
                ret = max(ret, abs(x));
            s.insert(x);
        }
        return ret;
    }
};

void test(vector<int>& nums) {
    Solution solution;
    int ret = solution.findMaxK(nums);
    cout << "Result:" << ret << endl;
}

int main () {
    vector<int> nums = {-1, 10, 6, 7, -7, 1};
    vector<int> nums1 = {-1,2,-3,3};
    test(nums);
    test(nums1);

    return 0;
}