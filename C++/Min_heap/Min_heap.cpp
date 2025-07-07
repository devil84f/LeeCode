#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int res = 0;
        int i = 0, n = events.size();

        for (int day = 1; day <= 100000; ++day) {
            while (i < n && events[i][0] == day) {
                minHeap.push(events[i][1]);
                ++i;
            }
            while (!minHeap.empty() && minHeap.top() < day) {
                minHeap.pop();
            }
            if (!minHeap.empty()) {
                minHeap.pop();
                ++res;
            }
            if (i == n && minHeap.empty()) {
                break;
            }
        }
        return res;
    }
};

int main() {
    // 示例输入：每个子向量是 {start_day, end_day}
    vector<vector<int>> events = {
        {1, 2},
        {2, 3},
        {3, 4},
        {1, 2}
    };

    Solution sol;
    int result = sol.maxEvents(events);

    cout << "最多可以参加的会议数: " << result << endl;

    return 0;
}
