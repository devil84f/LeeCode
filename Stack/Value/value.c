/*
 * @Author: LiNing
 * @Date: 2025-03-05
 * ��ջʵս�����ʽ��ֵ
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
    printf("��׺���ʽ: %s", postfix);

    int result = evaluatePostfix(postfix);
    printf("������: %d", result);

    return 0;
}