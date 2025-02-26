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

// ����������ڵ�ṹ
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// ǰ���������
void post(struct TreeNode* root, int* ret, int* returnSize) {
    if (root == NULL) {
        return;
    }
    post(root->left, ret, returnSize);
    post(root->right, ret, returnSize);
    ret[(*returnSize)++] = root->val;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int* ret = (int*)malloc(sizeof(int) * 100);
    *returnSize = 0;
    post(root, ret, returnSize);
    return ret;
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
    int* result = postorderTraversal(&n1, &returnSize);

    // ���ǰ��������
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}