/*
 * @Author: LiNing
 * @Date: 2025-01-21 23:26:40
 * @LastEditors: LiNing
 * @LastEditTime: 2025-01-21 23:26:59
 * @FilePath: \LeeCode_Modularization\Link_list\LeeCode19\LeeCode19.c
 * @Description: 
 * Copyright (c) 2025 by ${git_name_email}, All Rights Reserved. 
 */
#include <stdio.h>
#include <stdlib.h>

// ��������ڵ�ṹ
struct ListNode {
    int val;
    struct ListNode* next;
};

// ��������ڵ�ĸ�������
struct ListNode* createNode(int value) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

// ��ӡ����ĸ�������
void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *dummy = (struct ListNode*)malloc(sizeof(struct ListNode));  // �����ڴ�
    dummy->next = head;
    struct ListNode *slow = dummy;
    struct ListNode *fast = dummy;

    for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }

    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    struct ListNode *toDelete = slow->next;
    slow->next = toDelete->next;  // ɾ���ڵ�
    free(toDelete);  // �ͷ��ڴ�

    return dummy->next;  // �����µ�ͷ�ڵ�
}
// �ͷ������ڴ�ĸ�������
void freeList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        struct ListNode* temp = current;
        current = current->next;
        free(temp);
    }
}

// ������
int main() {
    // ����һ������1 -> 2 -> 3 -> 4 -> 5 -> NULL
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("ԭʼ����\n");
    printList(head);

    // ���� removeNthFromEnd ������ɾ�������� n ���ڵ�
    int n = 2;  // ɾ�������� 2 ���ڵ�
    head = removeNthFromEnd(head, n);

    printf("ɾ�������� %d ���ڵ�������\n", n);
    printList(head);

    // �ͷ������ڴ�
    freeList(head);

    return 0;
}