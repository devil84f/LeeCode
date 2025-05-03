/*
 * @Author: LiNing
 * @Date: 2025-04-13
 * 统计好三元组
*/
#include <stdio.h>
#include <stdlib.h>

int countGoodTriplets(int* arr, int arrSize, int a, int b, int c) {
    int count = 0;
    for (int i = 0; i < arrSize - 2; i++) {
        for (int j = i + 1; j < arrSize - 1; j++) {
            if (abs(arr[i] - arr[j]) > a) {
                continue;
            }
            for (int k = j + 1; k < arrSize; k++) {
                if (abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c) {
                    count++;
                }
            }
        }
    }
    return count;
}

int main() {
    // 测试用例1
    int arr1[] = {3, 0, 1, 1, 9, 7};
    int a1 = 7, b1 = 2, c1 = 3;
    int expected1 = 4;
    int result1 = countGoodTriplets(arr1, sizeof(arr1)/sizeof(arr1[0]), a1, b1, c1);
    printf("Test case 1: %s\n", result1 == expected1 ? "Passed" : "Failed");
    printf("Expected: %d, Result: %d\n\n", expected1, result1);

    // 测试用例2
    int arr2[] = {1, 1, 2, 2, 3};
    int a2 = 0, b2 = 0, c2 = 1;
    int expected2 = 0;
    int result2 = countGoodTriplets(arr2, sizeof(arr2)/sizeof(arr2[0]), a2, b2, c2);
    printf("Test case 2: %s\n", result2 == expected2 ? "Passed" : "Failed");
    printf("Expected: %d, Result: %d\n\n", expected2, result2);

    // 测试用例3
    int arr3[] = {7, 3, 7, 3, 12, 1, 12, 2, 3};
    int a3 = 5, b3 = 8, c3 = 1;
    int expected3 = 12;
    int result3 = countGoodTriplets(arr3, sizeof(arr3)/sizeof(arr3[0]), a3, b3, c3);
    printf("Test case 3: %s\n", result3 == expected3 ? "Passed" : "Failed");
    printf("Expected: %d, Result: %d\n\n", expected3, result3);

    return 0;
}