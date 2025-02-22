/*
 * @Author: LiNing
 * @Date: 2025-02-22 15:07:46
 * @LastEditors: LiNing
 * @LastEditTime: 2025-02-22 15:13:34
 * @FilePath: \LeeCode_Modularization\Stacks_Queues\LeeCode239\LeeCode239.c
 * @Description: 
 * Copyright (c) 2025 by ${git_name_email}, All Rights Reserved. 
 */

#include <stdio.h>
#include <stdlib.h>

// 定义双端队列结构
typedef struct {
    int *data;
    int front;
    int rear;
    int capacity;
} Deque;

// 初始化队列
Deque* createDeque(int capacity) {
    Deque* deque = (Deque*)malloc(sizeof(Deque));
    deque->data = (int*)malloc(capacity * sizeof(int));
    deque->front = -1;
    deque->rear = -1;
    deque->capacity = capacity;
    return deque;
}

// 判断队列是否为空
int isEmpty(Deque* deque) {
    return deque->front == -1;
}

// 判断队列是否已满
int isFull(Deque* deque) {
    return (deque->rear + 1) % deque->capacity == deque->front;
}

// 从队头移除元素
void popFront(Deque* deque) {
    if (isEmpty(deque)) return;
    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = -1;
    } else {
        deque->front = (deque->front + 1) % deque->capacity;
    }
}

// 从队尾移除元素
void popBack(Deque* deque) {
    if (isEmpty(deque)) return;
    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = -1;
    } else {
        deque->rear = (deque->rear - 1 + deque->capacity) % deque->capacity;
    }
}

// 在队尾添加元素
void pushBack(Deque* deque, int value) {
    if (isFull(deque)) return;
    if (isEmpty(deque)) {
        deque->front = 0;
        deque->rear = 0;
    } else {
        deque->rear = (deque->rear + 1) % deque->capacity;
    }
    deque->data[deque->rear] = value;
}

// 获取队头元素
int front(Deque* deque) {
    if (isEmpty(deque)) return -1;
    return deque->data[deque->front];
}

// 获取队尾元素
int back(Deque* deque) {
    if (isEmpty(deque)) return -1;
    return deque->data[deque->rear];
}

// 释放队列
void freeDeque(Deque* deque) {
    free(deque->data);
    free(deque);
}

// 滑动窗口最大值
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    if (numsSize == 0 || k == 0) {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = numsSize - k + 1;
    int* result = (int*)malloc(*returnSize * sizeof(int));
    Deque* deque = createDeque(numsSize);

    for (int i = 0; i < numsSize; i++) {
        // 移除不在窗口中的元素
        if (!isEmpty(deque) && front(deque) == i - k) {
            popFront(deque);
        }

        // 移除所有小于当前元素的元素
        while (!isEmpty(deque) && nums[back(deque)] < nums[i]) {
            popBack(deque);
        }

        // 添加当前元素的索引
        pushBack(deque, i);

        // 记录当前窗口的最大值
        if (i >= k - 1) {
            result[i - k + 1] = nums[front(deque)];
        }
    }

    freeDeque(deque);
    return result;
}

// 测试代码
int main() {
    int nums[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 3;
    int returnSize;
    int* result = maxSlidingWindow(nums, numsSize, k, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}