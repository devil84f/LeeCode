/*
 * @Author: LiNing
 * @Date: 2025-02-15 23:44:20
 * @LastEditors: LiNing
 * @LastEditTime: 2025-02-15 23:49:31
 * @FilePath: \LeeCode_Modularization\Stacks_Queues\LeeCode225\LeeCode225.c
 * @Description: 
 * Copyright (c) 2025 by ${git_name_email}, All Rights Reserved. 
 */

#include <stdio.h>
#include <stdlib.h>

// ������нṹ��
typedef struct {
    int* data;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;

// ��ʼ������
Queue* queueCreate(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->data = (int*)malloc(sizeof(int) * capacity);
    queue->front = 0;
    queue->rear = 0;
    queue->size = 0;
    queue->capacity = capacity;
    return queue;
}

// ��Ӳ���
void queueEnqueue(Queue* queue, int x) {
    queue->data[queue->rear] = x;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->size++;
}

// ���Ӳ���
int queueDequeue(Queue* queue) {
    int value = queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return value;
}

// ��ȡ����ͷ��Ԫ��
int queueFront(Queue* queue) {
    return queue->data[queue->front];
}

// �ж϶����Ƿ�Ϊ��
int queueIsEmpty(Queue* queue) {
    return queue->size == 0;
}

// �ͷŶ����ڴ�
void queueFree(Queue* queue) {
    free(queue->data);
    free(queue);
}

// ����ջ�ṹ��
typedef struct {
    Queue* queue1;
    Queue* queue2;
} MyStack;

// ��ʼ��ջ
MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    stack->queue1 = queueCreate(100);  // ���� 1 ��ʼ��
    stack->queue2 = queueCreate(100);  // ���� 2 ��ʼ��
    return stack;
}

// ��ջ����
void myStackPush(MyStack* obj, int x) {
    queueEnqueue(obj->queue1, x);
}

// ��ջ����
int myStackPop(MyStack* obj) {
    if (queueIsEmpty(obj->queue1)) {
        return -1;  // ���ջΪ�գ����� -1
    }
    while (obj->queue1->size > 1) {
        queueEnqueue(obj->queue2, queueDequeue(obj->queue1));  // ������ 1 �е�Ԫ��ת�Ƶ����� 2 ��
    }
    int poppedValue = queueDequeue(obj->queue1);  // ����ջ��Ԫ��
    Queue* temp = obj->queue1;
    obj->queue1 = obj->queue2;
    obj->queue2 = temp;  // �������� 1 �Ͷ��� 2
    return poppedValue;
}

// ��ȡջ��Ԫ��
int myStackTop(MyStack* obj) {
    if (queueIsEmpty(obj->queue1)) {
        return -1;  // ���ջΪ�գ����� -1
    }
    while (obj->queue1->size > 1) {
        queueEnqueue(obj->queue2, queueDequeue(obj->queue1));  // ������ 1 �е�Ԫ��ת�Ƶ����� 2 ��
    }
    int topValue = queueFront(obj->queue1);  // ��ȡջ��Ԫ��
    queueEnqueue(obj->queue2, queueDequeue(obj->queue1));  // ��ջ��Ԫ�طŻض��� 2
    Queue* temp = obj->queue1;
    obj->queue1 = obj->queue2;
    obj->queue2 = temp;  // �������� 1 �Ͷ��� 2
    return topValue;
}

// ���ջ�Ƿ�Ϊ��
int myStackEmpty(MyStack* obj) {
    return queueIsEmpty(obj->queue1);  // ������� 1 Ϊ�գ���ջΪ��
}

// �ͷ�ջ�ڴ�
void myStackFree(MyStack* obj) {
    queueFree(obj->queue1);
    queueFree(obj->queue2);
    free(obj);
}

// ����������
int main() {
    MyStack* stack = myStackCreate();
    
    myStackPush(stack, 1);
    myStackPush(stack, 2);
    printf("top: %d\n", myStackTop(stack));  // Ӧ��� 2
    printf("pop: %d\n", myStackPop(stack));   // Ӧ��� 2
    printf("empty: %d\n", myStackEmpty(stack));  // Ӧ��� 0

    myStackPush(stack, 3);
    printf("top: %d\n", myStackTop(stack));  // Ӧ��� 3
    printf("pop: %d\n", myStackPop(stack));   // Ӧ��� 3
    printf("pop: %d\n", myStackPop(stack));   // Ӧ��� 1
    printf("empty: %d\n", myStackEmpty(stack));  // Ӧ��� 1

    myStackFree(stack);
    return 0;
}
