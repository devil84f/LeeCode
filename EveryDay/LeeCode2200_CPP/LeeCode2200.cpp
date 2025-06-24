#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
    int n = nums.size();
    vector<bool> marked(n, false);

    for (int i = 0; i < n; ++i) {
        if (nums[i] == key) {
            int left = max(0, i - k);
            int right = min(n - 1, i + k);
            for (int j = left; j <= right; ++j) {
                marked[j] = true;
            }
        }
    }

    vector<int> result;
    for (int i = 0; i < n; ++i) {
        if (marked[i]) {
            result.push_back(i);
        }
    }

    return result;
}

int main() {
    vector<int> nums = {3, 4, 9, 1, 3, 9, 5};
    int key = 9, k = 1;
    vector<int> res = findKDistantIndices(nums, key, k);

    cout << "k-distant indices: ";
    for (int idx : res) {
        cout << idx << " ";
    }
    cout << endl;

    return 0;
}
