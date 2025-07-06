#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 20000 // 假设哈希表大小足够
#define EMPTY -1
#define DELETED -2

typedef struct {
    int* nums1;
    int nums1Size;
    int* nums2;
    int nums2Size;
    int* keys;
    int* values;
} FindSumPairs;

FindSumPairs* findSumPairsCreate(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    FindSumPairs* obj = (FindSumPairs*)malloc(sizeof(FindSumPairs));
    obj->nums1 = (int*)malloc(nums1Size * sizeof(int));
    obj->nums2 = (int*)malloc(nums2Size * sizeof(int));
    obj->nums1Size = nums1Size;
    obj->nums2Size = nums2Size;
    memcpy(obj->nums1, nums1, nums1Size * sizeof(int));
    memcpy(obj->nums2, nums2, nums2Size * sizeof(int));

    // 初始化哈希表
    obj->keys = (int*)malloc(HASH_SIZE * sizeof(int));
    obj->values = (int*)malloc(HASH_SIZE * sizeof(int));
    for (int i = 0; i < HASH_SIZE; i++) {
        obj->keys[i] = EMPTY;
        obj->values[i] = 0;
    }

    // 构建 nums2 的频率哈希表
    for (int i = 0; i < nums2Size; i++) {
        int num = nums2[i];
        int index = abs(num) % HASH_SIZE;
        while (obj->keys[index] != EMPTY && obj->keys[index] != num) {
            index = (index + 1) % HASH_SIZE;
        }
        if (obj->keys[index] == EMPTY) {
            obj->keys[index] = num;
            obj->values[index] = 1;
        } else {
            obj->values[index]++;
        }
    }
    return obj;
}

void findSumPairsAdd(FindSumPairs* obj, int index, int val) {
    if (index < 0 || index >= obj->nums2Size) return;

    int old_val = obj->nums2[index];
    int new_val = old_val + val;
    obj->nums2[index] = new_val;

    // 从哈希表中移除 old_val
    int idx = abs(old_val) % HASH_SIZE;
    while (obj->keys[idx] != EMPTY && obj->keys[idx] != old_val) {
        idx = (idx + 1) % HASH_SIZE;
    }
    if (obj->keys[idx] == old_val) {
        obj->values[idx]--;
        if (obj->values[idx] == 0) {
            obj->keys[idx] = DELETED;
        }
    }

    // 向哈希表中添加 new_val
    idx = abs(new_val) % HASH_SIZE;
    while (obj->keys[idx] != EMPTY && obj->keys[idx] != new_val && obj->keys[idx] != DELETED) {
        idx = (idx + 1) % HASH_SIZE;
    }
    if (obj->keys[idx] == EMPTY || obj->keys[idx] == DELETED) {
        obj->keys[idx] = new_val;
        obj->values[idx] = 1;
    } else {
        obj->values[idx]++;
    }
}

int findSumPairsCount(FindSumPairs* obj, int tot) {
    int count = 0;
    for (int i = 0; i < obj->nums1Size; i++) {
        int target = tot - obj->nums1[i];
        int idx = abs(target) % HASH_SIZE;
        while (obj->keys[idx] != EMPTY && obj->keys[idx] != target) {
            idx = (idx + 1) % HASH_SIZE;
        }
        if (obj->keys[idx] == target) {
            count += obj->values[idx];
        }
    }
    return count;
}

void findSumPairsFree(FindSumPairs* obj) {
    free(obj->nums1);
    free(obj->nums2);
    free(obj->keys);
    free(obj->values);
    free(obj);
}

int main() {
    int nums1[] = {1, 1, 2, 2};
    int nums2[] = {3, 4, 5, 6};
    int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
    int nums2Size = sizeof(nums2) / sizeof(nums2[0]);

    FindSumPairs* obj = findSumPairsCreate(nums1, nums1Size, nums2, nums2Size);
    printf("%d\n", findSumPairsCount(obj, 7)); // 输出 2
    findSumPairsAdd(obj, 3, 2);
    printf("%d\n", findSumPairsCount(obj, 8)); // 输出 1
    findSumPairsFree(obj);
    return 0;
}
