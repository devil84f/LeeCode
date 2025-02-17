/*
 * @Author: LiNing
 * @Date: 2025-02-11 12:41:09
 * @LastEditors: LiNing
 * @LastEditTime: 2025-02-11 12:46:59
 * @FilePath: \LeeCode_Modularization\dual_pointer\LeeCode0207\LeeCode0207.c
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

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *dummyA = NULL, *dummyB = NULL;
    int lenA = 0, lenB = 0, gap = 0;
    dummyA = headA;
    while (dummyA) {
        lenA++;
        dummyA = dummyA->next;
    }
    dummyB = headB;
    while (dummyB) {
        lenB++;
        dummyB = dummyB->next;
    }

    // ������������Ȳ�
    if (lenA > lenB) {
        dummyA = headA, dummyB = headB;
        gap = lenA - lenB;
    } else {
        dummyA = headB, dummyB = headA;
        gap = lenB - lenA;
    }

    // β������
    while (gap--) dummyA = dummyA->next;
    // �ƶ���������Ƿ�����ͬ��Ԫ��
    while (dummyA) {
        if (dummyA == dummyB) return dummyA;
        dummyA = dummyA->next, dummyB = dummyB->next;
    }

    return NULL;
}

int main () {
    struct ListNode *headA = createNode(4);
    headA->next = createNode(1);
    struct ListNode *headB = createNode(5);
    headB->next = createNode(0);
    headB->next->next = createNode(1);
    headA->next->next = createNode(8);
    headB->next->next->next = headA->next->next;
    headA->next->next->next = createNode(4);
    headA->next->next->next->next = createNode(5);
    headB->next->next->next->next = headA->next->next->next;
    headB->next->next->next->next->next = headA->next->next->next->next;

    printList(headA);
    printList(headB);
    struct ListNode *same = getIntersectionNode(headA, headB);
    printList(same);
}