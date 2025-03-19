/*
 * @Author: LiNing
 * @Date: 2025-03-18
 * ���ؾ���Խ������������
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int isPrime(int num) {
    if (num <= 1) {
        return 0; // 0��1��������
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0; // ���num�ܱ�i��������num��������
        }
    }
    return 1; // ���num���ܱ�2��sqrt(num)֮����κ�һ������������num������
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
    printf("����Խ��������������%d\n", diagonalPrime(mat1Ptr, matSize1, matColSize1));
    return 0;
}