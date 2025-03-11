/*
 * @Author: LiNing
 * @Date: 2025-03-05
 * 动态队列学习、实现
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int* data;
    int front;
    int rear;
    int len;
}Queue;

Queue* QueueInit (int size) {
    Queue* q = (Queue*)malloc(sizeof(q));
    q->data = (int*)malloc(sizeof(int) * size);
    q->front = 0;
    q->rear = 0;
    q->len = size;
}

int isQueueEmpty (Queue *q) {
    return q->rear == q->front;
}

int isQueueFull (Queue *q) {
    return (q->rear + 1) % q->len == q->front;
}

void resizeQueue (Queue *q) {
    q->len *= 2;
    q->data = (int*)realloc(q->data, sizeof(int) * q->len);
}

void enqueue (Queue *q, int value) {
    if (isQueueFull(q)) {
        resizeQueue(q);
    }
    q->data[q->rear] = value;
    q->rear = (q->rear + 1) % q->len;
}

int dequeue(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("队列为空！\n");
        return 0;
    }
    int value = q->data[q->front];
    q->front = (q->front + 1) % q->len;
    return value;
}

void printQueue (Queue *q) {
    if (isQueueEmpty(q)) {
        printf("队列为空。\n");
        return;
    }
    printf("队列状态：");
    int i = q->front;
    while (i != q->rear) {
        printf("%d ", q->data[i]);
        i = (i + 1) % q->len;
    }
    printf("\n");
}

int main() {
    Queue* q = QueueInit(4);

    // 测试入队操作
    printf("开始入队操作...\n");
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    printQueue(q);

    // 尝试入队超过队列容量的元素
    enqueue(q, 50);
    enqueue(q, 60);

    printQueue(q);

    // 测试出队操作
    printf("\n开始出队操作...\n");
    printf("出队：%d\n", dequeue(q));
    printf("出队：%d\n", dequeue(q));
    printQueue(q);

    // 再次入队
    enqueue(q, 50);
    enqueue(q, 60);
    printQueue(q);

    // 继续出队直到队列为空
    printf("\n继续出队操作...\n");
    printf("出队：%d\n", dequeue(q));
    printf("出队：%d\n", dequeue(q));
    printf("出队：%d\n", dequeue(q));
    printf("出队：%d\n", dequeue(q));
    printf("出队：%d\n", dequeue(q));
    printf("出队：%d\n", dequeue(q));
    printQueue(q);

    // 尝试从空队列出队
    int i = dequeue(q); // 应该失败

    return 0;
}