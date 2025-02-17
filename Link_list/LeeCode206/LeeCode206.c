/*
 * @Author: LiNing
 * @Date: 2025-01-19 00:19:48
 * @LastEditors: LiNing
 * @LastEditTime: 2025-01-19 00:20:23
 * @FilePath: \LeeCode_Modularization\link_list\LeeCode206\LeeCode206.c
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

// ��ת������
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;  // ��ʼ��ǰ���ڵ�Ϊ NULL
    struct ListNode* curr = head; // ��ǰ�ڵ�ָ������ͷ��

    while (curr != NULL) {         // ��������ֱ����ǰ�ڵ�Ϊ NULL
        struct ListNode* nextTemp = curr->next; // �ݴ浱ǰ�ڵ����һ�ڵ�
        curr->next = prev;        // ��ǰ�ڵ��ָ��ָ��ǰ���ڵ�
        prev = curr;              // ǰ���ڵ�ǰ��
        curr = nextTemp;          // ��ǰ�ڵ����
    }

    return prev;                  // �����������ͷ�ڵ�
}

// �����½ڵ�
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// ��ӡ����
void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}

// ����������
int main() {
    // ��������1 -> 2 -> 3 -> 4 -> 5 -> NULL
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("ԭ����: ");
    printList(head);

    // ��ת����
    struct ListNode* reversedHead = reverseList(head);

    printf("��ת�������: ");
    printList(reversedHead);

    return 0;
}
