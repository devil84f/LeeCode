/*
 * @Author: LiNing
 * @Date: 2025-02-09 22:42:25
 * @LastEditors: LiNing
 * @LastEditTime: 2025-02-09 22:48:24
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

// 创建新节点
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// 打印链表
void printList(struct ListNode* head) {
    // struct ListNode* current = head;
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

int main () {
    // 创建链表：1 -> 2 -> 3 -> 4 -> 5 -> NULL
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("原链表: ");
    printList(head);

    // 反转链表
    struct ListNode* reversedHead = reverseList(head);

    printf("反转后的链表: ");
    printList(reversedHead);
    printf("%d", reversedHead->val);

    return 0;
}