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

// 链表节点定义
struct ListNode {
    int val;
    struct ListNode* next;
};

// 找到两个链表相交的起始节点
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if (!headA || !headB) return NULL;

    struct ListNode *pA = headA, *pB = headB;
    while (pA != pB) {  // 当两个指针相遇时，说明找到了相交节点
        pA = pA ? pA->next : headB;  // 如果 pA 到链表末尾，则切换到 headB
        pB = pB ? pB->next : headA;  // 如果 pB 到链表末尾，则切换到 headA
    }
    return pA;  // 返回相交节点或 NULL
}

// 创建链表节点
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// 打印链表
void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}

// 主函数测试
int main() {
    // 创建链表 A：1 -> 2 -> 3 -> 4 -> 5
    struct ListNode* headA = createNode(1);
    headA->next = createNode(2);
    headA->next->next = createNode(3);
    headA->next->next->next = createNode(4);
    headA->next->next->next->next = createNode(5);

    // 创建链表 B：9 -> 4 -> 5
    struct ListNode* headB = createNode(9);
    headB->next = headA->next->next->next;  // B 的第二个节点指向 A 的第四个节点

    printf("链表 A: ");
    printList(headA);
    printf("链表 B: ");
    printList(headB);

    // 找到相交节点
    struct ListNode* intersection = getIntersectionNode(headA, headB);
    if (intersection) {
        printf("两个链表相交于节点值: %d\n", intersection->val);
    } else {
        printf("两个链表不相交\n");
    }

    return 0;
}
