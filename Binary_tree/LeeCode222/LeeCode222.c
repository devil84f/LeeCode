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

int countNodes(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
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
    printf("root Nodes = %d\n", countNodes(root1));
    freeTree(root1);  // �ͷ��ڴ�

    return 0;
}