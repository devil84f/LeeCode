#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<array<int, 3>> jobs(n);
        for (int i = 0; i < n; i++) {
            jobs[i] = {endTime[i], startTime[i], profit[i]};
        }
        
        // 排序（语法相同）
        sort(jobs.begin(), jobs.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });
        
        // 初始化dp数组
        vector<int> dp(n);
        dp[0] = jobs[0][2];
        
        for(int i = 1; i < n; ++i) {
            // 不选当前工作
            int profit1 = dp[i-1];
            
            // 选当前工作
            int profit2 = jobs[i][2];
            int last = -1;
            
            // 二分查找最后一个不冲突的工作
            int left = 0, right = i-1;
            while(left <= right) {
                int mid = left + (right - left)/2;
                if(jobs[mid][1] <= jobs[i][0]) {
                    last = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            
            if(last != -1) {
                profit2 += dp[last];
            }
            
            dp[i] = max(profit1, profit2);
        }
        
        return dp.back();
    }
};

int main() {
    Solution sol;
    vector<int> start = {1,2,3,3}, end = {3,4,5,6}, profit = {50,10,40,70};
    cout << sol.jobScheduling(start, end, profit) << endl; // 输出120
    return 0;
}