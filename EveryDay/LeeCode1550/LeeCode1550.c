/*
 * @Author: LiNing
 * @Date: 2025-05-11
 * 存在连续三个奇数的数组
*/

#include <stdio.h>
#include <stdbool.h>

bool threeConsecutiveOdds(int* arr, int arrSize) {
    int num = 0;
    for (int i = 0; i < arrSize; i++) {
        if ((arr[i] % 2) == 1) {
            num++;
        } else num = 0;
        if (num == 3) return true;
    }
    return false;
}

// 测试主函数
int main() {
    // 测试用例1
    int arr1[] = {2, 6, 4, 1};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("测试1: %s\n", threeConsecutiveOdds(arr1, size1) ? "true" : "false");
    
    // 测试用例2
    int arr2[] = {1, 2, 34, 3, 4, 5, 7, 23, 12};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("测试2: %s\n", threeConsecutiveOdds(arr2, size2) ? "true" : "false");
    
    // 测试用例3
    int arr3[] = {1, 3, 5};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    printf("测试3: %s\n", threeConsecutiveOdds(arr3, size3) ? "true" : "false");
    
    // 测试用例4
    int arr4[] = {1, 1, 1};
    int size4 = sizeof(arr4) / sizeof(arr4[0]);
    printf("测试4: %s\n", threeConsecutiveOdds(arr4, size4) ? "true" : "false");
    
    // 测试用例5
    int arr5[] = {2, 4, 6, 8};
    int size5 = sizeof(arr5) / sizeof(arr5[0]);
    printf("测试5: %s\n", threeConsecutiveOdds(arr5, size5) ? "true" : "false");
    
    return 0;
}
