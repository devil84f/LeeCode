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

// ����������ڵ�ṹ��
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// ������нڵ�ṹ��
struct QueueNode {
    struct TreeNode *node;
    struct QueueNode *next;
};

// ������нṹ��
struct Queue {
    struct QueueNode *front;
    struct QueueNode *rear;
};

// ��ʼ������
struct Queue* createQueue() {
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    if (!q) return NULL; // ����ڴ����
    q->front = q->rear = NULL;
    return q;
}

// ��Ӳ���
void enqueue(struct Queue *q, struct TreeNode *node) {
    if (!q || !node) return;
    struct QueueNode *newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    if (!newNode) return; // ����ڴ����
    newNode->node = node;
    newNode->next = NULL;
    if (q->rear == NULL) { // ����Ϊ��
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

// ���Ӳ���
struct TreeNode* dequeue(struct Queue *q) {
    if (q->front == NULL)
        return NULL;
    struct QueueNode *temp = q->front;
    struct TreeNode *node = temp->node;
    q->front = q->front->next;
    if (q->front == NULL) // ���б�Ϊ��
        q->rear = NULL;
    free(temp);
    return node;
}

// �ж϶����Ƿ�Ϊ��
int isQueueEmpty(struct Queue *q) {
    return q->front == NULL;
}

// �ͷŶ����ڴ�
void freeQueue(struct Queue *q) {
    while (!isQueueEmpty(q)) {
        dequeue(q);
    }
    free(q);
}

// �����������
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (root == NULL) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    // ��ʼ������
    struct Queue *q = createQueue();
    if (!q) return NULL; // �����д���
    enqueue(q, root);

    // ��̬���������飬��ʼ����Ϊ10���ɸ�����Ҫ����
    int capacity = 10;
    int **result = (int**)malloc(capacity * sizeof(int*));
    if (!result) {
        freeQueue(q);
        return NULL; // �ڴ����ʧ��
    }
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));
    if (!(*returnColumnSizes)) {
        free(result);
        freeQueue(q);
        return NULL; // �ڴ����ʧ��
    }

    int level = 0;

    while (!isQueueEmpty(q)) {
        int size = 0;
        // ���㵱ǰ��Ľڵ���
        struct QueueNode *temp = q->front;
        for (; temp != NULL; temp = temp->next) {
            size++;
        }

        // �����ǰ����������������չ�������
        if (level >= capacity) {
            capacity *= 2;
            int **tempResult = (int**)realloc(result, capacity * sizeof(int*));
            if (!tempResult) {
                // �ڴ����ʧ�ܣ��������
                // �ͷ��ѷ�����ڴ�
                for (int i = 0; i < level; i++) {
                    free(result[i]);
                }
                free(result);
                free(*returnColumnSizes);
                freeQueue(q);
                return NULL;
            }
            result = tempResult;

            // ��չ column sizes
            int *tempColSizes = (int*)realloc(*returnColumnSizes, capacity * sizeof(int));
            if (!tempColSizes) {
                // �ڴ����ʧ�ܣ��������
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

        // ���䵱ǰ��Ŀռ�
        result[level] = (int*)malloc(size * sizeof(int));
        if (!result[level]) {
            // �ڴ����ʧ�ܣ��������
            // �ͷ��ѷ�����ڴ�
            for (int i = 0; i < level; i++) {
                free(result[i]);
            }
            free(result);
            free(*returnColumnSizes);
            freeQueue(q);
            return NULL;
        }
        (*returnColumnSizes)[level] = size;

        // ������ǰ������нڵ�
        for (int i = 0; i < size; i++) {
            struct TreeNode *node = dequeue(q);
            if (!node) break; // ��ֹ����Ϊ��ʱ��������
            result[level][i] = node->val;

            // ���ӽڵ����
            if (node->left != NULL) {
                enqueue(q, node->left);
            }
            if (node->right != NULL) {
                enqueue(q, node->right);
            }
        }

        level++;
    }

    // ���·��صĲ���
    *returnSize = level;

    // �ͷŶ���
    freeQueue(q);

    return result;
}

// ���������������½ڵ�
struct TreeNode* createTreeNode(int val) {
    struct TreeNode *node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (!node) return NULL; // ����ڴ����
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// ������ʾ��
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

    // ��ӡ���
    for (int i = 0; i < returnSize; i++) {
        printf("[");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d", result[i][j]);
            if (j != returnColumnSizes[i] - 1)
                printf(", ");
        }
        printf("]\n");
        
        // �ͷ�ÿһ����ڴ�
        free(result[i]);
    }

    // �ͷ������ڴ�
    free(result);
    free(returnColumnSizes);

    return 0;
}