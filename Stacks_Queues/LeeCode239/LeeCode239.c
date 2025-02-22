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

// ����˫�˶��нṹ
typedef struct {
    int *data;
    int front;
    int rear;
    int capacity;
} Deque;

// ��ʼ������
Deque* createDeque(int capacity) {
    Deque* deque = (Deque*)malloc(sizeof(Deque));
    deque->data = (int*)malloc(capacity * sizeof(int));
    deque->front = -1;
    deque->rear = -1;
    deque->capacity = capacity;
    return deque;
}

// �ж϶����Ƿ�Ϊ��
int isEmpty(Deque* deque) {
    return deque->front == -1;
}

// �ж϶����Ƿ�����
int isFull(Deque* deque) {
    return (deque->rear + 1) % deque->capacity == deque->front;
}

// �Ӷ�ͷ�Ƴ�Ԫ��
void popFront(Deque* deque) {
    if (isEmpty(deque)) return;
    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = -1;
    } else {
        deque->front = (deque->front + 1) % deque->capacity;
    }
}

// �Ӷ�β�Ƴ�Ԫ��
void popBack(Deque* deque) {
    if (isEmpty(deque)) return;
    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = -1;
    } else {
        deque->rear = (deque->rear - 1 + deque->capacity) % deque->capacity;
    }
}

// �ڶ�β���Ԫ��
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

// ��ȡ��ͷԪ��
int front(Deque* deque) {
    if (isEmpty(deque)) return -1;
    return deque->data[deque->front];
}

// ��ȡ��βԪ��
int back(Deque* deque) {
    if (isEmpty(deque)) return -1;
    return deque->data[deque->rear];
}

// �ͷŶ���
void freeDeque(Deque* deque) {
    free(deque->data);
    free(deque);
}

// �����������ֵ
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    if (numsSize == 0 || k == 0) {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = numsSize - k + 1;
    int* result = (int*)malloc(*returnSize * sizeof(int));
    Deque* deque = createDeque(numsSize);

    for (int i = 0; i < numsSize; i++) {
        // �Ƴ����ڴ����е�Ԫ��
        if (!isEmpty(deque) && front(deque) == i - k) {
            popFront(deque);
        }

        // �Ƴ�����С�ڵ�ǰԪ�ص�Ԫ��
        while (!isEmpty(deque) && nums[back(deque)] < nums[i]) {
            popBack(deque);
        }

        // ��ӵ�ǰԪ�ص�����
        pushBack(deque, i);

        // ��¼��ǰ���ڵ����ֵ
        if (i >= k - 1) {
            result[i - k + 1] = nums[front(deque)];
        }
    }

    freeDeque(deque);
    return result;
}

// ���Դ���
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