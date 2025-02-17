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

// ����ڵ�ṹ
struct ListNode {
    int val;
    struct ListNode *next;
};

// ������
struct MyLinkedList {
    struct ListNode *head;
};

// ����һ���½ڵ�
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// ��ʼ������
struct MyLinkedList* myLinkedListCreate() {
    struct MyLinkedList* obj = (struct MyLinkedList*)malloc(sizeof(struct MyLinkedList));
    obj->head = createNode(0);  // ��������ͷ�ڵ�
    return obj;
}

// ��ȡ����� index ���ڵ��ֵ
int myLinkedListGet(struct MyLinkedList* obj, int index) {
    struct ListNode* current = obj->head->next;  // ������ͷ�ڵ����һ����ʼ
    for (int i = 0; i < index && current != NULL; i++) {
        current = current->next;
    }
    return (current == NULL) ? -1 : current->val;
}

// ������ͷ�����һ��ֵΪ val �Ľڵ�
void myLinkedListAddAtHead(struct MyLinkedList* obj, int val) {
    struct ListNode* newNode = createNode(val);
    newNode->next = obj->head->next;
    obj->head->next = newNode;
}

// ������β�����һ��ֵΪ val �Ľڵ�
void myLinkedListAddAtTail(struct MyLinkedList* obj, int val) {
    struct ListNode* current = obj->head;
    while (current->next != NULL) {
        current = current->next;
    }
    struct ListNode* newNode = createNode(val);
    current->next = newNode;
}

// ������� index ��λ��֮ǰ���һ��ֵΪ val �Ľڵ�
void myLinkedListAddAtIndex(struct MyLinkedList* obj, int index, int val) {
    if (index < 0) return;
    struct ListNode* current = obj->head;
    for (int i = 0; i < index && current != NULL; i++) {
        current = current->next;
    }
    if (current == NULL) return;  // ������Ч
    struct ListNode* newNode = createNode(val);
    newNode->next = current->next;
    current->next = newNode;
}

// ɾ������� index ��λ�õĽڵ�
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

// �ͷ�����
void myLinkedListFree(struct MyLinkedList* obj) {
    struct ListNode* current = obj->head;
    while (current != NULL) {
        struct ListNode* toDelete = current;
        current = current->next;
        free(toDelete);
    }
    free(obj);
}

// ��ӡ����
void printList(struct MyLinkedList* obj) {
    struct ListNode* current = obj->head->next;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}

// ����������
int main() {
    // ��������
    struct MyLinkedList* myList = myLinkedListCreate();
    printf("��ʼ����: ");
    printList(myList);

    // ��ӽڵ�
    myLinkedListAddAtHead(myList, 1);
    printf("��� 1 ��ͷ��: ");
    printList(myList);

    myLinkedListAddAtTail(myList, 3);
    printf("��� 3 ��β��: ");
    printList(myList);

    myLinkedListAddAtIndex(myList, 1, 2);
    printf("������ 1 ��� 2: ");
    printList(myList);

    // ��ȡֵ
    int val = myLinkedListGet(myList, 1);
    printf("��ȡ���� 1 ��ֵ: %d\n", val);

    // ɾ���ڵ�
    myLinkedListDeleteAtIndex(myList, 1);
    printf("ɾ������ 1 �Ľڵ�: ");
    printList(myList);

    // �ͷ�����
    myLinkedListFree(myList);
    return 0;
}
