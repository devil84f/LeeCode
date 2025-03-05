/*
 * @Author: LiNing
 * @Date: 2025-03-05
 * ��ջ����ѧϰ��ʵ��
 */

 #include <stdio.h>
 #include <string.h>
 #include <stdbool.h>
 #include <stdlib.h>

// ����ջ�ṹ��
typedef struct {
    int* data;
    int top;
} Stack;

// ��ʼ��ջ
Stack* InitStack (int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->data = (int*)malloc(sizeof(int) * capacity);
    stack->top = -1;
    return stack;
}

// ���ջ�Ƿ�Ϊ��
bool IsEmpty (Stack* stack) {
    return stack->top == -1;
}

// ��ջ����
int Pop (Stack* stack) {
    return stack->data[stack->top--];
}

// ��ջ����
void Push (Stack* stack, int val) {
    stack->data[++stack->top] = val;
}

// ��ȡջ��Ԫ��
int StackPeek (Stack* stack) {
    return stack->data[stack->top];
}

// �ͷ�ջ�ڴ�
void StackFree (Stack* stack) {
    free(stack->data);
    free(stack);
}

// ��ӡջ����
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
    printf("��ջ��ջ��Ԫ�أ�%d\n", StackPeek(stack));
    PrintStack(stack);

    StackFree(stack); // �ͷ�ջ���ڴ�
    return 0;
}