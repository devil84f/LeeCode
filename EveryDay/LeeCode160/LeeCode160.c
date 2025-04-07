/*
 * @Author: LiNing
 * @Date: 2025-04-07
 * �ཻ�����C���Խⷨ������������
*/
#include <stdio.h>
#include <stdlib.h>

// ����ڵ㶨��
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

// ��������ڵ�
struct ListNode *createNode(int val) {
    struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// ��ӡ����
void printList(struct ListNode *head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

// ����������
int main() {
    // ������������
    // ����A: 4 -> 1 -> 8 -> 4 -> 5
    // ����B: 5 -> 0 -> 1 -> 8 -> 4 -> 5
    // �ཻ�ڵ���ֵΪ8�Ľڵ�
    
    // ������������
    struct ListNode *commonNode1 = createNode(8);
    struct ListNode *commonNode2 = createNode(4);
    struct ListNode *commonNode3 = createNode(5);
    commonNode1->next = commonNode2;
    commonNode2->next = commonNode3;
    
    // ��������A
    struct ListNode *headA = createNode(4);
    struct ListNode *nodeA1 = createNode(1);
    headA->next = nodeA1;
    nodeA1->next = commonNode1;
    
    // ��������B
    struct ListNode *headB = createNode(5);
    struct ListNode *nodeB1 = createNode(0);
    struct ListNode *nodeB2 = createNode(1);
    headB->next = nodeB1;
    nodeB1->next = nodeB2;
    nodeB2->next = commonNode1;
    
    // ��ӡ����
    printf("����A: ");
    printList(headA);
    printf("����B: ");
    printList(headB);
    
    // �����ཻ�ڵ�
    struct ListNode *intersection = getIntersectionNode(headA, headB);
    if (intersection != NULL) {
        printf("�ཻ�ڵ�ֵΪ: %d\n", intersection->val);
    } else {
        printf("�����ཻ\n");
    }
    
    // �ͷ��ڴ�
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
