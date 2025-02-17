/*
 * @Author: LiNing
 * @Date: 2025-01-29 23:38:54
 * @LastEditors: LiNing
 * @LastEditTime: 2025-01-29 23:50:59
 * @FilePath: \LeeCode_Modularization\Hash_table\LeeCode454\LeeCode454.c
 * @Description: 
 * Copyright (c) 2025 by ${git_name_email}, All Rights Reserved. 
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ��ϣ��Ĵ�С
#define HASH_SIZE 100000

// ��ϣ����
typedef struct HashNode {
    int key;
    int value;
    struct HashNode* next;
} HashNode;

// ������ϣ��
HashNode** createHashTable() {
    HashNode** table = (HashNode**)malloc(sizeof(HashNode*) * HASH_SIZE);
    for (int i = 0; i < HASH_SIZE; i++) {
        table[i] = NULL;
    }
    return table;
}

// ��ϣ����
int hash(int key) {
    return (key % HASH_SIZE + HASH_SIZE) % HASH_SIZE;
}

// ���ϣ������ֵ��
void insert(HashNode** table, int key, int value) {
    int idx = hash(key);
    HashNode* node = table[idx];
    
    while (node) {
        if (node->key == key) {
            node->value += value; // ����Ѿ����ڣ����¼���
            return;
        }
        node = node->next;
    }
    
    node = (HashNode*)malloc(sizeof(HashNode));
    node->key = key;
    node->value = value;
    node->next = table[idx];
    table[idx] = node;
}

// �ڹ�ϣ���в���
int find(HashNode** table, int key) {
    int idx = hash(key);
    HashNode* node = table[idx];
    
    while (node) {
        if (node->key == key) {
            return node->value;
        }
        node = node->next;
    }
    
    return 0; // û�ҵ�����0
}

// 4Sum II�Ľⷨ
int fourSumCount(int* A, int* B, int* C, int* D, int ASize, int BSize, int CSize, int DSize) {
    int result = 0;
    HashNode** table = createHashTable();
    
    // ��A + B����Ϻͳ��ִ��������ϣ��
    for (int i = 0; i < ASize; i++) {
        for (int j = 0; j < BSize; j++) {
            int sumAB = A[i] + B[j];
            insert(table, sumAB, 1);
        }
    }
    
    // ����C + D����ϣ�����Ƿ��ж�Ӧ��-(C + D)�ڹ�ϣ����
    for (int i = 0; i < CSize; i++) {
        for (int j = 0; j < DSize; j++) {
            int sumCD = -(C[i] + D[j]);
            result += find(table, sumCD); // �����Ƿ�����ͬ�ĺ�
        }
    }
    
    return result;
}

// ���Դ���
int main() {
    int A[] = {1, 2};
    int B[] = {-2, -1};
    int C[] = {-1, 2};
    int D[] = {0, 2};
    
    int result = fourSumCount(A, B, C, D, 2, 2, 2, 2);
    printf("Result: %d\n", result);  // 2
    
    return 0;
}
