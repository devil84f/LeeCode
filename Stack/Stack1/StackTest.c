/*
 * @Author: LiNing
 * @Date: 2025-03-05
 * ��ջ���ף���̬��ջ
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
        printf("�ڴ����ʧ�ܣ�\n");
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
        printf("�ڴ����ʧ�ܣ�\n");
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
        printf("��ջΪ�գ��޷�����Ԫ�ء�\n");
        return -1;
    }
    return s->items[(s->top)--];
}

int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("��ջΪ�գ�û�ж���Ԫ�ء�\n");
        return -1;
    }
    return s->items[s->top];
}

void freeStack(Stack *s) {
    free(s->items);
}

int main() {
    Stack s;
    initialize(&s, 2);  // ��ʼ����Ϊ2

    // ���Զ�ջ��չ
    printf("ѹ��Ԫ��: 10\n");
    push(&s, 10);
    printf("��ǰ��ջ����: %d\n", s.capacity);  // ���: ��ǰ��ջ����: 2

    printf("ѹ��Ԫ��: 20\n");
    push(&s, 20);
    printf("��ǰ��ջ����: %d\n", s.capacity);  // ���: ��ǰ��ջ����: 2

    printf("ѹ��Ԫ��: 30\n");
    push(&s, 30);  // ����ᴥ����ջ��չ
    printf("��ǰ��ջ����: %d\n", s.capacity);  // ���: ��ǰ��ջ����: 4

    printf("ѹ��Ԫ��: 40\n");
    push(&s, 40);
    printf("��ǰ��ջ����: %d\n", s.capacity);  // ���: ��ǰ��ջ����: 4

    printf("ѹ��Ԫ��: 50\n");
    push(&s, 50);  // ������ٴδ�����ջ��չ
    printf("��ǰ��ջ����: %d\n", s.capacity);  // ���: ��ǰ��ջ����: 8

    // ���Զ�ջ����
    printf("����Ԫ��: %d\n", peek(&s));  // ���: ����Ԫ��: 50

    printf("����Ԫ��: %d\n", pop(&s));  // ���: ����Ԫ��: 50
    printf("����Ԫ��: %d\n", pop(&s));  // ���: ����Ԫ��: 40

    printf("����Ԫ��: %d\n", peek(&s));  // ���: ����Ԫ��: 30

    // �ͷŶ�ջ�ڴ�
    freeStack(&s);
    return 0;
}