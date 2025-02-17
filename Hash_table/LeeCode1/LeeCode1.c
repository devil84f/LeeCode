/*
 * @Author: LiNing
 * @Date: 2025-01-28 01:08:34
 * @LastEditors: LiNing
 * @LastEditTime: 2025-01-28 01:23:05
 * @FilePath: \LeeCode_Modularization\Hash_table\LeeCode1\LeeCode1.c
 * @Description: 
 * Copyright (c) 2025 by ${git_name_email}, All Rights Reserved. 
 */
#include <stdio.h>
#include <stdlib.h>

// ��ϣ���С��ѡ��һ�������Լ��ٳ�ͻ��
#define HASH_SIZE 20011

// ��ϣ��ڵ�ṹ��
typedef struct {
    int key;   // �洢����
    int value; // �洢�±�
} HashNode;

// ��ϣ��
HashNode* hashTable[HASH_SIZE];

// ��ʼ����ϣ��
void initHashTable() {
    for (int i = 0; i < HASH_SIZE; i++) {
        hashTable[i] = NULL;
    }
}

// ��ϣ����
int hash(int key) {
    return abs(key) % HASH_SIZE; // ȡ����ֵ��ȡģ
}

// �����ϣ��
void insert(int key, int value) {
    int index = hash(key);
    while (hashTable[index] != NULL) {
        index = (index + 1) % HASH_SIZE; // ����̽������ͻ
    }
    HashNode* node = (HashNode*)malloc(sizeof(HashNode));
    node->key = key;
    node->value = value;
    hashTable[index] = node;
}

// ���ҹ�ϣ��
int find(int key) {
    int index = hash(key);
    while (hashTable[index] != NULL) {
        if (hashTable[index]->key == key) {
            return hashTable[index]->value; // �����±�
        }
        index = (index + 1) % HASH_SIZE; // ����̽������ͻ
    }
    return -1; // δ�ҵ�
}

// ����֮�ͺ���
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    initHashTable(); // ��ʼ����ϣ��
    int* result = (int*)malloc(2 * sizeof(int)); // ������������ڴ�
    *returnSize = 2; // ���÷�������Ĵ�СΪ 2

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i]; // ����Ŀ��ֵ�뵱ǰ���ֵĲ�ֵ
        int index = find(complement); // ���Ҳ�ֵ�Ƿ��ڹ�ϣ����
        if (index != -1) {
            result[0] = index; // ��ֵ���±�
            result[1] = i;     // ��ǰ���ֵ��±�
            return result;     // ���ؽ��
        }
        insert(nums[i], i); // ����ǰ���ּ����±�����ϣ��
    }

    return result; // ���û���ҵ������ؿ����飨��Ŀ��֤�н⣩
}

// ����������
int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;

    int* result = twoSum(nums, numsSize, target, &returnSize);

    printf("���: [%d, %d]\n", result[0], result[1]);

    // �ͷŶ�̬������ڴ�
    free(result);

    // �ͷŹ�ϣ���ڴ�
    for (int i = 0; i < HASH_SIZE; i++) {
        if (hashTable[i] != NULL) {
            free(hashTable[i]);
        }
    }

    return 0;
}