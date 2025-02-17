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

// 定义队列结构体
typedef struct {
    int* data;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;

// 初始化队列
Queue* queueCreate(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->data = (int*)malloc(sizeof(int) * capacity);
    queue->front = 0;
    queue->rear = 0;
    queue->size = 0;
    queue->capacity = capacity;
    return queue;
}

// 入队操作
void queueEnqueue(Queue* queue, int x) {
    queue->data[queue->rear] = x;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->size++;
}

// 出队操作
int queueDequeue(Queue* queue) {
    int value = queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return value;
}

// 获取队列头部元素
int queueFront(Queue* queue) {
    return queue->data[queue->front];
}

// 判断队列是否为空
int queueIsEmpty(Queue* queue) {
    return queue->size == 0;
}

// 释放队列内存
void queueFree(Queue* queue) {
    free(queue->data);
    free(queue);
}

// 定义栈结构体
typedef struct {
    Queue* queue1;
    Queue* queue2;
} MyStack;

// 初始化栈
MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    stack->queue1 = queueCreate(100);  // 队列 1 初始化
    stack->queue2 = queueCreate(100);  // 队列 2 初始化
    return stack;
}

// 入栈操作
void myStackPush(MyStack* obj, int x) {
    queueEnqueue(obj->queue1, x);
}

// 出栈操作
int myStackPop(MyStack* obj) {
    if (queueIsEmpty(obj->queue1)) {
        return -1;  // 如果栈为空，返回 -1
    }
    while (obj->queue1->size > 1) {
        queueEnqueue(obj->queue2, queueDequeue(obj->queue1));  // 将队列 1 中的元素转移到队列 2 中
    }
    int poppedValue = queueDequeue(obj->queue1);  // 弹出栈顶元素
    Queue* temp = obj->queue1;
    obj->queue1 = obj->queue2;
    obj->queue2 = temp;  // 交换队列 1 和队列 2
    return poppedValue;
}

// 获取栈顶元素
int myStackTop(MyStack* obj) {
    if (queueIsEmpty(obj->queue1)) {
        return -1;  // 如果栈为空，返回 -1
    }
    while (obj->queue1->size > 1) {
        queueEnqueue(obj->queue2, queueDequeue(obj->queue1));  // 将队列 1 中的元素转移到队列 2 中
    }
    int topValue = queueFront(obj->queue1);  // 获取栈顶元素
    queueEnqueue(obj->queue2, queueDequeue(obj->queue1));  // 将栈顶元素放回队列 2
    Queue* temp = obj->queue1;
    obj->queue1 = obj->queue2;
    obj->queue2 = temp;  // 交换队列 1 和队列 2
    return topValue;
}

// 检查栈是否为空
int myStackEmpty(MyStack* obj) {
    return queueIsEmpty(obj->queue1);  // 如果队列 1 为空，则栈为空
}

// 释放栈内存
void myStackFree(MyStack* obj) {
    queueFree(obj->queue1);
    queueFree(obj->queue2);
    free(obj);
}

// 测试主函数
int main() {
    MyStack* stack = myStackCreate();
    
    myStackPush(stack, 1);
    myStackPush(stack, 2);
    printf("top: %d\n", myStackTop(stack));  // 应输出 2
    printf("pop: %d\n", myStackPop(stack));   // 应输出 2
    printf("empty: %d\n", myStackEmpty(stack));  // 应输出 0

    myStackPush(stack, 3);
    printf("top: %d\n", myStackTop(stack));  // 应输出 3
    printf("pop: %d\n", myStackPop(stack));   // 应输出 3
    printf("pop: %d\n", myStackPop(stack));   // 应输出 1
    printf("empty: %d\n", myStackEmpty(stack));  // 应输出 1

    myStackFree(stack);
    return 0;
}
