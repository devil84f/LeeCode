/*
 * @Author: LiNing
 * @Date: 2025-03-05
 * 堆栈基础学习、实现
 */

 #include <stdio.h>
 #include <string.h>
 #include <stdbool.h>
 #include <stdlib.h>

// 定义栈结构体
typedef struct {
    int* data;
    int top;
} Stack;

// 初始化栈
Stack* InitStack (int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->data = (int*)malloc(sizeof(int) * capacity);
    stack->top = -1;
    return stack;
}

// 检查栈是否为空
bool IsEmpty (Stack* stack) {
    return stack->top == -1;
}

// 出栈操作
int Pop (Stack* stack) {
    return stack->data[stack->top--];
}

// 入栈操作
void Push (Stack* stack, int val) {
    stack->data[++stack->top] = val;
}

// 获取栈顶元素
int StackPeek (Stack* stack) {
    return stack->data[stack->top];
}

// 释放栈内存
void StackFree (Stack* stack) {
    free(stack->data);
    free(stack);
}

// 打印栈内容
void PrintStack (Stack* stack) {
    int i = stack->top;
    while (i >= 0) {
        printf("%d ", stack->data[i--]);
    }
    printf("\n");
}

int main () {
    Stack* stack = InitStack(10);
    Push(stack, 0);
    Push(stack, 1);
    Push(stack, 2);
    Push(stack, 3);
    printf("%d\n", StackPeek(stack));
    PrintStack(stack);
    Pop(stack);
    printf("出栈后栈顶元素：%d\n", StackPeek(stack));
    PrintStack(stack);

    StackFree(stack); // 释放栈的内存
    return 0;
}