/*
 * @Author: LiNing
 * @Date: 2025-05-19
 * ����������
*/

#include <stdio.h>
#include <string.h>

char* triangleType(int a, int b, int c) {
    // ����Ƿ��ܹ���������
    if (a + b <= c || a + c <= b || b + c <= a) {
        return "none";
    }
    
    // �ж�����������
    if (a == b && b == c) {
        return "equilateral";
    } else if (a == b || b == c || a == c) {
        return "isosceles";
    } else {
        return "scalene";
    }
}

// ����������
int main() {
    // ��������1: �ȱ�������
    printf("����1 (3,3,3): %s\n", triangleType(3, 3, 3));
    
    // ��������2: ����������
    printf("����2 (3,3,4): %s\n", triangleType(3, 3, 4));
    
    // ��������3: ��ͨ������
    printf("����3 (3,4,5): %s\n", triangleType(3, 4, 5));
    
    // ��������4: ���ܹ���������
    printf("����4 (1,1,3): %s\n", triangleType(1, 1, 3));
    
    // ��������5: ����������(��һ�����)
    printf("����5 (5,5,2): %s\n", triangleType(5, 5, 2));
    
    // ��������6: ���ܹ���������(�߳�Ϊ0)
    printf("����6 (0,1,2): %s\n", triangleType(0, 1, 2));
    
    // ��������7: ���ܹ���������(���߳�)
    printf("����7 (-1,2,3): %s\n", triangleType(-1, 2, 3));
    
    return 0;
}
