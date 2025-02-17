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

// 定义链表节点结构
typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

// 函数：检测链表中环的入口
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *fast = head, *slow = head;
    while (fast && fast->next) {
        // 这里判断两个指针是否相等，所以移位操作放在前面
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) { // 相交，开始找环形入口：分别从头部和从交点出发，找到相遇的点就是环形入口
            struct ListNode *f = fast, *h = head;
            while (f != h) f = f->next, h = h->next;
            return h;
        }
    }
    return NULL;
}

// 测试主函数
int main() {
    // 创建链表：1 -> 2 -> 3 -> 4 -> 5 -> 3（环的入口是节点3）
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
    head->next->next->next->next->next = head->next->next; // 创建环，指向节点3

    // 调用函数检测环的入口
    ListNode* cycleEntry = detectCycle(head);

    if (cycleEntry) {
        printf("环的入口节点是：%d\n", cycleEntry->val);
    } else {
        printf("链表中不存在环\n");
    }

    // 释放链表内存（注意：由于存在环，需要特别处理）
    ListNode* current = head;
    ListNode* prev = NULL;
    while (current != cycleEntry) {
        prev = current;
        current = current->next;
    }
    prev->next = NULL; // 打破环

    // 释放链表
    while (head) {
        ListNode* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}