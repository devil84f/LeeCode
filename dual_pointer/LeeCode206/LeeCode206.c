/*
 * @Author: LiNing
 * @Date: 2025-02-09 22:42:25
 * @LastEditors: LiNing
 * @LastEditTime: 2025-02-09 23:55:21
 * @FilePath: \LeeCode_Modularization\dual_pointer\LeeCode206\LeeCode206.c
 * @Description: 
 * Copyright (c) 2025 by ${git_name_email}, All Rights Reserved. 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* cur = head;
    struct ListNode* pre = NULL;
    struct ListNode* temp;

    while (cur) {
        temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }
    return pre;
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
    // struct ListNode* current = head;
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

int main () {
    // ��������1 -> 2 -> 3 -> 4 -> 5 -> NULL
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("ԭ����: ");
    printList(head);
    printf("%d\n", head->val);

    // ��ת����
    struct ListNode* reversedHead = reverseList(head);

    printf("��ת�������: ");
    printList(reversedHead);

    return 0;
}