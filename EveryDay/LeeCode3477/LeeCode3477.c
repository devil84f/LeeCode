#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int remainingFruits(int* fruits, int fruitsSize, int* baskets, int basketsSize) {
    bool* used = (bool*)calloc(basketsSize, sizeof(bool)); // 标记篮子是否被占用
    int cannotPlace = 0; // 无法放置的水果数量

    for (int i = 0; i < fruitsSize; i++) {
        bool placed = false;
        for (int j = 0; j < basketsSize; j++) {
            if (!used[j] && baskets[j] >= fruits[i]) {
                used[j] = true; // 占用该篮子
                placed = true;
                break;
            }
        }
        if (!placed) {
            cannotPlace++;
        }
    }

    free(used);
    return cannotPlace;
}

// 测试用例
void test() {
    int fruits1[] = {3, 2, 4, 1};
    int baskets1[] = {4, 3, 2, 5};
    int result1 = remainingFruits(fruits1, 4, baskets1, 4);
    printf("Test 1: %d (Expected: 0)\n", result1);

    int fruits2[] = {5, 6, 7};
    int baskets2[] = {4, 4, 4};
    int result2 = remainingFruits(fruits2, 3, baskets2, 3);
    printf("Test 2: %d (Expected: 3)\n", result2);

    int fruits3[] = {1, 2, 3};
    int baskets3[] = {3, 2, 1};
    int result3 = remainingFruits(fruits3, 3, baskets3, 3);
    printf("Test 3: %d (Expected: 0)\n", result3);
}

int main() {
    test();
    return 0;
}