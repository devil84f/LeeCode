/*
 * @Author: LiNing
 * @Date: 2025-01-24 01:08:27
 * @LastEditors: LiNing
 * @LastEditTime: 2025-01-24 01:08:30
 * @FilePath: \LeeCode_Modularization\Link_list\LeeCode0207\LeeCode0207.c
 * @Description: 
 * Copyright (c) 2025 by ${git_name_email}, All Rights Reserved. 
 */

#include <stdio.h>
#include <stdlib.h>

// ����ڵ㶨��
struct ListNode {
    int val;
    struct ListNode* next;
};

// �ҵ����������ཻ����ʼ�ڵ�
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if (!headA || !headB) return NULL;

    struct ListNode *pA = headA, *pB = headB;
    while (pA != pB) {  // ������ָ������ʱ��˵���ҵ����ཻ�ڵ�
        pA = pA ? pA->next : headB;  // ��� pA ������ĩβ�����л��� headB
        pB = pB ? pB->next : headA;  // ��� pB ������ĩβ�����л��� headA
    }
    return pA;  // �����ཻ�ڵ�� NULL
}

// ��������ڵ�
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// ��ӡ����
void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}

// ����������
int main() {
    // �������� A��1 -> 2 -> 3 -> 4 -> 5
    struct ListNode* headA = createNode(1);
    headA->next = createNode(2);
    headA->next->next = createNode(3);
    headA->next->next->next = createNode(4);
    headA->next->next->next->next = createNode(5);

    // �������� B��9 -> 4 -> 5
    struct ListNode* headB = createNode(9);
    headB->next = headA->next->next->next;  // B �ĵڶ����ڵ�ָ�� A �ĵ��ĸ��ڵ�

    printf("���� A: ");
    printList(headA);
    printf("���� B: ");
    printList(headB);

    // �ҵ��ཻ�ڵ�
    struct ListNode* intersection = getIntersectionNode(headA, headB);
    if (intersection) {
        printf("���������ཻ�ڽڵ�ֵ: %d\n", intersection->val);
    } else {
        printf("���������ཻ\n");
    }

    return 0;
}
