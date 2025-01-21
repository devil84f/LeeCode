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

// 定义链表节点结构
struct ListNode {
    int val;
    struct ListNode* next;
};

// 创建链表节点的辅助函数
struct ListNode* createNode(int value) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

// 打印链表的辅助函数
void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *dummy = (struct ListNode*)malloc(sizeof(struct ListNode));  // 分配内存
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
    slow->next = toDelete->next;  // 删除节点
    free(toDelete);  // 释放内存

    return dummy->next;  // 返回新的头节点
}
// 释放链表内存的辅助函数
void freeList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        struct ListNode* temp = current;
        current = current->next;
        free(temp);
    }
}

// 主函数
int main() {
    // 创建一个链表：1 -> 2 -> 3 -> 4 -> 5 -> NULL
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("原始链表：\n");
    printList(head);

    // 调用 removeNthFromEnd 函数，删除倒数第 n 个节点
    int n = 2;  // 删除倒数第 2 个节点
    head = removeNthFromEnd(head, n);

    printf("删除倒数第 %d 个节点后的链表：\n", n);
    printList(head);

    // 释放链表内存
    freeList(head);

    return 0;
}