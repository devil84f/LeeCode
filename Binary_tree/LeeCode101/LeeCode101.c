/*
 * @Author: LiNing
 * @Date: 2025-03-15
 * �Գƶ�����
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ����������ڵ�ṹ
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool compare(struct TreeNode* left, struct TreeNode* right) {
    if ((left == NULL && right != NULL) || (left != NULL && right == NULL)) {
        return false;
    } else if (left == NULL && right == NULL) {
        return true;
    } else if (left->val != right->val) {
        return false;
    }
    else {
        bool outside =  compare (left->left, right->right);
        bool inside =  compare (left->right, right->left);
        return outside && inside;
    }
}

bool isSymmetric(struct TreeNode* root) {
    if (root == NULL) {
        return true;
    }
    return compare (root->left, root->right);
}

// �����������ڵ�ĸ�������
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// ���Ժ���
void testSymmetry(struct TreeNode* root) {
    if (isSymmetric(root)) {
        printf("The tree is symmetric.\n");
    } else {
        printf("The tree is not symmetric.\n");
    }
}

int main() {
    // ��������1���Գƶ�����
    struct TreeNode* root1 = createNode(1);
    root1->left = createNode(2);
    root1->right = createNode(2);
    root1->left->left = createNode(3);
    root1->left->right = createNode(4);
    root1->right->left = createNode(4);
    root1->right->right = createNode(3);

    printf("Test Case 1:\n");
    testSymmetry(root1);

    // ��������2���ǶԳƶ�����
    struct TreeNode* root2 = createNode(1);
    root2->left = createNode(2);
    root2->right = createNode(2);
    root2->left->right = createNode(3);
    root2->right->right = createNode(3);

    printf("Test Case 2:\n");
    testSymmetry(root2);

    // ��������3������
    struct TreeNode* root3 = NULL;

    printf("Test Case 3:\n");
    testSymmetry(root3);

    // ��������4�����ڵ���
    struct TreeNode* root4 = createNode(1);

    printf("Test Case 4:\n");
    testSymmetry(root4);

    // �ͷ��ڴ�
    free(root1->left->left);
    free(root1->left->right);
    free(root1->right->left);
    free(root1->right->right);
    free(root1->left);
    free(root1->right);
    free(root1);

    free(root2->left->right);
    free(root2->right->right);
    free(root2->left);
    free(root2->right);
    free(root2);

    free(root4);

    return 0;
}