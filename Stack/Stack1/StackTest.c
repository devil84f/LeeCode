/*
 * @Author: LiNing
 * @Date: 2025-03-05
 * 堆栈进阶，动态堆栈
 */

 #include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *items;
    int top;
    int capacity;
} Stack;

void initialize(Stack *s, int initialCapacity) {
    s->items = (int *)malloc(initialCapacity * sizeof(int));
    if (s->items == NULL) {
        printf("内存分配失败！\n");
        exit(1);
    }
    s->top = -1;
    s->capacity = initialCapacity;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == s->capacity - 1;
}

void resize(Stack *s) {
    s->capacity *= 2;
    s->items = (int *)realloc(s->items, s->capacity * sizeof(int));
    if (s->items == NULL) {
        printf("内存分配失败！\n");
        exit(1);
    }
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        resize(s);
    }
    s->items[++(s->top)] = value;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("堆栈为空，无法弹出元素。\n");
        return -1;
    }
    return s->items[(s->top)--];
}

int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("堆栈为空，没有顶部元素。\n");
        return -1;
    }
    return s->items[s->top];
}

void freeStack(Stack *s) {
    free(s->items);
}

int main() {
    Stack s;
    initialize(&s, 2);  // 初始容量为2

    // 测试堆栈扩展
    printf("压入元素: 10\n");
    push(&s, 10);
    printf("当前堆栈容量: %d\n", s.capacity);  // 输出: 当前堆栈容量: 2

    printf("压入元素: 20\n");
    push(&s, 20);
    printf("当前堆栈容量: %d\n", s.capacity);  // 输出: 当前堆栈容量: 2

    printf("压入元素: 30\n");
    push(&s, 30);  // 这里会触发堆栈扩展
    printf("当前堆栈容量: %d\n", s.capacity);  // 输出: 当前堆栈容量: 4

    printf("压入元素: 40\n");
    push(&s, 40);
    printf("当前堆栈容量: %d\n", s.capacity);  // 输出: 当前堆栈容量: 4

    printf("压入元素: 50\n");
    push(&s, 50);  // 这里会再次触发堆栈扩展
    printf("当前堆栈容量: %d\n", s.capacity);  // 输出: 当前堆栈容量: 8

    // 测试堆栈操作
    printf("顶部元素: %d\n", peek(&s));  // 输出: 顶部元素: 50

    printf("弹出元素: %d\n", pop(&s));  // 输出: 弹出元素: 50
    printf("弹出元素: %d\n", pop(&s));  // 输出: 弹出元素: 40

    printf("顶部元素: %d\n", peek(&s));  // 输出: 顶部元素: 30

    // 释放堆栈内存
    freeStack(&s);
    return 0;
}