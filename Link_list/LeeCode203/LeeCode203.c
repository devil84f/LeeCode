/*
 * @Author: LiNing
 * @Date: 2025-01-09 00:10:37
 * @LastEditors: LiNing
 * @LastEditTime: 2025-01-09 00:13:46
 * @FilePath: \LeeCode_Arrays\LeeCode_Arrays\LeeCode34\LeeCode34.c
 * @Description: 
 * Copyright (c) 2025 by ${git_name_email}, All Rights Reserved. 
 */

#include <stdio.h>
#include <stdlib.h>

// ��������ڵ�ṹ
struct ListNode {
    int val;
    struct ListNode *next;
};

// ����һ���½ڵ�
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// ɾ������������ֵΪ val �Ľڵ�
struct ListNode* removeElements(struct ListNode* head, int val) {
    // ����һ������ڵ㣬���㴦��ͷ�ڵ�
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* current = dummy;

    // ��������
    while (current->next != NULL) {
        if (current->next->val == val) { // �ҵ�ֵΪ val �Ľڵ�
            struct ListNode* temp = current->next;
            current->next = current->next->next; // ɾ���ýڵ�
            free(temp); // �ͷ��ڴ�
        } else {
            current = current->next; // ��������
        }
    }

    // �����µ�����ͷ
    struct ListNode* newHead = dummy->next;
    free(dummy); // �ͷ�����ڵ��ڴ�
    return newHead;
}

// ��ӡ����
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

// ����������
int main() {
    // ������������: 1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(6);
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(4);
    head->next->next->next->next->next = createNode(5);
    head->next->next->next->next->next->next = createNode(6);

    printf("ԭ����: ");
    printList(head);

    // �Ƴ�ֵΪ 6 �Ľڵ�
    head = removeElements(head, 6);

    printf("�Ƴ� 6 �������: ");
    printList(head);

    return 0;
}
