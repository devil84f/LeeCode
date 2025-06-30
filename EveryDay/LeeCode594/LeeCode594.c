#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ��ϣ��ڵ�ṹ
typedef struct HashNode {
    int key;
    int value;
    struct HashNode* next;
} HashNode;

// ��ϣ��ṹ
typedef struct {
    HashNode** buckets;
    int size;
    int capacity;
} HashMap;

// ��ʼ����ϣ��
HashMap* createHashMap(int capacity) {
    HashMap* map = (HashMap*)malloc(sizeof(HashMap));
    map->buckets = (HashNode**)calloc(capacity, sizeof(HashNode*));
    map->size = 0;
    map->capacity = capacity;
    return map;
}

// ��ϣ����
int hash(int key, int capacity) {
    return (key & 0x7fffffff) % capacity;
}

// ���ݹ�ϣ��
void resize(HashMap* map) {
    int newCapacity = map->capacity * 2;
    HashNode** newBuckets = (HashNode**)calloc(newCapacity, sizeof(HashNode*));
    for (int i = 0; i < map->capacity; i++) {
        HashNode* node = map->buckets[i];
        while (node != NULL) {
            HashNode* next = node->next;
            int index = hash(node->key, newCapacity);
            node->next = newBuckets[index];
            newBuckets[index] = node;
            node = next;
        }
    }
    
    free(map->buckets);
    map->buckets = newBuckets;
    map->capacity = newCapacity;
}

// �������¼�ֵ��
void put(HashMap* map, int key, int value) {
    if (map->size >= map->capacity / 2) {
        resize(map);
    }
    
    int index = hash(key, map->capacity);
    HashNode* node = map->buckets[index];
    
    // ����Ƿ��Ѵ���
    while (node != NULL) {
        if (node->key == key) {
            node->value = value;
            return;
        }
        node = node->next;
    }
    
    // �����½ڵ�
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->key = key;
    newNode->value = value;
    newNode->next = map->buckets[index];
    map->buckets[index] = newNode;
    map->size++;
}

// ��ȡ����Ӧ��ֵ
int get(HashMap* map, int key) {
    int index = hash(key, map->capacity);
    HashNode* node = map->buckets[index];
    
    while (node != NULL) {
        if (node->key == key) {
            return node->value;
        }
        node = node->next;
    }
    
    return 0; // Ĭ�Ϸ���0
}

// ���ٹ�ϣ��
void freeHashMap(HashMap* map) {
    for (int i = 0; i < map->capacity; i++) {
        HashNode* node = map->buckets[i];
        while (node != NULL) {
            HashNode* next = node->next;
            free(node);
            node = next;
        }
    }
    free(map->buckets);
    free(map);
}

// �����⺯��
int findLHS(int* nums, int numsSize) {
    HashMap* map = createHashMap(16);
    int max_len = 0;
    
    // ͳ��Ƶ��
    for (int i = 0; i < numsSize; i++) {
        int count = get(map, nums[i]);
        put(map, nums[i], count + 1);
    }
    
    // ������������
    for (int i = 0; i < map->capacity; i++) {
        HashNode* node = map->buckets[i];
        while (node != NULL) {
            int key = node->key;
            int count = get(map, key + 1);
            if (count > 0) {
                int current = node->value + count;
                if (current > max_len) {
                    max_len = current;
                }
            }
            node = node->next;
        }
    }
    
    freeHashMap(map);
    return max_len;
}

int main() {
    int nums[] = {1,3,2,2,5,2,3,7};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    
    int result = findLHS(nums, numsSize);
    printf("The longest harmonious subsequence length is: %d\n", result);
    
    return 0;
}