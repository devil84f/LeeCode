/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2025-01-08 00:03:12
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2025-01-08 00:13:06
 * @FilePath: \LeeCode_Arrays\LeeCode704\LeeCode704.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

#include <stdio.h>

int search(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    int middle = left + (right - left) / 2;

    while (left <= right) {  
        // 检查middle是否为目标值
        if (nums[middle] == target) return middle;

        // middle小于target 说明target在middle右边 移动left到middle右边一位
        // middle大于target 说明target在middle左边 移动right到middle左边一位
        if (nums[middle] < target) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }

        // 更新middle位置
        middle = left + (right - left) / 2;
    }
    return -1;
}

int main () {
    int nums[] = {-1, 0, 3, 5, 9, 12};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 9;

    int result = search(nums, numsSize, target);

    if (result != -1) {
        printf("Target %d found at index %d\n", target, result);
    } else {
        printf("Target %d not found in the array.\n", target);
    }
    
    return 0;
}