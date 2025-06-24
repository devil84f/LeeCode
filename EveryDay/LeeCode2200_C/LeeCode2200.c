#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int* findKDistantIndices(int* nums, int n, int key, int k, int* returnSize) {
    int *ans = malloc(n * sizeof(int));
    *returnSize = 0;
    int start = 0;
    for (int i = 0; i < n; ++i) {
        if (nums[i] == key) {
            int left = i - k;
            if (left < 0) left = 0;
            int right = i + k;
            if (right >= n) right = n - 1;
            while (start <= right) {
                if (start >= left) {
                    ans[(*returnSize)++] = start;
                }
                ++start;
            }
        }
    }
    return ans;
}

int main() {
    int nums[] = {3,4,9,1,3,9,5};
    int n = sizeof(nums)/sizeof(nums[0]);
    int key = 9, k = 1, sz;
    int *res = findKDistantIndices(nums, n, key, k, &sz);
    printf("result indices: ");
    for (int i = 0; i < sz; i++) {
        printf("%d ", res[i]);
    }
    free(res);
    return 0;
}
