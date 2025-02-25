/*
 * @Author: LiNing
 * @Date: 2025-02-24 22:41:45
 * @LastEditors: LiNing
 * @LastEditTime: 2025-02-24 22:41:47
 * @FilePath: \LeeCode_Modularization\Binary_tree\LeeCode144\LeeCode144.c
 * @Description: 
 * Copyright (c) 2025 by ${git_name_email}, All Rights Reserved. 
 */

#include <stdio.h>
#include <stdlib.h>

// ����������ڵ�ṹ
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// ǰ���������
void preorderTraversalHelper(struct TreeNode* root, int* result, int* index) {
    if (root == NULL) {
        return;
    }
    // ���ʸ��ڵ�
    result[(*index)++] = root->val;
    // �ݹ����������
    preorderTraversalHelper(root->left, result, index);
    // �ݹ����������
    preorderTraversalHelper(root->right, result, index);
}

// ����ǰ���������ĺ���
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    // �����������ڵ���Ϊ1000
    int* result = (int*)malloc(1000 * sizeof(int));
    *returnSize = 0;
    preorderTraversalHelper(root, result, returnSize);
    return result;
}

// ���Դ���
int main() {
    // ����һ���򵥵Ķ�����
    struct TreeNode n1, n2, n3;
    n1.val = 1;
    n2.val = 2;
    n3.val = 3;
    n1.left = &n2;
    n1.right = &n3;
    n2.left = NULL;
    n2.right = NULL;
    n3.left = NULL;
    n3.right = NULL;

    int returnSize;
    int* result = preorderTraversal(&n1, &returnSize);

    // ���ǰ��������
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}