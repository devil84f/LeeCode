#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// 创建二叉树节点
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int countNodes(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// 释放二叉树内存
void freeTree(struct TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// 测试主函数
int main() {
    // 构建测试用例1
    struct TreeNode* root1 = createNode(3);
    root1->left = createNode(9);
    root1->right = createNode(20);
    root1->right->left = createNode(15);
    root1->right->right = createNode(7);

    // 测试用例1：最小深度为2
    printf("root Nodes = %d\n", countNodes(root1));
    freeTree(root1);  // 释放内存

    return 0;
}