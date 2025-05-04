/*
 * @Author: LiNing
 * @Date: 2025-05-04
 * �ȼ۶���ŵ���ƶԵ�����
*/
#include <stdio.h>
// #include <stdlib.h>

int numEquivDominoPairs(int** dominoes, int dominoesSize, int* dominoesColSize) {
    int hash[100] = {0};
    int ret = 0;

    for (int i = 0; i < dominoesSize; i++) {
        int a = dominoes[i][0];
        int b = dominoes[i][1];
        int key = a < b ? a * 10 + b : b * 10 + a;
        ret += hash[key];
        hash[key]++; 
    }

    return ret;
}

int main() {
    // �������� [[1,2],[2,1],[3,4],[5,6]]
    int data[4][2] = {{1, 2}, {2, 1}, {3, 4}, {5, 6}};
    int* dominoes[4];
    int dominoesColSize[4];

    for (int i = 0; i < 4; i++) {
        dominoes[i] = data[i];       // ָ������ָ���ά������
        dominoesColSize[i] = 2;      // ÿ�������鳤��Ϊ 2
    }

    int result = numEquivDominoPairs(dominoes, 4, dominoesColSize);
    printf("�ȼ۶���ŵ���ƶԵ�����Ϊ: %d\n", result);  // ���Ӧ��Ϊ 1

    return 0;
}