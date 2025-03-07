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
        printf("ջΪ�գ��޷�����\n");
        return 1;
    }
    return stack->data[stack->top--];
}

int StackPeek (Stack* stack) {
    if (IsEmpty(stack)) {
        printf("ջΪ�գ��޷��鿴��Ԫ��\n");
        return 1;
    }
    return stack->data[stack->top];
}

void FreeStack (Stack* stack) {
    free(stack->data);
    free(stack);
}

// �ж��ַ��Ƿ��������
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// ��ȡ��������ȼ�
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// ִ������
int applyOp(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

// ��׺���ʽת��׺���ʽ
void infixToPostfix(char *infix, char *postfix) {
    Stack *stack = InitStack(strlen(infix));
    int i, j = 0;

    for (i = 0; infix[i] != '\0'; i++) {
        if (isdigit(infix[i])) {
            postfix[j++] = infix[i]; // ������ֱ�����
        } else if (infix[i] == '(') {
            StackPush(stack, infix[i]); // ������ѹ���ջ
        } else if (infix[i] == ')') {
            while (!IsEmpty(stack) && StackPeek(stack) != '(') {
                postfix[j++] = StackPop(stack); // ���������
            }
            StackPop(stack); // ����������
        } else if (isOperator(infix[i])) {
            while (!IsEmpty(stack) && precedence(StackPeek(stack)) >= precedence(infix[i])) {
                postfix[j++] = StackPop(stack); // �������ȼ��ߵ������
            }
            StackPush(stack, infix[i]); // ��ǰ�����ѹ���ջ
        }
    }

    while (!IsEmpty(stack)) {
        postfix[j++] = StackPop(stack); // ����ʣ�������
    }
    postfix[j] = '\0'; // ����ַ���������
}

// ��׺���ʽ��ֵ
int evaluatePostfix(char *postfix) {
    Stack *stack = InitStack(strlen(postfix));

    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isdigit(postfix[i])) {
            StackPush(stack, postfix[i] - '0'); // ������ѹ���ջ
        } else if (isOperator(postfix[i])) {
            int b = StackPop(stack);
            int a = StackPop(stack);
            StackPush(stack, applyOp(a, b, postfix[i])); // ������ѹ���ջ
        }
    }

    int result = StackPop(stack); // ���ս��
    free(stack->data);
    free(stack);
    return result;
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