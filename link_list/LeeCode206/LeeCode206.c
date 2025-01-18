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

// 定义链表节点结构
struct ListNode {
    int val;
    struct ListNode* next;
};

// 反转链表函数
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;  // 初始化前驱节点为 NULL
    struct ListNode* curr = head; // 当前节点指向链表头部

    while (curr != NULL) {         // 遍历链表直到当前节点为 NULL
        struct ListNode* nextTemp = curr->next; // 暂存当前节点的下一节点
        curr->next = prev;        // 当前节点的指针指向前驱节点
        prev = curr;              // 前驱节点前移
        curr = nextTemp;          // 当前节点后移
    }

    return prev;                  // 返回新链表的头节点
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
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}

// 测试主函数
int main() {
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

    return 0;
}
