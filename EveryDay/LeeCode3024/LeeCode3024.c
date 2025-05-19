/*
 * @Author: LiNing
 * @Date: 2025-05-19
 * 三角形类型
*/

#include <stdio.h>
#include <string.h>

char* triangleType(int a, int b, int c) {
    // 检查是否能构成三角形
    if (a + b <= c || a + c <= b || b + c <= a) {
        return "none";
    }
    
    // 判断三角形类型
    if (a == b && b == c) {
        return "equilateral";
    } else if (a == b || b == c || a == c) {
        return "isosceles";
    } else {
        return "scalene";
    }
}

// 测试主函数
int main() {
    // 测试用例1: 等边三角形
    printf("测试1 (3,3,3): %s\n", triangleType(3, 3, 3));
    
    // 测试用例2: 等腰三角形
    printf("测试2 (3,3,4): %s\n", triangleType(3, 3, 4));
    
    // 测试用例3: 普通三角形
    printf("测试3 (3,4,5): %s\n", triangleType(3, 4, 5));
    
    // 测试用例4: 不能构成三角形
    printf("测试4 (1,1,3): %s\n", triangleType(1, 1, 3));
    
    // 测试用例5: 等腰三角形(另一种情况)
    printf("测试5 (5,5,2): %s\n", triangleType(5, 5, 2));
    
    // 测试用例6: 不能构成三角形(边长为0)
    printf("测试6 (0,1,2): %s\n", triangleType(0, 1, 2));
    
    // 测试用例7: 不能构成三角形(负边长)
    printf("测试7 (-1,2,3): %s\n", triangleType(-1, 2, 3));
    
    return 0;
}
