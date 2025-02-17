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

// 哈希表的大小
#define HASH_SIZE 100000

// 哈希表结点
typedef struct HashNode {
    int key;
    int value;
    struct HashNode* next;
} HashNode;

// 创建哈希表
HashNode** createHashTable() {
    HashNode** table = (HashNode**)malloc(sizeof(HashNode*) * HASH_SIZE);
    for (int i = 0; i < HASH_SIZE; i++) {
        table[i] = NULL;
    }
    return table;
}

// 哈希函数
int hash(int key) {
    return (key % HASH_SIZE + HASH_SIZE) % HASH_SIZE;
}

// 向哈希表插入键值对
void insert(HashNode** table, int key, int value) {
    int idx = hash(key);
    HashNode* node = table[idx];
    
    while (node) {
        if (node->key == key) {
            node->value += value; // 如果已经存在，更新计数
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

// 在哈希表中查找
int find(HashNode** table, int key) {
    int idx = hash(key);
    HashNode* node = table[idx];
    
    while (node) {
        if (node->key == key) {
            return node->value;
        }
        node = node->next;
    }
    
    return 0; // 没找到返回0
}

// 4Sum II的解法
int fourSumCount(int* A, int* B, int* C, int* D, int ASize, int BSize, int CSize, int DSize) {
    int result = 0;
    HashNode** table = createHashTable();
    
    // 将A + B的组合和出现次数存入哈希表
    for (int i = 0; i < ASize; i++) {
        for (int j = 0; j < BSize; j++) {
            int sumAB = A[i] + B[j];
            insert(table, sumAB, 1);
        }
    }
    
    // 遍历C + D的组合，检查是否有对应的-(C + D)在哈希表中
    for (int i = 0; i < CSize; i++) {
        for (int j = 0; j < DSize; j++) {
            int sumCD = -(C[i] + D[j]);
            result += find(table, sumCD); // 查找是否有相同的和
        }
    }
    
    return result;
}

// 测试代码
int main() {
    int A[] = {1, 2};
    int B[] = {-2, -1};
    int C[] = {-1, 2};
    int D[] = {0, 2};
    
    int result = fourSumCount(A, B, C, D, 2, 2, 2, 2);
    printf("Result: %d\n", result);  // 2
    
    return 0;
}
