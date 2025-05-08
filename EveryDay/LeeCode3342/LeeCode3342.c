/*
 * @Author: LiNing
 * @Date: 2025-05-08
 * 到达最后一个房间的最少时间 II
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 55
#define INF 0x3f3f3f3f

// 定义移动方向
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

typedef struct {
    int x, y;
    int time;     // 当前到达时间
    int step;     // 步数（用于判断下一步消耗时间1还是2）
} State;

// ================== 优先队列（最小堆） ==================
#define HEAP_SIZE (MAXN * MAXN * 4)
State heap[HEAP_SIZE];
int heapSize = 0;

int compare(State a, State b) {
    return a.time - b.time;
}

void swap(State* a, State* b) {
    State tmp = *a;
    *a = *b;
    *b = tmp;
}

void push(State val) {
    heap[++heapSize] = val;
    int i = heapSize;
    while (i > 1 && compare(heap[i], heap[i/2]) < 0) {
        swap(&heap[i], &heap[i/2]);
        i /= 2;
    }
}

State pop() {
    State top = heap[1];
    heap[1] = heap[heapSize--];
    int i = 1;
    while (1) {
        int smallest = i;
        if (2*i <= heapSize && compare(heap[2*i], heap[smallest]) < 0) smallest = 2*i;
        if (2*i+1 <= heapSize && compare(heap[2*i+1], heap[smallest]) < 0) smallest = 2*i+1;
        if (smallest == i) break;
        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }
    return top;
}

int isEmpty() {
    return heapSize == 0;
}
// ========================================================

// 主算法：返回最短时间
int minimumTime(int** moveTime, int n, int m) {
    int dist[MAXN][MAXN][2]; // [x][y][step % 2]
    memset(dist, 0x3f, sizeof(dist));
    dist[0][0][0] = 0;
    heapSize = 0;

    State start = {0, 0, 0, 0};
    push(start);

    while (!isEmpty()) {
        State cur = pop();
        if (cur.x == n - 1 && cur.y == m - 1) return cur.time;

        for (int d = 0; d < 4; ++d) {
            int nx = cur.x + dx[d];
            int ny = cur.y + dy[d];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

            int stepCost = (cur.step % 2 == 0) ? 1 : 2;
            int arriveTime = cur.time + stepCost;
            if (arriveTime < moveTime[nx][ny]) {
                arriveTime = moveTime[nx][ny];
            }

            int nextStep = cur.step + 1;
            int mod = nextStep % 2;
            if (arriveTime < dist[nx][ny][mod]) {
                dist[nx][ny][mod] = arriveTime;
                State next = {nx, ny, arriveTime, nextStep};
                push(next);
            }
        }
    }

    return -1; // 不可达
}

// =================== 测试主函数 ===================

int** allocMoveTime(int grid[][MAXN], int n, int m) {
    int** mt = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; ++i) {
        mt[i] = (int*)malloc(m * sizeof(int));
        for (int j = 0; j < m; ++j) {
            mt[i][j] = grid[i][j];
        }
    }
    return mt;
}

int main() {
    // 示例输入
    int n = 3, m = 3;
    int grid[MAXN][MAXN] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    int** moveTime = allocMoveTime(grid, n, m);

    int result = minimumTime(moveTime, n, m);
    printf("最少时间为：%d\n", result);

    // 释放内存
    for (int i = 0; i < n; ++i) {
        free(moveTime[i]);
    }
    free(moveTime);
    return 0;
}
