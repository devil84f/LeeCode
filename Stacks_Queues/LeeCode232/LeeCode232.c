/*
 * @Author: LiNing
 * @Date: 2025-02-15 23:25:14
 * @LastEditors: LiNing
 * @LastEditTime: 2025-02-15 23:38:50
 * @FilePath: \LeeCode_Modularization\Stacks_Queues\LeeCode232\LeeCode232.c
 * @Description: 
 * Copyright (c) 2025 by ${git_name_email}, All Rights Reserved. 
 */
#include <stdio.h>
#include <stdlib.h>

// ����ջ�ṹ��
typedef struct {
    int* data;
    int top;
    int capacity;
} Stack;

// ��ʼ��ջ
Stack* stackCreate(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->data = (int*)malloc(sizeof(int) * capacity);
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

// ���ջ�Ƿ�Ϊ��
int stackIsEmpty(Stack* stack) {
    return stack->top == -1;
}

// ��ջ����
void stackPush(Stack* stack, int x) {
    stack->data[++stack->top] = x;
}

// ��ջ����
int stackPop(Stack* stack) {
    return stack->data[stack->top--];
}

// ��ȡջ��Ԫ��
int stackTop(Stack* stack) {
    return stack->data[stack->top];
}

// �ͷ�ջ�ڴ�
void stackFree(Stack* stack) {
    free(stack->data);
    free(stack);
}

// ������нṹ��
typedef struct {
    Stack* stackA;
    Stack* stackB;
} MyQueue;

// ��ʼ������
MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->stackA = stackCreate(100); // ջ A �ĳ�ʼ����
    queue->stackB = stackCreate(100); // ջ B �ĳ�ʼ����
    return queue;
}

// ��Ӳ���
void myQueuePush(MyQueue* obj, int x) {
    stackPush(obj->stackA, x);  // ��Ԫ������ջ A
}

// ���Ӳ���
int myQueuePop(MyQueue* obj) {
    if (stackIsEmpty(obj->stackB)) {  // ���ջ B Ϊ��
        while (!stackIsEmpty(obj->stackA)) {  // ��ջ A �е�Ԫ��ȫ���Ƶ�ջ B
            stackPush(obj->stackB, stackPop(obj->stackA));
        }
    }
    return stackPop(obj->stackB);  // ��ջ B ��ջ
}

// ��ȡ����ͷ��Ԫ��
int myQueuePeek(MyQueue* obj) {
    if (stackIsEmpty(obj->stackB)) {  // ���ջ B Ϊ��
        while (!stackIsEmpty(obj->stackA)) {  // ��ջ A �е�Ԫ��ȫ���Ƶ�ջ B
            stackPush(obj->stackB, stackPop(obj->stackA));
        }
    }
    return stackTop(obj->stackB);  // ����ջ B ����Ԫ��
}

// �������Ƿ�Ϊ��
int myQueueEmpty(MyQueue* obj) {
    return stackIsEmpty(obj->stackA) && stackIsEmpty(obj->stackB);  // ջ A ��ջ B ��Ϊ��ʱ����Ϊ��
}

// �ͷŶ����ڴ�
void myQueueFree(MyQueue* obj) {
    stackFree(obj->stackA);
    stackFree(obj->stackB);
    free(obj);
}

// ����������
int main() {
    MyQueue* queue = myQueueCreate();
    
    myQueuePush(queue, 1);
    myQueuePush(queue, 2);
    printf("peek: %d\n", myQueuePeek(queue));  // Ӧ��� 1
    printf("pop: %d\n", myQueuePop(queue));   // Ӧ��� 1
    printf("empty: %d\n", myQueueEmpty(queue));  // Ӧ��� 0

    myQueuePush(queue, 3);
    printf("peek: %d\n", myQueuePeek(queue));  // Ӧ��� 2
    printf("pop: %d\n", myQueuePop(queue));   // Ӧ��� 2
    printf("pop: %d\n", myQueuePop(queue));   // Ӧ��� 3
    printf("empty: %d\n", myQueueEmpty(queue));  // Ӧ��� 1

    myQueueFree(queue);
    return 0;
}
