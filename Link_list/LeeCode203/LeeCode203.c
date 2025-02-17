/*
 * @Author: LiNing
 * @Date: 2025-01-09 00:10:37
 * @LastEditors: LiNing
 * @LastEditTime: 2025-01-09 00:13:46
 * @FilePath: \LeeCode_Arrays\LeeCode_Arrays\LeeCode34\LeeCode34.c
 * @Description: 
 * Copyright (c) 2025 by ${git_name_email}, All Rights Reserved. 
 */

#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构
struct ListNode {
    int val;
    struct ListNode *next;
};

// 创建一个新节点
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// 删除链表中所有值为 val 的节点
struct ListNode* removeElements(struct ListNode* head, int val) {
    // 创建一个虚拟节点，方便处理头节点
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* current = dummy;

    // 遍历链表
    while (current->next != NULL) {
        if (current->next->val == val) { // 找到值为 val 的节点
            struct ListNode* temp = current->next;
            current->next = current->next->next; // 删除该节点
            free(temp); // 释放内存
        } else {
            current = current->next; // 继续遍历
        }
    }

    // 返回新的链表头
    struct ListNode* newHead = dummy->next;
    free(dummy); // 释放虚拟节点内存
    return newHead;
}

// 打印链表
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

// 主函数测试
int main() {
    // 创建测试链表: 1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(6);
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(4);
    head->next->next->next->next->next = createNode(5);
    head->next->next->next->next->next->next = createNode(6);

    printf("原链表: ");
    printList(head);

    // 移除值为 6 的节点
    head = removeElements(head, 6);

    printf("移除 6 后的链表: ");
    printList(head);

    return 0;
}
