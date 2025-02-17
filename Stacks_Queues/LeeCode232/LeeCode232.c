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

// 定义栈结构体
typedef struct {
    int* data;
    int top;
    int capacity;
} Stack;

// 初始化栈
Stack* stackCreate(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->data = (int*)malloc(sizeof(int) * capacity);
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

// 检查栈是否为空
int stackIsEmpty(Stack* stack) {
    return stack->top == -1;
}

// 入栈操作
void stackPush(Stack* stack, int x) {
    stack->data[++stack->top] = x;
}

// 出栈操作
int stackPop(Stack* stack) {
    return stack->data[stack->top--];
}

// 获取栈顶元素
int stackTop(Stack* stack) {
    return stack->data[stack->top];
}

// 释放栈内存
void stackFree(Stack* stack) {
    free(stack->data);
    free(stack);
}

// 定义队列结构体
typedef struct {
    Stack* stackA;
    Stack* stackB;
} MyQueue;

// 初始化队列
MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->stackA = stackCreate(100); // 栈 A 的初始容量
    queue->stackB = stackCreate(100); // 栈 B 的初始容量
    return queue;
}

// 入队操作
void myQueuePush(MyQueue* obj, int x) {
    stackPush(obj->stackA, x);  // 将元素推入栈 A
}

// 出队操作
int myQueuePop(MyQueue* obj) {
    if (stackIsEmpty(obj->stackB)) {  // 如果栈 B 为空
        while (!stackIsEmpty(obj->stackA)) {  // 将栈 A 中的元素全部移到栈 B
            stackPush(obj->stackB, stackPop(obj->stackA));
        }
    }
    return stackPop(obj->stackB);  // 从栈 B 出栈
}

// 获取队列头部元素
int myQueuePeek(MyQueue* obj) {
    if (stackIsEmpty(obj->stackB)) {  // 如果栈 B 为空
        while (!stackIsEmpty(obj->stackA)) {  // 将栈 A 中的元素全部移到栈 B
            stackPush(obj->stackB, stackPop(obj->stackA));
        }
    }
    return stackTop(obj->stackB);  // 返回栈 B 顶部元素
}

// 检查队列是否为空
int myQueueEmpty(MyQueue* obj) {
    return stackIsEmpty(obj->stackA) && stackIsEmpty(obj->stackB);  // 栈 A 和栈 B 都为空时队列为空
}

// 释放队列内存
void myQueueFree(MyQueue* obj) {
    stackFree(obj->stackA);
    stackFree(obj->stackB);
    free(obj);
}

// 测试主函数
int main() {
    MyQueue* queue = myQueueCreate();
    
    myQueuePush(queue, 1);
    myQueuePush(queue, 2);
    printf("peek: %d\n", myQueuePeek(queue));  // 应输出 1
    printf("pop: %d\n", myQueuePop(queue));   // 应输出 1
    printf("empty: %d\n", myQueueEmpty(queue));  // 应输出 0

    myQueuePush(queue, 3);
    printf("peek: %d\n", myQueuePeek(queue));  // 应输出 2
    printf("pop: %d\n", myQueuePop(queue));   // 应输出 2
    printf("pop: %d\n", myQueuePop(queue));   // 应输出 3
    printf("empty: %d\n", myQueueEmpty(queue));  // 应输出 1

    myQueueFree(queue);
    return 0;
}
