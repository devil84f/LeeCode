/*
 * @Author: LiNing
 * @Date: 2025-02-26 22:53:29
 * @LastEditors: LiNing
 * @LastEditTime: 2025-02-26 22:57:08
 * @FilePath: \LeeCode_Modularization\Binary_tree\LeeCode145_step\LeeCode145_step.c
 * @Description: 
 * Copyright (c) 2025 by ${git_name_email}, All Rights Reserved. 
 */
#include <stdio.h>
#include <stdlib.h>

// ����������ڵ�ṹ
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// ����ջ�ṹ
struct Stack {
    struct TreeNode **array; // �洢�������ڵ��ָ������
    int top;                 // ջ��ָ��
    int capacity;            // ջ������
};

// ��ʼ��ջ
struct Stack *createStack(int capacity) {
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->array = (struct TreeNode **)malloc(capacity * sizeof(struct TreeNode *));
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

// �ж�ջ�Ƿ�Ϊ��
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// ѹջ
void push(struct Stack *stack, struct TreeNode *node) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack overflow!\n");
        return;
    }
    stack->array[++stack->top] = node;
}

// ��ջ
struct TreeNode *pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        return NULL;
    }
    return stack->array[stack->top--];
}

// ��ȡջ��Ԫ��
struct TreeNode *peek(struct Stack *stack) {
    if (isEmpty(stack)) {
        return NULL;
    }
    return stack->array[stack->top];
}

// �����������������
void inorderTraversal(struct TreeNode *root) {
    if (root == NULL) {
        return;
    }

    // ��ʼ��ջ
    struct Stack *stack = createStack(100);

    struct TreeNode *current = root;

    while (current != NULL || !isEmpty(stack)) {
        // ����ǰ�ڵ㼰���������ӽڵ�ѹ��ջ��
        while (current != NULL) {
            push(stack, current);
            current = current->left;
        }

        // ����ջ���ڵ㲢����
        current = pop(stack);
        printf("%d ", current->val);

        // ת��������
        current = current->right;
    }

    // �ͷ�ջ�ڴ�
    free(stack->array);
    free(stack);
}

// �����½ڵ�
struct TreeNode *newNode(int val) {
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// ������
int main() {
    // ����һ���򵥵Ķ�����
    struct TreeNode *root = newNode(1);
    root->right = newNode(2);
    root->right->left = newNode(3);

    // �������
    printf("Inorder Traversal: ");
    inorderTraversal(root); // ���: 1 3 2

    return 0;
}