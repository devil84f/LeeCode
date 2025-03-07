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

bool IsFull (Stack* stack) {
    return stack->top == stack->capacity - 1;
}

bool IsEmpty (Stack* stack) {
    return stack->top == -1;
}

void ReSize (Stack* stack) {
    stack->capacity *= 2;
    stack->data = (int*)realloc(stack->data, stack->capacity * sizeof(int));
}

void StackPush (Stack* stack, int val) {
    if (IsFull(stack)) {
        ReSize(stack);
    }
    stack->data[++stack->top] = val;
}

int StackPop (Stack* stack) {
    if (IsEmpty(stack)) {
        printf("栈为空，无法弹出\n");
        return 1;
    }
    return stack->data[stack->top--];
}

int StackPeek (Stack* stack) {
    if (IsEmpty(stack)) {
        printf("栈为空，无法查看首元素\n");
        return 1;
    }
    return stack->data[stack->top];
}

void FreeStack (Stack* stack) {
    free(stack->data);
    free(stack);
}

// 判断字符是否是运算符
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// 获取运算符优先级
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// 执行运算
int applyOp(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

// 中缀表达式转后缀表达式
void infixToPostfix(char *infix, char *postfix) {
    Stack *stack = InitStack(strlen(infix));
    int i, j = 0;

    for (i = 0; infix[i] != '\0'; i++) {
        if (isdigit(infix[i])) {
            postfix[j++] = infix[i]; // 操作数直接输出
        } else if (infix[i] == '(') {
            StackPush(stack, infix[i]); // 左括号压入堆栈
        } else if (infix[i] == ')') {
            while (!IsEmpty(stack) && StackPeek(stack) != '(') {
                postfix[j++] = StackPop(stack); // 弹出运算符
            }
            StackPop(stack); // 弹出左括号
        } else if (isOperator(infix[i])) {
            while (!IsEmpty(stack) && precedence(StackPeek(stack)) >= precedence(infix[i])) {
                postfix[j++] = StackPop(stack); // 弹出优先级高的运算符
            }
            StackPush(stack, infix[i]); // 当前运算符压入堆栈
        }
    }

    while (!IsEmpty(stack)) {
        postfix[j++] = StackPop(stack); // 弹出剩余运算符
    }
    postfix[j] = '\0'; // 添加字符串结束符
}

// 后缀表达式求值
int evaluatePostfix(char *postfix) {
    Stack *stack = InitStack(strlen(postfix));

    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isdigit(postfix[i])) {
            StackPush(stack, postfix[i] - '0'); // 操作数压入堆栈
        } else if (isOperator(postfix[i])) {
            int b = StackPop(stack);
            int a = StackPop(stack);
            StackPush(stack, applyOp(a, b, postfix[i])); // 计算结果压入堆栈
        }
    }

    int result = StackPop(stack); // 最终结果
    free(stack->data);
    free(stack);
    return result;
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