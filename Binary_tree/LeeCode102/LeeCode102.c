/*
 * @Author: LiNing
 * @Date: 2025-02-24 22:41:45
 * @LastEditors: LiNing
 * @LastEditTime: 2025-02-26 22:48:10
 * @FilePath: \LeeCode_Modularization\Binary_tree\LeeCode144\LeeCode144.c
 * @Description: 
 * Copyright (c) 2025 by ${git_name_email}, All Rights Reserved. 
 */

 #include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构体
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// 定义队列节点结构体
struct QueueNode {
    struct TreeNode *node;
    struct QueueNode *next;
};

// 定义队列结构体
struct Queue {
    struct QueueNode *front;
    struct QueueNode *rear;
};

// 初始化队列
struct Queue* createQueue() {
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    if (!q) return NULL; // 检查内存分配
    q->front = q->rear = NULL;
    return q;
}

// 入队操作
void enqueue(struct Queue *q, struct TreeNode *node) {
    if (!q || !node) return;
    struct QueueNode *newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    if (!newNode) return; // 检查内存分配
    newNode->node = node;
    newNode->next = NULL;
    if (q->rear == NULL) { // 队列为空
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

// 出队操作
struct TreeNode* dequeue(struct Queue *q) {
    if (q->front == NULL)
        return NULL;
    struct QueueNode *temp = q->front;
    struct TreeNode *node = temp->node;
    q->front = q->front->next;
    if (q->front == NULL) // 队列变为空
        q->rear = NULL;
    free(temp);
    return node;
}

// 判断队列是否为空
int isQueueEmpty(struct Queue *q) {
    return q->front == NULL;
}

// 释放队列内存
void freeQueue(struct Queue *q) {
    while (!isQueueEmpty(q)) {
        dequeue(q);
    }
    free(q);
}

// 层序遍历函数
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (root == NULL) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    // 初始化队列
    struct Queue *q = createQueue();
    if (!q) return NULL; // 检查队列创建
    enqueue(q, root);

    // 动态分配结果数组，初始容量为10，可根据需要调整
    int capacity = 10;
    int **result = (int**)malloc(capacity * sizeof(int*));
    if (!result) {
        freeQueue(q);
        return NULL; // 内存分配失败
    }
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));
    if (!(*returnColumnSizes)) {
        free(result);
        freeQueue(q);
        return NULL; // 内存分配失败
    }

    int level = 0;

    while (!isQueueEmpty(q)) {
        int size = 0;
        // 计算当前层的节点数
        struct QueueNode *temp = q->front;
        for (; temp != NULL; temp = temp->next) {
            size++;
        }

        // 如果当前层数超过容量，扩展结果数组
        if (level >= capacity) {
            capacity *= 2;
            int **tempResult = (int**)realloc(result, capacity * sizeof(int*));
            if (!tempResult) {
                // 内存分配失败，处理错误
                // 释放已分配的内存
                for (int i = 0; i < level; i++) {
                    free(result[i]);
                }
                free(result);
                free(*returnColumnSizes);
                freeQueue(q);
                return NULL;
            }
            result = tempResult;

            // 扩展 column sizes
            int *tempColSizes = (int*)realloc(*returnColumnSizes, capacity * sizeof(int));
            if (!tempColSizes) {
                // 内存分配失败，处理错误
                for (int i = 0; i < level; i++) {
                    free(result[i]);
                }
                free(result);
                free(*returnColumnSizes);
                freeQueue(q);
                return NULL;
            }
            *returnColumnSizes = tempColSizes;
        }

        // 分配当前层的空间
        result[level] = (int*)malloc(size * sizeof(int));
        if (!result[level]) {
            // 内存分配失败，处理错误
            // 释放已分配的内存
            for (int i = 0; i < level; i++) {
                free(result[i]);
            }
            free(result);
            free(*returnColumnSizes);
            freeQueue(q);
            return NULL;
        }
        (*returnColumnSizes)[level] = size;

        // 遍历当前层的所有节点
        for (int i = 0; i < size; i++) {
            struct TreeNode *node = dequeue(q);
            if (!node) break; // 防止队列为空时继续出队
            result[level][i] = node->val;

            // 将子节点入队
            if (node->left != NULL) {
                enqueue(q, node->left);
            }
            if (node->right != NULL) {
                enqueue(q, node->right);
            }
        }

        level++;
    }

    // 更新返回的层数
    *returnSize = level;

    // 释放队列
    freeQueue(q);

    return result;
}

// 辅助函数：创建新节点
struct TreeNode* createTreeNode(int val) {
    struct TreeNode *node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (!node) return NULL; // 检查内存分配
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// 主函数示例
int main() {
    /*
            3
           / \
          9  20
             / \
            15 7
    */

    struct TreeNode *root = createTreeNode(3);
    if (!root) return -1;
    root->left = createTreeNode(9);
    root->right = createTreeNode(20);
    root->right->left = createTreeNode(15);
    root->right->right = createTreeNode(7);

    int returnSize;
    int *returnColumnSizes;
    int **result = levelOrder(root, &returnSize, &returnColumnSizes);

    // 打印结果
    for (int i = 0; i < returnSize; i++) {
        printf("[");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d", result[i][j]);
            if (j != returnColumnSizes[i] - 1)
                printf(", ");
        }
        printf("]\n");
        
        // 释放每一层的内存
        free(result[i]);
    }

    // 释放其他内存
    free(result);
    free(returnColumnSizes);

    return 0;
}