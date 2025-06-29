/*
 * @Author: LiNing
 * @Date: 2025-03-15
 * 对称二叉树
*/
#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// 你的 maxDepth 函数
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

// 创建二叉树的辅助函数
struct TreeNode* createTreeNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 测试主函数
int main() {
    // 创建一个测试用的二叉树
    // 示例树结构：
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

    // 调用 maxDepth 函数并打印结果
    int depth = maxDepth(root);
    printf("The maximum depth of the binary tree is: %d\n", depth);

    // 释放二叉树内存（简单释放，未考虑递归释放）
    free(root->left->left);
    free(root->left->right);
    free(root->right->left);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}