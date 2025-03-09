/*
 * @Author: LiNing
 * @Date: 2025-03-05
 * ���л���ѧϰ��ʵ��
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5  // Ϊ�˱��ڲ��ԣ������д�С��Ϊ5

// ������нṹ��
typedef struct {
    int data[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

// ��ʼ������
void initQueue(Queue *q) {
    q->front = 0;
    q->rear = 0;
}

// �ж϶����Ƿ�Ϊ��
int isQueueEmpty(Queue *q) {
    return q->front == q->rear;
}

// �ж϶����Ƿ�����
int isQueueFull(Queue *q) {
    return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

// ��Ӳ���
int enqueue(Queue *q, int value) {
    if (isQueueFull(q)) {
        printf("���ʧ�ܣ�����������\n");
        return -1; // �����������޷����
    }
    q->data[q->rear] = value;
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    printf("���Ԫ�أ�%d\n", value);
    return 0;
}

// ���Ӳ���
int dequeue(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("����ʧ�ܣ�����Ϊ�ա�\n");
        return -1; // ����Ϊ�գ��޷�����
    }
    int value = q->data[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    printf("����Ԫ�أ�%d\n", value);
    return value;
}

// ��ӡ���е�ǰ״̬�����ڵ��ԣ�
void printQueue(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("����Ϊ�ա�\n");
        return;
    }
    printf("����״̬��");
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

    // ������Ӳ���
    printf("��ʼ��Ӳ���...\n");
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    printQueue(&q);

    // ������ӳ�������������Ԫ��
    enqueue(&q, 50); // Ӧ��ʧ��

    // ���Գ��Ӳ���
    printf("\n��ʼ���Ӳ���...\n");
    dequeue(&q); // ����10
    dequeue(&q); // ����20
    printQueue(&q);

    // �ٴ����
    enqueue(&q, 50);
    enqueue(&q, 60);
    printQueue(&q);

    // ��������ֱ������Ϊ��
    printf("\n�������Ӳ���...\n");
    dequeue(&q); // ����30
    dequeue(&q); // ����40
    dequeue(&q); // ����50
    dequeue(&q); // ����60
    printQueue(&q);

    // ���Դӿն��г���
    dequeue(&q); // Ӧ��ʧ��

    return 0;
}