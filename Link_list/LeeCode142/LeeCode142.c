/*
 * @Author: LiNing
 * @Date: 2025-01-25 00:27:54
 * @LastEditors: LiNing
 * @LastEditTime: 2025-01-25 00:28:12
 * @FilePath: \LeeCode_Modularization\Link_list\LeeCode142\LeeCode142.c
 * @Description: 
 * Copyright (c) 2025 by ${git_name_email}, All Rights Reserved. 
 */
#include <stdio.h>
#include <stdlib.h>

// ��������ڵ�ṹ
typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

// ��������������л������
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *fast = head, *slow = head;
    while (fast && fast->next) {
        // �����ж�����ָ���Ƿ���ȣ�������λ��������ǰ��
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) { // �ཻ����ʼ�һ�����ڣ��ֱ��ͷ���ʹӽ���������ҵ������ĵ���ǻ������
            struct ListNode *f = fast, *h = head;
            while (f != h) f = f->next, h = h->next;
            return h;
        }
    }
    return NULL;
}

// ����������
int main() {
    // ��������1 -> 2 -> 3 -> 4 -> 5 -> 3����������ǽڵ�3��
    ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    head->val = 1;
    head->next = (ListNode*)malloc(sizeof(ListNode));
    head->next->val = 2;
    head->next->next = (ListNode*)malloc(sizeof(ListNode));
    head->next->next->val = 3;
    head->next->next->next = (ListNode*)malloc(sizeof(ListNode));
    head->next->next->next->val = 4;
    head->next->next->next->next = (ListNode*)malloc(sizeof(ListNode));
    head->next->next->next->next->val = 5;
    head->next->next->next->next->next = head->next->next; // ��������ָ��ڵ�3

    // ���ú�����⻷�����
    ListNode* cycleEntry = detectCycle(head);

    if (cycleEntry) {
        printf("������ڽڵ��ǣ�%d\n", cycleEntry->val);
    } else {
        printf("�����в����ڻ�\n");
    }

    // �ͷ������ڴ棨ע�⣺���ڴ��ڻ�����Ҫ�ر���
    ListNode* current = head;
    ListNode* prev = NULL;
    while (current != cycleEntry) {
        prev = current;
        current = current->next;
    }
    prev->next = NULL; // ���ƻ�

    // �ͷ�����
    while (head) {
        ListNode* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}