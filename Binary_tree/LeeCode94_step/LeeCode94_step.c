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

// 定义二叉树节点结构
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// 定义栈结构
struct Stack {
    struct TreeNode **array; // 存储二叉树节点的指针数组
    int top;                 // 栈顶指针
    int capacity;            // 栈的容量
};

// 初始化栈
struct Stack *createStack(int capacity) {
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->array = (struct TreeNode **)malloc(capacity * sizeof(struct TreeNode *));
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

// 判断栈是否为空
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// 压栈
void push(struct Stack *stack, struct TreeNode *node) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack overflow!\n");
        return;
    }
    stack->array[++stack->top] = node;
}

// 弹栈
struct TreeNode *pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        return NULL;
    }
    return stack->array[stack->top--];
}

// 获取栈顶元素
struct TreeNode *peek(struct Stack *stack) {
    if (isEmpty(stack)) {
        return NULL;
    }
    return stack->array[stack->top];
}

// 中序遍历（迭代法）
void inorderTraversal(struct TreeNode *root) {
    if (root == NULL) {
        return;
    }

    // 初始化栈
    struct Stack *stack = createStack(100);

    struct TreeNode *current = root;

    while (current != NULL || !isEmpty(stack)) {
        // 将当前节点及其所有左子节点压入栈中
        while (current != NULL) {
            push(stack, current);
            current = current->left;
        }

        // 弹出栈顶节点并访问
        current = pop(stack);
        printf("%d ", current->val);

        // 转向右子树
        current = current->right;
    }

    // 释放栈内存
    free(stack->array);
    free(stack);
}

// 创建新节点
struct TreeNode *newNode(int val) {
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// 主函数
int main() {
    // 构建一个简单的二叉树
    struct TreeNode *root = newNode(1);
    root->right = newNode(2);
    root->right->left = newNode(3);

    // 中序遍历
    printf("Inorder Traversal: ");
    inorderTraversal(root); // 输出: 1 3 2

    return 0;
}