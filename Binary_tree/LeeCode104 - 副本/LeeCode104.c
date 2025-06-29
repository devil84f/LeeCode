/*
 * @Author: LiNing
 * @Date: 2025-03-15
 * �Գƶ�����
*/
#include <stdio.h>
#include <stdlib.h>

// ����������ڵ�ṹ
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// ��� maxDepth ����
int maxDepth(struct TreeNode* root) {
    if (!root)
        return 0;

    int depth = 0;
    struct TreeNode** queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 6000);
    int queueFront = 0;
    int queueEnd = 0;

    queue[queueEnd++] = root;
    int queueSize = 0;
    while (queueSize = queueEnd - queueFront) {
        for (int i = 0; i < queueSize; i++) {
            struct TreeNode* tempNode = queue[queueFront + i];
            if (tempNode->left) {
                queue[queueEnd++] = tempNode->left;
            }
            if (tempNode->right) {
                queue[queueEnd++] = tempNode->right;
            }
        }
        queueFront += queueSize;
        depth++;
    }
    free(queue);
    return depth;
}

// �����������ĸ�������
struct TreeNode* createTreeNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// ����������
int main() {
    // ����һ�������õĶ�����
    // ʾ�����ṹ��
    //         1
    //       /   \
    //      2     3
    //     / \   /
    //    4   5 6
    struct TreeNode* root = createTreeNode(1);
    root->left = createTreeNode(2);
    root->right = createTreeNode(3);
    root->left->left = createTreeNode(4);
    root->left->right = createTreeNode(5);
    root->right->left = createTreeNode(6);

    // ���� maxDepth ��������ӡ���
    int depth = maxDepth(root);
    printf("The maximum depth of the binary tree is: %d\n", depth);

    // �ͷŶ������ڴ棨���ͷţ�δ���ǵݹ��ͷţ�
    free(root->left->left);
    free(root->left->right);
    free(root->right->left);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}