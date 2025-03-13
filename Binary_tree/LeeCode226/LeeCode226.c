/*
 * @Author: LiNing
 * @Date: 2025-03-13
 * ��ת��
*/
#include <stdio.h>
#include <stdlib.h>

// ����������ڵ�ṹ
typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// �����½ڵ�
TreeNode* createNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// ��ת�������ĺ���
TreeNode* invertTree(TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }
    TreeNode* temp = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(temp);
    return root;
}

// ��ӡ�������ĺ��������������
void printTreeInOrder(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    printTreeInOrder(root->left);
    printf("%d ", root->val);
    printTreeInOrder(root->right);
}

// ����������
int main() {
    // �����������
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

    // ��ת������
    root = invertTree(root);

    printf("Inverted Tree (In-order traversal): ");
    printTreeInOrder(root);
    printf("\n");

    return 0;
}