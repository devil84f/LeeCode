/*
 * @Author: LiNing
 * @Date: 2025-03-29
 * 图中的最长环
*/
#include <stdio.h>
#include <stdlib.h>

int longestCycle(int* edges, int edgesSize) {
    int n = edgesSize;
    int* label = (int*)calloc(n, sizeof(int));
    int current_label = 0, ans = -1;
    for (int i = 0; i < n; ++i) {
        if (label[i]) {
            continue;
        }
        int pos = i, start_label = current_label;
        while (pos != -1) {
            ++current_label;
            // 如果遇到了已经遍历过的节点
            if (label[pos]) {
                // 如果该节点是这一次 i 循环中遍历的，说明找到了新的环，更新答案
                if (label[pos] > start_label) {
                    ans = ans > (current_label - label[pos]) ? ans : (current_label - label[pos]);
                }
                break;
            }
            label[pos] = current_label;
            pos = edges[pos];
        }
    }
    free(label);
    return ans;
}

int main () {
    int edge[] = {3, 3, 4, 2, 3};
    int edgeSize = sizeof(edge) / sizeof(edge[0]);
    int result = longestCycle(edge, edgeSize);
    printf("%d\n", result);

    return 0;
}