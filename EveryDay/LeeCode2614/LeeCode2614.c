/*
 * @Author: LiNing
 * @Date: 2025-03-18
 * 返回矩阵对角线上最大质数
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int isPrime(int num) {
    if (num <= 1) {
        return 0; // 0和1不是质数
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0; // 如果num能被i整除，则num不是质数
        }
    }
    return 1; // 如果num不能被2到sqrt(num)之间的任何一个数整除，则num是质数
}

int diagonalPrime(int** nums, int numsSize, int* numsColSize) {
    int result = 0;
    int j = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i][i] > result && isPrime(nums[i][i])) {
            result = nums[i][i];
        }
        if (nums[i][numsSize - i - 1] > result && isPrime(nums[i][numsSize - i - 1])) {
            result = nums[i][numsSize - i - 1];
        }
    }
    return result;
}

int main () {
    int mat1[3][3] = {
        {2, 3, 5},
        {3, 5, 7},
        {5, 7, 11}
    };
    int matSize1 = 3;
    int* matColSize1 = (int*)malloc(matSize1 * sizeof(int));
    for (int i = 0; i < matSize1; i++) {
        matColSize1[i] = matSize1;
    }
    int** mat1Ptr = (int**)malloc(matSize1 * sizeof(int*));
    for (int i = 0; i < matSize1; i++) {
        mat1Ptr[i] = mat1[i];
    }
    printf("矩阵对角线上最大质数：%d\n", diagonalPrime(mat1Ptr, matSize1, matColSize1));
    return 0;
}