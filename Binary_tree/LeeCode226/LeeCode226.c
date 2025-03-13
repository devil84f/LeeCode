/*
 * @Author: LiNing
 * @Date: 2025-03-13
 * 翻转树
*/
#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构
typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// 创建新节点
TreeNode* createNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// 翻转二叉树的函数
TreeNode* invertTree(TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }
    TreeNode* temp = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(temp);
    return root;
}

// 打印二叉树的函数（中序遍历）
void printTreeInOrder(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    printTreeInOrder(root->left);
    printf("%d ", root->val);
    printTreeInOrder(root->right);
}

// 测试主函数
int main() {
    // 构造测试用例
    TreeNode* root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(7);
    root->left->left = createNode(1);
    root->left->right = createNode(3);
    root->right->left = createNode(6);
    root->right->right = createNode(9);

    printf("Original Tree (In-order traversal): ");
    printTreeInOrder(root);
    printf("\n");

    // 翻转二叉树
    root = invertTree(root);

    printf("Inverted Tree (In-order traversal): ");
    printTreeInOrder(root);
    printf("\n");

    return 0;
}