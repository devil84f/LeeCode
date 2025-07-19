#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 比较函数，用于排序
int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

// 判断b是否是a的子文件夹
int isSubfolder(const char *a, const char *b) {
    while (*a && *b && *a == *b) {
        a++;
        b++;
    }
    return (*a == '\0' && *b == '/');
}

char **removeSubfolders(char **folder, int folderSize, int *returnSize) {
    // 对文件夹路径进行排序
    qsort(folder, folderSize, sizeof(char *), compare);
    
    char **result = (char **)malloc(folderSize * sizeof(char *));
    *returnSize = 0;
    
    // 第一个文件夹一定不是子文件夹
    result[(*returnSize)++] = folder[0];
    
    for (int i = 1; i < folderSize; i++) {
        // 检查当前文件夹是否是前一个结果的子文件夹
        if (!isSubfolder(result[*returnSize - 1], folder[i])) {
            result[(*returnSize)++] = folder[i];
        }
    }
    
    return result;
}

// 测试函数
void testRemoveSubfolders() {
    // 测试用例1
    char *folder1[] = {"/a", "/a/b", "/c/d", "/c/d/e", "/c/f"};
    int folderSize1 = 5;
    int returnSize1;
    char **result1 = removeSubfolders(folder1, folderSize1, &returnSize1);
    printf("Test Case 1:\n");
    for (int i = 0; i < returnSize1; i++) {
        printf("%s\n", result1[i]);
    }
    free(result1);
    
    // 测试用例2
    char *folder2[] = {"/a", "/a/b/c", "/a/b/d"};
    int folderSize2 = 3;
    int returnSize2;
    char **result2 = removeSubfolders(folder2, folderSize2, &returnSize2);
    printf("\nTest Case 2:\n");
    for (int i = 0; i < returnSize2; i++) {
        printf("%s\n", result2[i]);
    }
    free(result2);
    
    // 测试用例3
    char *folder3[] = {"/a/b/c", "/a/b/ca", "/a/b/d"};
    int folderSize3 = 3;
    int returnSize3;
    char **result3 = removeSubfolders(folder3, folderSize3, &returnSize3);
    printf("\nTest Case 3:\n");
    for (int i = 0; i < returnSize3; i++) {
        printf("%s\n", result3[i]);
    }
    free(result3);
}

int main() {
    testRemoveSubfolders();
    return 0;
}
