/*
 * @Author: LiNing
 * @Date: 2025-03-22
 * һ������
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* rowAndMaximumOnes(int** mat, int matSize, int* matColSize, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * 2);
    int num = 0;
    int col = 0;
    for (int i = 0; i < matSize; i++) {
        int temp = 0;
        for (int j = 0; j < matColSize[i]; j++) {
            if (mat[i][j] == 1) temp++;
        }
        if (temp > num) {
            num = temp;
            col = i;
        }
    }
    * returnSize = 2;
    result[0] = col;
    result[1] = num;
    return result;
}

int main () {
    // ����һ����ά�������
    int matSize = 3; // ���������
    int matColSize[3] = {5, 5, 5}; // ÿ�е�����
    int** mat = (int**)malloc(matSize * sizeof(int*)); // ��̬����������ָ��

    // ��ʼ������
    mat[0] = (int*)malloc(matColSize[0] * sizeof(int));
    mat[1] = (int*)malloc(matColSize[1] * sizeof(int));
    mat[2] = (int*)malloc(matColSize[2] * sizeof(int));

    // ������
    mat[0][0] = 0; mat[0][1] = 1; mat[0][2] = 1; mat[0][3] = 0; mat[0][4] = 0;
    mat[1][0] = 1; mat[1][1] = 0; mat[1][2] = 0; mat[1][3] = 1; mat[1][4] = 1;
    mat[2][0] = 1; mat[2][1] = 1; mat[2][2] = 1; mat[2][3] = 1; mat[2][4] = 0;

    // ��ӡ����
    printf("Matrix:\n");
    for (int i = 0; i < matSize; i++) {
        for (int j = 0; j < matColSize[i]; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    // ���ú���
    int returnSize;
    int* result = rowAndMaximumOnes(mat, matSize, matColSize, &returnSize);

    // ��ӡ���
    printf("Result:\n");
    printf("Row with maximum ones: %d\n", result[0]);
    printf("Number of ones in that row: %d\n", result[1]);

    // �ͷ��ڴ�
    for (int i = 0; i < matSize; i++) {
        free(mat[i]);
    }
    free(mat);
    free(result);

    return 0;
}