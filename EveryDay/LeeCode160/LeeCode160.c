/*
 * @Author: LiNing
 * @Date: 2025-04-07
 * 相交链表的C语言解法及测试主函数
*/
#include <stdio.h>
#include <stdlib.h>

// 链表节点定义
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if (headA == NULL || headB == NULL) return NULL;
    
    struct ListNode *pA = headA;
    struct ListNode *pB = headB;
    
    while (pA != pB) {
        pA = (pA == NULL) ? headB : pA->next;
        pB = (pB == NULL) ? headA : pB->next;
    }
    
    return pA;
}

// 创建链表节点
struct ListNode *createNode(int val) {
    struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// 打印链表
void printList(struct ListNode *head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

// 测试主函数
int main() {
    // 创建测试链表
    // 链表A: 4 -> 1 -> 8 -> 4 -> 5
    // 链表B: 5 -> 0 -> 1 -> 8 -> 4 -> 5
    // 相交节点是值为8的节点
    
    // 创建公共部分
    struct ListNode *commonNode1 = createNode(8);
    struct ListNode *commonNode2 = createNode(4);
    struct ListNode *commonNode3 = createNode(5);
    commonNode1->next = commonNode2;
    commonNode2->next = commonNode3;
    
    // 创建链表A
    struct ListNode *headA = createNode(4);
    struct ListNode *nodeA1 = createNode(1);
    headA->next = nodeA1;
    nodeA1->next = commonNode1;
    
    // 创建链表B
    struct ListNode *headB = createNode(5);
    struct ListNode *nodeB1 = createNode(0);
    struct ListNode *nodeB2 = createNode(1);
    headB->next = nodeB1;
    nodeB1->next = nodeB2;
    nodeB2->next = commonNode1;
    
    // 打印链表
    printf("链表A: ");
    printList(headA);
    printf("链表B: ");
    printList(headB);
    
    // 查找相交节点
    struct ListNode *intersection = getIntersectionNode(headA, headB);
    if (intersection != NULL) {
        printf("相交节点值为: %d\n", intersection->val);
    } else {
        printf("链表不相交\n");
    }
    
    // 释放内存
    free(commonNode1);
    free(commonNode2);
    free(commonNode3);
    free(headA);
    free(nodeA1);
    free(headB);
    free(nodeB1);
    free(nodeB2);
    
    return 0;
}
