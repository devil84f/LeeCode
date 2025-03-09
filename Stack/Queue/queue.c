/*
 * @Author: LiNing
 * @Date: 2025-03-05
 * 队列基础学习、实现
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5  // 为了便于测试，将队列大小设为5

// 定义队列结构体
typedef struct {
    int data[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

// 初始化队列
void initQueue(Queue *q) {
    q->front = 0;
    q->rear = 0;
}

// 判断队列是否为空
int isQueueEmpty(Queue *q) {
    return q->front == q->rear;
}

// 判断队列是否已满
int isQueueFull(Queue *q) {
    return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

// 入队操作
int enqueue(Queue *q, int value) {
    if (isQueueFull(q)) {
        printf("入队失败：队列已满。\n");
        return -1; // 队列已满，无法入队
    }
    q->data[q->rear] = value;
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    printf("入队元素：%d\n", value);
    return 0;
}

// 出队操作
int dequeue(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("出队失败：队列为空。\n");
        return -1; // 队列为空，无法出队
    }
    int value = q->data[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    printf("出队元素：%d\n", value);
    return value;
}

// 打印队列当前状态（用于调试）
void printQueue(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("队列为空。\n");
        return;
    }
    printf("队列状态：");
    int i = q->front;
    while (i != q->rear) {
        printf("%d ", q->data[i]);
        i = (i + 1) % MAX_QUEUE_SIZE;
    }
    printf("\n");
}

int main() {
    Queue q;
    initQueue(&q);

    // 测试入队操作
    printf("开始入队操作...\n");
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    printQueue(&q);

    // 尝试入队超过队列容量的元素
    enqueue(&q, 50); // 应该失败

    // 测试出队操作
    printf("\n开始出队操作...\n");
    dequeue(&q); // 出队10
    dequeue(&q); // 出队20
    printQueue(&q);

    // 再次入队
    enqueue(&q, 50);
    enqueue(&q, 60);
    printQueue(&q);

    // 继续出队直到队列为空
    printf("\n继续出队操作...\n");
    dequeue(&q); // 出队30
    dequeue(&q); // 出队40
    dequeue(&q); // 出队50
    dequeue(&q); // 出队60
    printQueue(&q);

    // 尝试从空队列出队
    dequeue(&q); // 应该失败

    return 0;
}