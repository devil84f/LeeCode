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

// 哈希表大小（选择一个质数以减少冲突）
#define HASH_SIZE 20011

// 哈希表节点结构体
typedef struct {
    int key;   // 存储数字
    int value; // 存储下标
} HashNode;

// 哈希表
HashNode* hashTable[HASH_SIZE];

// 初始化哈希表
void initHashTable() {
    for (int i = 0; i < HASH_SIZE; i++) {
        hashTable[i] = NULL;
    }
}

// 哈希函数
int hash(int key) {
    return abs(key) % HASH_SIZE; // 取绝对值并取模
}

// 插入哈希表
void insert(int key, int value) {
    int index = hash(key);
    while (hashTable[index] != NULL) {
        index = (index + 1) % HASH_SIZE; // 线性探测解决冲突
    }
    HashNode* node = (HashNode*)malloc(sizeof(HashNode));
    node->key = key;
    node->value = value;
    hashTable[index] = node;
}

// 查找哈希表
int find(int key) {
    int index = hash(key);
    while (hashTable[index] != NULL) {
        if (hashTable[index]->key == key) {
            return hashTable[index]->value; // 返回下标
        }
        index = (index + 1) % HASH_SIZE; // 线性探测解决冲突
    }
    return -1; // 未找到
}

// 两数之和函数
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    initHashTable(); // 初始化哈希表
    int* result = (int*)malloc(2 * sizeof(int)); // 分配结果数组的内存
    *returnSize = 2; // 设置返回数组的大小为 2

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i]; // 计算目标值与当前数字的差值
        int index = find(complement); // 查找差值是否在哈希表中
        if (index != -1) {
            result[0] = index; // 差值的下标
            result[1] = i;     // 当前数字的下标
            return result;     // 返回结果
        }
        insert(nums[i], i); // 将当前数字及其下标存入哈希表
    }

    return result; // 如果没有找到，返回空数组（题目保证有解）
}

// 测试主函数
int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;

    int* result = twoSum(nums, numsSize, target, &returnSize);

    printf("结果: [%d, %d]\n", result[0], result[1]);

    // 释放动态分配的内存
    free(result);

    // 释放哈希表内存
    for (int i = 0; i < HASH_SIZE; i++) {
        if (hashTable[i] != NULL) {
            free(hashTable[i]);
        }
    }

    return 0;
}