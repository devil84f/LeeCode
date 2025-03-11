/*
 * @Author: LiNing
 * @Date: 2025-03-05
 * ��̬����ѧϰ��ʵ��
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
        printf("����Ϊ�գ�\n");
        return 0;
    }
    int value = q->data[q->front];
    q->front = (q->front + 1) % q->len;
    return value;
}

void printQueue (Queue *q) {
    if (isQueueEmpty(q)) {
        printf("����Ϊ�ա�\n");
        return;
    }
    printf("����״̬��");
    int i = q->front;
    while (i != q->rear) {
        printf("%d ", q->data[i]);
        i = (i + 1) % q->len;
    }
    printf("\n");
}

int main() {
    Queue* q = QueueInit(4);

    // ������Ӳ���
    printf("��ʼ��Ӳ���...\n");
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    printQueue(q);

    // ������ӳ�������������Ԫ��
    enqueue(q, 50);
    enqueue(q, 60);

    printQueue(q);

    // ���Գ��Ӳ���
    printf("\n��ʼ���Ӳ���...\n");
    printf("���ӣ�%d\n", dequeue(q));
    printf("���ӣ�%d\n", dequeue(q));
    printQueue(q);

    // �ٴ����
    enqueue(q, 50);
    enqueue(q, 60);
    printQueue(q);

    // ��������ֱ������Ϊ��
    printf("\n�������Ӳ���...\n");
    printf("���ӣ�%d\n", dequeue(q));
    printf("���ӣ�%d\n", dequeue(q));
    printf("���ӣ�%d\n", dequeue(q));
    printf("���ӣ�%d\n", dequeue(q));
    printf("���ӣ�%d\n", dequeue(q));
    printf("���ӣ�%d\n", dequeue(q));
    printQueue(q);

    // ���Դӿն��г���
    int i = dequeue(q); // Ӧ��ʧ��

    return 0;
}