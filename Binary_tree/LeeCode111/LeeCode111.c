#include <stdio.h>
#include <stdlib.h>

// ����������ڵ�
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// �����������ڵ�
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// ������нڵ�
typedef struct QueueNode {
    struct TreeNode* treeNode;
    struct QueueNode* next;
} QueueNode;

// �������
typedef struct {
    QueueNode* front;
    QueueNode* rear;
} Queue;

// ��������
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// ���
void enqueue(Queue* q, struct TreeNode* node) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->treeNode = node;
    newNode->next = NULL;
    if (q->rear) {
        q->rear->next = newNode;
    }
    q->rear = newNode;
    if (!q->front) {
        q->front = newNode;
    }
}

// ����
struct TreeNode* dequeue(Queue* q) {
    if (!q->front) return NULL;
    QueueNode* temp = q->front;
    struct TreeNode* node = temp->treeNode;
    q->front = q->front->next;
    if (!q->front) {
        q->rear = NULL;
    }
    free(temp);
    return node;
}

// �ж϶����Ƿ�Ϊ��
int isEmpty(Queue* q) {
    return q->front == NULL;
}

// �ͷŶ���
void freeQueue(Queue* q) {
    while (!isEmpty(q)) {
        dequeue(q);
    }
    free(q);
}

// ������
int minDepth(struct TreeNode* root) {
    if (!root) return 0;

    int depth = 1;
    Queue* q = createQueue();
    enqueue(q, root);

    while (!isEmpty(q)) {
        int size = 0;
        Queue* tempQueue = createQueue();
        while (!isEmpty(q)) {
            struct TreeNode* node = dequeue(q);
            if (!node->left && !node->right) {
                freeQueue(tempQueue);
                freeQueue(q);
                return depth;
            }
            if (node->left) enqueue(tempQueue, node->left);
            if (node->right) enqueue(tempQueue, node->right);
            size++;
        }
        freeQueue(q);
        q = tempQueue;
        depth++;
    }

    freeQueue(q);
    return depth;
}

// �ͷŶ������ڴ�
void freeTree(struct TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// ����������
int main() {
    // ������������1
    struct TreeNode* root1 = createNode(3);
    root1->left = createNode(9);
    root1->right = createNode(20);
    root1->right->left = createNode(15);
    root1->right->right = createNode(7);

    // ��������1����С���Ϊ2
    printf("Test Case 1: Min Depth = %d\n", minDepth(root1));
    freeTree(root1);  // �ͷ��ڴ�

    // ������������2
    struct TreeNode* root2 = createNode(2);
    root2->right = createNode(3);
    root2->right->right = createNode(4);
    root2->right->right->right = createNode(5);
    root2->right->right->right->right = createNode(6);

    // ��������2����С���Ϊ5
    printf("Test Case 2: Min Depth = %d\n", minDepth(root2));
    freeTree(root2);  // �ͷ��ڴ�

    // ������������3������
    struct TreeNode* root3 = NULL;

    // ��������3����С���Ϊ0
    printf("Test Case 3: Min Depth = %d\n", minDepth(root3));

    return 0;
}