/*
 * @Author: LiNing
 * @Date: 2025-03-05
 * 堆栈实战，表达式求值
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct {
    int* data;
    int top;
    int capacity;
}Stack;

Stack* InitStack (int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->data = (int*)malloc(sizeof(int) * capacity);
    stack->top = -1;
    stack->capacity = capacity;
}

bool IsEmpty (Stack* stack) {
    return stack->top == -1;
}

void StackPush (Stack* stack, int val) {

    stack->data[++stack->top] = val;
}

infixToPostfix(char* infix, char* postfix) {
    
}

int main () {
    char infix[] = "3+5*(2-8)";
    char postfix[256];

    infixToPostfix(infix, postfix);
    printf("后缀表达式: %s", postfix);

    int result = evaluatePostfix(postfix);
    printf("计算结果: %d", result);

    return 0;
}