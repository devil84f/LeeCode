/*
 * @Author: LiNing
 * @Date: 2025-01-18 23:54:40
 * @LastEditors: LiNing
 * @LastEditTime: 2025-01-18 23:56:38
 * @FilePath: \LeeCode_Modularization\link_list\LeeCode707\LeeCode707.c
 * @Description: 
 * Copyright (c) 2025 by ${git_name_email}, All Rights Reserved. 
 */

#include <stdio.h>
#include <stdlib.h>

// 链表节点结构
struct ListNode {
    int val;
    struct ListNode *next;
};

// 链表类
struct MyLinkedList {
    struct ListNode *head;
};

// 创建一个新节点
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// 初始化链表
struct MyLinkedList* myLinkedListCreate() {
    struct MyLinkedList* obj = (struct MyLinkedList*)malloc(sizeof(struct MyLinkedList));
    obj->head = createNode(0);  // 创建虚拟头节点
    return obj;
}

// 获取链表第 index 个节点的值
int myLinkedListGet(struct MyLinkedList* obj, int index) {
    struct ListNode* current = obj->head->next;  // 从虚拟头节点的下一个开始
    for (int i = 0; i < index && current != NULL; i++) {
        current = current->next;
    }
    return (current == NULL) ? -1 : current->val;
}

// 在链表头部添加一个值为 val 的节点
void myLinkedListAddAtHead(struct MyLinkedList* obj, int val) {
    struct ListNode* newNode = createNode(val);
    newNode->next = obj->head->next;
    obj->head->next = newNode;
}

// 在链表尾部添加一个值为 val 的节点
void myLinkedListAddAtTail(struct MyLinkedList* obj, int val) {
    struct ListNode* current = obj->head;
    while (current->next != NULL) {
        current = current->next;
    }
    struct ListNode* newNode = createNode(val);
    current->next = newNode;
}

// 在链表第 index 个位置之前添加一个值为 val 的节点
void myLinkedListAddAtIndex(struct MyLinkedList* obj, int index, int val) {
    if (index < 0) return;
    struct ListNode* current = obj->head;
    for (int i = 0; i < index && current != NULL; i++) {
        current = current->next;
    }
    if (current == NULL) return;  // 索引无效
    struct ListNode* newNode = createNode(val);
    newNode->next = current->next;
    current->next = newNode;
}

// 删除链表第 index 个位置的节点
void myLinkedListDeleteAtIndex(struct MyLinkedList* obj, int index) {
    struct ListNode* current = obj->head;
    for (int i = 0; i < index && current != NULL; i++) {
        current = current->next;
    }
    if (current == NULL || current->next == NULL) return;
    struct ListNode* toDelete = current->next;
    current->next = current->next->next;
    free(toDelete);
}

// 释放链表
void myLinkedListFree(struct MyLinkedList* obj) {
    struct ListNode* current = obj->head;
    while (current != NULL) {
        struct ListNode* toDelete = current;
        current = current->next;
        free(toDelete);
    }
    free(obj);
}

// 打印链表
void printList(struct MyLinkedList* obj) {
    struct ListNode* current = obj->head->next;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}

// 测试主函数
int main() {
    // 创建链表
    struct MyLinkedList* myList = myLinkedListCreate();
    printf("初始链表: ");
    printList(myList);

    // 添加节点
    myLinkedListAddAtHead(myList, 1);
    printf("添加 1 到头部: ");
    printList(myList);

    myLinkedListAddAtTail(myList, 3);
    printf("添加 3 到尾部: ");
    printList(myList);

    myLinkedListAddAtIndex(myList, 1, 2);
    printf("在索引 1 添加 2: ");
    printList(myList);

    // 获取值
    int val = myLinkedListGet(myList, 1);
    printf("获取索引 1 的值: %d\n", val);

    // 删除节点
    myLinkedListDeleteAtIndex(myList, 1);
    printf("删除索引 1 的节点: ");
    printList(myList);

    // 释放链表
    myLinkedListFree(myList);
    return 0;
}
