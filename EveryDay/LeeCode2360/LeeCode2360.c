/*
 * @Author: LiNing
 * @Date: 2025-03-29
 * ͼ�е����
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
            // ����������Ѿ��������Ľڵ�
            if (label[pos]) {
                // ����ýڵ�����һ�� i ѭ���б����ģ�˵���ҵ����µĻ������´�
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